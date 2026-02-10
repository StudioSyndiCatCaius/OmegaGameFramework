// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Functions/OmegaFunctions_CombatantFilter.h"
#include "Functions/F_ScriptedEffects.h"
#include "Interfaces/I_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "Selectors/Selector_LevelSequence.h"
#include "Selectors/Selector_Montage.h"
#include "DA_CommonBattleAction.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonBattleAction : public UOmegaDataAsset, public IOmegaScriptedEffectsInterface, public IDataInterface_Skill, public IDataInterface_CombatantFilter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	FCombatantFilterData TargetFilterData;
	virtual FCombatantFilterData GetSkillTargetFilterData_Implementation() override {return TargetFilterData;} ;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combat") UOmegaSelector_LevelSequence* Sequence;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combat") TMap<FName,UOmegaSelector_LevelSequence*> Sequence_Named;
	virtual ULevelSequence* GetSkill_Sequences_Implementation(UCombatantComponent* Combatant, FName Name) override;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combat") UOmegaSelector_Montage* Montage;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combat") TMap<FName,UOmegaSelector_Montage*> Montage_Named;
	virtual UAnimMontage* GetSkill_Montage_Implementation(UCombatantComponent* Combatant, FName Name) override;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combat")
	TArray<UOmegaScriptedEffect*> Effects;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	TMap<FName,FOmegaCustomScriptedEffects> Effects_Named;
	virtual FOmegaCustomScriptedEffects GetScriptedEffects_Implementation(FName Name) override;
};
