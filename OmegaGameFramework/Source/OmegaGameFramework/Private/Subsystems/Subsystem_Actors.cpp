// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/Subsystem_Actors.h"

#include "OmegaSettings.h"
#include "Components/Component_ActorIdentity.h"
#include "OmegaSettings_Gameplay.h"
#include "Components/Component_ActorConfig.h"
#include "Misc/OmegaUtils_Methods.h"

void UOmegaActorSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
}

TMap<FName, FString>& UOmegaActorSubsystem::GetA_PMap(AActor* a)
{
	return actors_meta.FindOrAdd(a).boundParam;
}

FString UOmegaActorSubsystem::GetAParam_string(AActor* a, FName key, FString def)
{
	
	return OGF_SoftParam::Conv_string(GetA_PMap(a),key,def);
}

float UOmegaActorSubsystem::GetAParam_float(AActor* a, FName key, float def)
{
	return OGF_SoftParam::Conv_float(GetA_PMap(a),key,def);
}

int32 UOmegaActorSubsystem::GetAParam_int(AActor* a, FName key, int32 def)
{
	return OGF_SoftParam::Conv_int(GetA_PMap(a),key,def);
}

bool UOmegaActorSubsystem::GetAParam_bool(AActor* a, FName key, bool def)
{
	return OGF_SoftParam::Conv_bool(GetA_PMap(a),key,def);
}

void UOmegaActorSubsystem::SetAParam_string(AActor* a, FName key, FString def)
{
	if(a) { OGF_SoftParam::set_string(GetA_PMap(a),key,def); }
}

void UOmegaActorSubsystem::SetAParam_float(AActor* a, FName key, float def)
{
	if(a) { OGF_SoftParam::set_float(GetA_PMap(a),key,def); }
}

void UOmegaActorSubsystem::SetAParam_int(AActor* a, FName key, int32 def)
{
	if(a) { OGF_SoftParam::set_int(GetA_PMap(a),key,def); }
}

void UOmegaActorSubsystem::SetAParam_bool(AActor* a, FName key, bool def)
{
	if(a) { OGF_SoftParam::set_bool(GetA_PMap(a),key,def); }
}


void UOmegaActorSubsystem::OnCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void UOmegaActorSubsystem::OnCompEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void UOmegaActorSubsystem::LinkComponentToTagTarget(UPrimitiveComponent* Component, AActor* Actor, FGameplayTag Tag, bool bLinked)
{
	if (Component && Actor)
	{
		if (bLinked)
		{
			Component->OnComponentBeginOverlap.AddDynamic(this, &UOmegaActorSubsystem::OnCompBeginOverlap);
			Component->OnComponentEndOverlap.AddDynamic(this, &UOmegaActorSubsystem::OnCompEndOverlap);	
		}
		else
		{
			Component->OnComponentBeginOverlap.RemoveDynamic(this, &UOmegaActorSubsystem::OnCompBeginOverlap);
			Component->OnComponentEndOverlap.RemoveDynamic(this, &UOmegaActorSubsystem::OnCompEndOverlap);	
		}
		
	}
}


void UOmegaActorSubsystem::local_RegisterActorIdComp(UActorIdentityComponent* Component, bool bIsRegister)
{
	if(Component)
	{
		if(bIsRegister && !REF_ActorIdComps.Contains(Component))
		{
			REF_ActorIdComps.Add(Component);
			OnActorIdentityRegistered.Broadcast(Component->GetOwner(),Component,true);
		}
		if(!bIsRegister && REF_ActorIdComps.Contains(Component))
		{
			REF_ActorIdComps.Remove(Component);
			OnActorIdentityRegistered.Broadcast(Component->GetOwner(),Component,false);
		}
	}
}

TArray<UActorIdentityComponent*> UOmegaActorSubsystem::GetAllActorIdentityComponents()
{
	TArray<UActorIdentityComponent*> out;
	for(auto* i : REF_ActorIdComps)
	{
		if(i) {out.Add(i);}
	}
	return out;
}

AActor* UOmegaActorSubsystem::GetFirstActorIfIdentity(UPrimaryDataAsset* Identity,TSubclassOf<AActor> FilterClass)
{
	if(Identity)
	{
		for(auto* a : GetAllActorIdentityComponents())
		{
			if(a && a->GetIdentitySourceAsset()==Identity && (!FilterClass || a->GetClass()->IsChildOf(FilterClass)))
			{
				return a->GetOwner();
			}
		}
	}
	return nullptr;
}

bool UOmegaActorSubsystem::CanInteract(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if(TargetActor && Instigator)
	{
		if(UActorConfigComponent* _ConfigComp=Cast<UActorConfigComponent>(TargetActor->GetComponentByClass(UActorConfigComponent::StaticClass())))
		{
			if(UOmegaActorConfig* _cfg=_ConfigComp->DefaultConfig)
			{
				if(!_cfg->CanInteract_Instigator.CheckConditions(Instigator) || !_cfg->CanInteract_Target.CheckConditions(TargetActor))
				{
					return false;
				}
			}
		}
		if(TargetActor->GetClass()->ImplementsInterface(UActorInterface_Interactable::StaticClass())
			&& IActorInterface_Interactable::Execute_IsInteractionBlocked(TargetActor,Instigator,Tag,Context))
		{
			return false;
		}
		return true;
	}
	return false;
}


void UOmegaActorSubsystem::PerformInteraction(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, FOmegaCommonMeta Context)
{
	if(Instigator && TargetActor)
	{
		if(CanInteract(Instigator,TargetActor,Tag,Context))
		{
			if(TargetActor->GetClass()->ImplementsInterface(UActorInterface_Interactable::StaticClass()))
			{
				IActorInterface_Interactable::Execute_OnInteraction(TargetActor,Instigator,Tag,Context);
			}
			for (UActorComponent* ac : TargetActor->GetComponentsByInterface(UActorInterface_Interactable::StaticClass()))
			{
				if (ac)
				{
					IActorInterface_Interactable::Execute_OnInteraction(ac,Instigator,Tag,Context);
				}
			}
			OnActorInteraction.Broadcast(Instigator,TargetActor,Tag,Context);
		}
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
		OnActorGroupChange.Broadcast(Actor,GroupTag,registered);
	}
	else
	{
		// Remove the actor from the group if the group exists
		if (actorGroups.Contains(GroupTag))
		{
			actorGroups[GroupTag].Actors.Remove(Actor);
			OnActorGroupChange.Broadcast(Actor,GroupTag,registered);
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
			temp_meta.TaggedTargets.Add(Tag,nullptr);
		}
		if(Target)
		{
			OnActorTaggedTargetChange.Broadcast(Instigator,Tag,Target,true);
			temp_meta.TaggedTargets.Add(Tag,Target);
		}
		actors_meta.Add(Instigator,temp_meta);
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
