// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataAsset.h"
#include "DataInterface_General.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "OmegaDataTrait.h"
#include "OmegaDataTraitCollection.h"
#include "Data/DataAssetCollectionInterface.h"
#include "Data/SoftPropertiesInterface.h"
#include "Gameplay/DataInterface_AttributeModifier.h"
#include "Gameplay/DataInterface_OmegaEffect.h"
#include "Gameplay/Combatant/DataInterface_SkillSource.h"

#include "OmegaDataItem.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADATA_API UOmegaDataItem : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataAssetCollectionInterface,
																public ISoftPropertiesInterface, public IDataInterface_AttributeModifier, public IDataInterface_OmegaEffect, public IDataInterface_SkillSource
{
	GENERATED_BODY()

public:

	//General
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", DisplayName="Name")
	FText DisplayName;
	
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
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Tags", AdvancedDisplay)
	FGameplayTag GameplayID;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Tags")
	FGameplayTag GameplayCategory;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Tags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Tags", AdvancedDisplay)
	TMap<FString, FGameplayTagQuery> TagQueries;

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
	
//////////////////////
/// DATA INTERFACE
/////////////////////

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
FGameplayTag GetObjectGameplayCategory();
	virtual FGameplayTag GetObjectGameplayCategory_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTagContainer GetObjectGameplayTags();
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation();
	
	//DataInterface

	//Texts
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralDataText(const FString& Label, const class UObject* Context,	FText& Name, FText& Description);
	virtual void GetGeneralDataText_Implementation(const FString& Label, const class UObject* Context, FText& Name, FText& Description);
	
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	//Images
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const class UObject* Context, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush);

	UFUNCTION(BlueprintNativeEvent)
	int32 GetMaxCollectionNumber();
	virtual int32 GetMaxCollectionNumber_Implementation() override;

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;
	virtual TArray<FOmegaEffectContainer> GetOmegaEffects_Implementation() override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation() override;

	UFUNCTION()
	TMap<FString, FString> DEBUG_GetProperties();
	
	//Item Properties
	FString Local_GetItemProperty(const FString& Property);
	TArray<FString> Local_GetItemPropertyList(const FString& Property);

	UFUNCTION()
	FString GetItemProperty_String(const FString& Property);
	/*
	UFUNCTION(BlueprintPure, Category="DataItem|Properties")
	int32 GetItemProperty_Int32(const FString& Property);
	UFUNCTION(BlueprintPure, Category="DataItem|Properties")
	float GetItemProperty_Float(const FString& Property);
	UFUNCTION(BlueprintPure, Category="DataItem|Properties")
	bool GetItemProperty_Bool(const FString& Property);
	*/
	
	//////////////////////
	/// DATA INTERFACE
	/////////////////////
	
};
