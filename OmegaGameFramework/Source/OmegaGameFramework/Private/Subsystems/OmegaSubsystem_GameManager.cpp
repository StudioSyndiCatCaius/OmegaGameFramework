// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Misc/OmegaGameplayModule.h"
#include "JsonBlueprintFunctionLibrary.h"
#include "Engine/GameInstance.h"
#include "Subsystems/OmegaSubsystem_AssetHandler.h"

void UOmegaGameManager::Initialize(FSubsystemCollectionBase& Colection)
{
#if !PLATFORM_ANDROID
	GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->ClearSortedAssets_All();
#endif
	for(TSubclassOf<UOmegaGameplayModule> TempModule : GetMutableDefault<UOmegaSettings>()->GetGameplayModuleClasses())
	{
		if(TempModule)
		{
			ActivateModuleFromClass(TempModule);
		}
	}
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
	if(ModuleClass)
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
	return nullptr;
}



UOmegaGameplayModule* UOmegaGameManager::GetGameplayModule(TSubclassOf<UOmegaGameplayModule> Module)
{
	for(UOmegaGameplayModule* TempModule : ActiveModules)
	{
		if(TempModule->GetClass()->IsChildOf(Module))
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

void UOmegaGameManager::FireTaggedGlobalEvent(FGameplayTag Event, UObject* Context)
{
	OnTaggedGlobalEvent.Broadcast(Event,Context);
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

