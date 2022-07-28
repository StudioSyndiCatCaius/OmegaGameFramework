// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/CombatantComponent.h"
#include "TurnManagerBase.h"
#include "Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h"
#include "TurnBasedManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTurnStart, UCombatantComponent*, Combatant, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTurnEnd, UCombatantComponent*, Combatant, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAddedToTurnOrder, UCombatantComponent*, Combatant, int32, Index, FString, Flag, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRemovedFromTurnOrder, UCombatantComponent*, Combatant, FString, Flag, FGameplayTagContainer, Tags);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
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

	UPROPERTY(EditDefaultsOnly, Category="Turn")
	TSubclassOf<UTurnManagerBase> TurnManagerClass = UTurnManagerBase::StaticClass();

	UPROPERTY()
	UTurnManagerBase* TurnManager;
	
	UPROPERTY(BlueprintReadOnly, Category="TurnBased")
	TArray<UCombatantComponent*> TurnOrder;

	UFUNCTION(BlueprintPure, Category="TurnBased")
	UCombatantComponent* GetActiveTurnMember();

	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void AddToTurnOrder(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void RemoveFromTurnOrder(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category="TurnBased")
	TArray<UCombatantComponent*> GenerateTurnOrder();
	
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	bool NextTurn(bool bGenerateIfEmpty, FString Flag, FGameplayTagContainer Tags, FString& FailReason);
	
	UFUNCTION(BlueprintCallable, Category="TurnBased", meta=(AdvancedDisplay="Flag, Tags"))
	void ClearTurnOrder(FString Flag, FGameplayTagContainer Tags);
	
	///////////////
	///// Combatants ////
	//////////////
	UPROPERTY(BlueprintReadOnly, Category="TurnBased")
	TArray<UCombatantComponent*> RegisteredCombatants;

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

