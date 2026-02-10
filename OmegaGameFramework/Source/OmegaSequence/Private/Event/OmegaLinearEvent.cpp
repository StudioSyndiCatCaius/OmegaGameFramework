// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/OmegaLinearEvent.h"
#include "Engine/GameInstance.h"
#include "Subsystems/Subsystem_GameManager.h"

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
	if(WorldPrivate)
	{
		WorldPrivate->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UOmegaLinearEvent::OnGlobalEvent_Named);
		WorldPrivate->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnTaggedGlobalEvent.AddDynamic(this, &UOmegaLinearEvent::OnGlobalEvent_Tagged);
	}
	OnEventBegin(Flag);
}

void UOmegaLinearEvent::OnEventEnd_Implementation(const FString& Flag)
{
}

void UOmegaLinearEvent::OnEventBegin_Implementation(const FString& Flag)
{
}

void UOmegaLinearEvent::Finish(const FString& Flag, const FName JumpToID)
{
	if(WorldPrivate)
	{
		WorldPrivate->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.RemoveDynamic(this, &UOmegaLinearEvent::OnGlobalEvent_Named);
		WorldPrivate->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnTaggedGlobalEvent.RemoveDynamic(this, &UOmegaLinearEvent::OnGlobalEvent_Tagged);
	}
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
