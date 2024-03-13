// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_File.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void UOmegaFileSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("get override image path: %s"), *GetOverrideDirectory_Images());
	TArray<FString> file_list = GetFilesOfExtension(GetOverrideDirectory_Images(),TEXT(".png"));
	for(FString file: file_list)
	{
		FString loc_filename = FPaths::GetBaseFilename(file, true);
		if(UTexture2D* new_image = UKismetRenderingLibrary::ImportFileAsTexture2D(GetWorld(), file))
		{
			imported_images.Add(loc_filename,new_image);
		}
	}
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

FString UOmegaFileSubsystem::GetOverrideDirectory() const
{
	const FString dir = UKismetSystemLibrary::GetProjectDirectory();
	//+over_path="/"
	return dir+"override/";
}

FString UOmegaFileSubsystem::GetOverrideDirectory_Images() const
{
	return GetOverrideDirectory()+override_images_path+"/";
}

FString UOmegaFileSubsystem::GetOverrideDirectory_Audio() const
{
	return GetOverrideDirectory()+override_audio_path+"/";
}

UTexture2D* UOmegaFileFunctions::GetOverride_Texture(UObject* WorldContextObject, const FString& name)
{
	if(!WorldContextObject->GetWorld()->GetGameInstance())
	{
		return nullptr;
	}
	if(UTexture2D* out = WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaFileSubsystem>()->imported_images.FindOrAdd(name))
	{
		return out;
	}
	return nullptr;
}


