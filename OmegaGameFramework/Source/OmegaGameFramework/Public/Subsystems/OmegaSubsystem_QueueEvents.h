// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Materials/MaterialExpression.h"
#include "GameplayTags.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaSubsystem_QueueEvents.generated.h"

// =========================================================================================================
// DELAY
// =========================================================================================================
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

// =========================================================================================================
// QUERY
// =========================================================================================================
UINTERFACE(MinimalAPI)
class UInterface_QueuedQuery : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IInterface_QueuedQuery
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category = "Queued Delay")
	bool GetQueuedQueryValue(FGameplayTag Tag, UObject* Context=nullptr);
	
};


// =========================================================================================================
// SELECTOR
// =========================================================================================================
UINTERFACE(MinimalAPI)
class UInterface_QueuedSelector : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IInterface_QueuedSelector
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Queued Delay")
	UObject* GetQueuedSelectorObject(FGameplayTag Tag, int32& Priority);

};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_QueueEvents : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY() TArray<UObject*> sources_delay;
	UPROPERTY() TArray<UObject*> sources_query;
	UPROPERTY() TArray<UObject*> sources_selector;
	
public:

	// -------------------------------------------------------------------------------------
	// DELAY
	// -------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category="Omega|Queued|Delay")
	bool IsTagInQueuedDelay(FGameplayTag Tag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Queued|Delay")
	bool SetQueuedDelaySourceRegistered(UObject* Source, bool bIsRegistered);


	// -------------------------------------------------------------------------------------
	// Query
	// -------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category="Omega|Queued|Query")
	bool CheckQueuedQuery(FGameplayTag Tag, UObject* Context);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Queued|Query")
	bool SetQueuedQuerySourceRegistered(UObject* Source, bool bIsRegistered);

	// -------------------------------------------------------------------------------------
	// SELECTOR
	// -------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category="Omega|Queued|Selector",meta=(DeterminesOutputType="Class",ExpandBoolAsExecs="Result"))
	UObject* GetQueuedSelectedObject(FGameplayTag Tag,UObject* Fallback, TSubclassOf<UObject> Class,bool& Result);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Queued|Selector")
	bool SetQueuedSelectorSourceRegistered(UObject* Source, bool bIsRegistered);
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
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true", WorldContext="WorldContextObject", AdvancedDisplay="Player"), Category="Omega|GameplayTasks",
		DisplayName="Ω🔷 Await Queued Delay")
	static UAsyncAction_AwaitQueuedDelay* AwaitQueuedDelay(UObject* WorldContextObject, FGameplayTag QueueTag);
	
};
