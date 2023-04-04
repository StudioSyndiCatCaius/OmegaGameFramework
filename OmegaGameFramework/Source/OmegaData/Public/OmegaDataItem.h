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
#include "Gameplay/Combatant/DataInterface_Skill.h"
#include "Gameplay/Combatant/DataInterface_SkillSource.h"

#include "OmegaDataItem.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADATA_API UOmegaDataItem : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataAssetCollectionInterface,
																public ISoftPropertiesInterface, public IDataInterface_AttributeModifier, public IDataInterface_OmegaEffect,
																public IDataInterface_SkillSource, public IDataInterface_Skill, public IDataInterface_ContextAV
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

	//###############################################################################
	// Contextual Data
	//###############################################################################
	virtual TMap<FGameplayTag, ULevelSequence*> GetContextAVSequences_Implementation() override;
	virtual TMap<FGameplayTag, USoundBase*> GetContextAVSounds_Implementation() override;
	virtual TMap<FGameplayTag, UNiagaraSystem*> GetContextAVNiagara_Implementation() override;
	
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
	
	
};
