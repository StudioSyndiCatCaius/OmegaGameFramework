// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Types/Struct_CombatantConfig.h"

#include "Actors/Actor_Ability.h"
#include "Components/Component_Combatant.h"
#include "DataAssets/DA_Faction.h"

void FOmegaCombatantConfig::Apply(UCombatantComponent* combatant)
{
	if (combatant)
	{
		if (!combatant->AttributeSet)
		{
			if (UOmegaAttributeSet* a=AttributeSet.LoadSynchronous())
			{
				combatant->AttributeSet=a;
			}	
		}
		if (!combatant->FactionDataAsset)
		{
			if (UOmegaFaction* a=Faction.LoadSynchronous())
			{
				combatant->FactionDataAsset=a;
			}	
		}
		
		for (auto i : Abilities)
		{
			if (TSubclassOf<AOmegaAbility> a=i.LoadSynchronous())
			{
				combatant->GrantedAbilities.Add(a);
			}
		}
		
	}
}

