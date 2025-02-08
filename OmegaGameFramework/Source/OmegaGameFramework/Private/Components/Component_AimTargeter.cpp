// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_AimTargeter.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"


FVector UAimTargetComponent::local_GetTargetLoc(AActor* target_actor) const
{
	if(target_actor)
	{
		if(target_actor->GetClass()->ImplementsInterface(UActorInterface_AimTarget::StaticClass()))
		{
			return IActorInterface_AimTarget::Execute_GetAimTargetLocation(target_actor,this);
		}
		return target_actor->GetActorLocation();
	}
	return FVector();
}

FVector UAimTargetComponent::GetSelf_AimRootLocation() const
{
	return local_GetTargetLoc(GetOwner());
}

FVector UAimTargetComponent::GetTarget_AimLocation() const
{
	return local_GetTargetLoc(AimTarget);
}

AActor* UAimTargetComponent::GetAimTarget() const
{
	if(AimTarget) {return nullptr;}
	return nullptr;
}

void UAimTargetComponent::SetAimTarget(AActor* NewTarget)
{
	ClearAimTarget();
	if (NewTarget)
	{
		AimTarget=NewTarget;
	}
}

void UAimTargetComponent::ClearAimTarget()
{
	AimTarget=nullptr;
}

bool UAimTargetComponent::IsAimActive() const
{
	if(AimTarget) {return true;} return false;
}
