// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_Squad.h"

#include "Components/Component_Combatant.h"

TArray<UCombatantComponent*> UCombatantSquadComponent::GetSquadMembers()
{
	TArray<UCombatantComponent*> out;
	for(auto* i : SquadMembers)
	{
		if(i) { out.Add(i);}
	}
	SquadMembers=out;
	return out;
}

void UCombatantSquadComponent::SetCombatantInSquad(UCombatantComponent* Combatant, bool bInSquad)
{
	if(Combatant)
	{
		if(!SquadMembers.Contains(Combatant) && bInSquad)
		{
			SquadMembers.Add(Combatant);
			OnSquadMembersChanged.Broadcast(this,Combatant,true);
		}
		else if (SquadMembers.Contains(Combatant) && !bInSquad)
		{
			SquadMembers.Remove(Combatant);
			OnSquadMembersChanged.Broadcast(this,Combatant,false);
		}
	}
}

void UCombatantSquadComponent::SwapSquadMembers_ByIndex(int32 A, int32 B)
{
	if(SquadMembers.IsValidIndex(A) && SquadMembers.IsValidIndex(B))
	{
		GetSquadMembers();
		SquadMembers.Swap(A,B);
	}
}

void UCombatantSquadComponent::SwapSquadMembers_ByAsset(UPrimaryDataAsset* A, UPrimaryDataAsset* B)
{
	SwapSquadMembers_ByIndex(GetMemberIndex_ByAsset(A),GetMemberIndex_ByAsset(B));
}

int32 UCombatantSquadComponent::GetMemberIndex_ByAsset(UPrimaryDataAsset* Asset)
{
	if(Asset)
	{
		for(auto* i : GetSquadMembers())
		{
			if(i && i->GetSourceDataAsset()==Asset)
			{
				return GetSquadMembers().Find(i);
			}
		}
	}
	return -1;
}
