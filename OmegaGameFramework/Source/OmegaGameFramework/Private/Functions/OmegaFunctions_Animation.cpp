// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Animation.h"

#include "GameFramework/Character.h"



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
