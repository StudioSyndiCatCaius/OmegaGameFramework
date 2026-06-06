// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenFor_GlobalEvent.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Subsystems/Subsystem_GameManager.h"

void UListenFor_GlobalEventNamed::Native_OnEvent(FName Event, UObject* Context, FOmegaCommonMeta _meta)
{
	if (LocalWorldContext)
	{
		OnEvent.Broadcast(Event,Context,_meta);
	}
	else
	{
		SetReadyToDestroy();
	}

}

void UListenFor_GlobalEventNamed::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		LocalWorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_GameInstance>()->OnGlobalEvent.AddDynamic(this,&UListenFor_GlobalEventNamed::Native_OnEvent);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_GlobalEventNamed* UListenFor_GlobalEventNamed::ListenFor_GlobalEventNamed(const UObject* WorldContextObject)
{
	UListenFor_GlobalEventNamed* NewNode = NewObject<UListenFor_GlobalEventNamed>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}


void UListenFor_GlobalEventTagged::Native_OnEvent(FGameplayTag Event, UObject* Context, FOmegaCommonMeta _meta)
{
	if (LocalWorldContext)
	{
		OnEvent.Broadcast(Event,Context,_meta);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_GlobalEventTagged::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		LocalWorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_GameInstance>()->OnTaggedGlobalEvent.AddDynamic(this,&UListenFor_GlobalEventTagged::Native_OnEvent);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_GlobalEventTagged* UListenFor_GlobalEventTagged::ListenFor_GlobalEventTagged(
	const UObject* WorldContextObject)
{
	UListenFor_GlobalEventTagged* NewNode = NewObject<UListenFor_GlobalEventTagged>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}
