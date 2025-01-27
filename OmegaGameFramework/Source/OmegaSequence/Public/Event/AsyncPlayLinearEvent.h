// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaLinearEvent.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncPlayLinearEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventFinished, const FString&, Flag);

UCLASS()
class OMEGASEQUENCE_API UAsyncPlayLinearEvent : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	virtual void Activate() override;

	UPROPERTY(BlueprintAssignable) FEventFinished Finished;

	UFUNCTION() void LocalEnd(UOmegaLinearEvent* Event,const FString& Flag);

	UPROPERTY() UOmegaLinearEvent* EventRef;
	UPROPERTY() FString in_flag;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks|LinearEvent", DisplayName="Ω🔷 Play Linear Event")
	static UAsyncPlayLinearEvent* PlayLinearEvent(UOmegaLinearEvent* Event,const FString& Flag);
};
