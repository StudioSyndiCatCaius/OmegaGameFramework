// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonItem.h"
#include "Components/Component_Equipment.h"
#include "Misc/OmegaAttribute.h"
#include "Condition/Condition_Actor.h"
#include "DataAssets/DA_Appearance.h"
#include "Interfaces/I_BitFlag.h"
#include "Types/Struct_CombatantSource.h"
#include "Interfaces/I_Combatant.h"
#include "Interfaces/I_Skill.h"
#include "DA_CommonEquipment.generated.h"


class UOAsset_Appearance;
class UOAsset_Common_EquipType;

UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonEquipment : public UOAsset_CommonItem, public IDataInterface_Equipable, public IDataInterface_SkillSource,
												public IDataInterface_AttributeModifier, public IDataInterface_DamageModifier, public IDataInterface_AppearanceSource
{
	GENERATED_BODY()

	FOmegaCombatantSources L_GetCombatMods() const;
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	UOAsset_Common_EquipType* Type;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Equipment")
	TArray<UOmegaCondition_Actor*> EquipConditions;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TMap<UOmegaAttribute*,int32> Attributes;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	FOmegaCombatantSources CombatModifiers;

	//true=will scale this attribute modifier values from the Type.RankAttributeScales based on the Equipment's rank.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_RankAttributeScaling=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_AttributeMods=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_DamageMods=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_Skills=true;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Appearance")
	bool DefaultToTypeAppearance=true;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Appearance")
	UOAsset_Appearance* Appearance;
	
	virtual bool CanEquipItem_Implementation(UEquipmentComponent* Component,UEquipmentSlot* Slot) override;
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;

	UFUNCTION(BlueprintPure,Category="Equipment") bool IsOfType(TArray<UOAsset_Common_EquipType*> AcceptedTypes) const;
};


