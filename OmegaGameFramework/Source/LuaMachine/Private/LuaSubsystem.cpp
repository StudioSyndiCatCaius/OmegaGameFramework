// Fill out your copyright notice in the Description page of Project Settings.


#include "LuaSubsystem.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "LuaSettings.h"
#include "HAL/FileManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Algo/Sort.h"
#include "Statics/OMEGA_File.h"

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
	
	if(bRecursive)
	{
		FileManager.FindFilesRecursive(FileNames,*target_path,TEXT("*"),true,false);

	}
	else
	{
		FileManager.FindFiles(FileNames,*target_path,TEXT(".lua"));
	}
	Algo::Sort(FileNames);
	
	for(FString i : FileNames)
	{
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
	for (FString pt : GetMutableDefault<ULuaSettings>()->Autorun_FilePaths)
	{
		FString final_path=OMEGA_File::PathCorrect(pt);
		TArray<FString> _foundFiles;
		GetAllLuaFiles(final_path,_foundFiles);
		
		for(FString i : _foundFiles)
		{
			ULuaBlueprintFunctionLibrary::LuaRunNonContentFile(this,nullptr,i,true);
		}
	}
}

