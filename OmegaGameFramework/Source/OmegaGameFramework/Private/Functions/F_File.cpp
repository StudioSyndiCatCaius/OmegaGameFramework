// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_File.h"

#include "ImageUtils.h"
#include "OmegaSettings.h"
#include "Interfaces/IPluginManager.h"
#include "Kismet/BlueprintPathsLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Sound/SoundWaveProcedural.h"
#include "Statics/OMEGA_File.h"


UObject* UOmegaFileManagerSettings::ImportFile(const FString& path) const
{
	FString extension = UBlueprintPathsLibrary::GetExtension(path);
	FString filename = UBlueprintPathsLibrary::GetBaseFilename(path);
	for(auto* TempScript : ImportScripts)
	{
		if(TempScript && TempScript->ValidExtensions.Contains(extension))
		{
			UGameInstance* in_GamInst=nullptr;
			if(GetWorld() && GetWorld()->GetGameInstance())
			{
				in_GamInst = GetWorld()->GetGameInstance();
			}
			return  TempScript->ImportAsObject(path,filename,extension,in_GamInst);
		}
	}
	return nullptr;
}


FString UOmegaFileFunctions::GetPluginBaseDir(const FString& PluginName)
{
	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(PluginName);
	if (!Plugin.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Plugin '%s' not found!"), *PluginName);
		return FString();
	}

	return Plugin->GetBaseDir();
}

TArray<FString> UOmegaFileFunctions::GameData_GetDirectories(FString OverrideFolder)
{
	TArray<FString> Subfolders;
	TArray<FString> out;
    
	Subfolders.Add(FPaths::ProjectDir());
	Subfolders.Append(GetSubfolders(FPaths::ProjectModsDir()));
    
	for(FString _basePath : Subfolders)
	{
		FString _subFolder;
		if (OverrideFolder.IsEmpty())
		{
			_subFolder=OGF_CFG()->GameData_Base_Directory;
		}
		else
		{
			_subFolder=OverrideFolder;
		}
		out.Add(_basePath+_subFolder);
	}
    
	return out;
}

TArray<FString> UOmegaFileFunctions::GameData_GetFiles(const FString& subdirectory, const FString& extension, bool bRecursive)
{
	TArray<FString> out;
	for (FString base_dir : GameData_GetDirectories())
	{
		for (FString _file : OMEGA_File::ListFilesInDirectory(base_dir+subdirectory,bRecursive))
		{
			if (extension.IsEmpty() || FPaths::GetExtension(_file)==extension)
			{
				out.Add(_file);
			}
		}
	}
	return out;
}

TArray<FString> UOmegaFileFunctions::GetSubfolders(FString RootPath, bool OnlyNames)
{
	if (OnlyNames)
	{
		TArray<FString> Subfolders;
    
		// Ensure the path exists
		if (!FPaths::DirectoryExists(RootPath))
		{
			return Subfolders;
		}
    
		// Get all directories in the root path
		IFileManager& FileManager = IFileManager::Get();
		FileManager.FindFiles(Subfolders, *RootPath, false, true);
    
		return Subfolders;
	}
	TArray<FString> AllSubfolders;
    
	// Ensure the path exists
	if (!FPaths::DirectoryExists(RootPath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Directory does not exist: %s"), *RootPath);
		return AllSubfolders;
	}
    
	// Ensure path ends with /
	if (!RootPath.EndsWith(TEXT("/")))
	{
		RootPath += TEXT("/");
	}
    
	// Get immediate subdirectories
	TArray<FString> FolderNames;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(FolderNames, *(RootPath + TEXT("*")), false, true);
    
	
	// Process each folder
	for (const FString& FolderName : FolderNames)
	{
		FString FullPath = RootPath + FolderName;
		AllSubfolders.Add(FullPath);
        
		// Recursively get subfolders
		//TArray<FString> NestedFolders = GetSubfolders(FullPath);
		//AllSubfolders.Append(NestedFolders);
	}
    
	return AllSubfolders;
}

// ================================================================================================
// FILE IMPORT TYPES
// ================================================================================================
UTexture2D* UOmegaFileFunctions::OmegaImport_Texture2D(const FString& FilePath,TEnumAsByte<TextureMipGenSettings> MipGenSettings)
{
	UTexture2D* Texture = FImageUtils::ImportFileAsTexture2D(FilePath);
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