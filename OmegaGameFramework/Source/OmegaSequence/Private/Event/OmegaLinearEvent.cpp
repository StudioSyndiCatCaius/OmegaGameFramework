// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/OmegaLinearEvent.h"
#include "Engine/GameInstance.h"

UOmegaLinearEvent::UOmegaLinearEvent(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
	if(!EventGuid.IsValid())
	{
		EventGuid=FGuid::NewGuid();
	}
}

UWorld* UOmegaLinearEvent::GetWorld() const
{
	if(WorldPrivate)
	{
		return WorldPrivate;
	}
	else if(GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}
	return nullptr;
}

UGameInstance* UOmegaLinearEvent::GetGameInstance() const
{
	return GameInstanceRef;
}

bool UOmegaLinearEvent::CanPlayEvent_Implementation()
{
	return true;
}

void UOmegaLinearEvent::Native_Begin(const FString& Flag)
{
	EventBegin.Broadcast(this,Flag);
	OnEventBegin(Flag);
}

void UOmegaLinearEvent::Finish(const FString& Flag, const FName JumpToID)
{
	IncomingEventID = JumpToID;
	OnEventEnd(Flag);
	EventEnded.Broadcast(this,Flag);
	
}

void UOmegaLinearEvent::StopEventSequence()
{
	Finish("@@InternalFinish_STOP@@");
}

void UOmegaLinearEvent::JumpToEvent(FName Event, bool EndSequenceIfFail)
{
	//SetJumpPoint
	Finish("");
}

FLinearEventSequence UOmegaLinearEventFunctions::CreateLinearEventSequence_FromReader(UObject* WorldContextObject,
	UOmegaLinearEventReader*  Reader,const FString&  SourceString)
{
	if(Reader)
	{
		return Reader->Convert_StringToEvents(WorldContextObject,SourceString);
	}
	return FLinearEventSequence();
}

FString UOmegaLinearEventFunctions::CreateLinearEventString_FromReader(UObject* WorldContextObject,
	UOmegaLinearEventReader*  Reader, FLinearEventSequence Events)
{
	if(Reader)
	{
		return Reader->Convert_EventsToString(WorldContextObject,Events);
	}
	return "";
}

FString UOmegaLinearEvent::GetLogString_Implementation() const
{
	return "";
}
