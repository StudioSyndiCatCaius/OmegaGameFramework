// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "GameFramework/Actor.h"
#include "LevelSequence.h"
#include "GameplayTagContainer.h"
#include "Functions/OmegaFunctions_SoftProperty.h"
#include "OmegaDataTrait.generated.h"

class AActor;
class UUserWidget;
class UOmegaDataItem;
class USoundBase;
class UNiagaraSystem;

UCLASS(Blueprintable, abstract, const, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGADATA_API UOmegaDataTrait : public UObject, public IDataInterface_General
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

	//###############################################################################
	// Actor Events
	//###############################################################################

	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait")
	void OnActorTagEvent(AActor* Actor, FGameplayTag Event) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="DataItem|Trait")
	void OnActorTick(AActor* Actor, float DeltaTime) const;
	// SOFT PROPERTIES
	
};
