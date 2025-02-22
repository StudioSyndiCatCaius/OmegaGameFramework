// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/AsyncPlayLinearEvent.h"

void UAsyncPlayLinearEvent::Activate()
{
	EventRef->EventEnded.AddDynamic(this, &UAsyncPlayLinearEvent::LocalEnd);
	EventRef->OnEventBegin(in_flag);
}

void UAsyncPlayLinearEvent::LocalEnd(UOmegaLinearEvent* Event,const FString& Flag)
{
	if(Event==EventRef)
	{
		Finished.Broadcast(Flag);
		SetReadyToDestroy();
	}
}

UAsyncPlayLinearEvent* UAsyncPlayLinearEvent::PlayLinearEvent(UOmegaLinearEvent* Event,const FString& Flag)
{
	UAsyncPlayLinearEvent* NewEvent = NewObject<UAsyncPlayLinearEvent>();
	NewEvent->in_flag=Flag;
	NewEvent->EventRef = Event;
	
	return  NewEvent;
}
