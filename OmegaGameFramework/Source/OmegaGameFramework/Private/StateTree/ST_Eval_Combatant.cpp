// Fill out your copyright notice in the Description page of Project Settings.

#include "StateTree/ST_Eval_Combatant.h"
#include "Components/Component_Combatant.h"
#include "StateTreeLinker.h"

bool FST_Eval_Combatant::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(OwnerActorHandle);
	return true;
}

void FST_Eval_Combatant::TreeStart(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	const AActor& OwnerActor = Context.GetExternalData(OwnerActorHandle);
	InstanceData.CombatantComponent = OwnerActor.FindComponentByClass<UCombatantComponent>();
}

void FST_Eval_Combatant::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (InstanceData.CombatantComponent)
	{
		InstanceData.ActiveTarget = InstanceData.CombatantComponent->GetActiveTarget();
	}
}
