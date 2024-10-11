// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/OmegaLinearEventInstance.h"

void UOmegaLinearEventInstance::NextEvent(const FString& Flag)
{
	//Unbind last event
	if(SequenceData.Events.IsValidIndex(GetCurrentEventIndex()))
	{
		SequenceData.Events[GetCurrentEventIndex()]->EventEnded.RemoveDynamic(this, &UOmegaLinearEventInstance::NextEvent);
	}

	//CHECK IF SHOULD STOP EVENT SEQUENCE
	if(Flag=="@@InternalFinish_STOP@@")
	{
		EndInstance("STOPPED");
		return;
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

void UOmegaLinearEventInstance::StartEvent(UOmegaLinearEvent* Event)
{
	if(Event->CanPlayEvent())
	{
		//Bind event so when it finishes, we go to next event
		Event->EventEnded.AddDynamic(this, &UOmegaLinearEventInstance::NextEvent);
		
		//setup vars
		Event->GameInstanceRef = SubsystemRef->GameInstanceReference;
		Event->WorldPrivate = SubsystemRef->GetWorld();
		
		//broadcast delegates for event start (first - from instance / second - from subsystem)
		OnEventUpdated.Broadcast(this,GetCurrentEventIndex(),Event);
		//SubsystemRef->OnLinearEventBegin.Broadcast(this,Event,GetCurrentEventIndex());

		//Finally, start the event
		Event->Native_Begin();
	}
	else
	{
		NextEvent("Skipped");
	}
}
