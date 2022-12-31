// Fill out your copyright notice in the Description page of Project Settings.

#include "OmegaLinearEventSubsystem.h"

#include "Engine/World.h"
#include "Event/OmegaLinearEventInstance.h"
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


UOmegaLinearEventInstance* UOmegaLinearEventSubsystem::PlayLinearEvent(FLinearEventSequence Sequence, int32 StartingEvent)
{
	UOmegaLinearEventInstance* TempEventInst = NewObject<UOmegaLinearEventInstance>(this, UOmegaLinearEventInstance::StaticClass());
	
	TempEventInst->SubsystemRef = this;
	TempEventInst->SequenceData = Sequence;
	TempEventInst->ActiveIndex = StartingEvent-1;
	TempEvents.Add(TempEventInst);
	TempEventInst->NextEvent("Root");
	return TempEventInst;
}

UOmegaLinearEventInstance* UOmegaLinearEventSubsystem::PlayLinearEventFromID(FLinearEventSequence Sequence, FName ID)
{
	for(UOmegaLinearEvent* TempEvent : Sequence.Events)
	{
		if(TempEvent->EventID == ID)
		{
			return PlayLinearEvent(Sequence, Sequence.Events.Find(TempEvent));
		}
	}
	return nullptr;
}

AOmegaLinearChoiceInstance* UOmegaLinearEventSubsystem::PlayLinearChoice(FOmegaLinearChoices Choices, TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass)
{
	TSubclassOf<AOmegaLinearChoiceInstance> LocalClass;
	if(InstanceClass)
	{
		LocalClass = InstanceClass;
	}
	else
	{
		LocalClass = AOmegaLinearChoiceInstance::StaticClass();
	}

	const FTransform SpawnWorldPoint;
	AOmegaLinearChoiceInstance* LocalInst = GetWorld()->SpawnActorDeferred<AOmegaLinearChoiceInstance>(LocalClass, SpawnWorldPoint, nullptr);
	LocalInst->ChoiceData = Choices;
	for(auto* TempChoice : LocalInst->ChoiceData.Choices)
	{
		TempChoice->GameInstanceRef = GetWorld()->GetGameInstance();
	}
	LocalInst->FinishSpawning(SpawnWorldPoint);
	
	return LocalInst;
}
