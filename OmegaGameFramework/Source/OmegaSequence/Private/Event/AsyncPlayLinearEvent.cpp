// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/AsyncPlayLinearEvent.h"

void UAsyncPlayLinearEvent::Activate()
{
	EventRef->EventEnded.AddDynamic(this, &UAsyncPlayLinearEvent::LocalEnd);
	EventRef->OnEventBegin();
}

void UAsyncPlayLinearEvent::LocalEnd(const FString& Flag)
{
	Finished.Broadcast(Flag);
	SetReadyToDestroy();
}

UAsyncPlayLinearEvent* UAsyncPlayLinearEvent::PlayLinearEvent(UOmegaLinearEvent* Event)
{
	UAsyncPlayLinearEvent* NewEvent = NewObject<UAsyncPlayLinearEvent>();
	
	NewEvent->EventRef = Event;
	
	return  NewEvent;
}
