// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenFor_Actor.h"

#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"



// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// INTERACTION
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
void UListenFor_ActorInteraction::L_OnEvent(AActor* InteractInstigator, AActor* Target, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if (LocalWorldContext)
	{
		OnInteraction.Broadcast(InteractInstigator,Target,Tag,Context);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_ActorInteraction::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		OGF_Subsystems::oWorld(LocalWorldContext)->OnActorInteraction.AddDynamic(this,&UListenFor_ActorInteraction::L_OnEvent);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_ActorInteraction* UListenFor_ActorInteraction::ListenFor_ActorInteraction(const UObject* WorldContextObject)
{
	UListenFor_ActorInteraction* NewNode = NewObject<UListenFor_ActorInteraction>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}

// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// Tag Target Change
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

void UListenFor_ActorTagTarget::L_OnEvent(AActor* Instigator, FGameplayTag Tag, AActor* Target, bool bRegsitered)
{
	if (LocalWorldContext)
	{
		OnTargetChange.Broadcast(Instigator,Tag,Target,bRegsitered);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_ActorTagTarget::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		OGF_Subsystems::oWorld(LocalWorldContext)->OnActorTaggedTargetChange.AddDynamic(this,&UListenFor_ActorTagTarget::L_OnEvent);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_ActorTagTarget* UListenFor_ActorTagTarget::ListenFor_ActorTagTarget(const UObject* WorldContextObject)
{
	UListenFor_ActorTagTarget* NewNode = NewObject<UListenFor_ActorTagTarget>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}


// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// Tag Event
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

void UListenFor_ActorTagEvent::L_OnEvent(AActor* Actor, FGameplayTag Tag)
{
	if (LocalWorldContext)
	{
		OnTagEvent.Broadcast(Actor,Tag);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_ActorTagEvent::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		OGF_Subsystems::oWorld(LocalWorldContext)->OnActorTagEvent.AddDynamic(this,&UListenFor_ActorTagEvent::L_OnEvent);
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_ActorTagEvent* UListenFor_ActorTagEvent::ListenFor_ActorTagEvent(const UObject* WorldContextObject)
{
	UListenFor_ActorTagEvent* NewNode = NewObject<UListenFor_ActorTagEvent>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}
