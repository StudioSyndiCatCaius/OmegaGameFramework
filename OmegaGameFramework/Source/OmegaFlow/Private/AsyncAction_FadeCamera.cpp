// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_FadeCamera.h"

#include "OmegaGameManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void UAsyncAction_FadeCamera::Tick(float DeltaTime)
{
	if(PlayerRef && PlayerRef->PlayerCameraManager->FadeAmount == TargetFadeState && !LocalIsFinishing)
	{
		LocalIsFinishing = true;
		Finished.Broadcast();
		SetReadyToDestroy();
	}
}

void UAsyncAction_FadeCamera::Activate()
{
	if(PlayerRef)
	{
		PlayerRef->PlayerCameraManager->StartCameraFade(PlayerRef->PlayerCameraManager->FadeAmount, TargetFadeState, TargetDuration, TargetFadeColor, Local_FadeAudio, Local_HoldOnFinish);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UAsyncAction_FadeCamera* UAsyncAction_FadeCamera::FadeCameraAsync(UObject* WorldContextObject,
	APlayerController* Player, float TargetAlpha, float Duration, FLinearColor FadeColor, bool FadeAudio,
	bool HoldWhenFinished)
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
	
	UAsyncAction_FadeCamera* NewNode = NewObject<UAsyncAction_FadeCamera>();
	NewNode->PlayerRef = TempPlayer;
	NewNode->TargetFadeState = TargetAlpha;
	NewNode->TargetFadeColor = FadeColor;
	NewNode->Local_HoldOnFinish = HoldWhenFinished;
	NewNode->Local_FadeAudio = FadeAudio;
	NewNode->TargetDuration = Duration;
	return NewNode;
}


