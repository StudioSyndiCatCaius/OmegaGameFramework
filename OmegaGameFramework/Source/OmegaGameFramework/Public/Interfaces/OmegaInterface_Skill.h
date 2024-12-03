// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Misc/OmegaAttribute.h"
#include "OmegaInterface_Skill.generated.h"

class UCombatantComponent;
class UCombatantFilter;

// ===================================================================================================================
// Skill Source
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_SkillSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_SkillSource
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintNativeEvent, Category="Combatant")
	TArray<UPrimaryDataAsset*> GetSkills(UCombatantComponent* Combatant);
};


// ===================================================================================================================
// Skill
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_Skill : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Skill
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Skills")
	TMap<UOmegaAttribute*, float> GetSkillAttributeCosts(UCombatantComponent* Combatant,UObject* Context);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	TSubclassOf<UCombatantFilter> GetSkillTargetFilter();

	// Skills are given two sequences slots: Charge is typically played first on the instigator. Execution is played second on the Target.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	ULevelSequence* GetSkill_Sequences(UCombatantComponent* Combatant, FGameplayTag Tag);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	UAnimMontage* GetSkill_Montage(UCombatantComponent* Combatant, FGameplayTag Tag);
};
