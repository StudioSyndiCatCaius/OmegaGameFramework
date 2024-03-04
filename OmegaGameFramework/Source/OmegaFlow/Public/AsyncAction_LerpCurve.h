// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_LerpCurve.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLerpCurveUpdate, float, LerpValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLerpCurveFinished);
UCLASS()

class OMEGAFLOW_API UAsyncAction_LerpCurve : public UBlueprintAsyncActionBase, public FTickableGameObject
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
	FOnLerpCurveUpdate Updated;
	UPROPERTY(BlueprintAssignable)
	FOnLerpCurveFinished Finished;

	UPROPERTY()
	bool local_playing;
	
	UPROPERTY()
	UCurveFloat* local_curve;

	UPROPERTY()
	float local_PlayRate;
	UPROPERTY()
	bool local_reversed;
	UPROPERTY()
	float elapsed_time;

	UPROPERTY()
	float new_value;
	UPROPERTY()
	float time_min;
	UPROPERTY()
	float time_max;
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true", WorldContext="WorldContextObject", AdvancedDisplay="Player"), Category="Omega|GameplayTasks")
	static UAsyncAction_LerpCurve* LerpAlongCurve(UObject* WorldContextObject, UCurveFloat* Curve, float PlayRate=1.0, bool bReverse=false);

	
};
