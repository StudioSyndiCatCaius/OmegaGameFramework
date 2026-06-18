// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Procedural_Skill.generated.h"


const int32 PSKILL_VAL_FIRST=0;
/*
 * Examples:
 *	- magAtk (does damage scaled by power)
 *	- buff
 * - debuff
 */
const int32 PSKILL_VAL_TYPE=1;
const int32 PSKILL_VAL_SUBTYPE=2;
const int32 PSKILL_VAL_TARGET=3;
const int32 PSKILL_VAL_POWER=4;

UCLASS(Blueprintable, BlueprintType,DisplayName="♎Demo - Skill (Name Procedural)")
class OMEGADEMO_API UDA_Procedural_Skill : public UOmegaMinimalDataAsset, public IDataInterface_General, public IDataInterface_Skill 
{
	GENERATED_BODY()
	
	FString L_GetProcValue(int32 index) const;
	
	virtual FOmegaSkillConfig Skill_GetConfig_Implementation(UCombatantComponent* Combatant) override;
	virtual float Skill_CheckUtility_OneTarget_Implementation(UCombatantComponent* Combatant, UCombatantComponent* Target, FGameplayTag Tag) override;
	
};
