// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_Hitstop.h"
#include "Kismet/GameplayStatics.h"


void UAsyncAction_Hitstop::Activate()
{
	if (!Local_WorldContext || !Local_WorldContext->GetWorld())
	{
		SetReadyToDestroy();
		return;
	}

	UGameplayStatics::SetGlobalTimeDilation(Local_WorldContext, Local_Dilation);
	Local_ElapsedTime = 0.0f;
	Local_bPlaying = true;
}

void UAsyncAction_Hitstop::Tick(float DeltaTime)
{
	if (!Local_bPlaying) return;

	// DeltaTime arrives already scaled by dilation; divide it back out to accumulate real-world seconds
	Local_ElapsedTime += DeltaTime / FMath::Max(Local_Dilation, SMALL_NUMBER);

	if (Local_ElapsedTime >= Local_Time)
	{
		Local_bPlaying = false;
		if (Local_WorldContext && Local_WorldContext->GetWorld())
		{
			UGameplayStatics::SetGlobalTimeDilation(Local_WorldContext, Local_DilationOnEnd);
		}
		Finished.Broadcast();
		SetReadyToDestroy();
	}
}

UAsyncAction_Hitstop* UAsyncAction_Hitstop::Hitstop(
	UObject* WorldContextObject,
	float Time,
	float Dilation,
	float DilationOnEnd)
{
	UAsyncAction_Hitstop* NewNode = NewObject<UAsyncAction_Hitstop>();
	NewNode->Local_WorldContext  = WorldContextObject;
	NewNode->Local_Time          = Time;
	NewNode->Local_Dilation      = Dilation;
	NewNode->Local_DilationOnEnd = DilationOnEnd;
	return NewNode;
}
