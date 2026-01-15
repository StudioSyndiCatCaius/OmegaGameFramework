// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Global.h"

#include "Misc/OmegaDamageType.h"


bool UOmegaGlobalSettings::FlowNode_CanPlay_Implementation(UObject* Node, FName Input) const
{
	return true;
}

float UOmegaGlobalSettings::Combatant_ModifyDamage_PreMod_Implementation(
	UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage,
	UOmegaDamageType* DamageType, UObject* Context) const
{
	return BaseDamage;
}

float UOmegaGlobalSettings::Combatant_ModifyDamage_PostMod_Implementation(
	UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage,
	UOmegaDamageType* DamageType, UObject* Context) const
{
	return BaseDamage;
}

void UOmegaGlobalSettings::WorldInit(UWorld* World) const
{
	OnWorldInit(World);
}

float UOmegaGlobalSettings::Attribute_GetMaxValue_Implementation(UCombatantComponent* Combatant,
	UOmegaAttribute* Attribute, int32 AttributeRank, float BaseValue) const
{
	return BaseValue;
}


FText UOmegaGlobalSettings::Text_PostGameplayFormat_Implementation(const FText& Text, FGameplayTag Tag,
                                                                   FOmegaCommonMeta meta) const
{
	return Text;
}


FText UOmegaGlobalSettings::Text_PreGameplayFormat_Implementation(const FText& Text, FGameplayTag Tag,
                                                                  FOmegaCommonMeta meta) const
{
	return Text;
}


