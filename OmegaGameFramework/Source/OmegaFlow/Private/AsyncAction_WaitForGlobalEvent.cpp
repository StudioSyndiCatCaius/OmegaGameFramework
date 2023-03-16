// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_WaitForGlobalEvent.h"

#include "OmegaGameManager.h"
#include "Player/OmegaPlayerSubsystem.h"

void UAsyncAction_WaitForGlobalEvent::Native_OnEvent(FName Event, UObject* Context)
{
	if(Event == EventRef)
	{
		OnReceiveEvent.Broadcast(Context);
		SetReadyToDestroy();
	}
}

void UAsyncAction_WaitForGlobalEvent::Activate()
{
	UOmegaGameManager* SubsystemRef = LocalWorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>();
	SubsystemRef->OnGlobalEvent.AddDynamic(this, &UAsyncAction_WaitForGlobalEvent::Native_OnEvent);
}

UAsyncAction_WaitForGlobalEvent* UAsyncAction_WaitForGlobalEvent::WaitForGlobalEvent(const UObject* WorldContextObject, FName Event)
{
	UAsyncAction_WaitForGlobalEvent* NewNode = NewObject<UAsyncAction_WaitForGlobalEvent>();
	NewNode->EventRef = Event;
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}