// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "OmegaInterface_Skill.generated.h"

class UOmegaAttribute;
class UCombatantComponent;
class UCombatantFilter;
class AOmegaGameplayEffect;



// ===================================================================================================================
// Skill Source
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_SkillSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_SkillSource
{
	GENERATED_BODY()
	public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	TArray<UPrimaryDataAsset*> GetSkills(UCombatantComponent* Combatant);
};


// ===================================================================================================================
// Skill
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_Skill : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Skill
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Skill")
	void OnSkillAddedToCombatant(UCombatantComponent* Combatant, bool Added);
	
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Skill")
	TMap<UOmegaAttribute*, float> GetSkillAttributeCosts(UCombatantComponent* Combatant,UObject* Context);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Skill")
	TSubclassOf<UCombatantFilter> GetSkillTargetFilter();
	
	// Skills are given two sequences slots: Charge is typically played first on the instigator. Execution is played second on the Target.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Skill")
	ULevelSequence* GetSkill_Sequences(UCombatantComponent* Combatant, FGameplayTag Tag);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Skill")
	UAnimMontage* GetSkill_Montage(UCombatantComponent* Combatant, FGameplayTag Tag);
};
