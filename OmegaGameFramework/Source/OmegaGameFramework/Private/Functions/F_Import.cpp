#include "Functions/F_Import.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManager.h"

USoundWave* UOmegaFunctions_Import::MP3(const FString& FilePath)
{
	// Validate file exists
	if (!IFileManager::Get().FileExists(*FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("F_Import::MP3 - File not found: %s"), *FilePath);
		return nullptr;
	}

	// Read raw bytes from disk
	TArray<uint8> RawFileData;
	if (!FFileHelper::LoadFileToArray(RawFileData, *FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("F_Import::MP3 - Failed to read file: %s"), *FilePath);
		return nullptr;
	}

	// Create a transient SoundWave
	USoundWave* SoundWave = NewObject<USoundWave>(GetTransientPackage(), NAME_None, RF_Transient);
	if (!SoundWave)
	{
		return nullptr;
	}

	// Feed the raw compressed audio data
	SoundWave->RawData.UpdatePayload(FSharedBuffer::Clone(RawFileData.GetData(), RawFileData.Num()));

	// MP3 is a compressed format - tell the engine not to decompress upfront
	SoundWave->DecompressionType = DTYPE_Streaming;
	SoundWave->SoundGroup = ESoundGroup::SOUNDGROUP_Default;
	SoundWave->bLooping = false;

	// Duration/channels are unknown until decoded; set sane defaults
	// These will be populated once the audio system processes the buffer
	SoundWave->NumChannels = 2;
	SoundWave->SetSampleRate(44100);

	return SoundWave;
}