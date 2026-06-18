// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "Functions/F_ScriptedAnim.h"
#include "Functions/F_ScriptedEffects.h"
#include "Functions/F_CombatantFilter.h"
#include "I_Skill.generated.h"

class UCombatantSelector;
class UOmegaDamageType;
class UOmegaAttribute;
class UCombatantComponent;
class UCombatantFilter;
class AOmegaGameplayEffect;
class IDataInterface_Grid3DPathfind;


USTRUCT(BlueprintType)
struct FOmegaSkillConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skill Config")
	TMap<UOmegaAttribute*, float> AttributeUseCost;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skill Config",DisplayName="🎯Target (Filter)")
	TObjectPtr<UCombatantFilterCollection> TargetFilter;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skill Config",DisplayName="🎯Target (Selector)")
	TSubclassOf<UCombatantSelector> TargetSelector;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skill Config")
	TArray<UPrimaryDataAsset*> UseRequiredSkills;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Skill Config",AdvancedDisplay)
	TScriptInterface<IDataInterface_Grid3DPathfind> Grid3DPathfind;
	UPROPERTY() UOmegaDamageType* DamageType;
	UPROPERTY() UOmegaAttribute* Attribute;
	
};


// ===================================================================================================================
// Skill
// ===================================================================================================================
UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - 🔥 Skill",BlueprintType) class UDataInterface_Skill : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Skill
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|🔥Skill", DisplayName="🔥Skill - On Owner Tag Event?")
	int32 Skill_OnActorEvent(UCombatantComponent* Combatant, FGameplayTag EventTag);
	
	UFUNCTION(BlueprintImplementableEvent,Category="♎I|🔥Skill",	DisplayName="🔥Skill - On Added to Combatant")
	void OnSkillAddedToCombatant(UCombatantComponent* Combatant, bool Added);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|🔥Skill", DisplayName="🔥Skill - Can Be Used?")
	bool CanUseSkill(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|🔥Skill",	DisplayName="🔥Skill - Get Config")
	FOmegaSkillConfig Skill_GetConfig(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|🔥Skill",	DisplayName="🔥Skill - Get Scripted Animation")
	FOmegaScriptedAnimationData Skill_GetScriptedAnim(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|🔥Skill",	DisplayName="🔥Skill - Get Scripted Effects")
	FOmegaCustomScriptedEffects Skill_GetScriptedEffects(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🔥Skill", DisplayName="🔥Skill - Check Utility (Single Target)")
	float Skill_CheckUtility_OneTarget(UCombatantComponent* Combatant, UCombatantComponent* Target,FGameplayTag Tag);
	
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🔥Skill", DisplayName="🔥Skill - Check Utility (Multi Target)")
	float Skill_CheckUtility(UCombatantComponent* Combatant, const TArray<UCombatantComponent*>& Targets,FGameplayTag Tag);
	
	
	// Skills are given two sequences slots: Charge is typically played first on the instigator. Execution is played second on the Target.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|🔥Skill", DisplayName="🔥Skill - Get Sequences")
	ULevelSequence* GetSkill_Sequences(UCombatantComponent* Combatant, FName Name);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|🔥Skill", DisplayName="🔥Skill - Get Montages")
	UAnimMontage* GetSkill_Montage(UCombatantComponent* Combatant, FName Name);
};
