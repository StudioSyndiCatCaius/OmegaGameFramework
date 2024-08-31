// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Materials/MaterialExpression.h"
#include "GameplayTags.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaSubsystem_QueueDelay.generated.h"

UINTERFACE(MinimalAPI)
class UInterface_QueueDelay : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IInterface_QueueDelay
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Queued Delay")
	bool GetQueuedDelayActive();

	UFUNCTION(BlueprintImplementableEvent, Category = "Queued Delay")
	FGameplayTagContainer GetQueuedDelayTags();

};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_QueueDelay : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<UObject*> DelaySources;

	
public:

	UFUNCTION(BlueprintCallable, Category="Omega|Queued Delay")
	bool IsTagInQueuedDelay(FGameplayTag Tag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Queued Delay")
	bool SetQueuedDelaySourceRegistered(UObject* Source, bool bIsRegistered);
};



// ------------------------------------------------------------------------------------------------
// Async Task
// ------------------------------------------------------------------------------------------------
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQueuedDelayFinish);
UCLASS()
class OMEGAGAMEFRAMEWORK_API UAsyncAction_AwaitQueuedDelay : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

	void local_TryEnd();

public:

	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override {return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables ); }
	virtual bool IsTickableWhenPaused() const { return true; }
	virtual bool IsTickableInEditor() const { return false; }
	// FTickableGameObject End
	
	UPROPERTY(BlueprintAssignable)
	FOnQueuedDelayFinish Finished;

	UPROPERTY() UObject* local_WorldContext;
	UPROPERTY() bool local_finishing;
	UPROPERTY() FGameplayTag local_tag;

	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true", WorldContext="WorldContextObject", AdvancedDisplay="Player"), Category="Omega|GameplayTasks")
	static UAsyncAction_AwaitQueuedDelay* AwaitQueuedDelay(UObject* WorldContextObject, FGameplayTag QueueTag);

	
};
