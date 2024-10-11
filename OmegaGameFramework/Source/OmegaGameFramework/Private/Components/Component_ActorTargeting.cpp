// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_ActorTargeting.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Functions/OmegaFunctions_TagEvent.h"
#include "Kismet/KismetMathLibrary.h"

bool is_valid_child(AActor* actor_ref, TArray<TSubclassOf<AActor>> classes_ref)
{
	for(auto TempClass : classes_ref)
	{
		if(actor_ref->GetClass()->IsChildOf(TempClass))
		{
			return true;
		}
	}
	return false;
}

bool is_valid_tag(AActor* actor_ref, TArray<FName> tags_ref)
{
	for(FName TempClass : tags_ref)
	{
		if(actor_ref->ActorHasTag(TempClass))
		{
			return true;
		}
	}
	return false;
}

bool UActorTargetingComponent::SetActorRegistered(AActor* Actor, bool bRegister)
{
	if(Actor)
	{
		if (bRegister
			&& !GetRegisteredTargets().Contains(Actor)
			&& (is_valid_child(Actor,IncludedClasses) || IncludedClasses.IsEmpty())
			&& !is_valid_child(Actor,ExcludedClasses)
			&& is_valid_tag(Actor,IncludedTags) || IncludedTags.IsEmpty()
			&& !is_valid_tag(Actor,ExcludedTags)
			)
		{
			REF_Actors.AddUnique(Actor);
			OnActorRegisteredUpdate.Broadcast(Actor,true);
			UActorTagEventFunctions::FireTagEventsOnActor(Actor,EventsOnRegister);
			local_setTagsOnActor(Actor,TagsOnRegister,true);
			return true;
		}
		if(!bRegister && GetRegisteredTargets().Contains(Actor))
		{
			REF_Actors.Remove(Actor);
			OnActorRegisteredUpdate.Broadcast(Actor,false);
			UActorTagEventFunctions::FireTagEventsOnActor(Actor,EventsOnUnregister);
			local_setTagsOnActor(Actor,TagsOnRegister,false);
			return true;
		}
	}
	return false;
}

void UActorTargetingComponent::SetActorRegistered_List(TArray<AActor*> Actors, bool bEmptyFirst)
{
	if(bEmptyFirst)
	{
		ClearRegisteredTargets();
	}
	for (auto* TempActor : Actors)
	{
		SetActorRegistered(TempActor,true);
	}
}

void UActorTargetingComponent::ClearRegisteredTargets()
{
	for(auto* TempTarget : GetRegisteredTargets())
	{
		SetActorRegistered(TempTarget,false);
	}
}

TArray<AActor*> UActorTargetingComponent::GetRegisteredTargets()
{
	TArray<AActor*> out;
	for(auto* TempActor : REF_Actors) { if(TempActor) { out.AddUnique(TempActor); }}
	REF_Actors=out;
	return REF_Actors;
}

void UActorTargetingComponent::SetActiveTarget(AActor* Actor, bool bAutoRegisterActor)
{
	if(REF_TargetActor)
	{
		UActorTagEventFunctions::FireTagEventsOnActor(REF_TargetActor,EventsOnUntarget);
		local_setTagsOnActor(Actor,TagsOnTarget,false);
		OnActorTargetUpdate.Broadcast(REF_TargetActor,false);
		REF_TargetActor=nullptr;
	}
	if(Actor)
	{
		if(bAutoRegisterActor && !GetRegisteredTargets().Contains(Actor))
		{
			SetActorRegistered(Actor,true);
		}
		UActorTagEventFunctions::FireTagEventsOnActor(Actor,EventsOnTarget);
		local_setTagsOnActor(Actor,TagsOnTarget,true);
		REF_TargetActor=Actor;
		OnActorTargetUpdate.Broadcast(Actor,true);
	}
}

AActor* UActorTargetingComponent::GetActiveTarget()
{
	if(REF_TargetActor)
	{
		return REF_TargetActor;
	}
	return nullptr;
}

AActor* UActorTargetingComponent::CycleTarget(int32 CycleAmount)
{
	int32 start_index=0;
	if(GetActiveTarget() && GetRegisteredTargets().Contains(GetActiveTarget()))
	{
		start_index= GetRegisteredTargets().Find(GetActiveTarget());
	}
	int32 new_index = UKismetMathLibrary::Wrap(start_index+CycleAmount,0,GetRegisteredTargets().Num()-1);
	if(GetRegisteredTargets().IsValidIndex(new_index))
	{
		SetActiveTarget(GetRegisteredTargets()[start_index],true);
	}
	return GetActiveTarget();
}
