// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/OmegaDamageType.h"



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
