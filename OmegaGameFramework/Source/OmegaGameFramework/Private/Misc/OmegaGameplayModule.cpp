// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaGameplayModule.h"

#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "UObject/Object.h"
#include "UObject/UObjectGlobals.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/GeneralDataObject.h"
#include "Subsystems/OmegaSubsystem_QueuedQuery.h"

UOmegaGameplayModule::UOmegaGameplayModule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); }
}
UWorld* UOmegaGameplayModule::GetWorld() const
{
	if(GetGameInstance()) { return GetGameInstance()->GetWorld(); } return nullptr;
}

void UOmegaGameplayModule::Native_Initialize()
{
	if((REF_OwningManager = GetGameInstance()->GetSubsystem<UOmegaGameManager>()) != nullptr)
	{
		REF_OwningManager->OnGlobalEvent.AddDynamic(this, &UOmegaGameplayModule::OnGlobalEvent);
		REF_OwningManager->OnTaggedGlobalEvent.AddDynamic(this, &UOmegaGameplayModule::OnTaggedGlobalEvent);
		REF_OwningManager->OnNewLevel.AddDynamic(this, &UOmegaGameplayModule::Native_OnLevelOpened);
	}
	if(UOmegaSaveSubsystem* _sys = GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>())
	{
		_sys->OnNewGameStarted.AddDynamic(this, &UOmegaGameplayModule::GameFileStarted);
		GameFileStarted(_sys->ActiveSaveData,FGameplayTagContainer());
	}
	
	Initialized();
}


void UOmegaGameplayModule::Native_OnLevelOpened(FString LevelName, AOmegaGameMode* GameMode)
{
	//Activate Game Systems
	for (TSubclassOf<AOmegaGameplaySystem> TempSystem : AutoGameplaySystems)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(TempSystem, this, "None");
	}
	if(UOmegaSubsystem_QueuedQuery* REF_QuerySubsystem = GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueuedQuery>()) 
	{
		REF_QuerySubsystem->SetQueuedQuerySourceRegistered(this,true); 
	} 
	OnLevelOpened(LevelName, GameMode);
}



UGameInstance* UOmegaGameplayModule::GetGameInstance() const
{
	return Cast<UGameInstance>(GetOuter());
}

bool UOmegaGameplayModule::GameFileSaved_Implementation(UOmegaSaveGame* SaveFile)
{
	return true;
}




