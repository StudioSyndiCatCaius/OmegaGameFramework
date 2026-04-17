// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/Conditions_Combatant.h"

#include "Functions/F_DataAsset.h"
#include "Functions/F_Math.h"


bool UOCon_Combatant_EquipSlot::CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const
{
	if (Combatant)
	{
		for (auto* SlotToCheck : SlotsToCheck)
		{
			if (SlotToCheck && Combatant)
			{
				bool _dumBool;
		
				//check if has at least one required item
				if (!Accepted_Items.IsEmpty() && !Accepted_Items.Contains(Combatant->Equipment_GetInSlot(SlotToCheck,_dumBool)))
				{
					return false;
				}
		
				//check if has NONE of rejected item
				if (!Rejected_Items.IsEmpty() && Rejected_Items.Contains(Combatant->Equipment_GetInSlot(SlotToCheck,_dumBool)))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
	
}

bool UOCon_Combatant_InventoryAmount::CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const
{
	if (Combatant)
	{
		return Combatant->Inventory_HasMinimum(MinimumItems);
	}
	return false;
}

bool UOCon_Combatant_LevelCheck::CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const
{
	if (Combatant && LevelingAsset)
	{
		return UOmegaMathFunctions::Compare_Int(Combatant->XP_GetLevel(LevelingAsset),Method,CheckLevel);
	}
	return false;
}

bool UOCon_Combatant_AttributePercent::CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const
{
	if (Attribute && Combatant)
	{
		UOmegaMathFunctions::Compare_Float(Combatant->GetAttributePercentage(Attribute),Method,Percent);
	}
	return false;
}

bool UOCon_Combatant_CheckTags::CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const
{
	if ((Combatant_Query.IsEmpty() || Combatant_Query.Matches(Combatant->CombatantTags)) &&
		(Entity_Query.IsEmpty() || Entity_Query.Matches(Combatant->L_GetEntityData()->Tags)))
	{
		return true;
	}
	return false;
}
