// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TurnBased/TurnBasedManagerComponent.h"

#include "Gameplay/ActorTagEvent/ActorTagEvent.h"


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
	if(!TurnManager->BlockFromTurnOrder(Combatant))
	{
		TurnOrder.Add(Combatant);	// NEEDS TO BE FINISHED!! Must add to appropriate Index
		OnAddedToTurnOrder.Broadcast(Combatant, TurnOrder.Find(Combatant), Flag, Tags);
	
		if(DoesCombatantUseInterface(Combatant))
		{
			IActorInterface_TurnOrderCombatant::Execute_OnAddedToTurnOrder(GetActiveTurnMember()->GetOwner(), this, Flag, Tags);
		}
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

void UTurnBasedManagerComponent::RemoveFactionFromTurnOrder(FGameplayTag Faction, FString Flag,
	FGameplayTagContainer Tags)
{
	for(auto* TempComb : GetRegisteredCombatants())
	{
		if(TempComb && TempComb->GetFactionTag()==Faction)
		{
			RemoveFromTurnOrder(TempComb,Flag,Tags);
		}
	}
}

//Generate TurnOrder
TArray<UCombatantComponent*> UTurnBasedManagerComponent::GenerateTurnOrder()
{
	TurnOrder.Empty();

	//Setup Basic Turn Order
	for(auto* TempComb : GetRegisteredCombatants())
	{
		AddToTurnOrder(TempComb, "",FGameplayTagContainer());
	}
	//TurnOrder = GetRegisteredCombatants();
	
	if(TurnManager)
	{
		// Create a copy of the input array to keep the original intact
		TArray<UCombatantComponent*> TempOrder = TurnOrder;

		// Sort the array using the ShouldCheckedObjectSortFirst function as a comparison
		TempOrder.Sort([&](UCombatantComponent& A, UCombatantComponent& B)
		{
			return TurnManager->ShouldTargetActFirst(&A,&B);
		});

		TurnOrder = TempOrder;
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
		GetActiveTurnMember()->TriggerEffectsWithTags(TriggeredEffectsOnTurnEnd);
		UActorTagEventFunctions::FireTagEventsOnActor(GetActiveTurnMember()->GetOwner(),TagEventsOnTurnEnd);
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
	GetActiveTurnMember()->TriggerEffectsWithTags(TriggeredEffectsOnTurnStart);
	UActorTagEventFunctions::FireTagEventsOnActor(GetActiveTurnMember()->GetOwner(),TagEventsOnTurnBegin);
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

void UTurnBasedManagerComponent::FireEventsOnCombatants(FGameplayTagContainer Events)
{
	for (const auto* TempComb :GetRegisteredCombatants())
	{
		if(TempComb)
		{
			UActorTagEventFunctions::FireTagEventsOnActor(TempComb->GetOwner(),Events);
		}
	}
}

void UTurnBasedManagerComponent::FireEventsOnFaction(FGameplayTagContainer Events, FGameplayTag Faction)
{
	for (auto* TempComb :GetRegisteredCombatants())
	{
		if(TempComb && TempComb->GetFactionTag().MatchesTag(Faction))
		{
			UActorTagEventFunctions::FireTagEventsOnActor(TempComb->GetOwner(),Events);
		}
	}
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
	if(Combatant && !BlockCombatantTagsFromRegister.HasAny(Combatant->GetCombatantTags()))
	{
		RegisteredCombatants.AddUnique(Combatant);
	}
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



