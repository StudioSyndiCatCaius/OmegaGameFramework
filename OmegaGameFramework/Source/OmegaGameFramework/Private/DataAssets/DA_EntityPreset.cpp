// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_EntityPreset.h"

#include "Components/Component_Combatant.h"
#include "Components/Component_Leveling.h"
#include "Functions/F_Entity.h"
#include "Functions/F_Save.h"


FOmegaEntity UOmegaEntityPreset::GetEntityData() const
{
	FOmegaEntity Entity;
	Entity.Equipment=Equipment;
	Entity.Skills=Skills;
	Entity.Inventory=Inventory;
	
	TArray<UOmegaLevelingAsset*> _lvlAssets;
	XpLevels.GetKeys(_lvlAssets);
	for (UOmegaLevelingAsset* lvlAsset : _lvlAssets)
	{
		if (lvlAsset)
		{
			float xp_min;
			float xp_max;
			lvlAsset->GetXPFromLevel(XpLevels[lvlAsset],xp_min,xp_max);
			
			Entity.Attributes.Add(lvlAsset,xp_min);
		}
	}
	
	Entity.Tags=EntityTags;
	Entity.params_int32=params_int;
	Entity.params_string=params_string;
	return Entity;
}

void UOmegaEntityPreset::ApplyToCombatant(UCombatantComponent* combatant, bool bEvenIfSaveEntity) const
{
	if (combatant)
	{
		if (!combatant->use_entity_id)
		{
			combatant->entity_data=GetEntityData();
		}
		else if (bEvenIfSaveEntity)
		{
			FOmegaEntityID _id=combatant->entity_id;
			UOmegaFunctions_Entity::SetEntity_ByID(combatant,_id,GetEntityData(),false);
		}
	}
}
