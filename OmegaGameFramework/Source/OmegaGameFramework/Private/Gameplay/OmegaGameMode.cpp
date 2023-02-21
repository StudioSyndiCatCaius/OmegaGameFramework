// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Gameplay/OmegaGameMode.h"

#include "OmegaGameManager.h"
#include "OmegaGameplaySubsystem.h"
#include "OmegaGameplaySystem.h"

void AOmegaGameMode::Local_LoadSystemShutdown(UObject* Context, FString Flag)
{
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	
	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem> TempSystem : PostLoadGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "GameMode_PostLoad");
	}
	
	OnLoadEventFinished();
}

void AOmegaGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Fire OnLevelOpened Delegate
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnNewLevel.Broadcast(UGameplayStatics::GetCurrentLevelName(this), this);
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();

	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem> TempSystem : AutoGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "GameMode_PreLoad");
	}

	if(LoadGameplaySystem)
	{
		AOmegaGameplaySystem* TempLoadSys = SystemRef->ActivateGameplaySystem(LoadGameplaySystem, this, "GameMode_Load");
		TempLoadSys->OnSystemShutdown.AddDynamic(this, &AOmegaGameMode::Local_LoadSystemShutdown);
	}
	else
	{
		Local_LoadSystemShutdown(this, "NONE");
	}
	
}
