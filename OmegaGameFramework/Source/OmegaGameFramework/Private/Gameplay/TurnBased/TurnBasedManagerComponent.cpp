// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TurnBased/TurnBasedManagerComponent.h"


// Sets default values for this component's properties
UTurnBasedManagerComponent::UTurnBasedManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTurnBasedManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	TurnManager = NewObject<UTurnManagerBase>(this, TurnManagerClass);
	// ...
	
}


// Called every frame
void UTurnBasedManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UCombatantComponent* UTurnBasedManagerComponent::GetActiveTurnMember()
{
	if(TurnOrder[0])
	{
		return TurnOrder[0];
	}
	else
	{
		return nullptr;
	}
}

void UTurnBasedManagerComponent::AddToTurnOrder(UCombatantComponent* Combatant, int32 Index)
{

	TurnOrder.Add(Combatant);	// NEEDS TO BE FINISHED!! Must add to appropriate Index

	OnAddedToTurnOrder.Broadcast(Combatant, TurnOrder.Find(Combatant));

}

void UTurnBasedManagerComponent::RemoveFromTurnOrder(UCombatantComponent* Combatant)
{

	TurnOrder.Remove(Combatant);
	OnRemovedFromTurnOrder.Broadcast(Combatant);

}

TArray<UCombatantComponent*> UTurnBasedManagerComponent::GenerateTurnOrder()
{
	TurnOrder.Empty();
	
	for(UCombatantComponent* TargetCombatant : RegisteredCombatants)
	{
		const int32 TargetIndex = RegisteredCombatants.Find(TargetCombatant);
		TurnOrder.Add(TargetCombatant);
		bool bComparing = true;

		TArray<UCombatantComponent*> FlippedTurnOrder = TurnOrder;
		Algo::Reverse(FlippedTurnOrder);
		
		for(UCombatantComponent* ComparedCombatant : FlippedTurnOrder)
		{
			
			if(bComparing && ComparedCombatant != TargetCombatant)		// If still comparing and NOT comparing self
			{
				const int32 ComparedIndex = TurnOrder.Find(ComparedCombatant);
				
				if(TurnManager->ShouldTargetActFirst(TargetCombatant, ComparedCombatant)) //Checks if Target should go first.
				{
					TurnOrder.Swap(ComparedIndex, TargetIndex);
				}
				else
				{
					bComparing = false;
				}
			}
		}
	}
	return TurnOrder;
}

void UTurnBasedManagerComponent::NextTurn()
{
	if(GetActiveTurnMember())
	{
		OnTurnEnd.Broadcast(GetActiveTurnMember());
		RemoveFromTurnOrder(GetActiveTurnMember());
	}

	if(!TurnOrder.IsValidIndex(0))
	{
		GenerateTurnOrder();
	}

	if(GetActiveTurnMember())
	{
		OnTurnStart.Broadcast(GetActiveTurnMember());
	}
}

void UTurnBasedManagerComponent::RegisterCombatant(UCombatantComponent* Combatant)
{
	RegisteredCombatants.AddUnique(Combatant);
}

void UTurnBasedManagerComponent::UnregisterCombatant(UCombatantComponent* Combatant)
{
	RegisteredCombatants.Remove(Combatant);
}



