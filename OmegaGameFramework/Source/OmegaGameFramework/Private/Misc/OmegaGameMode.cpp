// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaGameMode.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Actors/Actor_Player.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"

void AOmegaGameMode::Local_LoadSystemShutdown(UObject* Context, FString Flag)
{
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	
	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : PostLoadGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "GameMode_PostLoad");
	}
	OnLoadEventFinish.Broadcast();
	OnLoadEventFinished();
}

void AOmegaGameMode::Local_ActivatePersistentSystems()
{
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : PersistentGameplaySystems)
	{
		SystemRef->ActivateGameplaySystem(TempSystem, this, "PersistentSystem");
	}
}

void AOmegaGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Fire OnLevelOpened Delegate
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnNewLevel.Broadcast(UGameplayStatics::GetCurrentLevelName(this), this);
	UOmegaGameplaySubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();

	//Activate Game Systems
	for (const TSubclassOf<AOmegaGameplaySystem>& TempSystem : AutoGameplaySystems)
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

	// Bind a function to be called by the timer.
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("Local_ActivatePersistentSystems"));

	// Set the timer. Replace GetWorld()->GetTimerManager() with your context.
	GetWorld()->GetTimerManager().SetTimer(PersistentSystemsTimerHandle, TimerDel, PersistentSystemActivationFrequency, true);

	
}

FString AOmegaGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId,
	const FString& Options, const FString& Portal)
{
	if(AOmegaPlayer* p=Cast<AOmegaPlayer>(NewPlayerController))
	{
		p->Systems_Auto.Append(PlayerSystems_Auto);
		p->SetSystemsActive(PlayerSystems_Auto,this,"Auto",true);
		p->Systems_Persistent.Append(PlayerSystems_Auto);
	}
	return Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
}

