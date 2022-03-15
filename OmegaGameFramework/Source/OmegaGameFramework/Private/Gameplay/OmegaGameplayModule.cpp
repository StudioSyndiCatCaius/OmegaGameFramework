// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Gameplay/OmegaGameplayModule.h"

#include "OmegaGameplaySubsystem.h"
#include "OmegaGameManager.h"
#include "UObject/Object.h"
#include "UObject/UObjectGlobals.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"

UOmegaGameplayModule::UOmegaGameplayModule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UOmegaGameplayModule::GetWorld() const
{
	if(GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}
	return nullptr;
}

void UOmegaGameplayModule::Native_Initialize()
{
	//Bind OnGlobalEvent
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UOmegaGameplayModule::OnGlobalEvent);
	//Bind OnLevelOpened
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnNewLevel.AddDynamic(this, &UOmegaGameplayModule::Native_OnLevelOpened);
	Initialized();
}


void UOmegaGameplayModule::Native_OnLevelOpened(FString LevelName, AOmegaGameMode* GameMode)
{
	//Activate Game Systems
	for (TSubclassOf<AOmegaGameplaySystem> TempSystem : AutoGameplaySystems)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(TempSystem, this, "None");
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




