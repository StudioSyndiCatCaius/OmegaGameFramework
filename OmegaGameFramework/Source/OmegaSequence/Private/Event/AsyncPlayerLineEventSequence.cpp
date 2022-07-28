// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/AsyncPlayLinearEventSequence.h"
#include "Event/OmegaLinearEventInstance.h"

void UAsyncPlayLinearEventSequence::Local_Finish(const FString& Flag)
{
	OnFinished.Broadcast(Flag);
	SetReadyToDestroy();
}

void UAsyncPlayLinearEventSequence::Activate()
{
	UOmegaLinearEventInstance* TempInst = SubsystemRef->PlayLinearEvent(EventData, Local_StartingIndex);
	TempInst->OnEventSequenceFinish.AddDynamic(this, &UAsyncPlayLinearEventSequence::UAsyncPlayLinearEventSequence::Local_Finish);
}

UAsyncPlayLinearEventSequence* UAsyncPlayLinearEventSequence::PlayLinearEventSequence(UOmegaLinearEventSubsystem* Subsystem, FLinearEventSequence Events, int32 StartingIndex)
{
	UAsyncPlayLinearEventSequence* NewEvent = NewObject<UAsyncPlayLinearEventSequence>();
	NewEvent->SubsystemRef = Subsystem;
	NewEvent->EventData = Events;
	NewEvent->Local_StartingIndex = StartingIndex;
	return  NewEvent;
}
