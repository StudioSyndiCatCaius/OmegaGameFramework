// Fill out your copyright notice in the Description page of Project Settings.


#include "LuaSubsystem.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "LuaSettings.h"
#include "HAL/FileManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Algo/Sort.h"

void ULuaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	settings_ref = GetMutableDefault<ULuaSettings>();
	if(settings_ref->bAutorunFiles)
	{
		RunLocalFile(settings_ref->Autorun_InitFile);
	}

	for(TSoftObjectPtr<ULuaCode> temp_asset: settings_ref->AutorunCodeAssets)
	{
		ULuaBlueprintFunctionLibrary::LuaRunCodeAsset(GetWorld(),ULuaBlueprintFunctionLibrary::GetDefaultLuaState(),temp_asset.LoadSynchronous());
	}
	Super::Initialize(Collection);
}

FString ULuaSubsystem::GetLocalFilesPath()
{
	return UKismetSystemLibrary::GetProjectContentDirectory()+settings_ref->Autorun_ContentPath+"/";
}

FLuaValue ULuaSubsystem::RunLocalFile(const FString& file)
{
	
	const FString target_path = GetLocalFilesPath()+file+".lua";
	UE_LOG(LogTemp, Log, TEXT("Tried to autorun Luafile: %s"), *target_path);
	return ULuaBlueprintFunctionLibrary::LuaRunNonContentFile(GetWorld(),ULuaBlueprintFunctionLibrary::GetDefaultLuaState(),target_path,true);
}

void ULuaSubsystem::RunLocalFilesInPath(const FString& path, bool bRecursive)
{
	TArray<FString> FileNames;
	IFileManager & FileManager = IFileManager::Get();
	const FString target_path = GetLocalFilesPath()+path+"/";
	UE_LOG(LogTemp, Log, TEXT("Getting lua files from path: %s"), *target_path);
	if(bRecursive)
	{
		FileManager.FindFilesRecursive(FileNames,*target_path,TEXT("*"),true,false);
		//*TEXT("*")+TEXT(".lua")
	}
	else
	{
		FileManager.FindFiles(FileNames,*target_path,TEXT(".lua"));
	}
	Algo::Sort(FileNames);
	
	for(FString i : FileNames)
	{
		UE_LOG(LogTemp, Log, TEXT("Tried to autorun Luafile from path: %s"), *i);
		ULuaBlueprintFunctionLibrary::LuaRunNonContentFile(GetWorld(),ULuaBlueprintFunctionLibrary::GetDefaultLuaState(),i,true);
	}
}
