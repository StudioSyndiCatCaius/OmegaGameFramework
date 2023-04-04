// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_WaitForFadeState.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAsyncFadeStateReached);

UCLASS()
class OMEGAFLOW_API UAsyncAction_WaitForFadeState : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
	
	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables );
	}
	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}
	virtual bool IsTickableInEditor() const
	{
		return false;
	}
	// FTickableGameObject End
	
	UPROPERTY(BlueprintAssignable)
	FOnAsyncFadeStateReached Finished;
	
	UPROPERTY()
	APlayerController* PlayerRef;
	UPROPERTY()
	bool LocalIsFinishing;
	UPROPERTY()
	float TargetFadeState;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true", WorldContext="WorldContextObject", AdvancedDisplay="Player"), Category="Omega|GameplayTasks")
	static UAsyncAction_WaitForFadeState* WaitForFadeState(UObject* WorldContextObject, APlayerController* Player, float FadeState);

	
};
