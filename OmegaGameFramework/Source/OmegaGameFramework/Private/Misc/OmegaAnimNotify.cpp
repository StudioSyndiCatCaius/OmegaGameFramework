// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/OmegaAnimNotify.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/Component_Combatant.h"

void UCombatantAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if(MeshComp && MeshComp->GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		Cast<UCombatantComponent>(MeshComp->GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))->CombatantNotify(CombatantNotify, Flag);
	}
}
