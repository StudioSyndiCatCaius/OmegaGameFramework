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
			// Bind delegates to actor events
			if(Register_OverlapEvents)
			{
				
				Actor->OnActorBeginOverlap.AddDynamic(this, &AOmegaActorProcessor::OnRegistered_ActorBeginOverlap);
				Actor->OnActorEndOverlap.AddDynamic(this, &AOmegaActorProcessor::OnRegistered_ActorEndOverlap);
			}
			if(Register_CursorEvents)
			{
				Actor->OnActorHit.AddDynamic(this, &AOmegaActorProcessor::OnRegistered_ActorHit);
			}
			if(Register_CursorEvents)
			{
				Actor->OnBeginCursorOver.AddDynamic(this, &AOmegaActorProcessor::OnRegistered_BeginCursorOver);
				Actor->OnEndCursorOver.AddDynamic(this, &AOmegaActorProcessor::OnRegistered_EndCursorOver);
				Actor->OnClicked.AddDynamic(this, &AOmegaActorProcessor::OnRegistered_Clicked);
			}
			REF_TrackedActors.AddUnique(Actor);
			OnActorRegistered(Actor);
		}
		if(!bIsRegistered && REF_TrackedActors.Contains(Actor))
		{
			// Unbind delegates from actor events
			if(Register_OverlapEvents)
			{
				Actor->OnActorBeginOverlap.RemoveDynamic(this, &AOmegaActorProcessor::OnRegistered_ActorBeginOverlap);
				Actor->OnActorEndOverlap.RemoveDynamic(this, &AOmegaActorProcessor::OnRegistered_ActorEndOverlap);
			}
			if(Register_CursorEvents)
			{
				Actor->OnActorHit.RemoveDynamic(this, &AOmegaActorProcessor::OnRegistered_ActorHit);
			}
			if(Register_CursorEvents)
			{
				Actor->OnBeginCursorOver.RemoveDynamic(this, &AOmegaActorProcessor::OnRegistered_BeginCursorOver);
				Actor->OnEndCursorOver.RemoveDynamic(this, &AOmegaActorProcessor::OnRegistered_EndCursorOver);
				Actor->OnClicked.RemoveDynamic(this, &AOmegaActorProcessor::OnRegistered_Clicked);
			}
        
			REF_TrackedActors.Remove(Actor);
			OnActorUnregistered(Actor);
		}
	}
}
