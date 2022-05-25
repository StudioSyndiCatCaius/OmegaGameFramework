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
#include "OmegaDataItem.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADATA_API UOmegaDataItem : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataAssetCollectionInterface
{
	GENERATED_BODY()

public:

	//General
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", DisplayName="Name")
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General")
	FSlateBrush Icon;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", meta=( MultiLine="true" ), DisplayName="Description")
	FText DisplayDescription;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="General", AdvancedDisplay)
	int32 MaxCollectionAmount = 99;

	//Tags
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Tags")
	FGameplayTag GameplayCategory;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Tags")
	FGameplayTagContainer GameplayTags;

	//Traits
	UPROPERTY(EditAnywhere, Category="Traits")
	TArray<UOmegaDataTraitCollection*> TraitCollections;
	
	UPROPERTY(BlueprintReadOnly, Category="Traits", instanced, EditAnywhere)
	TArray<class UOmegaDataTrait*> Traits;

	UFUNCTION()
	TArray<class UOmegaDataTrait*>GetAllValidTraits();

	//Function
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
	TArray<UOmegaDataTrait*> GetTraitsWithInterface(TSubclassOf<UInterface> Interface);
	
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

	//Images
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const class UObject* Context, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush);

	UFUNCTION(BlueprintNativeEvent)
	int32 GetMaxCollectionNumber();
	virtual int32 GetMaxCollectionNumber_Implementation() override;
	
};
