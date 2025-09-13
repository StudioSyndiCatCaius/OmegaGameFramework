// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonBattleAction.h"
#include "Functions/OmegaFunctions_CombatantFilter.h"
#include "Interfaces/OmegaInterface_Skill.h"

#include "Misc/GeneralDataObject.h"
#include "Selectors/Selector_LevelSequence.h"
#include "Selectors/Selector_Montage.h"
#include "DA_CommonSkill.generated.h"

class UOAsset_EffectsPreset;
class ULevelSequence;
class UAnimMontage;
class UOmegaCondition_Combatant;

UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonSkill : public UOAsset_CommonBattleAction
{
	GENERATED_BODY()
public:
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual bool CanUseSkill_Implementation(UCombatantComponent* Combatant) override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags")
	bool bAppendEffectsDescription;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	int32 Rank;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Skill",DisplayName="Condition - Can Use?")
	TArray<UOmegaCondition_Combatant*> Conditions_CanUse;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Skill")
	TMap<UOmegaAttribute*, float> AttributeUseCost;
	virtual TMap<UOmegaAttribute*, float> GetSkillAttributeCosts_Implementation(UCombatantComponent* Combatant,UObject* Context) override;


};
