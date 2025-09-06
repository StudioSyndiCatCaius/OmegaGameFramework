// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonEquipment.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_CombatantExtension.h"
#include "DataAssets/DA_Common_EquipType.h"


FOmegaCombatantSources UOAsset_CommonEquipment::L_GetCombatMods() const
{
	FOmegaCombatantSources base=CombatModifiers;
	if(Type)
	{
		base.Append(Type->Sources,UseType_AttributeMods,UseType_DamageMods,UseType_Skills);
	}
	return base;
}

bool UOAsset_CommonEquipment::CanEquipItem_Implementation(UEquipmentComponent* Component,UEquipmentSlot* Slot)
{
	
	if(Component)
	{
		FOmegaConditions_Actor aCond;
		if(Type)
		{
			aCond.Conditions=Type->GetAllConditions();
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

TArray<FOmegaAttributeModifier> UOAsset_CommonEquipment::GetModifierValues_Implementation(
	UCombatantComponent* CombatantComponent)
{
	TArray<FOmegaAttributeModifier> g=L_GetCombatMods().GetAttributeMods(CombatantComponent);
	for(auto& p : Attributes)
	{
		if(p.Key)
		{
			FOmegaAttributeModifier mod;
			mod.Attribute=p.Key;
			mod.Incrementer=p.Value;
			g.Add(mod);
		}
	}
	if(Type)
	{
		if(UseType_RankAttributeScaling)
		{
			g.Append(Type->L_ScaleAttributeByRank_All(Rank));
		}
	}
	return FOmegaAttributeModifier::Simplify(g);
}

float UOAsset_CommonEquipment::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	return L_GetCombatMods().GetDamageMods(Attribute,Target,Instigator,BaseDamage,DamageType,Context);
}

TArray<UPrimaryDataAsset*> UOAsset_CommonEquipment::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	return L_GetCombatMods().GetSkills(Combatant);
}

UOAsset_Appearance* UOAsset_CommonEquipment::GetAppearanceAsset_Implementation()
{
	if(Type && DefaultToTypeAppearance && !Appearance)
	{
		return Execute_GetAppearanceAsset(Type);
	}
	if(Appearance)
	{
		return Appearance;
	}
	return nullptr;
}


