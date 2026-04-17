// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenFor_Message.h"

#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"

void UListenFor_GameMessage::N_MessageStart(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta Meta)
{
	if (LocalWorldContext)
	{
		MessageSent.Broadcast(Message, MessageCategory, Meta);	
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_GameMessage::N_MessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta Meta)
{
	if (LocalWorldContext)
	{
		MessageEnd.Broadcast(Message, MessageCategory, Meta);	
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_GameMessage::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		OGF_Subsystems::oWorld(LocalWorldContext)->OnGameplayMessage_Begin.AddDynamic(this,&UListenFor_GameMessage::N_MessageStart);
		OGF_Subsystems::oWorld(LocalWorldContext)->OnGameplayMessage_End.AddDynamic(this,&UListenFor_GameMessage::N_MessageEnd);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_GameMessage* UListenFor_GameMessage::ListenFor_GameMessage(const UObject* WorldContextObject)
{
	UListenFor_GameMessage* NewNode = NewObject<UListenFor_GameMessage>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}
