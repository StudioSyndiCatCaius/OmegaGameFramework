// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/OmegaSubsystem_File.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Engine/Texture2D.h"

#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "Sound/SoundWave.h"
#include "Sound/SoundWaveProcedural.h"
#include "Misc/FileHelper.h"

#include "OmegaSettings.h"
#include "Kismet/BlueprintPathsLibrary.h"

#include "Kismet/KismetSystemLibrary.h"

#include "ImageUtils.h"
#include "Subsystems/OmegaSubsystem_AssetHandler.h"

void UOmegaFileSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
}

TArray<FString> UOmegaFileSubsystem::GetFilesOfExtension(FString path, FString extension)
{
	IFileManager & FileManager = IFileManager::Get();
	TArray<FString> FileNames;
	FileManager.FindFiles(FileNames,*path,*extension);
	TArray<FString> out;
	for(FString fil : FileNames)
	{
		out.Add(path+fil);
	}
	return out;
}


UOmegaFileManagerSettings* UOmegaFileSubsystem::GetFileManagerSettings() const
{
	if(UOmegaFileManagerSettings* out = Cast<UOmegaFileManagerSettings>(GetMutableDefault<UOmegaSettings>()->DefaultSettings_FileManager.TryLoad()))
	{
		return out;
	}
	return nullptr;
}

void UOmegaFileSubsystem::ImportFileAsOverrideAsset(const FString& path)
{
	
	FString extension = UBlueprintPathsLibrary::GetExtension(path);
	FString filename = UBlueprintPathsLibrary::GetBaseFilename(path);
	if(GetFileManagerSettings())
	{
		for(auto* TempScript : GetFileManagerSettings()->ImportScripts)
		{
			if(TempScript && TempScript->ValidExtensions.Contains(extension))
			{
				UGameInstance* in_GamInst=nullptr;
				if(GetWorld() && GetWorld()->GetGameInstance())
				{
					in_GamInst = GetWorld()->GetGameInstance();
				}
				UObject* new_obj = TempScript->ImportAsObject(path,filename,extension,in_GamInst);
				RegisterOverrideAsset(new_obj,filename,TempScript->ImportClass);
			}
		}
	}
}

void UOmegaFileSubsystem::ImportFileAsOverrideAsset_List(const FString& path)
{
	TArray<FString> file_list; //= UFileSDKBPLibrary::GetFilesFromDirectory(path,"",true);
	for (auto temp_file : file_list)
	{
		ImportFileAsOverrideAsset(temp_file);
	}
}

FString UOmegaFileSubsystem::GetOverrideDirectory() const
{
	const FString dir = UKismetSystemLibrary::GetProjectDirectory();
	//+over_path="/"
	return dir+"override/";
}

UObject* UOmegaFileSubsystem::GetOverrideObject(FString name, UClass* Class) const
{
	if(imported_overrides.Contains(Class))
	{
		FOmegaFileObjectList filedat=imported_overrides[Class];
		if(filedat.file_objects.Contains(name))
		{
			return  filedat.file_objects[name];
		}
	}
	return nullptr;
}

void UOmegaFileSubsystem::RegisterOverrideAsset(UObject* Asset, FString Name, UClass* Class)
{
	if(Asset && !Name.IsEmpty())
	{
		GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->Register_SortedAsset(Asset,Name,true);
		
		UClass* in_class=Asset->GetClass();
		if(!Class)
		{
			in_class=Class;
		}
		if(Asset->GetClass()->IsChildOf(in_class))
		{
			FOmegaFileObjectList input_list;
			if(imported_overrides.Contains(in_class))
			{
				input_list=imported_overrides[in_class];
			}
			//add loaded object to import path.
			input_list.file_objects.Add(Name,Asset);
			imported_overrides.Add(Class,input_list);
		}
	}
}


// ================================================================================================
// FILE IMPORT TYPES
// ================================================================================================
UTexture2D* UOmegaFileFunctions::OmegaImport_Texture2D(const FString& FilePath,TEnumAsByte<TextureMipGenSettings> MipGenSettings)
{
	UTexture2D* Texture = FImageUtils::ImportFileAsTexture2D(FilePath);;
	if(Texture)
	{
		//Texture->MipGenSettings=MipGenSettings;
		Texture->RefreshSamplerStates();
		Texture->UpdateResource();
		return Texture;
	}
	return nullptr;
}

struct FWaveHeader
{
	// WAV file header structure
	uint8   RIFF[4];        // RIFF Header
	uint32  ChunkSize;      // RIFF Chunk Size
	uint8   WAVE[4];        // WAVE Header
	uint8   fmt[4];         // FMT header
	uint32  Subchunk1Size;  // Size of the fmt chunk
	uint16  AudioFormat;    // Audio format
	uint16  NumOfChan;      // Number of channels
	uint32  SamplesPerSec;  // Sampling Frequency in Hz
	uint32  bytesPerSec;    // bytes per second
	uint16  blockAlign;     // 2=16-bit mono, 4=16-bit stereo
	uint16  bitsPerSample;  // Number of bits per sample
	uint8   Subchunk2ID[4]; // "data"  string
	uint32  Subchunk2Size;  // Sampled data length
};

USoundWave* UOmegaFileFunctions::OmegaImport_Sound(const FString& FilePath, FString& Error)
{
	// Check if the file exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		Error="File does not exist: "+FilePath;
		UE_LOG(LogTemp, Error, TEXT("File does not exist: %s"), *FilePath);
		return nullptr;
	}

	// Load the file to a byte array
	TArray<uint8> RawFileData;
	if (!FFileHelper::LoadFileToArray(RawFileData, *FilePath))
	{
		Error="Failed to load file: "+FilePath;
		UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *FilePath);
		return nullptr;
	}

	// Parse the WAV header
	if (RawFileData.Num() < sizeof(FWaveHeader))
	{
		Error="File is too small to be a valid WAV file: "+FilePath;
		UE_LOG(LogTemp, Error, TEXT("File is too small to be a valid WAV file: %s"), *FilePath);
		return nullptr;
	}

	FWaveHeader* WaveHeader = reinterpret_cast<FWaveHeader*>(RawFileData.GetData());
	if (FMemory::Memcmp(WaveHeader->RIFF, "RIFF", 4) != 0 || FMemory::Memcmp(WaveHeader->WAVE, "WAVE", 4) != 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid WAV file: %s"), *FilePath);
		return nullptr;
	}

	// Create a new USoundWaveProcedural object
	USoundWaveProcedural* SoundWave = NewObject<USoundWaveProcedural>(USoundWaveProcedural::StaticClass());
	if (!SoundWave)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create USoundWaveProcedural object"));
		return nullptr;
	}

	// Set properties from WAV header
	SoundWave->SetSampleRate(WaveHeader->SamplesPerSec);
	SoundWave->NumChannels = WaveHeader->NumOfChan;
	SoundWave->Duration = static_cast<float>(WaveHeader->Subchunk2Size) / (WaveHeader->SamplesPerSec * WaveHeader->NumOfChan * (WaveHeader->bitsPerSample / 8));

	// Set the raw PCM data (skip the header)
	const uint8* PCMData = RawFileData.GetData() + sizeof(FWaveHeader);
	int32 PCMDataSize = RawFileData.Num() - sizeof(FWaveHeader);
	SoundWave->QueueAudio(PCMData, PCMDataSize);

	return SoundWave;
}


