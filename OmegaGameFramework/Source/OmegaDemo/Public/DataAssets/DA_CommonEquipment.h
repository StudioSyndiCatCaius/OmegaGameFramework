// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonItem.h"
#include "Functions/F_Equipment.h"
#include "Condition/Condition_Actor.h"
#include "DataAssets/DA_Attribute.h"
#include "DataAssets/DA_Appearance.h"
#include "Interfaces/I_Combatant.h"
#include "Interfaces/I_Skill.h"
#include "DA_CommonEquipment.generated.h"


class UOAsset_Appearance;
class UOAsset_Common_EquipType;

UCLASS(Blueprintable, BlueprintType,DisplayName="♎Demo - Equipment (Common)")
class OMEGADEMO_API UOAsset_CommonEquipment : public UOAsset_CommonItem, public IDataInterface_Equipable, public IDataInterface_Combatant,
											public IDataInterface_AppearanceSource
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	UOAsset_Common_EquipType* Type;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Equipment")
	TArray<UOmegaCondition_Actor*> EquipConditions;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TMap<UOmegaAttribute*,int32> Attributes;

	//true=will scale this attribute modifier values from the Type.RankAttributeScales based on the Equipment's rank.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_RankAttributeScaling=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_AttributeMods=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_DamageMods=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags",AdvancedDisplay) bool UseType_Skills=true;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Appearance")
	bool DefaultToTypeAppearance=true;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Appearance")
	UOAsset_Appearance* Appearance;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant", meta=(ShowOnlyInnerProperties))
	FOmegaScripted_CombatantModifiers Modifiers;
	virtual FOmegaScripted_CombatantModifiers Combatant_GetScriptedModifiers_Implementation() override { return Modifiers; };
	virtual bool CanEquipItem_Implementation(UCombatantComponent* Component, UEquipmentSlot* Slot) override;
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
	UFUNCTION(BlueprintPure,Category="Equipment") bool IsOfType(TArray<UOAsset_Common_EquipType*> AcceptedTypes) const;
};


