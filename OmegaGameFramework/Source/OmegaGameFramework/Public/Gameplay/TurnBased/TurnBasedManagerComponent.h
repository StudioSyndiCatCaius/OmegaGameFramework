﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "OmegaGameplaySystem.h"
#include "Components/ActorComponent.h"
#include "Gameplay/CombatantComponent.h"
#include "TurnManagerBase.h"
#include "Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h"
#include "TurnBasedManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTurnStart, UCombatantComponent*, Combatant, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTurnEnd, UCombatantComponent*, Combatant, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnFail, FString, Reason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAddedToTurnOrder, UCombatantComponent*, Combatant, int32, Index, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRemovedFromTurnOrder, UCombatantComponent*, Combatant, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnOrderGenerated, UTurnBasedManagerComponent*, Component);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UTurnBasedManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTurnBasedManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	
	///////////////
	///// Turn ////
	//////////////

	//###########################################
	// Turn Manager
	//###########################################
	
	UPROPERTY(EditDefaultsOnly, Category="Turn Manager")
	TSubclassOf<UTurnManagerBase> TurnManagerClass = UTurnManagerBase::StaticClass();

	UFUNCTION(BlueprintCallable, Category="Omega|TurnBased")
	void SetTurnManagerClass(TSubclassOf<UTurnManagerBase> NewClass);
	
	UPROPERTY()
	UTurnManagerBase* TurnManager;

	//Prevents Combatants with these tags from being allowed to have a turn.
	UPROPERTY(EditDefaultsOnly, Category="Turn Manager")
	FGameplayTagContainer BlockCombatantTagsFromTurnOrder;

	//Prevents Combatants with these tags from being registered into the turn order.
	UPROPERTY(EditDefaultsOnly, Category="Turn Manager")
	FGameplayTagContainer BlockCombatantTagsFromRegister;
	
	//###########################################
	// Turn 
	//###########################################
	
	UPROPERTY()
	TArray<UCombatantComponent*> TurnOrder;
	
	UFUNCTION(BlueprintPure, Category="TurnBased")
	TArray<UCombatantComponent*> GetTurnOrder();

	UPROPERTY()
	UCombatantComponent* ActiveTurnMember;
	
	UFUNCTION(BlueprintPure, Category="TurnBased")
	UCombatantComponent* GetActiveTurnMember();

	UFUNCTION(BlueprintPure, Category="TurnBased")
	UCombatantComponent* GetTurnMemberAtIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void AddToTurnOrder(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"), DisplayName="Remove From Turn Order (Combatant)")
	void RemoveFromTurnOrder(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"), DisplayName="Remove From Turn Order (Faction)")
	void RemoveFactionFromTurnOrder(FGameplayTag Faction, FString Flag, FGameplayTagContainer Tags);

	
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	FGameplayTagContainer TriggeredEffectsOnTurnStart;
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	FGameplayTagContainer TriggeredEffectsOnTurnEnd;
	
	
	//###########################################
	// Turn Order
	//###########################################

	UPROPERTY(BlueprintAssignable)
	FOnTurnOrderGenerated OnTurnOrderGenerated;
	
	UFUNCTION(BlueprintCallable, Category="TurnBased")
	TArray<UCombatantComponent*> GenerateTurnOrder();
	
	UPROPERTY(BlueprintAssignable)
	FOnTurnFail OnTurnFail;
	
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	bool NextTurn(bool bGenerateIfEmpty, FString Flag, FGameplayTagContainer Tags, FString& FailReason);

	UFUNCTION()
	void BeginTurn(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void ClearTurnOrder(FString Flag, FGameplayTagContainer Tags);

	//###########################################
	// Tag Events
	//###########################################

	UPROPERTY(EditAnywhere, Category="TagEvents")
	FGameplayTagContainer TagEventsOnTurnBegin;

	UPROPERTY(EditAnywhere, Category="TagEvents")
	FGameplayTagContainer TagEventsOnTurnEnd;

	UFUNCTION(BlueprintCallable, Category="TurnBased|Event")
	void FireEventsOnCombatants(FGameplayTagContainer Events);
	
	UFUNCTION(BlueprintCallable, Category="TurnBased|Event")
	void FireEventsOnFaction(FGameplayTagContainer Events, FGameplayTag Faction);
	
	///////////////
	///// Ability ////
	//////////////
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	TSubclassOf<AOmegaAbility> TurnAbility;

	//Automatically advance to the next turn when the Turn Ability finishes
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	bool bAutoAdvanceTurn = true;

	UFUNCTION(BlueprintCallable, Category="Omega|TurnBased")
	void SetTurnAbilityClass(TSubclassOf<AOmegaAbility> AbilityClass);

	UPROPERTY(EditDefaultsOnly, Category="Turn")
	bool bRepeatTurnOnAbilityCancel;
	
	UPROPERTY(EditDefaultsOnly, Category="Turn", AdvancedDisplay)
	FGameplayTagContainer RepeatedTurnTags;
	UPROPERTY(EditDefaultsOnly, Category="Turn", AdvancedDisplay)
	FGameplayTagContainer NextTurnTags;
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	bool bGenerateTurnOrderIfEmpty = true;
	
	TSubclassOf<AOmegaAbility> Local_GetTurnAbility() const
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

	UPROPERTY()
	AOmegaAbility* LocalTurnAbility;
	UFUNCTION()
	void Local_TurnAbilityFinish(bool Cancelled);
	
	///////////////
	///// Combatants ////
	//////////////
	UPROPERTY()
	TArray<UCombatantComponent*> RegisteredCombatants;
	
	UFUNCTION(BlueprintPure, Category="TurnBased")
	TArray<UCombatantComponent*> GetRegisteredCombatants();

	
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void RegisterCombatant(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);

	//Removes from list of combatants. Also remove form turn order if in.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void UnregisterCombatant(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);

	//Empties all registered combatants from the list
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void ClearRegisteredCombatants(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);

	static bool DoesCombatantUseInterface(const UCombatantComponent* Combatant);
	
	///////////////
	///// Delegates ////
	//////////////

	UPROPERTY(BlueprintAssignable)
	FOnTurnStart OnTurnStart;

	UPROPERTY(BlueprintAssignable)
	FOnTurnEnd OnTurnEnd;

	UPROPERTY(BlueprintAssignable)
	FOnAddedToTurnOrder OnAddedToTurnOrder;

	UPROPERTY(BlueprintAssignable)
	FOnRemovedFromTurnOrder OnRemovedFromTurnOrder;
};


inline bool UTurnBasedManagerComponent::DoesCombatantUseInterface(const UCombatantComponent* Combatant)
{
	if(Combatant)
	{
		return Combatant->GetOwner()->Implements<UActorInterface_TurnOrderCombatant>();
	}
	else
	{
		return false;
	}
}

