// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "DataInterface_Combatant.generated.h"

class UCombatantComponent;
class UOmegaAttribute;

// This class does not need to be modified.
UINTERFACE()
class UDataInterface_Combatant : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IDataInterface_Combatant
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	TMap<UOmegaAttribute*, float> OverrideCurrentAttributeValues(UCombatantComponent* Combatant, bool& bOverride);

	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	TMap<UOmegaAttribute*, int32> OverrideAttributeLevels(UCombatantComponent* Combatant, bool& bOverride);

	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	FGameplayTag OverrideAttributeValueCategory(UCombatantComponent* Combatant, bool& bOverride);

	UFUNCTION(BlueprintImplementableEvent, Category="Combatant")
	int32 OverrideCombatantLevel(UCombatantComponent* Combatant, bool& bOverride);
};
