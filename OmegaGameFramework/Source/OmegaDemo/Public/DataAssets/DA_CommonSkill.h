// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Functions/OmegaFunctions_CombatantFilter.h"
#include "Functions/OmegaFunctions_ScriptedEffects.h"
#include "Interfaces/OmegaInterface_Skill.h"

#include "Misc/GeneralDataObject.h"
#include "DA_CommonSkill.generated.h"

class ULevelSequence;
class UAnimMontage;

UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonSkill : public UOmegaDataAsset, public IDataInterface_Skill, public IDataInterface_CombatantFilter,
											public IOmegaScriptedEffectsInterface
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	int32 Rank;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	FCombatantFilterData TargetFilterData;
	virtual FCombatantFilterData GetSkillTargetFilterData_Implementation() override {return TargetFilterData;} ;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill",AdvancedDisplay)
	TSubclassOf<UCombatantFilter> TargetFilter;
	virtual TSubclassOf<UCombatantFilter> GetSkillTargetFilter_Implementation() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	TMap<UOmegaAttribute*, float> AttributeUseCost;
	virtual TMap<UOmegaAttribute*, float> GetSkillAttributeCosts_Implementation(UCombatantComponent* Combatant,UObject* Context) override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	FOmegaCustomScriptedEffects Effects_Target;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	FOmegaCustomScriptedEffects Effects_Instigator;
	virtual FOmegaCustomScriptedEffects GetScriptedEffects_Implementation() override;
	
	//ANIMATIOn
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation") UAnimMontage* DefaultMontage_Asset;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation") FGameplayTag DefaultMontage_Tag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation") TMap<FGameplayTag, UAnimMontage*> TaggedMontages;
	virtual ULevelSequence* GetSkill_Sequences_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation") ULevelSequence* DefaultSequence_Asset;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation") FGameplayTag DefaultSequence_Tag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation") TMap<FGameplayTag, ULevelSequence*> TaggedSequences;
	virtual UAnimMontage* GetSkill_Montage_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag) override;

	// Realtives
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Relative") UOmegaAttribute* Related_Attribute;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Relative") UOmegaDamageType* Related_DamageType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Relative") UCombatantFilterCollection* Related_TargetFilter;
};
