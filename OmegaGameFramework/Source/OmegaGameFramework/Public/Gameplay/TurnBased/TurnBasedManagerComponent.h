// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/CombatantComponent.h"
#include "TurnManagerBase.h"
#include "TurnBasedManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnStart, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTurnEnd, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddedToTurnOrder, UCombatantComponent*, Combatant, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemovedFromTurnOrder, UCombatantComponent*, Combatant);


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
	
	UPROPERTY(BlueprintReadOnly, Category="Turn")
	TArray<UCombatantComponent*> TurnOrder;

	UFUNCTION(BlueprintPure, Category="Combatants")
	UCombatantComponent* GetActiveTurnMember();

	UFUNCTION(BlueprintCallable, Category="Combatants")
	void AddToTurnOrder(UCombatantComponent* Combatant, int32 Index = -1);

	UFUNCTION(BlueprintCallable, Category="Combatants")
	void RemoveFromTurnOrder(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintCallable, Category="Combatants")
	TArray<UCombatantComponent*> GenerateTurnOrder();
	
	UFUNCTION(BlueprintCallable, Category="Combatants")
	void NextTurn();
	
	///////////////
	///// Combatants ////
	//////////////
	UPROPERTY(BlueprintReadOnly, Category="Combatants")
	TArray<UCombatantComponent*> RegisteredCombatants;

	UFUNCTION(BlueprintCallable, Category="Combatants")
	void RegisterCombatant(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintCallable, Category="Combatants")
	void UnregisterCombatant(UCombatantComponent* Combatant);

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
