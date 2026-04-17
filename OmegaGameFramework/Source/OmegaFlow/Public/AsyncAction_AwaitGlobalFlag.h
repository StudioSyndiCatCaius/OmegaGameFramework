// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaGameManager.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Tickable.h"
#include "AsyncAction_AwaitGlobalFlag.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAsyncGlobalFlagReached);

UCLASS()
class OMEGAFLOW_API UAsyncAction_AwaitGlobalFlag : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
	
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables ); }
	virtual bool IsTickableWhenPaused() const { return true; }
	virtual bool IsTickableInEditor() const { return false; }
	
	UPROPERTY(BlueprintAssignable)
	FOnAsyncGlobalFlagReached Finished;
	
	bool b_killing=false;
	UPROPERTY() UObject* WC;
	UPROPERTY() TEnumAsByte<EOmegaGlobalParamTarget> var_target;
	UPROPERTY() FGameplayTag target_flag;
	UPROPERTY() bool target_state;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true", WorldContext="WorldContextObject"), Category="Omega|Global|Bitflags",DisplayName="🚩 Await Global Bitflag State")
	static UAsyncAction_AwaitGlobalFlag* AwaitGlobalFlag(UObject* WorldContextObject, UPARAM(meta=(Categories="BITFLAG")) FGameplayTag Flag, TEnumAsByte<EOmegaGlobalParamTarget> Target, bool bDesiredState);
	
};
