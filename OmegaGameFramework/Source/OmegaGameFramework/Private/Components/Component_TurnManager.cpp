// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Ability.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_TurnBasedManager.h"
#include "Engine/GameInstance.h"

#include "Functions/F_TagEvent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/Subsystem_GameManager.h"


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

	if(!TurnManager)
	{
		TurnManager=NewObject<UTurnManagerBase>(this,UTurnManagerBase::StaticClass());
	}
	if(TurnManager)
	{
		TurnManager->TurnManagerRef=this;
	}
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
	OnRemovedFromTurnOrder.Broadcast(this,Combatant, Flag, Tags);
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
		OnTurnEnd.Broadcast(this,GetActiveTurnMember(), Flag, Tags);
		RemoveFromTurnOrder(GetActiveTurnMember(), Flag, Tags);
//		GetActiveTurnMember()->TriggerEffectsWithTags(TriggeredEffectsOnTurnEnd);
		UActorTagEventFunctions::FireTagEventsOnActor(GetActiveTurnMember()->GetOwner(),TagEventsOnTurnEnd);
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireTaggedGlobalEvent(TagEventsOnTurnEnd_Global,this);
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
	OnTurnStart.Broadcast(this,Combatant, Flag, Tags);
	bool LocalSuccess;
	Combatant->SetAbilityGranted(Local_GetTurnAbility(),true);
	//GetActiveTurnMember()->TriggerEffectsWithTags(TriggeredEffectsOnTurnStart);
	
	// TAG EVENTS
	UActorTagEventFunctions::FireTagEventsOnActor(GetActiveTurnMember()->GetOwner(),TagEventsOnTurnBegin);
	LocalTurnAbility = Combatant->ExecuteAbility(Local_GetTurnAbility(), this,LocalSuccess);
	
	if(LocalSuccess && LocalTurnAbility)
	{
		LocalTurnAbility->OnAbilityFinished.AddDynamic(this, &UTurnBasedManagerComponent::Local_TurnAbilityFinish);
	}
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireTaggedGlobalEvent(TagEventsOnTurnBegin_Global,this);
}

TSubclassOf<AOmegaAbility> UTurnBasedManagerComponent::Local_GetTurnAbility() const
{
	if(TurnAbility)
	{
		return TurnAbility;
	}
	else
	{
		return AOmegaAbility::StaticClass();
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
	else if(bAutoAdvanceTurn) //Try Start Turn
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
		if(TempCom && !TempCom->IsBeingDestroyed())
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

void UTurnBasedManagerComponent::ClearRegisteredCombatants(FString Flag, FGameplayTagContainer Tags)
{
	for(UCombatantComponent* TempCombatant : RegisteredCombatants)
	{
		if(TempCombatant)
		{
			UnregisterCombatant(TempCombatant, Flag, Tags);
		}
	}
}

void UTurnTrackerComponent::L_RunElapse(bool run)
{
	if(run)
	{
		SetTurnsElapsed(Elapse_IncrementValue,true);
	}
}

bool UTurnTrackerComponent::L_usesInterface(const UObject* obj) const
{
	if(obj)
	{
		return obj->GetClass()->ImplementsInterface(UDataInterface_TurnEntity::StaticClass());
	}
	return false;
}

void UTurnTrackerComponent::L_OnTurnStart(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant,
	FString Flag, FGameplayTagContainer Tags)
{
	if(Combatant==linked_combatant)
	{
		if(L_usesInterface(tracker_source))
		{
			IDataInterface_TurnEntity::Execute_OnTurnStart(tracker_source,this,Component,Combatant);
		}
		L_RunElapse(ElapseOn_TurnStart);
	}
}

void UTurnTrackerComponent::L_OnTurnEnd(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant,
	FString Flag, FGameplayTagContainer Tags)
{
	if(Combatant==linked_combatant)
	{
		if(L_usesInterface(tracker_source))
		{
			IDataInterface_TurnEntity::Execute_OnTurnEnd(tracker_source,this,Component,Combatant);
		}
		L_RunElapse(ElapseOn_TurnEnd);
	}
}


void UTurnTrackerComponent::LinkToTurnManager(UTurnBasedManagerComponent* TurnManager, UCombatantComponent* combatant)
{
	if(combatant)
	{
		linked_combatant=combatant;
	}
	if(TurnManager)
	{
		TurnManager->OnTurnStart.AddDynamic(this, &UTurnTrackerComponent::L_OnTurnStart);
		TurnManager->OnTurnEnd.AddDynamic(this, &UTurnTrackerComponent::L_OnTurnEnd);
	}
}

void UTurnTrackerComponent::SetSource(UObject* Source, bool bInitTurns)
{
	if(Source && L_usesInterface(Source))
	{
		tracker_source=Source;
		if(bInitTurns)
		{
			InitTurns(true);
		}
	}
}

void UTurnTrackerComponent::InitTurns(bool AddToCurrent)
{
	SetTurnsElapsed(IDataInterface_TurnEntity::Execute_GetTurns_Init(tracker_source),AddToCurrent);
}

void UTurnTrackerComponent::SetTurnsElapsed(int32 value, bool Added)
{
	if(Added) { TurnsElapsed+=value;}
	else { TurnsElapsed=value; }
	if(L_usesInterface(tracker_source))
	{
		TurnsElapsed=UKismetMathLibrary::Clamp(TurnsElapsed,0,IDataInterface_TurnEntity::Execute_GetTurns_Max(tracker_source));
	}
	OnTurnValueChanged.Broadcast(this,TurnsElapsed);
}
