// Fill out your copyright notice in the Description page of Project Settings.


#include "LuaSubsystem.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "LuaSettings.h"
#include "HAL/FileManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Algo/Sort.h"

void ULuaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{

	Super::Initialize(Collection);
}

FString ULuaSubsystem::GetLocalFilesPath()
{
	FString A=UKismetSystemLibrary::GetProjectContentDirectory();
	FString B=A+GetMutableDefault<ULuaSettings>()->Autorun_ContentPath;
	FString C=B+"/";
	return C;
}

FLuaValue ULuaSubsystem::RunLocalFile(const FString& file, bool bNonLocal)
{
	
	FString target_path = GetLocalFilesPath()+file+".lua";
	if(bNonLocal)
	{
		target_path=file;
	}
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



void GetAllLuaFiles(const FString& Directory, TArray<FString>& OutFiles)
{
	IFileManager& FileManager = IFileManager::Get();
    
	// Search pattern for .lua files
	FString SearchPattern = Directory / TEXT("*.lua");
    
	// Find all .lua files in the current directory
	TArray<FString> FoundFiles;
	FileManager.FindFiles(FoundFiles, *SearchPattern, true, false);
    
	// Add full paths to output array
	for (const FString& File : FoundFiles)
	{
		OutFiles.Add(Directory / File);
	}
    
	// Find all subdirectories
	TArray<FString> SubDirectories;
	FileManager.FindFiles(SubDirectories, *(Directory / TEXT("*")), false, true);
    
	// Recursively search subdirectories
	for (const FString& SubDir : SubDirectories)
	{
		GetAllLuaFiles(Directory / SubDir, OutFiles);
	}
}


// =====================================================================================================================
// ENGINE SUBSYSTEM
// =====================================================================================================================

void ULuaEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

// =====================================================================================================================
// WORLD SUBSYSTEM
// =====================================================================================================================

void ULuaWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RerunLua();
}

TArray<FName> ULuaWorldSubsystem::GetGlobalKeys(FString global)
{
	TArray<FName> out;
	FLuaValue _v=ULuaBlueprintFunctionLibrary::LuaGetGlobal(this,nullptr,global);
	TArray<FLuaValue> _list=ULuaBlueprintFunctionLibrary::LuaTableGetKeys(_v);
	for(FLuaValue val : _list)
	{
		if(val.Type==ELuaValueType::String)
		{
			out.Add(*val.ToString());
		}
	}
	// Sort alphabetically (case-insensitive)
	out.Sort([](const FName& A, const FName& B)
	{
		return A.ToString() < B.ToString();
	});
	return out;
}

void ULuaWorldSubsystem::RerunLua()
{
	FString _path=FPaths::ProjectDir()+"/Override/autorun/";
	TArray<FString> _outFiles;
	GetAllLuaFiles(_path,_outFiles);
	for(FString i : _outFiles)
	{
		ULuaBlueprintFunctionLibrary::LuaRunFile(this,nullptr,i,true);
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


