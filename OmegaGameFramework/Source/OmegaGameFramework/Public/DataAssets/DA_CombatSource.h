// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Combatant.h"
#include "Interfaces/I_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_CombatantSource.h"
#include "DA_CombatSource.generated.h"



UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_CombatSource : public UOmegaDataAsset, public IDataInterface_SkillSource, public IDataInterface_AttributeModifier, public IDataInterface_DamageModifier
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant") FOmegaCombatantSources Sources;
	
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override; 

};

inline TArray<FOmegaAttributeModifier> UOAsset_CombatSource::GetModifierValues_Implementation(
	UCombatantComponent* CombatantComponent)
{
	return Sources.GetAttributeMods(CombatantComponent);
}

inline float UOAsset_CombatSource::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	return Sources.GetDamageMods(Attribute,Target,Instigator,BaseDamage,DamageType,Context);
}

inline TArray<UPrimaryDataAsset*> UOAsset_CombatSource::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	return Sources.GetSkills(Combatant);
}
