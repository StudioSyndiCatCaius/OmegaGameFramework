
#include "Interfaces/I_Combatant.h"

TArray<FOmegaAttributeModifier> FOmegaScripted_CombatantModifiers::GatherAttributeModifiers(
	UCombatantComponent* CombatantComponent) const
{
	TArray<FOmegaAttributeModifier> out;
	for(auto* i : Modifiers)
	{
		if(i)
		{
			out.Append(IDataInterface_Combatant::Execute_GetModifierValues(i,CombatantComponent));
		}
	}
	return out;
}

float FOmegaScripted_CombatantModifiers::ApplyDamageMod(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	if(Modifiers.IsEmpty())
	{
		return BaseDamage;
	}
	float out=BaseDamage;
	for(auto* i : Modifiers)
	{
		if(i)
		{
			bool bMod=false;
			float dmgMod = IDataInterface_Combatant::Execute_ModifyDamage(i, Attribute, Target, Instigator, out, DamageType,
																		  Context);
			if (bMod)
			{
				out=dmgMod;
			}
		}
	}
	return out;
}
