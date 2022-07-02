// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "OmegaDataTrait.generated.h"

class AActor;
class UUserWidget;
class UOmegaDataItem;

UCLASS(Blueprintable, abstract, const, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGADATA_API UOmegaDataTrait : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trait")
	FString TraitLabel;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait", meta=(AdvancedDisplay="Flag, Tags"))
	void AppliedToActor(AActor* Actor, const FString& Flag, FGameplayTagContainer Tags) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait", meta=(AdvancedDisplay="Flag, Tags"))
	void AppliedToWidget(UUserWidget* Widget, const FString& Flag, FGameplayTagContainer Tags) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait", meta=(AdvancedDisplay="Flag, Tags"))
	FText AppendedItemName() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait", meta=(AdvancedDisplay="Flag, Tags"))
	FText AppendedItemDescription() const;

	/*
	UFUNCTION(BlueprintImplementableEvent, Category="Properties", DisplayName="Set Trait Property (Bool)")
	bool BindTraitProperty_Bool(const FString& Property, bool& ValidProperty);
	UFUNCTION(BlueprintImplementableEvent, Category="Properties", DisplayName="Set Trait Property (Int)")
	int32 BindTraitProperty_Int(const FString& Property, bool& ValidProperty);
	UFUNCTION(BlueprintImplementableEvent, Category="Properties", DisplayName="Set Trait Property (Bool)")
	float BindTraitProperty_Float(const FString& Property, bool& ValidProperty);
	UFUNCTION(BlueprintImplementableEvent, Category="Properties", DisplayName="Set Trait Property (Bool)")
	FString BindTraitProperty_String(const FString& Property, bool& ValidProperty);
	UFUNCTION(BlueprintImplementableEvent, Category="Properties", DisplayName="Set Trait Property (Data Asset)")
	UPrimaryDataAsset* BindTraitProperty_Asset(const FString& Property, bool& ValidProperty);
	UFUNCTION(BlueprintImplementableEvent, Category="Properties", DisplayName="Set Trait Property (Data Item)")
	UOmegaDataItem* BindTraitProperty_Item(const FString& Property, bool& ValidProperty);
	*/
};
