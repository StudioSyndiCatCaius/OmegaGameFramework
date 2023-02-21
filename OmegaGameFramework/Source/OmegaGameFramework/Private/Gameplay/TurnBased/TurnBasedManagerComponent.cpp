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

	SetTurnManagerClass(TurnManagerClass);
	
	
	
}


// Called every frame
void UTurnBasedManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTurnBasedManagerComponent::SetTurnManagerClass(TSubclassOf<UTurnManagerBase> NewClass)
{
	if(NewClass)
	{
		TurnManager = NewObject<UTurnManagerBase>(this, NewClass);
		TurnManager->TurnManagerRef = this;
	}
}

void UTurnBasedManagerComponent::SetTurnAbilityClass(TSubclassOf<AOmegaAbility> AbilityClass)
{
	if(AbilityClass)
	{
		TurnAbility = AbilityClass;
	}
}

TArray<UCombatantComponent*> UTurnBasedManagerComponent::GetTurnOrder()
{
	TArray<UCombatantComponent*> OutCombs;
	for(auto* TempComb : TurnOrder)
	{
		if(TempComb)
		{
			OutCombs.Add(TempComb);
		}
	}
	return OutCombs;
}

//Get Active Member
UCombatantComponent* UTurnBasedManagerComponent::GetActiveTurnMember()
{
	if(ActiveTurnMember)
	{
		return ActiveTurnMember;
	}
	return nullptr;
}

UCombatantComponent* UTurnBasedManagerComponent::GetTurnMemberAtIndex(int32 Index)
{
	if(GetTurnOrder().IsValidIndex(Index))
	{
		return GetTurnOrder()[Index];
	}
	return nullptr;
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
	OnTurnOrderGenerated.Broadcast(this);
	return TurnOrder;
}


// NEXT TURN
bool UTurnBasedManagerComponent::NextTurn(bool bGenerateIfEmpty, FString Flag, FGameplayTagContainer Tags, FString& FailReason)
{
	//END CURRENT TURN
	if(GetActiveTurnMember() != nullptr)		//If active turn member is valid
	{
		OnTurnEnd.Broadcast(GetActiveTurnMember(), Flag, Tags);
		RemoveFromTurnOrder(GetActiveTurnMember(), Flag, Tags);
	}
	
	//If Empty and should regenerator
	if(!GetTurnMemberAtIndex(0) && bGenerateIfEmpty)
	{
		GenerateTurnOrder();
	}

	//sELECT Member for turn
	
	if(GetTurnMemberAtIndex(0))
	{
		FString LocalFailReason;
		if(TurnManager->FailBeingTurn(FailReason))	//When Failed to Start Turn
		{
			OnTurnFail.Broadcast(FailReason);
			return false;
		}
		FailReason = "";

		ActiveTurnMember = GetTurnMemberAtIndex(0);
		BeginTurn(GetActiveTurnMember(), Flag, Tags);
		
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

void UTurnBasedManagerComponent::BeginTurn(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags)
{
	OnTurnStart.Broadcast(Combatant, Flag, Tags);
	bool LocalSuccess;
	Combatant->GrantAbility(Local_GetTurnAbility());
	LocalTurnAbility = Combatant->ExecuteAbility(Local_GetTurnAbility(), this,LocalSuccess);
	if(LocalSuccess && LocalTurnAbility)
	{
		LocalTurnAbility->OnAbilityFinished.AddDynamic(this, &UTurnBasedManagerComponent::Local_TurnAbilityFinish);
	}
}

void UTurnBasedManagerComponent::Local_TurnAbilityFinish(bool Cancelled)
{
	if(LocalTurnAbility)
	{
		LocalTurnAbility->OnAbilityFinished.RemoveDynamic(this, &UTurnBasedManagerComponent::Local_TurnAbilityFinish);
	}
	

	///Should Repeat Turn?
	if(bRepeatTurnOnAbilityCancel && Cancelled)			
	{
		BeginTurn(GetActiveTurnMember(), "Repeat", RepeatedTurnTags);
	}
	else //Try Start Turn
	{
		
		FString TurnFailReason;
		NextTurn(bGenerateTurnOrderIfEmpty, "NextTurn", NextTurnTags, TurnFailReason);
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


TArray<UCombatantComponent*> UTurnBasedManagerComponent::GetRegisteredCombatants()
{
	TArray<UCombatantComponent*> OutComs;
	for(auto* TempCom : RegisteredCombatants)
	{
		if(TempCom)
		{
			OutComs.Add(TempCom);
		}
	}
	return OutComs;
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



