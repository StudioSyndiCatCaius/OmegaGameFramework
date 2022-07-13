// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaLinearEventSubsystem.h"

#include "OmegaLinearEventInstance.h"
#include "Kismet/GameplayStatics.h"

void UOmegaLinearEventSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	GameInstanceReference = UGameplayStatics::GetGameInstance(this);
	Super::Initialize(Collection);
}

void UOmegaLinearEventSubsystem::Deinitialize()
{
	Super::Deinitialize();
}


UOmegaLinearEventInstance* UOmegaLinearEventSubsystem::PlayLinearEvent(FLinearEventSequence Sequence)
{
	
	UOmegaLinearEventInstance* TempEvent = NewObject<UOmegaLinearEventInstance>(this, UOmegaLinearEventInstance::StaticClass());

	TempEvent->SubsystemRef = this;
	TempEvent->SequenceData = Sequence;
	TempEvents.Add(TempEvent);
	TempEvent->NextEvent();
	return TempEvent;
}
