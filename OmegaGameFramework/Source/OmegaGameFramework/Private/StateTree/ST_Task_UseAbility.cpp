// Fill out your copyright notice in the Description page of Project Settings.

#include "StateTree/ST_Task_UseAbility.h"
#include "StateTreeExecutionContext.h"
#include "Components/Component_Combatant.h"
#include "Actors/Actor_Ability.h"

// ---------------------------------------------------------------------------
// EnterState
// ---------------------------------------------------------------------------


UCombatantComponent* FST_Task_UseAbility::GetCombatant(AActor* a) const
{
	if (!a) { return nullptr; }
	return Cast<UCombatantComponent>(a->GetComponentByClass(UCombatantComponent::StaticClass()));
}

EStateTreeRunStatus FST_Task_UseAbility::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	UCombatantComponent* Combatant = GetCombatant(InstanceData.Pawn);
	if (!Combatant || !InstanceData.AbilityClass)
	{
		return EStateTreeRunStatus::Failed;
	}

	bool bSuccess = false;
	Combatant->ExecuteAbility(InstanceData.AbilityClass, InstanceData.AbilityContext, bSuccess);

	if (!bSuccess)
	{
		return EStateTreeRunStatus::Failed;
	}

	return InstanceData.bWaitForCompletion ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Succeeded;
}

// ---------------------------------------------------------------------------
// Tick
// ---------------------------------------------------------------------------

EStateTreeRunStatus FST_Task_UseAbility::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	UCombatantComponent* Combatant = GetCombatant(InstanceData.Pawn);
	if (!Combatant)
	{
		return EStateTreeRunStatus::Failed;
	}

	// Succeed once the ability is no longer active
	if (!Combatant->IsAbilityActive(InstanceData.AbilityClass))
	{
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}

// ---------------------------------------------------------------------------
// ExitState
// ---------------------------------------------------------------------------

void FST_Task_UseAbility::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	if (!InstanceData.bCancelOnExit)
	{
		return;
	}

	UCombatantComponent* Combatant = GetCombatant(InstanceData.Pawn);
	if (Combatant && InstanceData.AbilityClass && Combatant->IsAbilityActive(InstanceData.AbilityClass))
	{
		Combatant->StopAbility(InstanceData.AbilityClass, /*bCancel=*/true);
	}
}

// ---------------------------------------------------------------------------
// Editor
// ---------------------------------------------------------------------------

#if WITH_EDITOR
FText FST_Task_UseAbility::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	if (!InstanceData || !InstanceData->AbilityClass)
	{
		return FText::FromString(TEXT("Use Ability"));
	}

	const FString AbilityName = InstanceData->AbilityClass->GetName();
	if (InstanceData->bWaitForCompletion)
	{
		return FText::FromString(FString::Printf(TEXT("Use Ability: %s (wait)"), *AbilityName));
	}
	return FText::FromString(FString::Printf(TEXT("Use Ability: %s"), *AbilityName));
}
#endif
