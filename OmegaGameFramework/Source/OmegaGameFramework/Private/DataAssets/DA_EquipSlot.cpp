// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_EquipSlot.h"

#include "Functions/F_Equipment.h"

bool UEquipmentSlot::CanSlotEquipItem(UPrimaryDataAsset* Item)
{
	if (Item)
	{
		FGameplayTag fCat=UDataInterface_General::GetGCategory(Item);
		FGameplayTagContainer fTags=UDataInterface_General::GetGTags(Item);
		if (!AcceptedCategories.IsEmpty() && !AcceptedCategories.HasTag(fCat)) { return false;}
		if (!TagsQuery.IsEmpty() && !TagsQuery.Matches(fTags)) { return false; }
		return true;
	}
	return false;
}

bool UEquipmentSlot::CanSlotEquipItemOnCombatant(UCombatantComponent* Combatant, UPrimaryDataAsset* Item)
{
	if (!Combatant || !Item) return false;
	if (CanSlotEquipItem(Item))
	{
		if (Item->GetClass()->ImplementsInterface(UDataInterface_Equipable::StaticClass()))
		{
			return IDataInterface_Equipable::Execute_CanEquipItem(Item,Combatant,this);
		}
	}
	return false;
}
