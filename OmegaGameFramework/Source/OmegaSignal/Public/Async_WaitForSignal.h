// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaSignalAsset.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Async_WaitForSignal.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSignal);

UCLASS()
class OMEGASIGNAL_API UAsync_WaitForSignal : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FOnSignal OnSignal;

	UFUNCTION()
	void Local_OnSignal(UOmegaSignalAsset* LocalSig);
	
	UPROPERTY()
	UOmegaSignalAsset* LocalSignal;
	
	UPROPERTY()
	const UObject* Local_WorldContext;
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", meta = (WorldContext = "WorldContextObject")) 
	static UAsync_WaitForSignal* WaitForSignal(const UObject* WorldContextObject, UOmegaSignalAsset* Signal);
	
};
