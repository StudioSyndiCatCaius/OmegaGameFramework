// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GeneralDataObject.h"
#include "Components/Component_Skin.h"
#include "Functions/OmegaFunctions_CombatantFilter.h"
#include "Functions/OmegaFunctions_ScriptedEffects.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Interfaces/OmegaInterface_Skill.h"
#include "OmegaDemoAssets.generated.h"

// ============================================================================================================
//  Prefab
// ============================================================================================================
UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaActorPrefab : public UObject
{
	GENERATED_UCLASS_BODY()
	
};

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaCommonSkill : public UOmegaDataAsset, public IDataInterface_Skill, public IDataInterface_CombatantFilter, public IOmegaScriptedEffectsInterface
{
	GENERATED_BODY()
public:
	
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
};

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaCombatantPreset : public UOmegaDataAsset, public IDataInterface_Combatant, public IDataInterface_SkinSource
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attributes") UOmegaFaction* Faction;
	virtual UOmegaFaction* GetFactionAsset_Implementation() override { return Faction;};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attributes") int32 Level;
	virtual int32 GetLevel_Implementation() override { return Level; };
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attributes") TMap<UOmegaAttribute*, float> OverrideMaxAttributes;
	virtual TMap<UOmegaAttribute*, float> GetMaxAttributeOverrides_Implementation() override {return OverrideMaxAttributes;};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attributes") FGameplayTag AttributeValueCategory;
	virtual FGameplayTag GetAttributeValueCategory_Implementation() override {return AttributeValueCategory;};

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Effects") TMap<UOmegaDamageType*,UOmegaDamageTypeReactionAsset*> DamageTypeReactions;
	virtual TMap<UOmegaDamageType*,UOmegaDamageTypeReactionAsset*> GetDamageTypeReactions_Implementation() override {return DamageTypeReactions;};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Abilities") TArray<UPrimaryDataAsset*> DefaultSkills;
	virtual TArray<UPrimaryDataAsset*> GetDefaultSkills_Implementation() override {return DefaultSkills;};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Abilities") UCombatantGambitAsset* Gambit;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Abilities") UCombatantGambitAsset* Gambit_Custom;
	virtual UCombatantGambitAsset* GetGambitAsset_Implementation() override
	{
		if(Gambit) { return Gambit; }
		if(Gambit_Custom) { return Gambit_Custom; }
		return nullptr;
	};
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance") TSubclassOf<AOmegaSkin> Skin;
	virtual TSubclassOf<AOmegaSkin> GetSkinClass_Implementation() override { return Skin;};
};