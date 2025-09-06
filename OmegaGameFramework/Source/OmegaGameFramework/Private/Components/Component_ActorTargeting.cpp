// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_ActorTargeting.h"
#include "Condition/Condition_Actor.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Functions/OmegaFunctions_Common.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Functions/OmegaFunctions_TagEvent.h"
#include "Kismet/GameplayStatics.h"
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

void UActorTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	if(bTargetFromMouseCursor)
	{
		AActor* in_actor=UOmegaGameFrameworkBPLibrary::GetPlayerMouseOverActor(
			UGameplayStatics::GetPlayerController(this,Mouse_PlayerIndex),Mouse_TraceChannel,Mouse_TraceRadius);
		if(GetActiveTarget()!=in_actor)
		{
			SetActiveTarget(in_actor,true);
		}
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UActorTargetingComponent::L_setTagsOnActor(AActor* Actor, TArray<FName> tags, bool bActive)
{
	if(Actor)
	{
		for (FName TempTag : tags)
		{
			UOmegaGameFrameworkBPLibrary::SetActorTagActive(Actor, TempTag,bActive);
		}
	}
}

bool UActorTargetingComponent::SetActorRegistered(AActor* Actor, bool bRegister)
{
	if(Actor)
	{
		FOmegaConditions_Actor con;
		con.Conditions=Conditions_CanRegister;
		if (bRegister && !IsActorRegistered(Actor) && con.CheckConditions(Actor))
		{
			REF_Actors.AddUnique(Actor);
			
			FActorModifiers mod;
			mod.Script=ActorMods_OnRegister;
			mod.ApplyMods(Actor);

			UActorTagEventFunctions::FireTagEventsOnActor(Actor,TagEvents_OnRegister);
			
			OnActorRegisteredUpdate.Broadcast(Actor,true);
			return true;
		}
		if(!bRegister && IsActorRegistered(Actor))
		{
			REF_Actors.Remove(Actor);
			
			FActorModifiers mod;
			mod.Script=ActorMods_OnUnregister;
			mod.ApplyMods(Actor);
			
			UActorTagEventFunctions::FireTagEventsOnActor(Actor,TagEvents_OnUnregister);
			
			OnActorRegisteredUpdate.Broadcast(Actor,false);
			
			// Cleat if Active Target
			if(GetActiveTarget() && GetActiveTarget()==Actor)
			{
				SetActiveTarget(nullptr,false);
			}
			return true;
		}
	}
	return false;
}

void UActorTargetingComponent::SetActorRegistered_List(TArray<AActor*> Actors, bool bRegister, bool bEmptyFirst)
{
	if(bEmptyFirst)
	{
		ClearRegisteredTargets();
	}
	for (auto* TempActor : Actors)
	{
		SetActorRegistered(TempActor,bRegister);
	}
}

void UActorTargetingComponent::ClearRegisteredTargets()
{
	for(auto* TempTarget : GetRegisteredTargets())
	{
		SetActorRegistered(TempTarget,false);
	}
}

bool UActorTargetingComponent::IsActorRegistered(AActor* Actor) const
{
	if(Actor && REF_Actors.Contains(Actor))
	{
		return true;
	}
	return false;
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
		FActorModifiers mod;
		mod.Script=ActorMods_OnTargeted;
		mod.ApplyMods(Actor);

		UActorTagEventFunctions::FireTagEventsOnActor(Actor,TagEvents_OnTargeted);
		
		OnActorTargetUpdate.Broadcast(REF_TargetActor,false);
		REF_TargetActor=nullptr;
	}
	if(Actor)
	{
		if(bAutoRegisterActor && !GetRegisteredTargets().Contains(Actor))
		{
			SetActorRegistered(Actor,true);
		}
		
		REF_TargetActor=Actor;
		
		FActorModifiers mod;
		mod.Script=ActorMods_OnTargeted;
		mod.ApplyMods(Actor);

		UActorTagEventFunctions::FireTagEventsOnActor(Actor,TagEvents_OnUntargeted);
		
		OnActorTargetUpdate.Broadcast(Actor,true);
		if(Sound_ChangeTarget)
		{
			UGameplayStatics::PlaySound2D(this,Sound_ChangeTarget);
		}
	}
}

AActor* UActorTargetingComponent::GetActiveTarget() const
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
