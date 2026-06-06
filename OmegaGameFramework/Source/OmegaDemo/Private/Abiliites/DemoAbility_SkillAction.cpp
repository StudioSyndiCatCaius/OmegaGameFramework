// Fill out your copyright notice in the Description page of Project Settings.


#include "Abiliites/DemoAbility_SkillAction.h"

#include "Components/Component_Combatant.h"
#include "DataAssets/DA_AssetLib.h"
#include "Functions/F_Combatant.h"
#include "Interfaces/I_Skill.h"


ADemoAbility_SkillAction::ADemoAbility_SkillAction()
{
	PrimaryActorTick.bCanEverTick = true;
}

bool ADemoAbility_SkillAction::CanActivate_Implementation(UObject* Context)
{
	if (Context)
	{
		return UCombatantFunctions::CanCombatantUseSkill(CombatantOwner,Context);
	}
	return false; 
}

void ADemoAbility_SkillAction::AbilityActivated_Implementation(class UObject* Context)
{
	Super::AbilityActivated_Implementation(Context);
	ref_skill=nullptr;
	if (Context && Context->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
	{
		ref_skill=Context;
		UCombatantFunctions::ConsumeSkillAttributes(CombatantOwner,Context);
		FOmegaScriptedAnimationData scriptedAnimationData=IDataInterface_Skill::Execute_Skill_GetScriptedAnim(ref_skill.GetObject(),CombatantOwner);
		
		UOmegaFunctions_ScriptedAnimation::PlayScriptedAnimationWithCallbacks(
	this, CombatantOwner->GetOwner(), scriptedAnimationData,
	[this](const FString& Flag)
	{
		/* finished */
		CompleteAbility();
	},
	[this](const FString& Tag)
	{
		/* notify */
		if (Tag=="cancel")
		{
			CancelAbility();
		}
		else if (Tag=="impact")
		{
			if (ref_skill.GetObject() && bIsActive)
			{
				//FOmegaSkillConfig _cfg=IDataInterface_Skill::Execute_Skill_GetConfig(ref_skill.GetObject(),CombatantOwner);
				FOmegaCustomScriptedEffects ef=IDataInterface_Skill::Execute_Skill_GetScriptedEffects(ref_skill.GetObject(),CombatantOwner);
				for (auto* c : CombatantOwner->GetRegisteredTargetList())
				{
					if (c)
					{
						UOmegaScriptedEffectFunctions::ApplyCustomScriptedEffectToCombatant(ef,c,CombatantOwner);
					}
				}
			}
		}
	}
);
		
	}
}

void ADemoAbility_SkillAction::BeginPlay()
{
	Super::BeginPlay();
	
}

