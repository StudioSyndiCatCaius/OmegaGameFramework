// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaDemoAssets.h"
#include "GameFramework/Character.h"
#include "Functions/OmegaFunctions_AVContext.h"

UOmegaActorPrefab::UOmegaActorPrefab(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}



TSubclassOf<UCombatantFilter> UOmegaCommonSkill::GetSkillTargetFilter_Implementation()
{
	return TargetFilter;
}

TMap<UOmegaAttribute*, float> UOmegaCommonSkill::GetSkillAttributeCosts_Implementation(UCombatantComponent* Combatant,
	UObject* Context)
{
	return AttributeUseCost;
}

FOmegaCustomScriptedEffects UOmegaCommonSkill::GetScriptedEffects_Implementation()
{
	return Effects_Target;
}

ULevelSequence* UOmegaCommonSkill::GetSkill_Sequences_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag)
{
	if(TaggedSequences.Contains(Tag))
	{
		return TaggedSequences[Tag];
	}
	if(DefaultSequence_Asset)
	{
		return DefaultSequence_Asset;
	}
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
	return nullptr;
}

UAnimMontage* UOmegaCommonSkill::GetSkill_Montage_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag)
{
	if(TaggedMontages.Contains(Tag))
	{
		return TaggedMontages[Tag];
	}
	if(DefaultMontage_Asset)
	{
		return DefaultMontage_Asset;
	}
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
	return nullptr;
}
