// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonSkill.h"
//#include "GameFramework/Character.h"
#include "LevelSequence.h"
//#include "Functions/OmegaFunctions_AVContext.h"
#include "Animation/AnimMontage.h"

TSubclassOf<UCombatantFilter> UOAsset_CommonSkill::GetSkillTargetFilter_Implementation()
{
	return TargetFilter;
}

TMap<UOmegaAttribute*, float> UOAsset_CommonSkill::GetSkillAttributeCosts_Implementation(UCombatantComponent* Combatant,
	UObject* Context)
{
	return AttributeUseCost;
}

FOmegaCustomScriptedEffects UOAsset_CommonSkill::GetScriptedEffects_Implementation(FGameplayTag Tag)
{
	if(Effects_Tagged.Contains(Tag))
	{
		return Effects_Tagged[Tag];
	}
	return Effects_Default;
}



ULevelSequence* UOAsset_CommonSkill::GetSkill_Sequences_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag)
{
	if(TaggedSequences.Contains(Tag))
	{
		return TaggedSequences[Tag];
	}
	if(DefaultSequence_Asset)
	{
		return DefaultSequence_Asset;
	}
	/*
	if(Combatant)
	{
		if(ACharacter* char_Ref = Cast<ACharacter>(Combatant->GetOwner()))
		{
			if(char_Ref->GetMesh()->GetAnimInstance())
			{
				TEnumAsByte<EOmegaFunctionResult> result;
				return UOmegaContextAVFunctions::TryGetObjectContext_Sequence(char_Ref->GetMesh()->GetAnimInstance(),DefaultSequence_Tag,nullptr,result);
			}
		}
	}
	*/
	return nullptr;
}

UAnimMontage* UOAsset_CommonSkill::GetSkill_Montage_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag)
{
	if(TaggedMontages.Contains(Tag))
	{
		return TaggedMontages[Tag];
	}
	if(DefaultMontage_Asset)
	{
		return DefaultMontage_Asset;
	}
	/*
	if(Combatant)
	{
		if(ACharacter* char_Ref = Cast<ACharacter>(Combatant->GetOwner()))
		{
			if(char_Ref->GetMesh()->GetAnimInstance())
			{
				TEnumAsByte<EOmegaFunctionResult> result;
				return UOmegaContextAVFunctions::TryGetObjectContext_Montages(char_Ref->GetMesh()->GetAnimInstance(),DefaultMontage_Tag,nullptr,result);
			}
		}
	}
	*/
	return nullptr;
}
