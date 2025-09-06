// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Misc/OmegaAttribute.h"
#include "OmegaInterface_Combatant.generated.h"

class UCombatantComponent;
class UCombatantFilter;

UINTERFACE() class UActorInterface_Combatant : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_Combatant
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant")
	TArray<UObject*> GetAttributeModifiers();
};


UINTERFACE() class UDataInterface_Combatant : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Combatant
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant") UCombatantGambitAsset* GetGambitAsset();
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant") UOmegaFaction* GetFactionAsset();
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant") TArray<UPrimaryDataAsset*> GetDefaultSkills();
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant") int32 GetLevel();
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant") TMap<UOmegaAttribute*, float> GetMaxAttributeOverrides();
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant") FGameplayTag GetAttributeValueCategory();
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant") TMap<UOmegaDamageType*,UOmegaDamageTypeReactionAsset*> GetDamageTypeReactions();
	
	UFUNCTION(BlueprintImplementableEvent, Category="ΩI|Combatant")
	TMap<UOmegaAttribute*, float> OverrideCurrentAttributeValues(UCombatantComponent* Combatant, bool& bOverride);

	UFUNCTION(BlueprintImplementableEvent, Category="ΩI|Combatant")
	TMap<UOmegaAttribute*, int32> OverrideAttributeLevels(UCombatantComponent* Combatant, bool& bOverride);

	UFUNCTION(BlueprintImplementableEvent, Category="ΩI|Combatant")
	FGameplayTag OverrideAttributeValueCategory(UCombatantComponent* Combatant, bool& bOverride);

	UFUNCTION(BlueprintImplementableEvent, Category="ΩI|Combatant")
	int32 OverrideCombatantLevel(UCombatantComponent* Combatant, bool& bOverride);
};


UINTERFACE() class UDataInterface_DamageModifier : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_DamageModifier
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Combatant",DisplayName="Damage Modifier - Apply")
	float ModifyDamage(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context);
};


// ===================================================================================================================
// Damage Modifier
// ===================================================================================================================

UCLASS(Blueprintable,BlueprintType,EditInlineNew,CollapseCategories,Const,Abstract)
class UOmegaScripted_DamageModifier : public UObject, public IDataInterface_DamageModifier
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FOmegaScripted_DamageModifiers
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="DamageModifiers")
	TArray<UOmegaScripted_DamageModifier*> Modifiers;

	float ApplyMod(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
	{
		if(Modifiers.IsEmpty())
		{
			return BaseDamage;
		}
		float out=0.0;
		for(auto* i : Modifiers)
		{
			if(i)
			{
				out=IDataInterface_DamageModifier::Execute_ModifyDamage(i,Attribute,Target,Instigator,BaseDamage,DamageType,Context);
			}
		}
		return out;
	}
};




