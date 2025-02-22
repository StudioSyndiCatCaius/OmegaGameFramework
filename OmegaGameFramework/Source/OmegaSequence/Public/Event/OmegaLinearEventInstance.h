// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OmegaLinearEvent.h"
#include "OmegaLinearEventSubsystem.h"
#include "OmegaLinearEventInstance.generated.h"

class UOmegaLinearEventSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEventSequenceFinish, const FString&, Flag, UOmegaLinearEventInstance*, Instance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEventUpdated, UOmegaLinearEventInstance*, Instance, int32, EventIndex, UOmegaLinearEvent*, Event);

UCLASS(BlueprintType,Blueprintable)
class OMEGASEQUENCE_API UOmegaLinearEventInstance : public UObject
{
	GENERATED_BODY()

	UFUNCTION() void on_EventEnd(UOmegaLinearEvent* Event, const FString& Flag);
	
public:
	UPROPERTY() UOmegaLinearEventSubsystem* SubsystemRef;
	
	UPROPERTY() FLinearEventSequence SequenceData;

	UPROPERTY(BlueprintAssignable)
	FOnEventSequenceFinish OnEventSequenceFinish;
	UPROPERTY(BlueprintAssignable)
	FOnEventUpdated OnEventUpdated;
	
	UFUNCTION() void NextEvent(const FString& Flag);
	UFUNCTION(BlueprintCallable,Category="LinearEvent") void EndInstance(const FString& Flag);

	UOmegaLinearEvent* GetEventFromID(FName ID);

	UPROPERTY() UOmegaLinearEvent* CurrentEvent;

	UFUNCTION(BlueprintPure, Category="LinearEvents")
	UOmegaLinearEvent* GetCurrentEvent() const;

	UFUNCTION()
	int32 GetCurrentEventIndex() const;

	UFUNCTION() void StartEvent(UOmegaLinearEvent* Event,const FString& Flag);
};


inline void UOmegaLinearEventInstance::EndInstance(const FString& Flag)
{
	if(CurrentEvent)
	{
		CurrentEvent->EventEnded.RemoveAll(this);
		CurrentEvent->Finish("PrematureStop");
	}
	OnEventSequenceFinish.Broadcast(Flag,this);
	SubsystemRef->TempEvents.Remove(this);
}

inline UOmegaLinearEvent* UOmegaLinearEventInstance::GetEventFromID(FName ID)
{
	for(UOmegaLinearEvent* TempEvent : SequenceData.Events)
	{
		if(TempEvent->EventID == ID)
		{
			return TempEvent;
		}
	}
	return nullptr;
}



