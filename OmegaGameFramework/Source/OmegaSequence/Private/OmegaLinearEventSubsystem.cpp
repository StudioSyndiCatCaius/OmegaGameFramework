// Fill out your copyright notice in the Description page of Project Settings.

#include "OmegaLinearEventSubsystem.h"

#include "Engine.h"
#include "Engine/World.h"
#include "Event/OmegaLinearEventInstance.h"
#include "Parser/OmegaDataParserSubsystem.h"
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

void UOmegaLinearEventSubsystem::Local_EndEvent(const FString& Flag, UOmegaLinearEventInstance* Instance)
{
	OnLinearEventSequenceEnd.Broadcast(Instance,Flag);
}

void UOmegaLinearEventSubsystem::Local_NewEvent(UOmegaLinearEventInstance* Instance, int32 EventIndex,
	UOmegaLinearEvent* Event)
{
	OnLinearEventBegin.Broadcast(Instance,Event,EventIndex);
}


UOmegaLinearEventInstance* UOmegaLinearEventSubsystem::PlayLinearEvent(FLinearEventSequence Sequence, int32 StartingEvent)
{
	UOmegaLinearEventInstance* TempEventInst = NewObject<UOmegaLinearEventInstance>(this, UOmegaLinearEventInstance::StaticClass());
	
	TempEventInst->SubsystemRef = this;
	TempEventInst->SequenceData = Sequence;

	TempEventInst->OnEventSequenceFinish.AddDynamic(this, &UOmegaLinearEventSubsystem::Local_EndEvent);
	TempEventInst->OnEventUpdated.AddDynamic(this, &UOmegaLinearEventSubsystem::Local_NewEvent);
	
	//set the starting event sequence to the previous event from "StartingEvent". This means when "NextEvent" fires bellow, it will run the correct starting index.
	if (Sequence.Events.IsValidIndex(StartingEvent-1))
	{
		TempEventInst->CurrentEvent=Sequence.Events[StartingEvent-1];
	}
	
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
		if(TempChoice)
		{
			TempChoice->GameInstanceRef = GetWorld()->GetGameInstance();
		}
	}
	LocalInst->FinishSpawning(SpawnWorldPoint);
	
	return LocalInst;
}

void UOmegaLinearEventSubsystem::RegisterQueuedLinearEventSource(UObject* Source, bool bRegistered)
{
	if(Source && Source->GetClass()->ImplementsInterface(UQueuedLinearEventInterface::StaticClass()))
	{
		if(bRegistered)
		{
			Queued_event_sources.AddUnique(Source);
		}
		else if(Queued_event_sources.Contains(Source))
		{
			Queued_event_sources.Remove(Source);
		}
	}
}

FLinearEventSequence UOmegaLinearEventSubsystem::GetLinearEventsFromQueueKey(const FString& Key)
{
	FLinearEventSequence out;
	TArray<FQueuedLinearEventData> all_guidslot_data;

	for (auto* TempSource : Queued_event_sources)
	{
		all_guidslot_data.Append(IQueuedLinearEventInterface::Execute_GetQueuedLinearEvents(TempSource,Key));
	}

	// Sort 'all_guidslot_data' by the 'priority' field
	Algo::Sort(all_guidslot_data, [](const FQueuedLinearEventData& A, const FQueuedLinearEventData& B)
	{
		return A.priority < B.priority; // Sort in ascending order of priority
	});

	for (FQueuedLinearEventData event_data : all_guidslot_data)
	{
		out.Events.Append(event_data.Events.Events);
	}

	return out;
}

FLinearEventSequence UOmegaLinearEventScriptReader::ConvertToLinearEventSequence(const FString& Script, TSubclassOf<UOmegaDataParserReader> ReaderClass, bool ScriptIsPath)
{
	FLinearEventSequence OutEventList;
	TArray<FOmegaLinearEventScriptData> ScriptEventList = ConvertScriptToEventData(Script);
	UOmegaDataParserReader* ReaderObject;
	
	if(ScriptIsPath)
	{
		ReaderObject = GEngine->GetEngineSubsystem<UOmegaDataParserSubsystem>()->ParseDataFromPath(ReaderClass, Script);
	}
	else
	{
		ReaderObject = GEngine->GetEngineSubsystem<UOmegaDataParserSubsystem>()->ParseDataFromString(ReaderClass, Script);
	}
	
	for (FOmegaLinearEventScriptData TempEvent : ScriptEventList)
	{
		ReaderObject->LoadedString = TempEvent.Event_Data;
		TSubclassOf<UOmegaLinearEvent> LocalEventClass = GetEventClassFromString(TempEvent.Event_Type);
		UOmegaLinearEvent* NewEvent = NewObject<UOmegaLinearEvent>(this, LocalEventClass);
		NewEvent->ReadParsedData(ReaderObject);
		OutEventList.Events.Add(NewEvent);
	}
	
	return OutEventList;
}

