// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameManager.h"
#include "Gameplay/OmegaGameplayModule.h"
#include "JsonBlueprintFunctionLibrary.h"
#include "Engine/GameInstance.h"

void UOmegaGameManager::Initialize(FSubsystemCollectionBase& Colection)
{
	/*
	const FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	FARFilter Filter;
	Filter.ClassNames.Add("Blueprint");
	Filter.ClassNames.Add("OmegaGameplayModule");
	
	for(const FDirectoryPath NewPath : GetMutableDefault<UOmegaSettings>()->AutoModuleScanPaths)
	{
		FString LocalString = NewPath.Path;
		Filter.PackagePaths.Add(FName(*LocalString));
	}
	
	TSet<FName> LocalExcludedClasses;
	LocalExcludedClasses.Add("Actor");
	LocalExcludedClasses.Add("Widget");
	Filter.RecursiveClassesExclusionSet = LocalExcludedClasses;
	
	Filter.bRecursiveClasses = true;
	Filter.bRecursivePaths = true;
	Filter.bIncludeOnlyOnDiskAssets = true;
	
	AssetRegistryModule.Get().GetAssetsByClass(UOmegaGameplayModule::StaticClass()->GetFName(),AssetData, true);
	//AssetRegistryModule.Get().GetAssets(Filter, AssetData);

	for(FAssetData TempAssetData : AssetData)
	{
		if(TempAssetData.GetClass())
		{
			UE_LOG(LogTemp, Display, TEXT("%hs_%p"),"ModuleClassLoaded: ", TempAssetData.GetAsset());
			TSubclassOf<UOmegaGameplayModule> TempModClass = TempAssetData.GetClass();
			if(TempModClass && Cast<UOmegaGameplayModule>(TempModClass->GetDefaultObject())->AutoRegisterModule)
			{
			ActivateModuleFromClass(TempModClass);
			}
			
		}
	}

	*/
	
	for(TSubclassOf<UOmegaGameplayModule> TempModule : GetMutableDefault<UOmegaSettings>()->GetGameplayModuleClasses())
	{
		if(TempModule)
		{
			//UObject* TempOuter = GetGameInstance();
			ActivateModuleFromClass(TempModule);
		}
	}

	//Setup timer
	// GetGameInstance()->GetTimerManager().SetTimer(PlaytimeUpdateHandle, this, &UOmegaGameManager::UpdatePlaytime, 1.0, true);
}

void UOmegaGameManager::Deinitialize()
{
	for(UOmegaGameplayModule* TempModule : ActiveModules)
	{
		TempModule->Shutdown();
	}
	Super::Deinitialize();
}

//############################################################################
// Gameplay Modules
//############################################################################

UOmegaGameplayModule* UOmegaGameManager::ActivateModuleFromClass(const UClass* ModuleClass)
{
	for (auto* TempMod : ActiveModules)
	{
		if(TempMod->GetClass()==ModuleClass)
		{
			return TempMod;
		}
	}
	
	UOmegaGameplayModule* NewModule = NewObject<UOmegaGameplayModule>(GetGameInstance(), ModuleClass);
	ActiveModules.Add(NewModule);
	NewModule->Native_Initialize();
	
	UE_LOG(LogTemp, Display, TEXT("%hs_%p"),"Gameplay Module Activated: ", NewModule->GetClass());
	return NewModule;
}



UOmegaGameplayModule* UOmegaGameManager::GetGameplayModule(TSubclassOf<UOmegaGameplayModule> Module)
{
	
	
	for(UOmegaGameplayModule* TempModule : ActiveModules)
	{
		if(TempModule->GetClass() == Module)
		{
			return TempModule;
		}
	}
	return nullptr;
}

TArray<UOmegaGameplayModule*> UOmegaGameManager::GetGameplayModules()
{
	return ActiveModules;
}

void UOmegaGameManager::FireGlobalEvent(FName Event, UObject* Context)
{
	OnGlobalEvent.Broadcast(Event, Context);
}

void UOmegaGameManager::SetFlagActive(FString Flag, bool bActive)
{
	if(IsFlagActive(Flag) != bActive)
	{
		if(bActive)
		{
			Flags.AddUnique(Flag);
		}
		else
		{
			Flags.Remove(Flag);
		}
		OnFlagStateChange.Broadcast(Flag, bActive);
	}
}

bool UOmegaGameManager::IsFlagActive(FString Flag)
{
	return Flags.Contains(Flag);
}

void UOmegaGameManager::ClearAllFlags()
{
	TArray<FString> LocalFlags = Flags;
	for(FString TempFlag : LocalFlags)
	{
		SetFlagActive(TempFlag, false);	
	}
	Flags.Empty();
}



void UOmegaGameManager::AddGameplayLog(const FString& String, const FString& LogCategory)
{
	FGameplayLogEntry TempEntry;
	TempEntry.Log = String;
	TempEntry.LogCategory = LogCategory;
	LocalLog.Add(TempEntry);
}

void UOmegaGameManager::ClearLog()
{
	LocalLog.Empty();
}

TArray<FString> UOmegaGameManager::GetGameplayLog()
{
	TArray<FString> LocalStrings;
	for(FGameplayLogEntry TempEntry : LocalLog)
	{
		LocalStrings.Add(TempEntry.Log);
	}
	LocalStrings.SetNum(MaxLogEntry);
	return LocalStrings;
}

TArray<FString> UOmegaGameManager::GetGameplayLogOfCategory(const FString& LogCategory)
{TArray<FString> LocalStrings;
	for(FGameplayLogEntry TempEntry : LocalLog)
	{
		if(TempEntry.LogCategory == LogCategory)
		{
			LocalStrings.Add(TempEntry.Log);
		}
	}
	LocalStrings.SetNum(MaxLogEntry);
	return LocalStrings;
	
}

