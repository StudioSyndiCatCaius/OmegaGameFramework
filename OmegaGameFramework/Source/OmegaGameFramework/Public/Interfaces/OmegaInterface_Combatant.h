// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Misc/OmegaAttribute.h"
#include "OmegaInterface_Combatant.generated.h"

class UCombatantComponent;
class UCombatantFilter;

UINTERFACE() class UActorInterface_Combatant : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_Combatant
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintNativeEvent, Category="Combatant")
	TArray<UObject*> GetAttributeModifiers();
};


UINTERFACE() class UDataInterface_Combatant : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Combatant
{
	GENERATED_BODY()

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


// ===================================================================================================================
// Effects
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_OmegaEffect : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_OmegaEffect
{
	GENERATED_BODY()

	public:
	UFUNCTION(BlueprintNativeEvent, Category="Effects")
	TArray<FOmegaEffectContainer> GetOmegaEffects();
};


// ===================================================================================================================
// Damage Modifier
// ===================================================================================================================
UINTERFACE() class UDataInterface_DamageModifier : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_DamageModifier
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintNativeEvent, Category="Attributes")
	float ModifyDamage(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context);
};

