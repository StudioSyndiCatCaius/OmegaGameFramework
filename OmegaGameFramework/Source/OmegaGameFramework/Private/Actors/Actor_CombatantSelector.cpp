// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_CombatantSelector.h"


void AOmegaCombatantSelector::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::Destroyed )
	{
		OnSelectionFinished.Broadcast(GetRegisteredCombatants(),outputNotify);
	}
	Super::EndPlay(EndPlayReason);
	
}

void AOmegaCombatantSelector::SetCombatantRegistered(UCombatantComponent* Combatant, bool bRegister)
{
	if(Combatant)
	{
		if(bRegister)
		{
			if(!registered_combatants.Contains(Combatant))
			{
				registered_combatants.AddUnique(Combatant);	
			}
		}
		else
		{
			if(registered_combatants.Contains(Combatant))
			{
				registered_combatants.Remove(Combatant);	
			}
		}
	}
}

TArray<UCombatantComponent*> AOmegaCombatantSelector::GetRegisteredCombatants()
{
	TArray<UCombatantComponent*> out;
	for (auto* temp_combatant : registered_combatants)
	{
		if(temp_combatant)
		{
			out.Add(temp_combatant);
		}
	}
	return out;
}

void AOmegaCombatantSelector::SetCombatantRegistered_List(TArray<UCombatantComponent*> Combatants, bool bRegister,
	bool bClearListFirst)
{
	if(bClearListFirst && bRegister)
	{
		UnregisterAllCombatants();
	}
	for (auto* temp_combatant : Combatants)
	{
		if(temp_combatant)
		{
			SetCombatantRegistered(temp_combatant,bRegister);
		}
	}
}

void AOmegaCombatantSelector::UnregisterAllCombatants()
{
	for (auto* temp_combatant : GetRegisteredCombatants())
	{
		if(temp_combatant)
		{
			SetCombatantRegistered(temp_combatant,false);
		}
	}
}

void AOmegaCombatantSelector::EndSelection(FName FinishNotify)
{
	bConfirming=true;
	outputNotify=FinishNotify;
	K2_DestroyActor();	
}

void UAsyncAction_CombatantSelector::local_Finish(TArray<UCombatantComponent*> Targets, FName FinishNotify)
{
	OnFinished.Broadcast(Targets,FinishNotify);
	SetReadyToDestroy();
}

void UAsyncAction_CombatantSelector::Activate()
{
	if(local_worldContext)
	{
		ref_actor=local_worldContext->GetWorld()->SpawnActorDeferred<AOmegaCombatantSelector>(local_Class,local_transform);
		if(ref_actor)
		{
			ref_actor->instigator_combatant=local_instigator;
			ref_actor->OnSelectionFinished.AddDynamic(this,&UAsyncAction_CombatantSelector::local_Finish);
			ref_actor->FinishSpawning(local_transform);
			return;
		}
	}
	SetReadyToDestroy();
}

UAsyncAction_CombatantSelector* UAsyncAction_CombatantSelector::AsyncSelectCombatant(UObject* WorldContextObject,
                                                                                     TSubclassOf<AOmegaCombatantSelector> Class, const FTransform Transform, UCombatantComponent* instigator)
{
	UAsyncAction_CombatantSelector* NewNode = NewObject<UAsyncAction_CombatantSelector>();
	NewNode->local_instigator = instigator;
	if(!Class)
	{
		NewNode->local_Class=AOmegaCombatantSelector::StaticClass();
	}
	else
	{
		NewNode->local_Class = Class;
	}
	NewNode->local_transform=Transform;
	NewNode->local_worldContext = WorldContextObject;
	return NewNode;
}
