// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/OmegaLinearEvent.h"


UOmegaLinearEvent::UOmegaLinearEvent(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
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

void UOmegaLinearEvent::Native_Begin()
{
	/*
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->AddGameplayLog(GetLogString(), "Event");
	*/
	OnEventBegin();
}

void UOmegaLinearEvent::Finish(const FString& Flag)
{
	OnEventEnd(Flag);
	EventEnded.Broadcast(Flag);
	
}
