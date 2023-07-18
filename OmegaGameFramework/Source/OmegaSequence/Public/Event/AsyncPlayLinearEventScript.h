// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaLinearEventSubsystem.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Templates/SubclassOf.h"
#include "AsyncPlayLinearEventScript.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScriptEventFinished, const FString&, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAsynScriptEventUpdated, int32, NewEventIndex, UOmegaLinearEvent*, NewEvent, UOmegaLinearEventInstance*, Instance);
UCLASS()
class OMEGASEQUENCE_API UAsyncPlayLinearEventScript : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;
	UPROPERTY()
	FString ScriptData;
	UPROPERTY()
	bool bIsScriptPath;
	UPROPERTY()
	int32 LocStartIndex;
	UPROPERTY()
	TSubclassOf<UOmegaLinearEventScriptReader> Local_ReaderClass;
	UPROPERTY()
	UOmegaLinearEventInstance* EventInstance;
	
	UFUNCTION()
	void Local_NewEvent(int32 Index, UOmegaLinearEvent* EventRef);
	UPROPERTY(BlueprintAssignable)
	FOnAsynScriptEventUpdated NewEvent;
	
	UFUNCTION()
	void Local_Finish(const FString& Flag);
	UPROPERTY(BlueprintAssignable)
	FOnScriptEventFinished OnFinished;
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category="OmegaSequence", DisplayName="Play Linear Event Script")
	static UAsyncPlayLinearEventScript* PlayLinearEventScript(UObject* WorldContextObject, TSubclassOf<UOmegaLinearEventScriptReader> ReaderClass, const FString& String, bool StringIsPath, int32 StartingIndex);

};

