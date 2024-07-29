// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_File.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "FileSDKBPLibrary.h"
#include "OmegaSettings.h"
#include "Kismet/BlueprintPathsLibrary.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

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
				UObject* new_obj = TempScript->ImportAsObject(path,filename,extension);
				if(new_obj)
				{
					FOmegaFileObjectList input_list;
					if(imported_overrides.Contains(TempScript->ImportClass))
					{
						input_list=imported_overrides[TempScript->ImportClass];
					}
					//add loaded object to import path.
					input_list.file_objects.Add(filename,new_obj);
					imported_overrides.Add(TempScript->ImportClass,input_list);
				}
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



