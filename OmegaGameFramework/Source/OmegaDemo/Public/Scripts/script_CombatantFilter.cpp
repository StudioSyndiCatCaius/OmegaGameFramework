// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "script_CombatantFilter.h"

#include "Components/Component_Combatant.h"

const TArray<UCombatantComponent*> UCombatantFilter_FactionAffinity::FilterCombatants_Implementation(
	UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const
{
	TArray<UCombatantComponent*> out;
	
	for (UCombatantComponent* c : CombatantsIn)
	{
		if (c && AcceptedAffinities.Contains(Instigator->GetAffinityToCombatant(c)))
		{
			out.Add(c);
		}
	}
	
	return out;
}

const TArray<UCombatantComponent*> UCombatantFilter_EffectTags::FilterCombatants_Implementation(
	UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const
{
	TArray<UCombatantComponent*> out;
	
	for (UCombatantComponent* c : CombatantsIn)
	{
		if (c && (!c->HasEffectWithTags(Effects_Blocked) || Effects_Blocked.IsEmpty()) && (c->HasEffectWithTags(Effects_Required) || Effects_Required.IsEmpty()))
		{
			out.Add(c);
		}
	}
	
	return out;
}

const TArray<UCombatantComponent*> UCombatantFilter_Self::FilterCombatants_Implementation(
	UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const
{
	if (bExcludeInstead)
	{
		TArray<UCombatantComponent*> out=CombatantsIn;
		if (out.Contains(Instigator))
		{
			out.Remove(Instigator);
		}
		return out;
	}
	TArray<UCombatantComponent*> out;
	out.Add(Instigator);
	return out;
}
