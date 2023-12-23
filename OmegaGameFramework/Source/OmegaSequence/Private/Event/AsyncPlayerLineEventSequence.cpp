// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/AsyncPlayLinearEventSequence.h"
#include "Event/OmegaLinearEventInstance.h"
#include "Engine/World.h"


void UAsyncPlayLinearEventSequence::Local_Finish(const UOmegaLinearEventInstance* Instance, FString Flag)
{
	if(Instance == EventInstance)
	{
		OnFinished.Broadcast(Flag);
		SetReadyToDestroy();
	}
}

void UAsyncPlayLinearEventSequence::Local_NewEvent(const UOmegaLinearEventInstance* Instance,
                                                   const UOmegaLinearEvent* Event, int32 EventIndex)
{
	if(Instance == EventInstance)
	{
		NewEvent.Broadcast(EventIndex,Event,EventInstance);
	}
}


void UAsyncPlayLinearEventSequence::Activate()
{

	if(EventData.Events.Num()<=0)
	{
		Local_Finish(nullptr,"Empty");
	}
	
	SubsystemRef->OnLinearEventSequenceEnd.AddDynamic(this, &UAsyncPlayLinearEventSequence::Local_Finish);
	SubsystemRef->OnLinearEventBegin.AddDynamic(this, &UAsyncPlayLinearEventSequence::Local_NewEvent);
	
	EventInstance = SubsystemRef->PlayLinearEvent(EventData, Local_StartingIndex);
	
	if(!EventInstance)
	{
		SetReadyToDestroy();
	}
}

UAsyncPlayLinearEventSequence* UAsyncPlayLinearEventSequence::PlayLinearEventSequence(UObject* WorldContextObject, FLinearEventSequence Events, int32 StartingIndex)
{
	UAsyncPlayLinearEventSequence* NewEvent = NewObject<UAsyncPlayLinearEventSequence>();
	NewEvent->SubsystemRef = WorldContextObject->GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>();
	NewEvent->EventData = Events;
	NewEvent->Local_StartingIndex = StartingIndex;
	return  NewEvent;
}
