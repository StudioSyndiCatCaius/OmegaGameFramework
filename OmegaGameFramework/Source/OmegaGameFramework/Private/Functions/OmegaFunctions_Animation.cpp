// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Animation.h"

#include "Functions/OmegaFunctions_AVContext.h"
#include "GameFramework/Character.h"


void UOmegaAnimationFunctions::PlayMontage_ByTag(USkeletalMeshComponent* Mesh, FGameplayTag MontageTag)
{
	if(Mesh && Mesh->GetAnimInstance())
	{
		TEnumAsByte<EOmegaFunctionResult> result;
		if(UAnimMontage* ref_montage=UOmegaContextAVFunctions::TryGetObjectContext_Montages(Mesh->GetAnimInstance(), MontageTag,nullptr,result))
		{
			Mesh->GetAnimInstance()->Montage_Play(ref_montage);
		}
	}
}

void UOmegaAnimationFunctions::StopMontage_ByTag(USkeletalMeshComponent* Mesh, FGameplayTag MontageTag,FMontageBlendSettings blend_settings)
{
	if(Mesh && Mesh->GetAnimInstance())
	{
		TEnumAsByte<EOmegaFunctionResult> result;
		if(UAnimMontage* ref_montage=UOmegaContextAVFunctions::TryGetObjectContext_Montages(Mesh->GetAnimInstance(), MontageTag,nullptr,result))
		{
			Mesh->GetAnimInstance()->Montage_StopWithBlendSettings(blend_settings,ref_montage);
		}
	}
}

void UOmegaAnimationFunctions::PlayEmoteAnimation(ACharacter* Character, UOmegaAnimationEmote* Emote)
{
	if(Character && Emote && Emote->Script)
	{
		Character->PlayAnimMontage(Emote->Script->GetEmoteMontage(Character));
	}
}

void UOmegaAnimationFunctions::StopEmoteAnimation(ACharacter* Character, UOmegaAnimationEmote* Emote)
{
	if(Character && Emote && Emote->Script)
	{
		Character->StopAnimMontage(Emote->Script->GetEmoteMontage(Character));
	}
}

void UOmegaAnimationFunctions::StopAllMontages_Character(ACharacter* character,float blendOutTime)
{
	if (character && character->GetMesh())
	{
		if (UAnimInstance* animInstance = character->GetMesh()->GetAnimInstance())
		{
			animInstance->StopAllMontages(blendOutTime);
		}
	}
}
