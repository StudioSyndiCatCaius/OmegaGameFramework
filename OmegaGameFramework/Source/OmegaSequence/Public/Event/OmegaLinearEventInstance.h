// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OmegaLinearEvent.h"
#include "OmegaLinearEventSubsystem.h"
#include "OmegaLinearEventInstance.generated.h"

class UOmegaLinearEventSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventSequenceFinish, const FString&, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventUpdated, int32, EventIndex);

UCLASS()
class OMEGASEQUENCE_API UOmegaLinearEventInstance : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;
	
	UPROPERTY()
	FLinearEventSequence SequenceData;
	
	UPROPERTY()
	int32 ActiveIndex = -1;

	UPROPERTY(BlueprintAssignable)
	FOnEventSequenceFinish OnEventSequenceFinish;
	UPROPERTY(BlueprintAssignable)
	FOnEventUpdated OnEventUpdated;
	
	UFUNCTION()
	void NextEvent(const FString& Flag);
	UFUNCTION()
	void EndInstance(const FString& Flag);

	const UOmegaLinearEvent* GetEventFromID(FName ID);

	UFUNCTION()
	void StartEvent(UOmegaLinearEvent* Event);
};

inline void UOmegaLinearEventInstance::NextEvent(const FString& Flag)
{
	if(SequenceData.Events.IsValidIndex(ActiveIndex))
	{
		SequenceData.Events[ActiveIndex]->EventEnded.RemoveDynamic(this, &UOmegaLinearEventInstance::NextEvent);
	}
	
	ActiveIndex = ActiveIndex +1;
	
	if(SequenceData.Events.IsValidIndex(ActiveIndex))
	{
		UOmegaLinearEvent* TempEvent = SequenceData.Events[ActiveIndex];
		StartEvent(TempEvent);
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

inline const UOmegaLinearEvent* UOmegaLinearEventInstance::GetEventFromID(FName ID)
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
	OnEventUpdated.Broadcast(ActiveIndex);
	SubsystemRef->OnLinearEventBegin.Broadcast(Event);
	Event->Native_Begin();
}
