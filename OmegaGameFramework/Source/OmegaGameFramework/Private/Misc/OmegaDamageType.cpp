// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/OmegaDamageType.h"
#include "Misc/OmegaAttribute.h"
#include "Components/Component_Combatant.h"


void UOmegaDamageType::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                         FText& Description)
{
	Name = DamageTypeName;
	Description= DisplayDescription;
}

void UOmegaDamageType::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color = DamageTypeColor;
}

void UOmegaDamageType::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = this->GetName();
}

void UOmegaDamageType::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = DamageTypeIcon;
}

FGameplayTag UOmegaDamageType::GetObjectGameplayCategory_Implementation()
{
	return GameplayCategory;
}

FGameplayTagContainer UOmegaDamageType::GetObjectGameplayTags_Implementation()
{
	return GameplayTags;
}

//################################################################
// DAMAGE ContextAV
//################################################################


void UOmegaDamageTypeReaction::OnEffectApplied_Implementation(UCombatantComponent* Combatant,
	AOmegaGameplayEffect* Effect) const
{
}

float UOmegaDamageTypeReaction::OnDamageApplied_Implementation(UCombatantComponent* Combatant,
	UOmegaAttribute* Attribute, float BaseDamage) const
{
	return BaseDamage;
}

UOmegaDamageTypeReactionAsset::UOmegaDamageTypeReactionAsset()
{
	if(!b_init)
	{
		b_init=true;
		if(ReactionScript)
		{
			ReactionScripts.Add(ReactionScript);
			ReactionScript=nullptr;
		}
	}
}

void UOmegaDamageTypeReactionAsset::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color = ReactionColor;
}

float UOmegaDamageTypeReactionAsset::ModifyDamage_Implementation(UOmegaAttribute* Attribute,
	UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	float dmg=BaseDamage;
	for(auto* s : ReactionScripts)
	{
		if(s)
		{
			dmg=s->OnDamageApplied(Target,Attribute,BaseDamage);
		}
	}
	return dmg;
}


UOmegaDamageTypeReaction* UOmegaDamageTypeFunctions::GetScriptFromCombatantDamageReaction(UCombatantComponent* Combatant,
                                                                                          UOmegaDamageType* DamageType, TSubclassOf<UOmegaDamageTypeReaction> ScriptClass)
{
	if(Combatant && DamageType)
	{
		if(const UOmegaDamageTypeReactionAsset* ReactAsset = Combatant->DamageTypeReactions.FindOrAdd(DamageType))
		{
			
		}
	}
	return nullptr;
}



//################################################################
// DAMAGE SCRIPT
//################################################################
float UOmegaDamageTypeScript::OnDamageApplied_Implementation(float BaseDamage) const
{
	return BaseDamage;
}

void UOmegaDamageTypeScript::OnEffectApplied_Implementation(AOmegaGameplayEffect* Effect) const
{
	return;
}
