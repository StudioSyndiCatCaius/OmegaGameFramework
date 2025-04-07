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
				AOmegaActorProcessor* _new = GetWorld()->SpawnActorDeferred<AOmegaActorProcessor>(c,FTransform());
				_new->FinishSpawning(FTransform());
				active_processors.AddUnique(_new);
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
		for(auto* a : active_processors)
		{
			if(a)
			{
				if(a->GetClass()==Processor)
				{
					a->SetActorRegisteredToProcessor(Actor,true);
				}
				//else
				//{
				//	a->SetActorRegisteredToProcessor(Actor,false);
				//}
				return;
			}
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
