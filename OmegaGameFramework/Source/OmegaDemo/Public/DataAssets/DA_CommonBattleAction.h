// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_ScriptedAnim.h"
#include "Functions/OmegaFunctions_CombatantFilter.h"
#include "Functions/F_ScriptedEffects.h"
#include "Interfaces/I_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "Selectors/Selector_LevelSequence.h"
#include "Selectors/Selector_Montage.h"
#include "DA_CommonBattleAction.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonBattleAction : public UOmegaDemoDataAsset, public IOmegaScriptedEffectsInterface, public IDataInterface_Skill, 
																			public IDataInterface_CombatantFilter, public IDataInterface_ScriptedAnimation
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation",DisplayName="🕺Animation") FOmegaScriptedAnimationData Animation;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Animation",DisplayName="🕺Animation (🇳)") TMap<FName,FOmegaScriptedAnimationData> Animation_Named;
	virtual FOmegaScriptedAnimationData GetScriptedAnimation_Implementation(FName name) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",DisplayName="🎯Target Data")
	FCombatantFilterData TargetFilterData;
	virtual FCombatantFilterData GetSkillTargetFilterData_Implementation() override {return TargetFilterData;} ;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combat",DisplayName="💫Effects")
	TArray<UOmegaScriptedEffect*> Effects;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",DisplayName="💫Effects (🇳)")
	TMap<FName,FOmegaCustomScriptedEffects> Effects_Named;
	virtual FOmegaCustomScriptedEffects GetScriptedEffects_Implementation(FName Name) override;
};
