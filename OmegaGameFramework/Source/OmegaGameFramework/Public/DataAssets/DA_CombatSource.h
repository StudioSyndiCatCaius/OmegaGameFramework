// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Interfaces/OmegaInterface_Skill.h"

#include "Misc/GeneralDataObject.h"
#include "DA_CombatSource.generated.h"



UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_CombatSource : public UOmegaDataAsset, public IDataInterface_SkillSource, public IDataInterface_AttributeModifier, public IDataInterface_DamageModifier
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_AttributeModifier*> Attribute_Mods;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_DamageModifier*> Damage_Mods;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_SkillSource*> Skills;

	
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override; 

};

inline TArray<FOmegaAttributeModifier> UOAsset_CombatSource::GetModifierValues_Implementation(
	UCombatantComponent* CombatantComponent)
{
	FOmegaScripted_AttributeModifiers mod;
	mod.Modifiers=Attribute_Mods;
	return mod.GatherModifiers(CombatantComponent);
}

inline float UOAsset_CombatSource::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	FOmegaScripted_DamageModifiers mod;
	mod.Modifiers=Damage_Mods;
	return mod.ApplyMod(Attribute,Target,Instigator,BaseDamage,DamageType,Context);
}

inline TArray<UPrimaryDataAsset*> UOAsset_CombatSource::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	FOmegaScripted_SkillSources mod;
	mod.Modifiers=Skills;
	return mod.GatherSkills(Combatant);
}
