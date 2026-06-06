// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_Equipment.h"
#include "Functions/F_ScriptedEffects.h"
#include "Functions/F_TagEvent.h"
#include "Interfaces/I_Combatant.h"
#include "Interfaces/I_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "DA_CommonFeat.generated.h"


class UOmegaDamageType;

USTRUCT(BlueprintType)
struct FOmegaCombatantEventContainer
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatantEvents",meta=(ShowOnlyInnerProperties))
	FOmegaCustomScriptedEffects Effects;
};

// A passive skill for Combatnats, containing attribute/damage modifiers, and event effects
UCLASS(DisplayName="♎Demo - Feat (Common)")
class OMEGADEMO_API UOAsset_CommonFeat : public UOmegaDemoDataAsset, public IDataInterface_Combatant,
																		public IActorTagEventInterface, public IDataInterface_Skill, public IDataInterface_Equipable
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant", meta=(ShowOnlyInnerProperties))
	FOmegaScripted_CombatantModifiers Modifiers;
	virtual FOmegaScripted_CombatantModifiers Combatant_GetScriptedModifiers_Implementation() override { return Modifiers; };
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Events",meta=(ShowOnlyInnerProperties,ForceInlineRow))
	TMap<FGameplayTag,FOmegaCombatantEventContainer> Events;

};
