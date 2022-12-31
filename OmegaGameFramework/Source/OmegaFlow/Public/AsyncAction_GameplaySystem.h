// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaGameplaySystem.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_GameplaySystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShutdown, FString, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailedActivateSystem);

UCLASS()
class OMEGAFLOW_API UAsyncAction_GameplaySystem : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FShutdown OnShutdown;
	
	UPROPERTY(BlueprintAssignable)
	FOnFailedActivateSystem Failed;

	UPROPERTY()
	TSubclassOf<AOmegaGameplaySystem> LocalSystemClass;
	UPROPERTY()
	FString LocalOpenFlag;
	UPROPERTY()
	UObject* LocalContext = nullptr;
	UPROPERTY()
	UOmegaGameplaySubsystem* SubSysRef;
	UPROPERTY()
	const UObject* Local_WorldContext;
	
	UFUNCTION()
	void NativeShutdown(const FString Flag);
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", meta = (WorldContext = "WorldContextObject")) 
	static UAsyncAction_GameplaySystem* ActivateGameplaySystem(const UObject* WorldContextObject, const TSubclassOf<AOmegaGameplaySystem> SystemClass, UObject* Context, const FString Flag);

	
};
