// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Combatant/CombatantGroupComponent.h"

#include "JsonObjectWrapper.h"

// Sets default values for this component's properties
UCombatantGroupComponent::UCombatantGroupComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatantGroupComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatantGroupComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UCombatantGroupComponent::IsGroupFull()
{
	return MaxGroupMembers>0 && GetCombatants().Num() >= MaxGroupMembers;
}

bool UCombatantGroupComponent::SetCombatantInGroup(UCombatantComponent* Combatant, bool InGroup)
{
	if(IsGroupFull())
	{
		return false;
	}
	if(Combatant)
	{
		if(InGroup)
		{
			Local_CombatantList.AddUnique(Combatant);
			
		}
		else
		{
			Local_CombatantList.Remove(Combatant);
		}
		
		OnCombatantSetInGroup.Broadcast(Combatant, InGroup);
	}
	return true;
}

TArray<UCombatantComponent*> UCombatantGroupComponent::GetCombatants()
{
	TArray<UCombatantComponent*> OutList;
	for(auto* TempCombatant : Local_CombatantList)
	{
		if(TempCombatant)
		{
			OutList.AddUnique(TempCombatant);
		}
	}
	return OutList;
}
