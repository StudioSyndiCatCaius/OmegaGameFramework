// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ActorInterface_TurnOrderCombatant.generated.h"

class UTurnBasedManagerComponent;
	
// This class does not need to be modified.
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
