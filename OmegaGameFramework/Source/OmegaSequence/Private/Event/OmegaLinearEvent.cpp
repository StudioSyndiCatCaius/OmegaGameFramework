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

void UOmegaLinearEvent::Native_Begin()
{
	/*
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->AddGameplayLog(GetLogString(), "Event");
	*/
	OnEventBegin();
}

void UOmegaLinearEvent::Finish(const FString& Flag, const FName JumpToID)
{
	IncomingEventID = JumpToID;
	OnEventEnd(Flag);
	EventEnded.Broadcast(Flag);
	
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

FString UOmegaLinearEvent::GetLogString_Implementation() const
{
	return "";
}
