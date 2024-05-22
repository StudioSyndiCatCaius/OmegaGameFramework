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
		RunLocalFile(settings_ref->Autorun_InitFile,false);
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

FLuaValue ULuaSubsystem::RunLocalFile(const FString& file, bool bNonLocal)
{
	
	FString target_path = GetLocalFilesPath()+file+".lua";
	if(bNonLocal)
	{
		target_path=file;
	}
	UE_LOG(LogTemp, Log, TEXT("Tried to autorun Luafile: %s"), *target_path);
	return ULuaBlueprintFunctionLibrary::LuaRunNonContentFile(GetWorld(),ULuaBlueprintFunctionLibrary::GetDefaultLuaState(),target_path,true);
}

void ULuaSubsystem::RunLocalFilesInPath(const FString& path, bool bRecursive,bool bNonLocal)
{
	TArray<FString> FileNames;
	IFileManager & FileManager = IFileManager::Get();
	FString target_path = GetLocalFilesPath()+path+"/";

	if(bNonLocal)
	{
		target_path=path;	
	}
	
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

ULuaObject* ULuaGlobalObjectFunctions::GetGlobalLuaObject_FromTag(UObject* WorldContextObject, FGameplayTag name,
	TSubclassOf<ULuaState> State)
{
	return  GetGlobalLuaObject_FromString(WorldContextObject,name.ToString(),State);
}

ULuaObject* ULuaGlobalObjectFunctions::GetGlobalLuaObject_FromString(UObject* WorldContextObject, const FString& name,
	TSubclassOf<ULuaState> State)
{
	ULuaSubsystem* subsys_ref = WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<ULuaSubsystem>();
	if(subsys_ref->globalLuaObjects.Contains(name) && subsys_ref->globalLuaObjects[name])
	{
		return subsys_ref->globalLuaObjects[name];
	}
	FLuaValue lua_key = ULuaBlueprintFunctionLibrary::Conv_StringToLuaValue(name);
	FLuaValue val = ULuaBlueprintFunctionLibrary::LuaGetGlobal(WorldContextObject,State,name);
	ULuaObject* newobjectlua = ULuaObjectFunctions::CreateLuaObject(WorldContextObject,lua_key,val);
	FString new_name = "LuaGen_" + name;
	newobjectlua->Rename(*new_name);
	subsys_ref->globalLuaObjects.Add(name,newobjectlua);
	return newobjectlua;
}


