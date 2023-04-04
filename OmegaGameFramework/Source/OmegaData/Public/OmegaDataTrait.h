// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_ContextAV.h"
#include "DataInterface_General.h"
#include "GameFramework/Actor.h"
#include "LevelSequence.h"
#include "GameplayTagContainer.h"
#include "Data/SoftPropertiesInterface.h"
#include "OmegaDataTrait.generated.h"

class AActor;
class UUserWidget;
class UOmegaDataItem;
class USoundBase;
class UNiagaraSystem;

UCLASS(Blueprintable, abstract, const, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGADATA_API UOmegaDataTrait : public UObject, public IDataInterface_General, public IDataInterface_ContextAV
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trait")
	FString TraitLabel;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait", meta=(AdvancedDisplay="Tags"))
	void AppliedToActor(AActor* Actor, const FString& Flag, FGameplayTagContainer Tags) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait", meta=(AdvancedDisplay="Tags"))
	void AppliedToComponent(UActorComponent* Component, const FString& Flag, FGameplayTagContainer Tags) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait", meta=(AdvancedDisplay="Tags"))
	void AppliedToWidget(UUserWidget* Widget, const FString& Flag, FGameplayTagContainer Tags) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait")
	FText AppendedItemName() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait")
	FText AppendedItemDescription() const;

	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait")
	FGameplayTagContainer AppendedItemTags() const;

	// SOFT PROPERTIES
	//BlueprintImplementableEvent, Category="Properties", DisplayName="Get Trait Property (Bool)"
	/*
	UFUNCTION(Category="Properties", DisplayName="Get Trait Property (Bool)")
	bool BindTraitProperty_Bool(const FString& Property, bool& ValidProperty) const;
	UFUNCTION(Category="Properties", DisplayName="Get Trait Property (Int32)")
	int32 BindTraitProperty_Int(const FString& Property, bool& ValidProperty) const;
	UFUNCTION(Category="Properties", DisplayName="Get Trait Property (Float)")
	float BindTraitProperty_Float(const FString& Property, bool& ValidProperty) const;
	UFUNCTION(Category="Properties", DisplayName="Get Trait Property (String)")
	FString BindTraitProperty_String(const FString& Property, bool& ValidProperty) const;
	UFUNCTION(Category="Properties", DisplayName="Get Trait Property (Object)")
	UObject* BindTraitProperty_Object(const FString& Property, bool& ValidProperty) const;
	*/
	
	//###############################################################################
	// Contextual Data
	//###############################################################################

	virtual TMap<FGameplayTag, ULevelSequence*> GetContextAVSequences_Implementation() override;
	virtual TMap<FGameplayTag, USoundBase*> GetContextAVSounds_Implementation() override;
	virtual TMap<FGameplayTag, UNiagaraSystem*> GetContextAVNiagara_Implementation() override;
	
};
