// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Inventory.h"
#include "Functions/F_Equipment.h"
#include "Functions/F_ScriptedEffects.h"
#include "Interfaces/I_Skill.h"
#include "Misc/GeneralDataObject.h"
#include "DA_ProceduralNamedAsset.generated.h"

class ULevelSequence;
class UAnimMontage;

/**
 *
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaProceduralNamedAsset : public UOmegaDataAsset,
														public IDataInterface_Skill, public IDataInterface_InventoryItem,
														public IDataInterface_Equipable, public IDataInterface_Combatant,
														public IDataInterface_ScriptedEffects
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ProceduralNamedAsset")
	FString GetNameProceduralValue(int32 index) const;

	UPROPERTY(EditAnywhere, Category="Procedural")
	TSubclassOf<UOmegaProceduralNamedAssetBuilder> OverrideBuilderClass;

	// IDataInterface_General
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& _CategoryTag, FGameplayTagContainer& _GameplayTags) override;
	virtual void Tag_Event_Implementation(FGameplayTag Event, FOmegaCommonMeta meta) override;
	virtual bool Tag_Query_Implementation(FGameplayTag Query, FOmegaCommonMeta meta) override;
	virtual float Tag_Utility_Implementation(FGameplayTag Query, FOmegaCommonMeta meta) override;
	virtual FOmegaBitmaskEditorData Bitflags_Override_Implementation(bool& bOverride) override;

	// IDataInterface_Skill
	virtual int32 Skill_OnActorEvent_Implementation(UCombatantComponent* Combatant, FGameplayTag EventTag) override;
	virtual bool CanUseSkill_Implementation(UCombatantComponent* Combatant) override;
	virtual FOmegaSkillConfig Skill_GetConfig_Implementation(UCombatantComponent* Combatant) override;
	virtual FOmegaScriptedAnimationData Skill_GetScriptedAnim_Implementation(UCombatantComponent* Combatant) override;
	virtual FOmegaCustomScriptedEffects Skill_GetScriptedEffects_Implementation(UCombatantComponent* Combatant) override;
	virtual float Skill_CheckUtility_OneTarget_Implementation(UCombatantComponent* Combatant, UCombatantComponent* Target, FGameplayTag Tag) override;
	virtual float Skill_CheckUtility_Implementation(UCombatantComponent* Combatant, const TArray<UCombatantComponent*>& Targets, FGameplayTag Tag) override;
	virtual ULevelSequence* GetSkill_Sequences_Implementation(UCombatantComponent* Combatant, FName Name) override;
	virtual UAnimMontage* GetSkill_Montage_Implementation(UCombatantComponent* Combatant, FName Name) override;

	// IDataInterface_InventoryItem
	virtual int32 GetMaxCollectionNumber_Implementation() override;
	virtual int32 GetSizePerAmount_Implementation() override;
	virtual TMap<UPrimaryDataAsset*, int32> GetTradeAssetRequirements_Implementation(FGameplayTag TradeTag) override;

	// IDataInterface_Equipable
	virtual bool CanEquipItem_Implementation(UCombatantComponent* Component, UEquipmentSlot* Slot) override;

	// IDataInterface_Combatant
	virtual int32 Combatant_OnEvent_Implementation(UCombatantComponent* Combatant, FGameplayTag Event, FOmegaCombatantEventMeta meta) override;
	virtual FOmegaCombatantSourceConfig Combatant_GetConfig_Implementation() override;
	virtual FOmegaScripted_CombatantModifiers Combatant_GetScriptedModifiers_Implementation() override;
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	virtual UPrimaryDataAsset* GetDamageType_Weight_Implementation(UCombatantComponent* Combatant, UOmegaDamageType* DamageType, float& weight, int32& priority) override;
	virtual UPrimaryDataAsset* Combatant_ModDynamicAsset_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag, UObject* Context, int32& priority, bool bValidConsider) override;
	virtual float Combatant_ModDynamicScalar_Implementation(UCombatantComponent* Combatant, FGameplayTag Tag, UObject* Context, int32& priority, bool bValidConsider) override;
	
	// IDataInterface_ScriptedEffects
	virtual FOmegaCustomScriptedEffects GetScriptedEffects_Implementation(FGameplayTag Tag) override;
	virtual int32 OnEffectsApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator, FGameplayTag Tag) override;

private:
	UOmegaProceduralNamedAssetBuilder* GetBuilder() const;
};


UCLASS(Blueprintable, BlueprintType, meta=(ShowWorldContextPin), Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaProceduralNamedAssetBuilder : public UObject
{
	GENERATED_BODY()

public:
	// General
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	void Build_General_Config(UOmegaProceduralNamedAsset* Asset, FGameplayTag Tag,
		FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	void Build_General_Tags(UOmegaProceduralNamedAsset* Asset, FGameplayTag& CategoryTag, FGameplayTagContainer& GameplayTags);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	void Build_General_TagEvent(UOmegaProceduralNamedAsset* Asset, FGameplayTag Event, FOmegaCommonMeta meta);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	bool Build_General_TagQuery(UOmegaProceduralNamedAsset* Asset, FGameplayTag Query, FOmegaCommonMeta meta);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	float Build_General_TagUtility(UOmegaProceduralNamedAsset* Asset, FGameplayTag Query, FOmegaCommonMeta meta);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	FOmegaBitmaskEditorData Build_General_BitflagsOverride(UOmegaProceduralNamedAsset* Asset, bool& bOverride);

	// Skill
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	int32 Build_Skill_OnActorEvent(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, FGameplayTag EventTag);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	bool Build_Skill_CanUse(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	FOmegaSkillConfig Build_Skill_GetConfig(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	FOmegaScriptedAnimationData Build_Skill_GetScriptedAnim(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	FOmegaCustomScriptedEffects Build_Skill_GetScriptedEffects(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	float Build_Skill_CheckUtility_OneTarget(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, UCombatantComponent* Target, FGameplayTag Tag);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	float Build_Skill_CheckUtility(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, const TArray<UCombatantComponent*>& Targets, FGameplayTag Tag);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	ULevelSequence* Build_Skill_GetSequence(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, FName Name);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	UAnimMontage* Build_Skill_GetMontage(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, FName Name);

	// InventoryItem
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	int32 Build_Item_MaxAmount(UOmegaProceduralNamedAsset* Asset);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	int32 Build_Item_SizePerAmount(UOmegaProceduralNamedAsset* Asset);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	TMap<UPrimaryDataAsset*, int32> Build_Item_TradeValues(UOmegaProceduralNamedAsset* Asset, FGameplayTag TradeTag);

	// Equipment
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	bool Build_Equipment_CanEquipItem(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Component, UEquipmentSlot* Slot);

	// Combatant
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	int32 Build_Combatant_OnEvent(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, FGameplayTag Event, FOmegaCombatantEventMeta meta);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	FOmegaCombatantSourceConfig Build_Combatant_GetConfig(UOmegaProceduralNamedAsset* Asset);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	FOmegaScripted_CombatantModifiers Build_Combatant_GetScriptedModifiers(UOmegaProceduralNamedAsset* Asset);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	TArray<FOmegaAttributeModifier> Build_Combatant_ModifyAttributes(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* CombatantComponent);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	float Build_Combatant_ModifyDamage(UOmegaProceduralNamedAsset* Asset, UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	TArray<UPrimaryDataAsset*> Build_Combatant_GetSkills(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	UPrimaryDataAsset* Build_Combatant_DamageTypeWeight(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, UOmegaDamageType* DamageType, float& weight, int32& priority);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	float Build_Combatant_ModDynamicScalar(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, FGameplayTag Tag, UObject* Context, int32& priority,bool bValidConsider);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	UPrimaryDataAsset* Build_Combatant_ModDynamicAsset(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Combatant, FGameplayTag Tag, UObject* Context, int32& priority,bool bValidConsider);
	
	// ScriptedEffects
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	FOmegaCustomScriptedEffects Build_ScriptedEffects_GetEffects(UOmegaProceduralNamedAsset* Asset, FGameplayTag Tag);
	UFUNCTION(BlueprintImplementableEvent, Category="ProceduralNamedAsset")
	int32 Build_ScriptedEffects_OnApplied(UOmegaProceduralNamedAsset* Asset, UCombatantComponent* Target, UCombatantComponent* Instigator, FGameplayTag Tag);
};
