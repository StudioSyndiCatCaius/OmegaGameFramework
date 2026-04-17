// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Functions/F_AVContext.h"
#include "Interfaces/I_Combatant.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "DA_DamageType.generated.h"

class AOmegaGameplayEffect;
class UNiagaraSystem;
class ULevelSequence;
class UOmegaAttribute;
class UCombatantComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDamageType : public UOmegaDataAsset
{
	GENERATED_BODY()

public: 

	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadOnly, Category="Damage Type")
	UOmegaDamageTypeScript* DamageScript;
	
};

UCLASS(Blueprintable, BlueprintType, Const, EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaDamageTypeScript : public UObject
{
	GENERATED_BODY()

public: 

	UFUNCTION(BlueprintNativeEvent, Category="Damage Type")
	float OnDamageApplied(float BaseDamage) const;

	UFUNCTION(BlueprintNativeEvent, Category="Damage Type")
	void OnEffectApplied(AOmegaGameplayEffect* Effect) const;
};

