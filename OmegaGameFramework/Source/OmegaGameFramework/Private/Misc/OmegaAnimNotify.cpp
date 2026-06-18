// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/OmegaAnimNotify.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/Component_Combatant.h"
#include "Functions/F_Tick.h"


void UCombatantAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	if(MeshComp && MeshComp->GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
    	{
    		Cast<UCombatantComponent>(MeshComp->GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))->CombatantNotify(CombatantNotify, Flag);
    	}
}

void UAnimNotifyState_CombatantTrackTarget::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp)
	{
		if (UCombatantComponent* comb=Cast<UCombatantComponent>(MeshComp->GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass())))
		{
			if (UCombatantComponent* activeTarg= comb->GetActiveTarget())
			{
				UOmegaFunctions_Tick::RotateComponent_TowardsTarget(FrameDeltaTime,MeshComp->GetOwner()->GetRootComponent(),
					activeTarg->GetOwner()->GetActorLocation(),Rotate_X,Rotate_Y,Rotate_Z);
			}
		}
	}
}
