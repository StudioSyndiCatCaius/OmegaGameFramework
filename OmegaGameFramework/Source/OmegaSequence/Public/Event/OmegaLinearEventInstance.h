// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OmegaLinearEvent.h"
#include "OmegaLinearEventSubsystem.h"
#include "OmegaLinearEventInstance.generated.h"

class UOmegaLinearEventSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventSequenceFinish, const FString&, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEventUpdated, int32, EventIndex, UOmegaLinearEvent*, Event);

UCLASS()
class OMEGASEQUENCE_API UOmegaLinearEventInstance : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;
	
	UPROPERTY()
	FLinearEventSequence SequenceData;

	UPROPERTY(BlueprintAssignable)
	FOnEventSequenceFinish OnEventSequenceFinish;
	UPROPERTY(BlueprintAssignable)
	FOnEventUpdated OnEventUpdated;
	
	UFUNCTION()
	void NextEvent(const FString& Flag);
	UFUNCTION()
	void EndInstance(const FString& Flag);

	UOmegaLinearEvent* GetEventFromID(FName ID);

	UPROPERTY()
	UOmegaLinearEvent* CurrentEvent;

	int32 GetCurrentEventIndex() const
	{
		if(CurrentEvent)
		{
			return SequenceData.Events.Find(CurrentEvent);
		}
		return -1;
	}

	UFUNCTION()
	void StartEvent(UOmegaLinearEvent* Event);
};

inline void UOmegaLinearEventInstance::NextEvent(const FString& Flag)
{
	if(SequenceData.Events.IsValidIndex(GetCurrentEventIndex()))
	{
		SequenceData.Events[GetCurrentEventIndex()]->EventEnded.RemoveDynamic(this, &UOmegaLinearEventInstance::NextEvent);
	}

	const int32 NextIndex = GetCurrentEventIndex() +1;
	
	UOmegaLinearEvent* IncomingEvent = nullptr;

	// Try to get event from id.
	if(CurrentEvent && !CurrentEvent->IncomingEventID.IsNone())
	{
		IncomingEvent = GetEventFromID(CurrentEvent->IncomingEventID);
	}
	//Try and get next event
	else if (SequenceData.Events.IsValidIndex(NextIndex))
	{
		IncomingEvent = SequenceData.Events[NextIndex];
	}

	// Try run incoming event
	if(IncomingEvent)
	{
		CurrentEvent = IncomingEvent;
		StartEvent(IncomingEvent);
	}
	else
	{
		EndInstance(Flag);
	}
	
}

inline void UOmegaLinearEventInstance::EndInstance(const FString& Flag)
{
	OnEventSequenceFinish.Broadcast(Flag);
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

inline void UOmegaLinearEventInstance::StartEvent(UOmegaLinearEvent* Event)
{
	Event->EventEnded.AddDynamic(this, &UOmegaLinearEventInstance::NextEvent);
	Event->GameInstanceRef = SubsystemRef->GameInstanceReference;
	Event->WorldPrivate = SubsystemRef->GetWorld();
	OnEventUpdated.Broadcast(GetCurrentEventIndex(),Event);
	SubsystemRef->OnLinearEventBegin.Broadcast(Event);
	Event->Native_Begin();
}
