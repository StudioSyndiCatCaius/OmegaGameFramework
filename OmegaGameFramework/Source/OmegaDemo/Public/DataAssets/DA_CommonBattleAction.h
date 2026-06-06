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
class OMEGADEMO_API UOAsset_CommonBattleAction : public UOmegaDemoDataAsset, public IDataInterface_ScriptedEffects, public IDataInterface_Skill, 
																			public IDataInterface_ScriptedAnimation
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",DisplayName="🕺Animation") FOmegaScriptedAnimationData Animation;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",DisplayName="🕺Animation (Tag)",meta=(Categories="ScriptedEffect",ForceInlineRow))
	TMap<FGameplayTag,FOmegaScriptedAnimationData> Animation_Named;
	virtual FOmegaScriptedAnimationData GetScriptedAnimation_Implementation(FGameplayTag Tag) override;
	
	UPROPERTY()
	FCombatantFilterData TargetFilterData;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combat",DisplayName="💫Effects")
	TArray<UOmegaScriptedEffect*> Effects;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",DisplayName="💫Effects (Tag)",meta=(Categories="ScriptedEffect",ForceInlineRow))
	TMap<FGameplayTag,FOmegaCustomScriptedEffects> Effects_Named;
	virtual FOmegaCustomScriptedEffects GetScriptedEffects_Implementation(FGameplayTag Tag) override;
};
