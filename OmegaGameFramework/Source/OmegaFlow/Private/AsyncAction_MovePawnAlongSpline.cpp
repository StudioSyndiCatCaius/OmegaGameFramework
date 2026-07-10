// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_MovePawnAlongSpline.h"
#include "GameFramework/PawnMovementComponent.h"


void UAsyncAction_MovePawnAlongSpline::Activate()
{
	if (!Local_Pawn || !Local_Spline || Local_Duration <= 0.0f)
	{
		Failed.Broadcast();
		SetReadyToDestroy();
		return;
	}

	Local_StartKey = Local_Spline->FindInputKeyClosestToWorldLocation(Local_Pawn->GetActorLocation());
	Local_ElapsedTime = 0.0f;
	Local_bPlaying = true;
}

void UAsyncAction_MovePawnAlongSpline::Tick(float DeltaTime)
{
	if (!Local_bPlaying) return;

	if (!Local_Pawn || !Local_Spline)
	{
		Failed.Broadcast();
		SetReadyToDestroy();
		return;
	}

	Local_ElapsedTime += DeltaTime;
	const float Alpha = FMath::Clamp(Local_ElapsedTime / Local_Duration, 0.0f, 1.0f);
	const float CurrentKey = FMath::Lerp(Local_StartKey, Local_TargetKey, Alpha);
	const FVector TargetLocation = Local_Spline->GetLocationAtSplineInputKey(CurrentKey, ESplineCoordinateSpace::World);

	switch (Local_MoveMethod)
	{
	case EPawnSplineMoveMethod::DirectVelocity:
		if (UPawnMovementComponent* MoveComp = Local_Pawn->GetMovementComponent())
		{
			const FVector Delta = TargetLocation - Local_Pawn->GetActorLocation();
			MoveComp->Velocity = DeltaTime > 0.0f ? Delta / DeltaTime : FVector::ZeroVector;
		}
		break;

	case EPawnSplineMoveMethod::AddMovementInput:
		{
			const FVector Direction = (TargetLocation - Local_Pawn->GetActorLocation()).GetSafeNormal();
			Local_Pawn->AddMovementInput(Direction, 1.0f);
		}
		break;

	case EPawnSplineMoveMethod::SetActorLocation:
		Local_Pawn->SetActorLocation(TargetLocation);
		break;
	}

	Updated.Broadcast(Alpha);

	if (Alpha >= 1.0f)
	{
		Local_bPlaying = false;
		Finished.Broadcast();
		SetReadyToDestroy();
	}
}

UAsyncAction_MovePawnAlongSpline* UAsyncAction_MovePawnAlongSpline::MovePawnAlongSpline(
	UObject* WorldContextObject,
	APawn* Pawn,
	USplineComponent* Spline,
	float Duration,
	EPawnSplineMoveMethod MoveMethod,
	float SplineInputKey)
{
	UAsyncAction_MovePawnAlongSpline* NewNode = NewObject<UAsyncAction_MovePawnAlongSpline>();
	NewNode->Local_Pawn = Pawn;
	NewNode->Local_Spline = Spline;
	NewNode->Local_Duration = Duration;
	NewNode->Local_MoveMethod = MoveMethod;
	NewNode->Local_TargetKey = SplineInputKey;
	return NewNode;
}
