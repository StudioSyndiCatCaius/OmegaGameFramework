// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_MoveComponentBetweenTargets.h"


void UAsyncAction_MoveComponentBetweenTargets::Activate()
{
	if (!Local_Source || !Local_StartComp || !Local_EndComp || Local_Duration <= 0.0f)
	{
		Failed.Broadcast();
		SetReadyToDestroy();
		return;
	}

	// Capture start/end transforms once so moving targets don't affect the lerp
	FTransform StartTransform = Local_bWorldTransform
		? Local_StartComp->GetComponentTransform()
		: FTransform(Local_StartComp->GetRelativeRotation(), Local_StartComp->GetRelativeLocation(), Local_StartComp->GetRelativeScale3D());

	FTransform EndTransform = Local_bWorldTransform
		? Local_EndComp->GetComponentTransform()
		: FTransform(Local_EndComp->GetRelativeRotation(), Local_EndComp->GetRelativeLocation(), Local_EndComp->GetRelativeScale3D());

	if (Local_bReverse)
	{
		Swap(StartTransform, EndTransform);
	}

	Local_StartLocation = StartTransform.GetLocation();
	Local_EndLocation   = EndTransform.GetLocation();
	Local_StartRotation = StartTransform.GetRotation();
	Local_EndRotation   = EndTransform.GetRotation();
	Local_StartScale    = StartTransform.GetScale3D();
	Local_EndScale      = EndTransform.GetScale3D();

	Local_ElapsedTime = 0.0f;
	Local_bPlaying = true;
}

void UAsyncAction_MoveComponentBetweenTargets::Tick(float DeltaTime)
{
	if (!Local_bPlaying) return;

	if (!Local_Source)
	{
		Failed.Broadcast();
		SetReadyToDestroy();
		return;
	}

	Local_ElapsedTime += DeltaTime;
	const float Alpha = FMath::Clamp(Local_ElapsedTime / Local_Duration, 0.0f, 1.0f);

	if (Local_bWorldTransform)
	{
		if (Local_bEditTranslation)
		{
			Local_Source->SetWorldLocation(FMath::Lerp(Local_StartLocation, Local_EndLocation, Alpha));
		}
		if (Local_bEditRotation)
		{
			Local_Source->SetWorldRotation(FQuat::Slerp(Local_StartRotation, Local_EndRotation, Alpha));
		}
		if (Local_bEditScale)
		{
			Local_Source->SetWorldScale3D(FMath::Lerp(Local_StartScale, Local_EndScale, Alpha));
		}
	}
	else
	{
		if (Local_bEditTranslation)
		{
			Local_Source->SetRelativeLocation(FMath::Lerp(Local_StartLocation, Local_EndLocation, Alpha));
		}
		if (Local_bEditRotation)
		{
			Local_Source->SetRelativeRotation(FQuat::Slerp(Local_StartRotation, Local_EndRotation, Alpha));
		}
		if (Local_bEditScale)
		{
			Local_Source->SetRelativeScale3D(FMath::Lerp(Local_StartScale, Local_EndScale, Alpha));
		}
	}

	Updated.Broadcast(Alpha);

	if (Alpha >= 1.0f)
	{
		Local_bPlaying = false;
		Finished.Broadcast();
		SetReadyToDestroy();
	}
}

UAsyncAction_MoveComponentBetweenTargets* UAsyncAction_MoveComponentBetweenTargets::MoveComponentBetweenTargets(
	UObject* WorldContextObject,
	USceneComponent* Source,
	USceneComponent* Start,
	USceneComponent* End,
	float Time,
	bool bReverse,
	bool bWorldTransform,
	bool bEditTranslation,
	bool bEditRotation,
	bool bEditScale)
{
	UAsyncAction_MoveComponentBetweenTargets* NewNode = NewObject<UAsyncAction_MoveComponentBetweenTargets>();
	NewNode->Local_Source         = Source;
	NewNode->Local_StartComp      = Start;
	NewNode->Local_EndComp        = End;
	NewNode->Local_Duration       = Time;
	NewNode->Local_bReverse       = bReverse;
	NewNode->Local_bWorldTransform   = bWorldTransform;
	NewNode->Local_bEditTranslation  = bEditTranslation;
	NewNode->Local_bEditRotation     = bEditRotation;
	NewNode->Local_bEditScale        = bEditScale;
	return NewNode;
}
