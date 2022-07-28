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
	TurnManager->TurnManagerRef = this;
	// ...
	
}


// Called every frame
void UTurnBasedManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//Get Active Member
UCombatantComponent* UTurnBasedManagerComponent::GetActiveTurnMember()
{
	if(TurnOrder.IsValidIndex(0))
	{
		if(TurnOrder[0] != nullptr)
		{
			return TurnOrder[0];
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}

//Add to Turn Order
void UTurnBasedManagerComponent::AddToTurnOrder(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags)
{

	TurnOrder.Add(Combatant);	// NEEDS TO BE FINISHED!! Must add to appropriate Index
	OnAddedToTurnOrder.Broadcast(Combatant, TurnOrder.Find(Combatant), Flag, Tags);
	
	if(DoesCombatantUseInterface(Combatant))
	{
		IActorInterface_TurnOrderCombatant::Execute_OnAddedToTurnOrder(GetActiveTurnMember()->GetOwner(), this, Flag, Tags);
	}

}

//Remove From Turn Order
void UTurnBasedManagerComponent::RemoveFromTurnOrder(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags)
{
	if(!Combatant)
	{
		return;
	}
	TurnOrder.Remove(Combatant);
	OnRemovedFromTurnOrder.Broadcast(Combatant, Flag, Tags);
	if(DoesCombatantUseInterface(Combatant))
	{
		IActorInterface_TurnOrderCombatant::Execute_OnRemovedFromTurnOrder(Combatant->GetOwner(), this, Flag, Tags);
	}
}

//Generate TurnOrder
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

// NEXT TURN
bool UTurnBasedManagerComponent::NextTurn(bool bGenerateIfEmpty, FString Flag, FGameplayTagContainer Tags, FString& FailReason)
{
	//Remove current member
	if(GetActiveTurnMember() != nullptr)
	{
		OnTurnEnd.Broadcast(GetActiveTurnMember(), Flag, Tags);
		RemoveFromTurnOrder(GetActiveTurnMember(), Flag, Tags);
        
        /*if(GetActiveTurnMember()) // If new active member valid
        {
            //Function on Combatant Actor
            if(DoesCombatantUseInterface(GetActiveTurnMember()))
            {
                IActorInterface_TurnOrderCombatant::Execute_OnTurnEnd(GetActiveTurnMember()->GetOwner(), this);
            }
        }*/
		
	}
	
	//If Empty and should regenerator
	if(!TurnOrder.IsValidIndex(0) && bGenerateIfEmpty)
	{
		GenerateTurnOrder();
	}

	if(GetActiveTurnMember() != nullptr)
	{
		FString LocalFailReason;
		if(TurnManager->FailBeingTurn(FailReason))
		{
			return false;
		}
		FailReason = "";
		OnTurnStart.Broadcast(GetActiveTurnMember(), Flag, Tags);

		
		//Function on Combatant Actor
		if(DoesCombatantUseInterface(GetActiveTurnMember()))
		{
			IActorInterface_TurnOrderCombatant::Execute_OnTurnBegin(GetActiveTurnMember()->GetOwner(), this);
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

void UTurnBasedManagerComponent::ClearTurnOrder(FString Flag, FGameplayTagContainer Tags)
{
	for(UCombatantComponent* TempCombatant : TurnOrder)
	{
		RemoveFromTurnOrder(TempCombatant, Flag, Tags);
	}
	TurnOrder.Empty();
}

// REGISTER
void UTurnBasedManagerComponent::RegisterCombatant(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags)
{
	RegisteredCombatants.AddUnique(Combatant);
}


// UNREGISTER
void UTurnBasedManagerComponent::UnregisterCombatant(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags)
{
	RegisteredCombatants.Remove(Combatant);
	if(TurnOrder.Contains(Combatant))
	{
		TurnOrder.Remove(Combatant);
	}
}

void UTurnBasedManagerComponent::ClearRegisteredCombatants(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags)
{
	for(UCombatantComponent* TempCombatant : RegisteredCombatants)
	{
		if(TempCombatant)
		{
			UnregisterCombatant(TempCombatant, Flag, Tags);
		}
	}
}



