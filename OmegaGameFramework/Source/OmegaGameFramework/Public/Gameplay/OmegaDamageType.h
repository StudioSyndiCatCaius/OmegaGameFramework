// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_ContextAV.h"
#include "Engine/DataAsset.h"
#include "DataInterface_General.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "OmegaDamageType.generated.h"

class AOmegaGameplayEffect;
class UNiagaraSystem;
class ULevelSequence;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDamageType : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataInterface_ContextAV

{
	GENERATED_BODY()

public: 
	//General
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText DamageTypeName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General", DisplayName="Icon")
	FSlateBrush DamageTypeIcon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General", DisplayName="Color")
	FLinearColor DamageTypeColor;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tags")
    FGameplayTag GameplayCategory;
	
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tags")
    FGameplayTagContainer GameplayTags;

	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadOnly, Category="Damage Type")
	UOmegaDamageTypeScript* DamageScript;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;

	//##############################################################################
	// Context AV
	//##############################################################################
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AV")
	TMap<FGameplayTag, ULevelSequence*> ContextSequences;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AV")
	TMap<FGameplayTag, USoundBase*> ContextSounds;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AV")
	TMap<FGameplayTag, UNiagaraSystem*> ContextNiagara;

	virtual TMap<FGameplayTag, ULevelSequence*> GetContextAVSequences_Implementation() override;
	virtual TMap<FGameplayTag, USoundBase*> GetContextAVSounds_Implementation() override;
	virtual TMap<FGameplayTag, UNiagaraSystem*> GetContextAVNiagara_Implementation() override;
};

UCLASS(Blueprintable, BlueprintType, Const, EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaDamageTypeScript : public UObject
{
	GENERATED_BODY()

public: 

	UFUNCTION(BlueprintNativeEvent, Category="Damage Type")
	float OnDamageApplied(float BaseDamage) const;

	UFUNCTION(BlueprintNativeEvent, Category="Damage Type")
	void OnEffectApplied(AOmegaGameplayEffect* Effect) const;
};