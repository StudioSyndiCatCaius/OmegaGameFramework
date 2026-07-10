// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonBattleAction.h"
#include "Functions/F_CombatantFilter.h"
#include "Interfaces/I_Skill.h"

#include "Misc/GeneralDataObject.h"
#include "Selectors/Selector_LevelSequence.h"
#include "Selectors/Selector_Montage.h"
#include "DA_CommonSkill.generated.h"

class UOmegaCondition_Actor;
class UOAsset_EffectsPreset;
class ULevelSequence;
class UAnimMontage;
class UOmegaCondition_Combatant;

UCLASS(Blueprintable, BlueprintType,DisplayName="♎Demo - Skill (Common)")
class OMEGADEMO_API UOAsset_CommonSkill : public UOAsset_CommonBattleAction
{
	GENERATED_BODY()
public:
	virtual bool CanUseSkill_Implementation(UCombatantComponent* Combatant) override;
	virtual void SetValue_Implementation(FLuaValue Value, const FString& Flag = "") override;
	virtual FOmegaSkillConfig Skill_GetConfig_Implementation(UCombatantComponent* Combatant) override;
	virtual float Skill_CheckUtility_Implementation(UCombatantComponent* Combatant, const TArray<UCombatantComponent*>& Targets, FGameplayTag Tag) override;
	virtual float Skill_CheckUtility_OneTarget_Implementation(UCombatantComponent* Combatant, UCombatantComponent* Target, FGameplayTag Tag) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags")
	bool bAppendEffectsDescription;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	int32 Rank;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Skill",DisplayName="Actor Condition - Can Use?")
	TArray<UOmegaCondition_Actor*> Conditions_CanUse;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill",meta=(ShowOnlyInnerProperties))
	FOmegaSkillConfig SkillConfig;
	
};

