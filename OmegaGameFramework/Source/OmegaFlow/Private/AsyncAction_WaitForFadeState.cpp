// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_WaitForFadeState.h"

#include "Subsystems/Subsystem_GameManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void UAsyncAction_WaitForFadeState::Tick(float DeltaTime)
{
	if(PlayerRef && PlayerRef->PlayerCameraManager->FadeAmount == TargetFadeState && !LocalIsFinishing)
	{
		LocalIsFinishing = true;
		Finished.Broadcast();
		SetReadyToDestroy();
	}
}

UAsyncAction_WaitForFadeState* UAsyncAction_WaitForFadeState::WaitForFadeState(UObject* WorldContextObject,
                                                                               APlayerController* Player, float FadeState)
{
	APlayerController* TempPlayer = nullptr;
	if(Player)
	{
		TempPlayer = Player;
	}
	else if(WorldContextObject)
	{
		TempPlayer = UGameplayStatics::GetPlayerController(WorldContextObject,0);
	}
	
	UAsyncAction_WaitForFadeState* NewMenuNode = NewObject<UAsyncAction_WaitForFadeState>();
	NewMenuNode->PlayerRef = TempPlayer;
	NewMenuNode->TargetFadeState = FadeState;
	return NewMenuNode;
}
