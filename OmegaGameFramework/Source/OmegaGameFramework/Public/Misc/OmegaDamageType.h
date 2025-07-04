// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneralDataObject.h"

#include "Engine/DataAsset.h"
#include "Functions/OmegaFunctions_AVContext.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaDamageType.generated.h"

class AOmegaGameplayEffect;
class UNiagaraSystem;
class ULevelSequence;
class UOmegaAttribute;
class UCombatantComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDamageType : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataInterface_ContextString

{
	GENERATED_BODY()

public: 
	//General
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText DamageTypeName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General", DisplayName="Icon")
	FSlateBrush DamageTypeIcon;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General", DisplayName="Description",meta=(MultiLine))
	FText DisplayDescription;	
	
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Contex")
	TMap<FGameplayTag,FText> Context_Text;

	virtual FText GetContextAV_Text_Implementation(FGameplayTag ID) override
	{
		if(Context_Text.Contains(ID)) {return Context_Text[ID];} return FText();
	}
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

//##################################################################################################################
// TYPE REACTIONS
//##################################################################################################################

UCLASS(Blueprintable, BlueprintType, Const, CollapseCategories, EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaDamageTypeReaction : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category="Damage Type")
	float OnDamageApplied(UCombatantComponent* Combatant,UOmegaAttribute* Attribute, float BaseDamage) const;

	UFUNCTION(BlueprintNativeEvent, Category="Damage Type")
	void OnEffectApplied(UCombatantComponent* Combatant,AOmegaGameplayEffect* Effect) const;

};

//##################################################################################################################
// Reaction Asset
//##################################################################################################################

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDamageTypeReactionAsset : public UOmegaDataAsset, public IDataInterface_DamageModifier
{
	GENERATED_BODY()

	// remove this in future versions
	UPROPERTY() bool b_init;
	UPROPERTY() UOmegaDamageTypeReaction* ReactionScript;
public:
	UOmegaDamageTypeReactionAsset();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Default")
	FLinearColor ReactionColor;

	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category="Default")
	TArray<UOmegaDamageTypeReaction*> ReactionScripts;

	
};

//##################################################################################################################
// Reaction Asset
//##################################################################################################################

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDamageTypeFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Omega|Combat|DamageType|Reactions", meta=(DeterminesOutputType="ScriptClass",DeprecatedFunction))
	static UOmegaDamageTypeReaction* GetScriptFromCombatantDamageReaction(UCombatantComponent* Combatant, UOmegaDamageType* DamageType, TSubclassOf<UOmegaDamageTypeReaction> ScriptClass);
};