// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Component_TurnBasedManager.generated.h"

class UCombatantComponent;
class AOmegaAbility;
class AOmegaGameplaySystem;

// =========================================
// Turn Manager 
// =========================================

UCLASS(Blueprintable, BlueprintType, EditInlineNew,CollapseCategories,Abstract)
class OMEGAGAMEFRAMEWORK_API UTurnManagerBase : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
	UTurnBasedManagerComponent* TurnManagerRef;
	
	UFUNCTION(BlueprintPure, Category="TurnManager")
	UTurnBasedManagerComponent* GetOwningTurnManager() const
	{
		return TurnManagerRef;
	}
	
	UFUNCTION(BlueprintImplementableEvent)
	bool ShouldTargetActFirst(UCombatantComponent* TargetCombatant, UCombatantComponent* ComparedCombatant);

	UFUNCTION(BlueprintImplementableEvent)
	bool FailBeingTurn(FString& FailReason);

	UFUNCTION(BlueprintImplementableEvent)
	bool BlockFromTurnOrder(UCombatantComponent* Combatant);
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnTurnDelegate, UTurnBasedManagerComponent*, Component, UCombatantComponent*, Combatant, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnFail, FString, Reason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAddedToTurnOrder, UCombatantComponent*, Combatant, int32, Index, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnComponentDelegate, UTurnBasedManagerComponent*, Component);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UTurnBasedManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTurnBasedManagerComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable) FOnTurnDelegate OnTurnStart;
	UPROPERTY(BlueprintAssignable) FOnTurnDelegate OnTurnEnd;
	UPROPERTY(BlueprintAssignable) FOnAddedToTurnOrder OnAddedToTurnOrder;
	UPROPERTY(BlueprintAssignable) FOnTurnDelegate OnRemovedFromTurnOrder;
	
	///////////////
	///// Turn ////
	//////////////

	//###########################################
	// Turn Manager
	//###########################################

	UFUNCTION()
	void SetTurnManagerClass(TSubclassOf<UTurnManagerBase> NewClass);
	
	UPROPERTY(EditAnywhere,Instanced, Category="Turn Manager")
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
	FOnTurnComponentDelegate OnTurnOrderGenerated;
	
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

	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Turn Member Events - On Turn Begin")
	FGameplayTagContainer TagEventsOnTurnBegin;
	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Turn Member Events - On Turn End")
	FGameplayTagContainer TagEventsOnTurnEnd;

	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Global Event - On Turn Begin")
	FGameplayTag TagEventsOnTurnBegin_Global;
	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Global Event - On Turn End")
	FGameplayTag TagEventsOnTurnEnd_Global;
	
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
	
	TSubclassOf<AOmegaAbility> Local_GetTurnAbility() const;

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
	void ClearRegisteredCombatants(FString Flag, FGameplayTagContainer Tags);

	static bool DoesCombatantUseInterface(const UCombatantComponent* Combatant);
	
	///////////////
	///// Delegates ////
	//////////////

};


inline bool UTurnBasedManagerComponent::DoesCombatantUseInterface(const UCombatantComponent* Combatant)
{
	if(Combatant)
	{
		return false; // this needs to be updated or removed
	}
	else
	{
		return false;
	}
}

// =========================================
// Turn Actor Interface
// =========================================

UINTERFACE()
class UActorInterface_TurnOrderCombatant : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IActorInterface_TurnOrderCombatant
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased")
	void OnTurnBegin(UTurnBasedManagerComponent* TurnManager);

	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased")
	void OnTurnEnd(UTurnBasedManagerComponent* TurnManager);

	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void OnAddedToTurnOrder(UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void OnRemovedFromTurnOrder(UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTurnTrackerDelegate,UTurnTrackerComponent*, Component, int32, TurnsElapsed);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UTurnTrackerComponent : public UActorComponent
{
	GENERATED_BODY()

	void L_RunElapse(bool run);
	
	bool L_usesInterface(const UObject* obj) const;

	UFUNCTION()
	void L_OnTurnStart(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);
	UFUNCTION()
	void L_OnTurnEnd(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);

	UPROPERTY() UObject* tracker_source;
	UPROPERTY() int32 TurnsElapsed;
	UPROPERTY() UCombatantComponent* linked_combatant;
	
public:
	UPROPERTY(BlueprintAssignable) FTurnTrackerDelegate OnTurnValueChanged;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Turn Tracker")
	bool ElapseOn_TurnStart=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Turn Tracker")
	bool ElapseOn_TurnEnd=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Turn Tracker")
	int32 Elapse_IncrementValue=-1;
	
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void LinkToTurnManager(UTurnBasedManagerComponent* TurnManager, UCombatantComponent* combatant);
	
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void SetSource(UObject* Source, bool bInitTurns);
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void InitTurns(bool AddToCurrent);
		
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void SetTurnsElapsed(int32 value, bool Added);

	UFUNCTION(BlueprintPure,Category="Turn Tracker")
	int32 GetTurnsElapsed() const { return TurnsElapsed; }
};

UINTERFACE(MinimalAPI)
class UDataInterface_TurnEntity : public UInterface
{
	GENERATED_BODY()
};

class OMEGAGAMEFRAMEWORK_API IDataInterface_TurnEntity
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - On Turn Start")
	void OnTurnStart(UTurnTrackerComponent* EntityComponent, UTurnBasedManagerComponent* TurnComponent, UCombatantComponent* Member);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - On Turn End")
	void OnTurnEnd(UTurnTrackerComponent* EntityComponent, UTurnBasedManagerComponent* TurnComponent, UCombatantComponent* Member);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - Get Turns Init")
	int32 GetTurns_Init();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - Get Turns Init")
	int32 GetTurns_Max();
};
