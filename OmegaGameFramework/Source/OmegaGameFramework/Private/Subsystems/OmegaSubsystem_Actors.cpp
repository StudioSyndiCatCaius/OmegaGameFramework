// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_Actors.h"

#include "OmegaSettings_Gameplay.h"

void UOmegaActorSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	active_processors.Empty();
	if(UOmegaSettings_Gameplay* set=UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
	{
		for(TSubclassOf<AOmegaActorProcessor> c : set->ActorProcessors)
		{
			if(c)
			{
				AOmegaActorProcessor* _newproc = GetWorld()->SpawnActorDeferred<AOmegaActorProcessor>(c,FTransform());
				_newproc->FinishSpawning(FTransform());
				active_processors.Add(c,_newproc);
				UE_LOG(LogTemp, Warning, TEXT("Created Actor Processor: %s"), *_newproc->GetName());
			}
		}
	}
	Super::OnWorldBeginPlay(InWorld);
}


void UOmegaActorSubsystem::local_RegisterActorIdComp(UActorIdentityComponent* Component, bool bIsRegister)
{
	if(Component)
	{
		if(bIsRegister && !REF_ActorIdComps.Contains(Component))
		{
			REF_ActorIdComps.Add(Component);
		}
		if(!bIsRegister && REF_ActorIdComps.Contains(Component))
		{
			REF_ActorIdComps.Remove(Component);
		}
	}
}

TArray<UActorIdentityComponent*> UOmegaActorSubsystem::GetAllActorIdentityComponents()
{
	TArray<UActorIdentityComponent*>out;
	for(auto* i : REF_ActorIdComps)
	{
		if(i) {out.Add(i);}
	}
	return out;
}

void UOmegaActorSubsystem::RegisterActorToProcessor(AActor* Actor, TSubclassOf<AOmegaActorProcessor> Processor)
{
	if(Actor && Processor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempting - Register %s to processor %s"), *Actor->GetName(), *Processor->GetName());
		if(AOmegaActorProcessor* temp_proc=active_processors.FindOrAdd(Processor))
		{
			temp_proc->SetActorRegisteredToProcessor(Actor,true);
			UE_LOG(LogTemp, Warning, TEXT("SUCCESS - Registered %s to processor %s"), *Actor->GetName(), *temp_proc->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FAILED - invalid processor actor"));
		}
	}
}

void UOmegaActorSubsystem::PerformInteraction(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, UObject* Context)
{
	if(Instigator && TargetActor)
	{
		if(TargetActor->GetClass()->ImplementsInterface(UActorInterface_Interactable::StaticClass()))
		{
			IActorInterface_Interactable::Execute_OnInteraction(TargetActor,Instigator,Tag,Context);
		}
		OnActorInteraction.Broadcast(Instigator,TargetActor,Tag,Context);
	}
}

bool UOmegaActorSubsystem::IsActorInGroup(FGameplayTag GroupTag, AActor* Actor) const
{
	return GetActorsInGroup(GroupTag).Contains(Actor);
}

void UOmegaActorSubsystem::SetActorRegisteredToGroup(FGameplayTag GroupTag, AActor* Actor, bool registered)
{
	if (!Actor)
	{
		return;
	}

	if (registered)
	{
		// Make sure the group exists in the map
		if (!actorGroups.Contains(GroupTag))
		{
			actorGroups.Add(GroupTag, FOmegaActorGroupData());
		}

		// Add the actor to the group if not already present
		actorGroups[GroupTag].Actors.AddUnique(Actor);
	}
	else
	{
		// Remove the actor from the group if the group exists
		if (actorGroups.Contains(GroupTag))
		{
			actorGroups[GroupTag].Actors.Remove(Actor);
		}
	}
}

void UOmegaActorSubsystem::SetActorsRegisteredToGroup(FGameplayTag GroupTag, TArray<AActor*> Actors, bool registered)
{
	for(auto* a : Actors)
	{
		SetActorRegisteredToGroup(GroupTag,a,registered);
	}
}

void UOmegaActorSubsystem::ClearActorGroup(FGameplayTag GroupTag)
{
	if (actorGroups.Contains(GroupTag))
	{
		actorGroups[GroupTag].Actors.Empty();
	}
}

TArray<AActor*> UOmegaActorSubsystem::GetActorsInGroup(FGameplayTag GroupTag) const
{
	if (actorGroups.Contains(GroupTag))
	{
		return actorGroups[GroupTag].Actors;
	}
    
	// Return an empty array if the group doesn't exist
	return TArray<AActor*>();
}

void UOmegaActorSubsystem::SetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag, AActor* Target)
{
	if(Instigator)
	{
		FOmegaActorMeta temp_meta=actors_meta.FindOrAdd(Instigator);
		if(AActor* previous = temp_meta.TaggedTargets.FindOrAdd(Tag))
		{
			OnActorTaggedTargetChange.Broadcast(Instigator,Tag,previous,false);
		}
		OnActorTaggedTargetChange.Broadcast(Instigator,Tag,Target,true);
	}
}

AActor* UOmegaActorSubsystem::GetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag)
{
	if(Instigator)
	{
		if(AActor* out=actors_meta.FindOrAdd(Instigator).TaggedTargets.FindOrAdd(Tag))
		{
			return out;
		}
	}
	return nullptr;
}
