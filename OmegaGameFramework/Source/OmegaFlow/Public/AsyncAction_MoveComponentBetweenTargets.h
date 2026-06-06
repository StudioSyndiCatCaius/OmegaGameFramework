// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Tickable.h"
#include "Components/SceneComponent.h"
#include "AsyncAction_MoveComponentBetweenTargets.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComponentMoveUpdated, float, Progress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComponentMoveFinished);

UCLASS()
class OMEGAFLOW_API UAsyncAction_MoveComponentBetweenTargets : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:
	// FTickableGameObject
	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UAsyncAction_MoveComponentBetweenTargets, STATGROUP_Tickables); }
	virtual bool IsTickableWhenPaused() const override { return false; }
	virtual bool IsTickableInEditor() const override { return false; }
	// FTickableGameObject End

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnComponentMoveUpdated Updated;

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnComponentMoveFinished Finished;

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnComponentMoveFinished Failed;

	// Stored references
	UPROPERTY() USceneComponent* Local_Source;
	UPROPERTY() USceneComponent* Local_StartComp;
	UPROPERTY() USceneComponent* Local_EndComp;
	UPROPERTY() float Local_Duration;
	UPROPERTY() bool Local_bReverse;
	UPROPERTY() bool Local_bWorldTransform;
	UPROPERTY() bool Local_bEditTranslation;
	UPROPERTY() bool Local_bEditRotation;
	UPROPERTY() bool Local_bEditScale;
	UPROPERTY() float Local_ElapsedTime;
	UPROPERTY() bool Local_bPlaying;

	// Transforms captured at Activate time
	FVector Local_StartLocation;
	FVector Local_EndLocation;
	FQuat   Local_StartRotation;
	FQuat   Local_EndRotation;
	FVector Local_StartScale;
	FVector Local_EndScale;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly, WorldContext="WorldContextObject",
		AdvancedDisplay="bEditTranslation, bEditRotation, bEditScale"),
		Category="Omega|AsyncGameplayTasks", DisplayName="Ω🔷 Move Component Between Targets")
	static UAsyncAction_MoveComponentBetweenTargets* MoveComponentBetweenTargets(
		UObject* WorldContextObject,
		USceneComponent* Source,
		USceneComponent* Start,
		USceneComponent* End,
		float Time,
		bool bReverse = false,
		bool bWorldTransform = true,
		bool bEditTranslation = true,
		bool bEditRotation = true,
		bool bEditScale = false);
};
