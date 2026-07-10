// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Tickable.h"
#include "AsyncAction_Hitstop.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitstopFinished);

UCLASS()
class OMEGAFLOW_API UAsyncAction_Hitstop : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:
	// FTickableGameObject
	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UAsyncAction_Hitstop, STATGROUP_Tickables); }
	virtual bool IsTickableWhenPaused() const override { return false; }
	virtual bool IsTickableInEditor() const override { return false; }
	// FTickableGameObject End

	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnHitstopFinished Finished;

	UPROPERTY() const UObject* Local_WorldContext;
	UPROPERTY() float Local_Time;
	UPROPERTY() float Local_Dilation;
	UPROPERTY() float Local_DilationOnEnd;
	UPROPERTY() float Local_ElapsedTime;
	UPROPERTY() bool  Local_bPlaying;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly, WorldContext="WorldContextObject",
		AdvancedDisplay="DilationOnEnd"),
		Category="Omega|AsyncGameplayTasks", DisplayName="Ω🔷 Hitstop")
	static UAsyncAction_Hitstop* Hitstop(
		UObject* WorldContextObject,
		float Time = 0.2f,
		float Dilation = 0.05f,
		float DilationOnEnd = 1.0f);
};
