// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Misc/OmegaAttribute.h"
#include "OmegaInterface_Combatant.generated.h"

class UCombatantComponent;
class UCombatantFilter;



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




