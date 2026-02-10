// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataAsset.h"
#include "Interfaces/I_Common.h"
#include "Interfaces/I_Combatant.h"
#include "Interfaces/I_Skill.h"
#include "Engine/GameInstance.h"
#include "OmegaDataTrait.h"
#include "OmegaDataTraitCollection.h"
#include "Components/Component_Inventory.h"
#include "Functions/F_SoftProperty.h"


#include "OmegaDataItem.generated.h"

class UAnimMontage;
class UOmegaDamageType;
class UNiagaraSystem;
class ULevelSequence;

UCLASS()
class OMEGADATA_API UOmegaDataItem : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataAssetCollectionInterface,
																public IOmegaSoftPropertyInterface, public IDataInterface_AttributeModifier,
																public IDataInterface_SkillSource, public IDataInterface_Skill, public ILuaInterface
{
	GENERATED_BODY()

public:

	//General
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", DisplayName="Name")
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	FLinearColor CustomColor;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override { Color=CustomColor; }; 
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	FString CustomLabel;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General")
	FSlateBrush Icon;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", meta=( MultiLine="true" ), DisplayName="Description")
	FText DisplayDescription;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	int32 MaxCollectionAmount = 99;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	int32 SortOrder;
	
	//###############################################################################
	// Gameplay Tags
	//###############################################################################
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	FGameplayTag GameplayID;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General")
	FGameplayTag GameplayCategory;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	TMap<FString, FGameplayTagQuery> TagQueries;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	bool bOverrideInAssetHandler;

	UFUNCTION(BlueprintPure, Category="OmegaDataItem|Tags", meta=(Keywords="Gameplay, Tag"))
	bool AreTagsAccepted(const FString& Query, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category="OmegaDataItem|Tags", meta=(Keywords="Gameplay, Tag"))
	bool IsObjectAccepted(const FString& Query, UObject* Object);
	
	//###############################################################################
	// Traits
	//###############################################################################
	UPROPERTY(EditAnywhere, Category="Traits", AdvancedDisplay)
	TArray<UOmegaDataTraitCollection*> TraitCollections;
	
	UPROPERTY(BlueprintReadOnly, Category="Traits", instanced, EditAnywhere)
	TArray<class UOmegaDataTrait*> Traits;

	UFUNCTION()
	TArray<class UOmegaDataTrait*>GetAllValidTraits();

	//Function
	UFUNCTION(BlueprintPure, Category="DataItem", meta=(DeterminesOutputType = "Class"))
	UOmegaDataTrait* GetTraitByLabel(const FString& Label);

	UFUNCTION(BlueprintPure, Category="DataItem", meta=(DeterminesOutputType = "Class"))
	TArray<UOmegaDataTrait*> GetTraitsByLabel(const FString& Label);
	
	UFUNCTION(BlueprintPure, Category="DataItem", meta=(DeterminesOutputType = "Class"))
	UOmegaDataTrait* GetTraitByType(TSubclassOf<UOmegaDataTrait> Class);
	
	UFUNCTION(BlueprintPure, Category="DataItem", meta=(DeterminesOutputType = "Class"))
	TArray<UOmegaDataTrait*> GetTraitsByType(TSubclassOf<UOmegaDataTrait> Class);

	UFUNCTION(BlueprintCallable, Category="DataItem", meta=(DeterminesOutputType = "Class"))
	void ApplyTraitsToActor(AActor* Actor, FString Flag, FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintCallable, Category="DataItem", meta=(DeterminesOutputType = "Class"))
	void ApplyTraitsToWidget(UUserWidget* Widget, FString Flag, FGameplayTagContainer Tags);

	//Interfaces
	UFUNCTION(BlueprintPure, Category="DataItem")
	UOmegaDataTrait* GetTraitWithInterface(TSubclassOf<UInterface> Interface);

	UFUNCTION(BlueprintPure, Category="DataItem")
	TArray<UOmegaDataTrait*> GetTraitsWithInterface(const UClass* Interface);

	//###############################################################################
	// Tag Event
	//###############################################################################
	
	//###############################################################################
	// Contextual Data
	//###############################################################################
	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", AdvancedDisplay)
	UAnimMontage* Montage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", AdvancedDisplay)
	USoundBase* Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", AdvancedDisplay)
	TMap<UOmegaAttribute*, float> AttributeValues;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", AdvancedDisplay)
	TArray<FOmegaAttributeModifier> AttributeModifiers;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", AdvancedDisplay)
	UOmegaDamageType* DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", AdvancedDisplay)
	TArray<FOmegaEffectContainer> Effects;
	*/
	//###############################################################################
	// Lua
	//###############################################################################
private:
	UPROPERTY() FLuaValue lua_val;
public:
	virtual FLuaValue GetKey_Implementation() override;
	virtual FLuaValue GetValue_Implementation(const FString& Field) override;
	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field) override;

	
	//###############################################################################
	// Gameplay Tags
	//###############################################################################
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;

	//###############################################################################
	// General TExt
	//###############################################################################
	virtual void GetGeneralDataText_Implementation(const FString& Label, const class UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const class UObject* Context, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush) override;

	virtual int32 GetMaxCollectionNumber_Implementation() override;

	//###############################################################################
	// Combatant
	//###############################################################################
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;
	
	//###############################################################################
	// Soft Properties
	//###############################################################################
	virtual FString GetSoftProperty_Implementation(const FName Property) override;
	virtual TMap<FName, FString> GetSoftPropertyMap_Implementation() override;

	//###############################################################################
	// Asset Actions
	//###############################################################################


};
