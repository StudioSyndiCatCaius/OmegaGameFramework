#include "script_CombatantMods.h"

#include "Components/Component_Combatant.h"
#include "Kismet/KismetMathLibrary.h"

TArray<FOmegaAttributeModifier> UAttributeMod_AddedMultiplier::GetModifierValues_Implementation(
	UCombatantComponent* CombatantComponent)
{
	TArray<FOmegaAttributeModifier> Modifiers;
	Modifiers.Append(FOmegaAttributeModifier::FromFlat(Increment, false));
	Modifiers.Append(FOmegaAttributeModifier::FromFlat(Scale, true));
	return FOmegaAttributeModifier::Simplify(Modifiers);
}


float UDamageMod_ByAttributePercent::ModifyDamage_Implementation(UOmegaAttribute* Attribute,
                                                                 UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType,
                                                                 UObject* Context)
{
	if (DamagedAttribute && ModifierAttribute)
	{
		//
		float modPercent=Target->GetAttributePercentage(ModifierAttribute);
		float moddedVal=modPercent*BaseDamage;
		
		float FinalDamage=UKismetMathLibrary::Lerp(BaseDamage,moddedVal,ModifierScale);
	}
	return BaseDamage;
}

float UDamageMod_ScaleByDamageType::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	if (Attribute && (DamagedAttributes.Contains(Attribute) || DamagedAttributes.IsEmpty()))
	{
		if (DamageType && DamageType==Damage_Type)
		{
			return BaseDamage*ModifierScale;
		}
	}
	return BaseDamage;
}

TArray<UPrimaryDataAsset*> USkillSource_Common::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	TArray<UPrimaryDataAsset*> out;
	for (const TScriptInterface<IDataInterface_Skill>& Skill : Skills)
	{
		if (UPrimaryDataAsset* Asset = Cast<UPrimaryDataAsset>(Skill.GetObject()))
		{
			out.Add(Asset);
		}
	}
	
	TArray<UPrimaryDataAsset*> temp;
	SkillsByLevel.GetKeys(temp);
	for (UPrimaryDataAsset* Skill : temp)
	{
		if (Skill && Combatant->Level>=SkillsByLevel.FindChecked(Skill))
		{
			out.Add(Skill);
		}
	}
	
	return out;
}
