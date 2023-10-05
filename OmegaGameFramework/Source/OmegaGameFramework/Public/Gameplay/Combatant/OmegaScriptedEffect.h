// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "Styling/SlateBrush.h"
#include "DataInterface_General.h"
#include "GameplayTagContainer.h"
#include "Curves/CurveFloat.h"
#include "Gameplay/CombatantComponent.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "Gameplay/OmegaGameplayCue.h"

#include "OmegaScriptedEffect.generated.h"

USTRUCT(BlueprintType)
struct FOmegaCustomScriptedEffects
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	TArray<UOmegaScriptedEffectAsset*> EffectAssets;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Effect")
	TArray<UOmegaScriptedEffect*> CustomEffects;
};


UCLASS(EditInlineNew, Blueprintable, BlueprintType, CollapseCategories, Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedEffect : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect")
	bool CanApplyEffect(UCombatantComponent* Target, UCombatantComponent* Instigator);
	
	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect")
	bool OnEffectApplied(UCombatantComponent* Target, UCombatantComponent* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect")
	TArray<TSubclassOf<AOmegaGameplayCue>> GetCuesToPlay();
};

UCLASS(EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedEffectAsset : public UPrimaryDataAsset, public IDataInterface_General
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="General", DisplayName="Name")
	FText EffectName;
	UPROPERTY(EditAnywhere, Category="General", DisplayName="Description")
	FText EffectDescription;
	UPROPERTY(EditAnywhere, Category="General", DisplayName="Icon")
	FSlateBrush EffectIcon;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Effect",meta=(ExposeOnSpawn))
	TArray<UOmegaScriptedEffect*> ScriptedEffects;
	
	UPROPERTY(EditAnywhere, Category="Effect")
	TArray<TSubclassOf<AOmegaGameplayCue>> GameplayCues;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedEffectFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Omega|Combat", DisplayName="Apply Scripted Effects")
	static void ApplyEffectScriptToCombatant(TArray<UOmegaScriptedEffect*> Effects, UCombatantComponent* Target=nullptr, UCombatantComponent* Instigator=nullptr);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combat", DisplayName="Apply Scripted Effects (Asset)")
	static void ApplyScriptedEffectToCombatant(UOmegaScriptedEffectAsset* EffectAsset, UCombatantComponent* Target=nullptr, UCombatantComponent* Instigator=nullptr);

	UFUNCTION(BlueprintCallable, Category="Omega|Combat", DisplayName="Apply Scripted Effects (Custom)")
	static void ApplyCustomScriptedEffectToCombatant(FOmegaCustomScriptedEffects Effects, UCombatantComponent* Target=nullptr, UCombatantComponent* Instigator=nullptr);

};