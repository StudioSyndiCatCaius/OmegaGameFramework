﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/AsyncPlayLinearEventScript.h"
#include "Event/OmegaLinearEventInstance.h"
#include "Engine/World.h"
#include "Parser/OmegaDataParserSubsystem.h"

void UAsyncPlayLinearEventScript::Local_NewEvent(UOmegaLinearEventInstance* Instance,int32 Index, UOmegaLinearEvent* EventRef)
{
	NewEvent.Broadcast(Index,EventRef,EventInstance);
}

void UAsyncPlayLinearEventScript::Local_Finish(const FString& Flag, UOmegaLinearEventInstance* Instance)
{
	OnFinished.Broadcast(Flag);
	SetReadyToDestroy();
}

void UAsyncPlayLinearEventScript::Activate()
{
	if(Local_ReaderClass)
	{
		// GEngine->GetEngineSubsystem<UOmegaDataParserSubsystem>()->ParseDataFromString(Local_ReaderClass, ScriptData);

		UOmegaLinearEventScriptReader* EventReader = NewObject<UOmegaLinearEventScriptReader>(SubsystemRef, Local_ReaderClass);
		const FLinearEventSequence EventData = EventReader->ConvertToLinearEventSequence(ScriptData,EventReader->GetParserClass(),bIsScriptPath);
		
		UE_LOG(LogTemp, Log, TEXT("Class Name: %s"), *EventReader->GetName());
		
		if(EventData.Events.Num()<=0)
		{
			Local_Finish("Empty");
		}
		
		EventInstance = SubsystemRef->PlayLinearEvent(EventData, LocStartIndex);
		EventInstance->OnEventUpdated.AddDynamic(this, &UAsyncPlayLinearEventScript::Local_NewEvent);
		EventInstance->OnEventSequenceFinish.AddDynamic(this, &UAsyncPlayLinearEventScript::Local_Finish);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UAsyncPlayLinearEventScript* UAsyncPlayLinearEventScript::PlayLinearEventScript(UObject* WorldContextObject,
	TSubclassOf<UOmegaLinearEventScriptReader> ReaderClass, const FString& String, bool StringIsPath, int32 StartingIndex)
{
	UAsyncPlayLinearEventScript* NewEvent = NewObject<UAsyncPlayLinearEventScript>();
	NewEvent->SubsystemRef = WorldContextObject->GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>();
	NewEvent->ScriptData = String;
	NewEvent->bIsScriptPath = StringIsPath;
	NewEvent->Local_ReaderClass = ReaderClass;
	NewEvent->LocStartIndex = StartingIndex;
	return NewEvent;
}

