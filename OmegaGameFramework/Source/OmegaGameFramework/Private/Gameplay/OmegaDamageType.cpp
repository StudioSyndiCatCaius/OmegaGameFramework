// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/OmegaDamageType.h"
#include "OmegaAttribute.h"
#include "Gameplay/CombatantComponent.h"


void UOmegaDamageType::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                         FText& Description)
{
	Name = DamageTypeName;
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

TMap<FGameplayTag, ULevelSequence*> UOmegaDamageType::GetContextAVSequences_Implementation()
{
	return ContextSequences;
}

TMap<FGameplayTag, USoundBase*> UOmegaDamageType::GetContextAVSounds_Implementation()
{
	return ContextSounds;
}

TMap<FGameplayTag, UNiagaraSystem*> UOmegaDamageType::GetContextAVNiagara_Implementation()
{
	return ContextNiagara;
}

void UOmegaDamageTypeReactionAsset::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color = ReactionColor;
}

void UOmegaDamageTypeReactionAsset::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context,
	FText& Name, FText& Description)
{
	Name = ReactionName;
	Description = ReactionDescription;
}

FGameplayTagContainer UOmegaDamageTypeReactionAsset::GetObjectGameplayTags_Implementation()
{
	return ReactionTags;
}

UOmegaDamageTypeReaction* UOmegaDamageTypeFunctions::GetScriptFromCombatantDamageReaction(UCombatantComponent* Combatant,
	UOmegaDamageType* DamageType, TSubclassOf<UOmegaDamageTypeReaction> ScriptClass)
{
	if(Combatant && DamageType)
	{
		if(const UOmegaDamageTypeReactionAsset* ReactAsset = Combatant->DamageTypeReactions.FindOrAdd(DamageType))
		{
			if(ReactAsset->ReactionScript)
			{
				return ReactAsset->ReactionScript;
			}
		}
	}
	return nullptr;
}

void UOmegaDamageTypeReaction::OnEffectApplied_Implementation(AOmegaGameplayEffect* Effect) const
{
}

float UOmegaDamageTypeReaction::OnDamageApplied_Implementation(UOmegaAttribute* Attribute, float BaseDamage) const
{
	return BaseDamage;
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
