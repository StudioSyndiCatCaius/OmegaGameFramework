#include "script_CombatantSelector.h"

void UCombatantSelector_Single::CycleTarget(int32 amount)
{
	if (InputTargets.Num() == 0) return;
	currentTargetIndex = ((currentTargetIndex + amount) % InputTargets.Num() + InputTargets.Num()) % InputTargets.Num();
	Refresh();
	SetSelectorTargetActive(InputTargets[currentTargetIndex], true);
}

void UCombatantSelector_Single::OnSelectorBegin_Implementation()
{
	CycleTarget(0);
}

void UCombatantSelector_Single::OnSelectorEvent_Implementation(FGameplayTag Event)
{
	if (Event==Event_CycleL)
	{
		CycleTarget(-1);
	}
	else if (Event==Event_CycleR)
	{
		CycleTarget(1);
	}
}

bool UCombatantSelector_Single::IsTargetValid_Implementation(UCombatantComponent* Target) const
{
	if (InputTargets.Contains(Target))
	{
		return InputTargets.Find(Target)==currentTargetIndex;
	}
	return false;
}

void UCombatantSelector_All::OnSelectorBegin_Implementation()
{
	ActiveTargets=InputTargets;
}

TArray<UCombatantComponent*> UCombatantSelector_All::OnFinalizeTargets_Implementation(
	const TArray<UCombatantComponent*>& Targets) const
{
	return InputTargets;
}

void UCombatantSelector_Random::OnSelectorBegin_Implementation()
{
	ActiveTargets=InputTargets;
}
