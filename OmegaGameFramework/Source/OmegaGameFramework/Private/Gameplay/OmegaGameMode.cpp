// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Gameplay/OmegaGameMode.h"

#include "OmegaGameManager.h"
#include "OmegaGameplaySubsystem.h"
#include "OmegaGameplaySystem.h"

void AOmegaGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Fire OnLevelOpened Delegate
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnNewLevel.Broadcast(UGameplayStatics::GetCurrentLevelName(this), this);
	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem> TempSystem : AutoGameplaySystems)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(TempSystem, this, "None");
	}
}
