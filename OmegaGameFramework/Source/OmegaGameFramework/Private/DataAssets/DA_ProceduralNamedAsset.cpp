// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_ProceduralNamedAsset.h"

#include "OmegaSettings.h"
#include "Kismet/KismetStringLibrary.h"

UOmegaProceduralNamedAssetBuilder* UOmegaProceduralNamedAsset::GetBuilder() const
{
	if (OverrideBuilderClass)
	{
		return OverrideBuilderClass->GetDefaultObject<UOmegaProceduralNamedAssetBuilder>();
	}
	TSubclassOf<UOmegaProceduralNamedAssetBuilder> BuilderClass = GetMutableDefault<UOmegaSettings>()->ProceduralDataAssetBuilderClass.LoadSynchronous();
	if (BuilderClass)
	{
		if (UOmegaProceduralNamedAssetBuilder* Builder = Cast<UOmegaProceduralNamedAssetBuilder>(BuilderClass->GetDefaultObject()))
		{
			return Builder;
		}
	}
	return nullptr;
}

FString UOmegaProceduralNamedAsset::GetNameProceduralValue(int32 index) const
{
	TArray<FString> vals = UKismetStringLibrary::ParseIntoArray(this->GetName(), "_");
	if (vals.Num() > index)
	{
		return vals[index];
	}
	return "";
}

// -- IDataInterface_General ----------------------------------------------------

void UOmegaProceduralNamedAsset::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
	{
		b->Build_General_Config(this, Tag, Name, Description, iconBrush, Color, Label, MetaConfig);
	}
	if (!DisplayName.IsEmpty()) { Name = DisplayName;}
	if (!DisplayDescription.IsEmpty()) { Description = DisplayDescription;}
	if (Icon.GetResourceObject()) { iconBrush = Icon; }
}

void UOmegaProceduralNamedAsset::GetObjectGameplayTags_Implementation(FGameplayTag& _CategoryTag, FGameplayTagContainer& _GameplayTags)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
	{
		b->Build_General_Tags(this, _CategoryTag, _GameplayTags);
	}
	if (CategoryTag.IsValid()) { _CategoryTag = CategoryTag; }
	if (GameplayTags.IsValid()) { _GameplayTags.AppendTags(GameplayTags); }
}

void UOmegaProceduralNamedAsset::Tag_Event_Implementation(FGameplayTag Event, FOmegaCommonMeta meta)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		b->Build_General_TagEvent(this, Event, meta);
}

bool UOmegaProceduralNamedAsset::Tag_Query_Implementation(FGameplayTag Query, FOmegaCommonMeta meta)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_General_TagQuery(this, Query, meta);
	return false;
}

float UOmegaProceduralNamedAsset::Tag_Utility_Implementation(FGameplayTag Query, FOmegaCommonMeta meta)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_General_TagUtility(this, Query, meta);
	return 0.f;
}

FOmegaBitmaskEditorData UOmegaProceduralNamedAsset::Bitflags_Override_Implementation(bool& bOverride)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_General_BitflagsOverride(this, bOverride);
	return FOmegaBitmaskEditorData{};
}

// -- IDataInterface_Skill ------------------------------------------------------

int32 UOmegaProceduralNamedAsset::Skill_OnActorEvent_Implementation(UCombatantComponent* Combatant, FGameplayTag EventTag)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_OnActorEvent(this, Combatant, EventTag);
	return 0;
}

bool UOmegaProceduralNamedAsset::CanUseSkill_Implementation(UCombatantComponent* Combatant)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_CanUse(this, Combatant);
	return true;
}

FOmegaSkillConfig UOmegaProceduralNamedAsset::Skill_GetConfig_Implementation(UCombatantComponent* Combatant)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_GetConfig(this, Combatant);
	return FOmegaSkillConfig{};
}

FOmegaScriptedAnimationData UOmegaProceduralNamedAsset::Skill_GetScriptedAnim_Implementation(UCombatantComponent* Combatant)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_GetScriptedAnim(this, Combatant);
	return FOmegaScriptedAnimationData{};
}

FOmegaCustomScriptedEffects UOmegaProceduralNamedAsset::Skill_GetScriptedEffects_Implementation(UCombatantComponent* Combatant)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_GetScriptedEffects(this, Combatant);
	return FOmegaCustomScriptedEffects{};
}

float UOmegaProceduralNamedAsset::Skill_CheckUtility_OneTarget_Implementation(UCombatantComponent* Combatant, UCombatantComponent* Target, FGameplayTag Tag)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_CheckUtility_OneTarget(this, Combatant, Target, Tag);
	return 0.f;
}

float UOmegaProceduralNamedAsset::Skill_CheckUtility_Implementation(UCombatantComponent* Combatant, const TArray<UCombatantComponent*>& Targets, FGameplayTag Tag)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_CheckUtility(this, Combatant, Targets, Tag);
	return 0.f;
}

ULevelSequence* UOmegaProceduralNamedAsset::GetSkill_Sequences_Implementation(UCombatantComponent* Combatant, FName Name)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_GetSequence(this, Combatant, Name);
	return nullptr;
}

UAnimMontage* UOmegaProceduralNamedAsset::GetSkill_Montage_Implementation(UCombatantComponent* Combatant, FName Name)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Skill_GetMontage(this, Combatant, Name);
	return nullptr;
}

// -- IDataInterface_InventoryItem ----------------------------------------------

int32 UOmegaProceduralNamedAsset::GetMaxCollectionNumber_Implementation()
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Item_MaxAmount(this);
	return 1;
}

int32 UOmegaProceduralNamedAsset::GetSizePerAmount_Implementation()
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Item_SizePerAmount(this);
	return 1;
}

TMap<UPrimaryDataAsset*, int32> UOmegaProceduralNamedAsset::GetTradeAssetRequirements_Implementation(FGameplayTag TradeTag)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Item_TradeValues(this, TradeTag);
	return {};
}

// -- IDataInterface_Equipable --------------------------------------------------

bool UOmegaProceduralNamedAsset::CanEquipItem_Implementation(UCombatantComponent* Component, UEquipmentSlot* Slot)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Equipment_CanEquipItem(this, Component, Slot);
	return false;
}

// -- IDataInterface_Combatant --------------------------------------------------

int32 UOmegaProceduralNamedAsset::Combatant_OnEvent_Implementation(UCombatantComponent* Combatant, FGameplayTag Event, FOmegaCombatantEventMeta meta)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Combatant_OnEvent(this, Combatant, Event, meta);
	return 0;
}

FOmegaCombatantSourceConfig UOmegaProceduralNamedAsset::Combatant_GetConfig_Implementation()
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Combatant_GetConfig(this);
	return FOmegaCombatantSourceConfig{};
}

FOmegaScripted_CombatantModifiers UOmegaProceduralNamedAsset::Combatant_GetScriptedModifiers_Implementation()
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Combatant_GetScriptedModifiers(this);
	return FOmegaScripted_CombatantModifiers{};
}

TArray<FOmegaAttributeModifier> UOmegaProceduralNamedAsset::GetModifierValues_Implementation(UCombatantComponent* CombatantComponent)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Combatant_ModifyAttributes(this, CombatantComponent);
	return {};
}

float UOmegaProceduralNamedAsset::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Combatant_ModifyDamage(this, Attribute, Target, Instigator, BaseDamage, DamageType, Context);
	return BaseDamage;
}

TArray<UPrimaryDataAsset*> UOmegaProceduralNamedAsset::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Combatant_GetSkills(this, Combatant);
	return {};
}

UPrimaryDataAsset* UOmegaProceduralNamedAsset::GetDamageType_Weight_Implementation(UCombatantComponent* Combatant, UOmegaDamageType* DamageType, float& weight, int32& priority)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_Combatant_DamageTypeWeight(this, Combatant, DamageType, weight, priority);
	return nullptr;
}


// -- IDataInterface_ScriptedEffects --------------------------------------------

FOmegaCustomScriptedEffects UOmegaProceduralNamedAsset::GetScriptedEffects_Implementation(FGameplayTag Tag)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_ScriptedEffects_GetEffects(this, Tag);
	return FOmegaCustomScriptedEffects{};
}

int32 UOmegaProceduralNamedAsset::OnEffectsApplied_Implementation(UCombatantComponent* Target, UCombatantComponent* Instigator, FGameplayTag Tag)
{
	if (UOmegaProceduralNamedAssetBuilder* b = GetBuilder())
		return b->Build_ScriptedEffects_OnApplied(this, Target, Instigator, Tag);
	return 0;
}
