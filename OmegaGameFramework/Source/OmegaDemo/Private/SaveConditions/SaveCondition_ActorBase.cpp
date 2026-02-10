// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveConditions/SaveCondition_ActorBase.h"

#include "Misc/OmegaUtils_Actor.h"

AActor* USaveCondition_ActorBase::GetConditionActor()
{
	if(GetWorld() && ActorSource)
	{
		return ActorSource->Private_GetActor(GetWorld());
	}
	return nullptr;
}

