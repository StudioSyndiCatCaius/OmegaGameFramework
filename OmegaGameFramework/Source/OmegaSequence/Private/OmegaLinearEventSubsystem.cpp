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

