// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_WaitForFlag.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFlagValid);


UCLASS()
class OMEGAFLOW_API UAsyncAction_WaitForFlag : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnFlagValid OnFlagValid;

	UPROPERTY()
	const UObject* LocalWorldContext;
	UPROPERTY()
	FString Local_Flag;
	UPROPERTY()
	bool Local_State;

	UFUNCTION()
	void Native_OnFlagEvent(FString Flag, bool State);

	UFUNCTION()
	void Local_Finish();
	
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", meta = (WorldContext = "WorldContextObject")) 
	static UAsyncAction_WaitForFlag* WaitForFlagState(UObject* WorldContextObject, const FString& Flag, bool bState);

	
};
