
#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Interfaces/OmegaInterface_Skill.h"
#include "Misc/OmegaAttribute.h"
#include "Struct_CombatantSource.generated.h"

class UOmegaScripted_DamageModifier;
class UOmegaScripted_DamageModifier;
class UOmegaScripted_SkillSource;



USTRUCT(BlueprintType)
struct FOmegaCombatantSources
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_AttributeModifier*> Attribute_Mods;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_DamageModifier*> Damage_Mods;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_SkillSource*> Skills;
	
	TArray<FOmegaAttributeModifier> GetAttributeMods(UCombatantComponent* c) const
	{
		FOmegaScripted_AttributeModifiers mod;
		mod.Modifiers=Attribute_Mods;
		return mod.GatherModifiers(c);
	}
	float GetDamageMods(UOmegaAttribute* Attribute, UCombatantComponent* Target,
		UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) const
	{
		FOmegaScripted_DamageModifiers mod;
		mod.Modifiers=Damage_Mods;
		return mod.ApplyMod(Attribute,Target,Instigator,BaseDamage,DamageType,Context);
	}
	TArray<UPrimaryDataAsset*> GetSkills(UCombatantComponent* c) const
	{
		FOmegaScripted_SkillSources mod;
		mod.Modifiers=Skills;
		return mod.GatherSkills(c);
	}

	void Append(FOmegaCombatantSources in, bool bAttributes=true,bool bDamage=true,bool bSkills=true)
	{
		if(bAttributes)
		{
			Attribute_Mods.Append(in.Attribute_Mods);
		}
		if(bDamage)
		{
			Damage_Mods.Append(in.Damage_Mods);
		}
		if(bSkills)
		{
			Skills.Append(in.Skills);
		}
	}
};