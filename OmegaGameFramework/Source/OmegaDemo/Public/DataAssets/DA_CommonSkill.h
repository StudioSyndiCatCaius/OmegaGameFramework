// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonBattleAction.h"
#include "Functions/OmegaFunctions_CombatantFilter.h"
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
	
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags")
	bool bAppendEffectsDescription;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	int32 Rank;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Skill",DisplayName="Actor Condition - Can Use?")
	TArray<UOmegaCondition_Actor*> Conditions_CanUse;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill",meta=(ShowOnlyInnerProperties))
	FOmegaSkillConfig SkillConfig;
	
};


// --------------------------------------------------------------------------------------------------------------
// Buff attribute
// --------------------------------------------------------------------------------------------------------------


UCLASS(Blueprintable, BlueprintType,DisplayName="♎Demo - Skill (Buff Attribute)")
class OMEGADEMO_API UOAsset_Skill_BuffAttribute : public UOmegaMinimalDataAsset, public IDataInterface_Skill, public IDataInterface_General
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill") UOmegaAttribute* Attribute;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill") int32 BuffRank;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTag categoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTagContainer gameplayTags;
	
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& CategoryTag, FGameplayTagContainer& GameplayTags) override;
};