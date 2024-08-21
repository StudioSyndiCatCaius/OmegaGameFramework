// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_WaitForGlobalEvent.h"

#include "Engine/GameInstance.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Subsystems/OmegaSubsystem_Player.h"

// ==============================================
// Name
// ==============================================

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


// ==============================================
// Tagged
// ==============================================

void UAsyncAction_WaitForTaggedGlobalEvent::Native_OnEvent(FGameplayTag Event, UObject* Context)
{
	if(Event == EventRef)
	{
		OnReceiveEvent.Broadcast(Context);
		SetReadyToDestroy();
	}
}

void UAsyncAction_WaitForTaggedGlobalEvent::Activate()
{
	UOmegaGameManager* SubsystemRef = LocalWorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>();
	SubsystemRef->OnTaggedGlobalEvent.AddDynamic(this, &UAsyncAction_WaitForTaggedGlobalEvent::Native_OnEvent);
}

UAsyncAction_WaitForTaggedGlobalEvent* UAsyncAction_WaitForTaggedGlobalEvent::WaitForTaggedGlobalEvent(const UObject* WorldContextObject, FGameplayTag Event)
{
	UAsyncAction_WaitForTaggedGlobalEvent* NewNode = NewObject<UAsyncAction_WaitForTaggedGlobalEvent>();
	NewNode->EventRef = Event;
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}
