// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_ActorProcessor.h"

TArray<AActor*> AOmegaActorProcessor::GetRegisteredActors()
{
	TArray<AActor*> out;
	for(auto* a : REF_TrackedActors)
	{
		if(a)
		{
			out.Add(a);
		}
	}
	return out;
}

void AOmegaActorProcessor::SetActorRegisteredToProcessor(AActor* Actor, bool bIsRegistered)
{
	if(Actor)
	{
		if(bIsRegistered && !REF_TrackedActors.Contains(Actor))
		{
			REF_TrackedActors.AddUnique(Actor);
			OnActorRegistered(Actor);
		}
		if(!bIsRegistered && REF_TrackedActors.Contains(Actor))
		{
			REF_TrackedActors.Remove(Actor);
			OnActorUnregistered(Actor);
		}
	}
}
