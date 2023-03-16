// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_WaitForGlobalEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReceiveEvent, UObject*, Context);


UCLASS()
class OMEGAFLOW_API UAsyncAction_WaitForGlobalEvent : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnReceiveEvent OnReceiveEvent;

	UPROPERTY()
	const UObject* LocalWorldContext;
	UPROPERTY()
	FName EventRef;
	UPROPERTY()
	UObject* ContextRef;

	UFUNCTION()
	void Native_OnEvent(FName Event, UObject* Context);
	
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", meta = (WorldContext = "WorldContextObject")) 
	static UAsyncAction_WaitForGlobalEvent* WaitForGlobalEvent(const UObject* WorldContextObject, FName Event);

	
};