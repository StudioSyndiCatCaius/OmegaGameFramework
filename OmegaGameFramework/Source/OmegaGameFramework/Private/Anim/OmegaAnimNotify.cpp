// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/OmegaAnimNotify.h"
#include "Components/SkeletalMeshComponent.h"
#include "Gameplay/CombatantComponent.h"

void UCombatantAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if(MeshComp && MeshComp->GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		Cast<UCombatantComponent>(MeshComp->GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))->CombatantNotify(CombatantNotify, Flag);
	}
}
