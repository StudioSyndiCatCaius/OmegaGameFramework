// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LuaInterface.h"
#include "LuaValue.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "OmegaFunctions_ScriptedEffects.generated.h"

class UCombatantComponent;
class AOmegaGameplayCue;
class UCurveFloat;

USTRUCT(BlueprintType)
struct FOmegaCustomScriptedEffects
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effect")
	TArray<UOmegaScriptedEffectAsset*> EffectAssets;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Effect")
	TArray<UOmegaScriptedEffect*> CustomEffects;

	TArray<UOmegaScriptedEffect*> GetAllEffects();
};


UCLASS(EditInlineNew, Blueprintable, BlueprintType, CollapseCategories, Abstract,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaScriptedEffect : public UObject, public ILuaInterface, public IDataInterface_General
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect")
	bool CanApplyEffect(UCombatantComponent* Target, UCombatantComponent* Instigator);
	
	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect")
	bool OnEffectApplied(UCombatantComponent* Target, UCombatantComponent* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category="Scripted Effect")
	TArray<TSubclassOf<AOmegaGameplayCue>> GetCuesToPlay();

	UPROPERTY() FLuaValue lua_val;
	virtual FLuaValue GetValue_Implementation(const FString& Field) override;
	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field) override;
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

public:
	UFUNCTION(BlueprintCallable, Category="Omega|Combat")
	static FText GetEffects_Description(FOmegaCustomScriptedEffects effects, const FString& delimiter=" ");
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combat", DisplayName="Apply Scripted Effects")
	static void ApplyScriptedEffects_List(TArray<UOmegaScriptedEffect*> Effects, UCombatantComponent* Target=nullptr, UCombatantComponent* Instigator=nullptr);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combat", DisplayName="Apply Scripted Effects (Asset)")
	static void ApplyScriptedEffects_Asset(UOmegaScriptedEffectAsset* EffectAsset, UCombatantComponent* Target=nullptr, UCombatantComponent* Instigator=nullptr);

	UFUNCTION(BlueprintCallable, Category="Omega|Combat", DisplayName="Apply Scripted Effects (Asset)")
	static void ApplyScriptedEffects_Source(UObject* EffectAsset, UCombatantComponent* Target=nullptr, UCombatantComponent* Instigator=nullptr,FGameplayTag Tag=FGameplayTag());
	
	UFUNCTION(BlueprintCallable, Category="Omega|Combat", DisplayName="Apply Scripted Effects (Custom)")
	static void ApplyCustomScriptedEffectToCombatant(FOmegaCustomScriptedEffects Effects, UCombatantComponent* Target=nullptr, UCombatantComponent* Instigator=nullptr);


};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UOmegaScriptedEffectsInterface : public UInterface
{
	GENERATED_BODY()
};

class OMEGAGAMEFRAMEWORK_API IOmegaScriptedEffectsInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|ScriptedEffects",DisplayName="Effect - Get Effects")
	FOmegaCustomScriptedEffects GetScriptedEffects(FName Name);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|ScriptedEffects",DisplayName="Effect - On Applied")
	FOmegaCustomScriptedEffects OnEffectsApplied(UCombatantComponent* Target,UCombatantComponent* Instigator,FGameplayTag Tag);
};
