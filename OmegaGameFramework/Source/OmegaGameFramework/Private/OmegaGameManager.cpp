// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameManager.h"
#include "Gameplay/OmegaGameplayModule.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"

void UOmegaGameManager::Initialize(FSubsystemCollectionBase& Colection)
{
	for(TSubclassOf<UOmegaGameplayModule> TempModule : GetMutableDefault<UOmegaSettings>()->GetGameplayModuleClasses())
	{
		if(TempModule)
		{
			//UObject* TempOuter = GetGameInstance();
			UOmegaGameplayModule* NewModule = NewObject<UOmegaGameplayModule>(GetGameInstance(), TempModule);
			ActiveModules.Add(NewModule);
			NewModule->Native_Initialize();
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
	if(bActive)
	{
		Flags.AddUnique(Flag);
	}
	else
	{
		Flags.Remove(Flag);
	}
}

bool UOmegaGameManager::IsFlagActive(FString Flag)
{
	return Flags.Contains(Flag);
}

//----------------------
// Playtime
//----------------------

/*
void UOmegaGameManager::SetPlaytimeActive(bool bActive)
{
	bIsPlaytimeActive = bActive;
}

void UOmegaGameManager::ResetPlaytime()
{
	Playtime.Frames = 0;
	Playtime.Hours = 0;
	Playtime.Minutes = 0;
	Playtime.Seconds = 0;
}

void UOmegaGameManager::UpdatePlaytime()
{
	if(!bIsPlaytimeActive)
	{
		return;
	}
	
	Playtime.Seconds = Playtime.Seconds+1;

	if(Playtime.Seconds >= 60)
	{
		Playtime.Seconds = 0;
		Playtime.Minutes = Playtime.Minutes+1;
		
		if(Playtime.Minutes >= 60)
		{
			Playtime.Minutes = 0;
			Playtime.Hours = Playtime.Hours+1;
		}
	}
}
*/