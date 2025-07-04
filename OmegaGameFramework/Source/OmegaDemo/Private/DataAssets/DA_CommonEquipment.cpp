// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonEquipment.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_CombatantExtension.h"
#include "DataAssets/DA_Common_EquipType.h"



float UOAsset_CommonEquipment::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	return IDataInterface_DamageModifier::ModifyDamage_Implementation(Attribute, Target, Instigator, BaseDamage,
	                                                                  DamageType, Context);
}

TArray<FOmegaAttributeModifier> UOAsset_CommonEquipment::GetModifierValues_Implementation(UCombatantComponent* CombatantComponent)
{
	TArray<FOmegaAttributeModifier> out;
	for(UOmegaScripted_AttributeModifier* i : Attribute_Mods)
	{
		if(i)
		{
			TArray<FOmegaAttributeModifier> t=IDataInterface_AttributeModifier::Execute_GetModifierValues(i,CombatantComponent);
			out.Append(t);
		}
	}
	return out;
}

bool UOAsset_CommonEquipment::CanEquipItem_Implementation(UEquipmentComponent* Component,UEquipmentSlot* Slot)
{
	if(Component)
	{
		FOmegaConditions_Actor aCond;
		if(Type)
		{
			aCond.Conditions=Type->EquipConditions;
			if(!aCond.CheckConditions(Component->GetOwner()))
			{
				return false;
			}
		}
		aCond.Conditions=EquipConditions;
		if(!aCond.CheckConditions(Component->GetOwner()))
		{
			return false;
		}
	}
	return true;
}

TArray<UPrimaryDataAsset*> UOAsset_CommonEquipment::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	TArray<UPrimaryDataAsset*> out;
	FOmegaScripted_SkillSources temp;
	temp.Modifiers=SkillsGranted;
	return temp.GatherSkills(Combatant);
}
