// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Subsystems/OmegaSubsystem_QueueDelay.h"
#include "AsyncAction_GameplaySystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FShutdown, UObject*, Context, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSystemNotify, UObject*, Context, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailedActivateSystem);

UCLASS()
class OMEGAFLOW_API UAsyncAction_GameplaySystem : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable) FShutdown OnShutdown;
	UPROPERTY(BlueprintAssignable) FSystemNotify Notify;
	UPROPERTY(BlueprintAssignable) FOnFailedActivateSystem Failed;
	UFUNCTION() void NativeShutdown(UObject* Context, const FString Flag);
	UFUNCTION() void Native_Notify(UObject* Context, const FString Flag);
	
	UPROPERTY() TSubclassOf<AOmegaGameplaySystem> LocalSystemClass;
	UPROPERTY() FString LocalOpenFlag;
	UPROPERTY() UObject* LocalContext = nullptr;
	UPROPERTY() UOmegaGameplaySubsystem* SubSysRef;
	UPROPERTY() const UObject* Local_WorldContext;
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|AsyncGameplayTasks", meta = (WorldContext = "WorldContextObject"),
		DisplayName="Ω🔷 Activate Gameplay System") 
	static UAsyncAction_GameplaySystem* ActivateGameplaySystem(const UObject* WorldContextObject, const TSubclassOf<AOmegaGameplaySystem> SystemClass, UObject* Context, const FString Flag);

	
};
