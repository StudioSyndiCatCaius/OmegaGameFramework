// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Tickable.h"
#include "GameFramework/Pawn.h"
#include "Components/SplineComponent.h"
#include "AsyncAction_MovePawnAlongSpline.generated.h"


UENUM(BlueprintType)
enum class EPawnSplineMoveMethod : uint8
{
	DirectVelocity		UMETA(DisplayName="Direct Velocity"),
	AddMovementInput	UMETA(DisplayName="Add Movement Input"),
	SetActorLocation	UMETA(DisplayName="Set Actor Location"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSplineMoveUpdated, float, Progress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSplineMoveFinished);

UCLASS()
class OMEGAFLOW_API UAsyncAction_MovePawnAlongSpline : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:
	// FTickableGameObject
	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UAsyncAction_MovePawnAlongSpline, STATGROUP_Tickables); }
	virtual bool IsTickableWhenPaused() const override { return false; }
	virtual bool IsTickableInEditor() const override { return false; }
	// FTickableGameObject End

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnSplineMoveUpdated Updated;

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnSplineMoveFinished Finished;

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnSplineMoveFinished Failed;

	UPROPERTY() APawn* Local_Pawn;
	UPROPERTY() USplineComponent* Local_Spline;
	UPROPERTY() float Local_Duration;
	UPROPERTY() EPawnSplineMoveMethod Local_MoveMethod;
	UPROPERTY() float Local_TargetKey;
	UPROPERTY() float Local_StartKey;
	UPROPERTY() float Local_ElapsedTime;
	UPROPERTY() bool Local_bPlaying;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly, WorldContext="WorldContextObject"), Category="Omega|AsyncGameplayTasks",
		DisplayName="Ω🔷 Move Pawn Along Spline")
	static UAsyncAction_MovePawnAlongSpline* MovePawnAlongSpline(
		UObject* WorldContextObject,
		APawn* Pawn,
		USplineComponent* Spline,
		float Duration,
		EPawnSplineMoveMethod MoveMethod = EPawnSplineMoveMethod::DirectVelocity,
		float SplineInputKey = 0.0f);
};
