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

// Abstract policy object that controls turn order priority and blocking rules for a UTurnBasedManagerComponent.
UCLASS(Blueprintable, BlueprintType, EditInlineNew,CollapseCategories,Abstract)
class OMEGAGAMEFRAMEWORK_API UTurnManagerBase : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UTurnBasedManagerComponent* TurnManagerRef;

	// Returns the turn manager that owns this policy object.
	UFUNCTION(BlueprintPure, Category="TurnManager")
	UTurnBasedManagerComponent* GetOwningTurnManager() const
	{
		return TurnManagerRef;
	}

	// Return true if TargetCombatant should act before ComparedCombatant in the turn order.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega")
	bool ShouldTargetActFirst(UCombatantComponent* TargetCombatant, UCombatantComponent* ComparedCombatant);

	// Return true (with a reason) to block the current turn from starting.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega")
	bool FailBeingTurn(FString& FailReason);

	// Return true to prevent Combatant from ever appearing in the turn order.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega")
	bool BlockFromTurnOrder(UCombatantComponent* Combatant);
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTurnDelegate, UTurnBasedManagerComponent*, Component, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnFail, FString, Reason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddedToTurnOrder, UCombatantComponent*, Combatant, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnComponentDelegate, UTurnBasedManagerComponent*, Component);

DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FQuery_CombatantCompare, UCombatantComponent*, Check,UCombatantComponent*, Against);
DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FQuery_CombatantCheck, UCombatantComponent*, Combatant);

// Manages a turn-based combat flow: registers combatants, generates a sorted turn order, and advances through turns using a configurable ability.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UTurnBasedManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTurnBasedManagerComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Fires at the start of each combatant's turn.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnTurnDelegate OnTurnStart;
	// Fires at the end of each combatant's turn.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnTurnDelegate OnTurnEnd;
	// Fires when a combatant is added to the turn order, passing its position index.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnAddedToTurnOrder OnAddedToTurnOrder;
	// Fires when a combatant is removed from the turn order.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnTurnDelegate OnRemovedFromTurnOrder;

	// Optional delegate to override the default turn priority comparison between two combatants.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Turn")
    FQuery_CombatantCompare Query_CombatantActFirst;

	// Optional delegate that prevents a combatant from ever entering the turn order.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Turn")
	FQuery_CombatantCheck Query_BlockFromTurnOrder;

	//###########################################
	// Turn
	//###########################################

	UPROPERTY()
	TArray<UCombatantComponent*> TurnOrder;

	// Returns the current ordered list of combatants waiting for their turn.
	UFUNCTION(BlueprintPure, Category="TurnBased")
	TArray<UCombatantComponent*> GetTurnOrder();

	UPROPERTY()
	UCombatantComponent* ActiveTurnMember;

	// Returns the combatant whose turn is currently active.
	UFUNCTION(BlueprintPure, Category="TurnBased")
	UCombatantComponent* GetActiveTurnMember();

	// Returns the combatant at a specific position in the turn order.
	UFUNCTION(BlueprintPure, Category="TurnBased")
	UCombatantComponent* GetTurnMemberAtIndex(int32 Index);

	// Inserts Combatant into the turn order at the appropriate priority position.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void AddToTurnOrder(UCombatantComponent* Combatant);

	// Removes Combatant from the turn order.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"), DisplayName="Remove From Turn Order (Combatant)")
	void RemoveFromTurnOrder(UCombatantComponent* Combatant);

	// Removes all combatants belonging to Faction from the turn order.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"), DisplayName="Remove From Turn Order (Faction)")
	void RemoveFactionFromTurnOrder(FGameplayTag Faction);

	//###########################################
	// Turn Order
	//###########################################

	// Fires after GenerateTurnOrder completes and the new order is ready.
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnTurnComponentDelegate OnTurnOrderGenerated;

	// Builds a fresh sorted turn order from all registered combatants and returns it.
	UFUNCTION(BlueprintCallable, Category="TurnBased")
	TArray<UCombatantComponent*> GenerateTurnOrder();

	// Fires when NextTurn is called but fails (passes the failure reason string).
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnTurnFail OnTurnFail;

	// Ends the current turn and starts the next one. Generates a new order if the list is empty and bGenerateIfEmpty is true.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	bool NextTurn(bool bGenerateIfEmpty, FString& FailReason);

	UFUNCTION()
	void BeginTurn(UCombatantComponent* Combatant);

	// Empties the current turn order without unregistering combatants.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void ClearTurnOrder();

	//###########################################
	// Tag Events
	//###########################################

	// Gameplay tags sent as events to the active turn member when their turn begins.
	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Turn Member Events - On Turn Begin")
	FGameplayTagContainer TagEventsOnTurnBegin;
	// Gameplay tags sent as events to the active turn member when their turn ends.
	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Turn Member Events - On Turn End")
	FGameplayTagContainer TagEventsOnTurnEnd;

	// Single global gameplay tag broadcast to all combatants when any turn begins.
	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Global Event - On Turn Begin")
	FGameplayTag TagEventsOnTurnBegin_Global;
	// Single global gameplay tag broadcast to all combatants when any turn ends.
	UPROPERTY(EditAnywhere, Category="TagEvents",DisplayName="Global Event - On Turn End")
	FGameplayTag TagEventsOnTurnEnd_Global;

	// Sends the given gameplay tag events to every registered combatant.
	UFUNCTION(BlueprintCallable, Category="TurnBased|Event")
	void FireEventsOnCombatants(FGameplayTagContainer Events);

	// Sends the given gameplay tag events only to combatants belonging to Faction.
	UFUNCTION(BlueprintCallable, Category="TurnBased|Event")
	void FireEventsOnFaction(FGameplayTagContainer Events, FGameplayTag Faction);

	///////////////
	///// Ability ////
	//////////////
	// The ability class executed at the start of each combatant's turn.
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	TSubclassOf<AOmegaAbility> TurnAbility;

	// When true, the manager automatically calls NextTurn once the turn ability finishes.
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	bool bAutoAdvanceTurn = true;

	// Replaces the turn ability class at runtime.
	UFUNCTION(BlueprintCallable, Category="Omega|TurnBased")
	void SetTurnAbilityClass(TSubclassOf<AOmegaAbility> AbilityClass);

	// When true, the same combatant's turn repeats if the turn ability is cancelled.
	UPROPERTY(EditDefaultsOnly, Category="Turn")
	bool bRepeatTurnOnAbilityCancel;

	// Tags applied to the turn ability when repeating a cancelled turn.
	UPROPERTY(EditDefaultsOnly, Category="Turn", AdvancedDisplay)
	FGameplayTagContainer RepeatedTurnTags;
	// Tags applied to the turn ability when advancing to the next turn normally.
	UPROPERTY(EditDefaultsOnly, Category="Turn", AdvancedDisplay)
	FGameplayTagContainer NextTurnTags;
	// When true, a new turn order is automatically generated if NextTurn is called on an empty order.
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

	// Returns all combatants currently registered with this manager.
	UFUNCTION(BlueprintPure, Category="TurnBased")
	TArray<UCombatantComponent*> GetRegisteredCombatants();


	// Adds a combatant to the registered pool so it can be included in turn orders.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void RegisterCombatant(UCombatantComponent* Combatant);

	// Removes from list of combatants. Also remove form turn order if in.
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void UnregisterCombatant(UCombatantComponent* Combatant);

	// Empties all registered combatants from the list
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

// Implement on combatant actors to receive turn lifecycle callbacks from UTurnBasedManagerComponent.
class OMEGAGAMEFRAMEWORK_API IActorInterface_TurnOrderCombatant
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	// Called when this actor's turn begins.
	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased")
	void OnTurnBegin(UTurnBasedManagerComponent* TurnManager);

	// Called when this actor's turn ends.
	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased")
	void OnTurnEnd(UTurnBasedManagerComponent* TurnManager);

	// Called when this actor is added to the turn order.
	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void OnAddedToTurnOrder(UTurnBasedManagerComponent* TurnManager);

	// Called when this actor is removed from the turn order.
	UFUNCTION(BlueprintImplementableEvent, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void OnRemovedFromTurnOrder(UTurnBasedManagerComponent* TurnManager);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTurnTrackerDelegate,UTurnTrackerComponent*, Component, int32, TurnsElapsed);

// Tracks how many turns have elapsed for a specific combatant within a turn-based manager, useful for effect durations.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UTurnTrackerComponent : public UActorComponent
{
	GENERATED_BODY()

	void L_RunElapse(bool run);

	bool L_usesInterface(const UObject* obj) const;

	UFUNCTION() void L_OnTurnStart(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant);
	UFUNCTION() void L_OnTurnEnd(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant);

	UPROPERTY() UObject* tracker_source;
	UPROPERTY() int32 TurnsElapsed;
	UPROPERTY() UCombatantComponent* linked_combatant;

public:
	// Fires whenever the turns elapsed count changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FTurnTrackerDelegate OnTurnValueChanged;

	// When true, the elapsed count increments at the start of the linked combatant's turn.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Turn Tracker")
	bool ElapseOn_TurnStart=true;
	// When true, the elapsed count increments at the end of the linked combatant's turn.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Turn Tracker")
	bool ElapseOn_TurnEnd=false;
	// The value added to (or subtracted from) TurnsElapsed each time the tracker elapses.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Turn Tracker")
	int32 Elapse_IncrementValue=-1;

	// Links this tracker to a turn manager and combatant so it can listen for their turn events.
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void LinkToTurnManager(UTurnBasedManagerComponent* TurnManager, UCombatantComponent* combatant);

	// Sets the source object that defines this tracker's initial and max turn counts.
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void SetSource(UObject* Source, bool bInitTurns);
	// Resets or adds the initial turn count from the source object.
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void InitTurns(bool AddToCurrent);

	// Directly sets TurnsElapsed; pass Added=true to add value instead of replacing it.
	UFUNCTION(BlueprintCallable,Category="Turn Tracker")
	void SetTurnsElapsed(int32 value, bool Added);

	// Returns the current number of turns elapsed on this tracker.
	UFUNCTION(BlueprintPure,Category="Turn Tracker")
	int32 GetTurnsElapsed() const { return TurnsElapsed; }
};

UINTERFACE(MinimalAPI)
class UDataInterface_TurnEntity : public UInterface
{
	GENERATED_BODY()
};

// Implement on objects tracked by UTurnTrackerComponent to define their initial/max turn counts and respond to turn events.
class OMEGAGAMEFRAMEWORK_API IDataInterface_TurnEntity
{
	GENERATED_BODY()
public:
	// Called when the linked combatant's turn starts while this entity is being tracked.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - On Turn Start")
	void OnTurnStart(UTurnTrackerComponent* EntityComponent, UTurnBasedManagerComponent* TurnComponent, UCombatantComponent* Member);
	// Called when the linked combatant's turn ends while this entity is being tracked.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - On Turn End")
	void OnTurnEnd(UTurnTrackerComponent* EntityComponent, UTurnBasedManagerComponent* TurnComponent, UCombatantComponent* Member);
	// Returns the starting turn count assigned to this entity when the tracker is initialized.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - Get Turns Init")
	int32 GetTurns_Init();
	// Returns the maximum number of turns this entity can be active before expiring.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|TurnBased",DisplayName="Turn Entity - Get Turns Init")
	int32 GetTurns_Max();
};
// --------------------------------------------------------------------------------------------------------------------
// LISTEN
// --------------------------------------------------------------------------------------------------------------------
