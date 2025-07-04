// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonItem.h"
#include "Components/Component_Equipment.h"
#include "Misc/OmegaAttribute.h"
#include "Condition/Condition_Actor.h"

#include "DA_CommonEquipment.generated.h"


class UOAsset_Common_EquipType;

UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonEquipment : public UOAsset_CommonItem, public IDataInterface_AttributeModifier,
													public IDataInterface_Equipable, public IDataInterface_DamageModifier, public IDataInterface_SkillSource
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	UOAsset_Common_EquipType* Type;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Equipment")
	TArray<UOmegaCondition_Actor*> EquipConditions;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_AttributeModifier*> Attribute_Mods;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_DamageModifier*> Damage_Mods;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Combatant")
	TArray<UOmegaScripted_SkillSource*> SkillsGranted;

	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual bool CanEquipItem_Implementation(UEquipmentComponent* Component,UEquipmentSlot* Slot) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
};
