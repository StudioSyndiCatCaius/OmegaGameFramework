// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaDataTrait.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaDataSubsystem.generated.h"

class UOmegaDataItem;

UCLASS()
class OMEGADATA_API UOmegaDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY()
	TArray<UOmegaDataItem*> PrivateDataItems;


public:

	//UFUNCTION(BlueprintCallable, Category="OmegaDataSubsytem", meta=(CompactNodeTitle="Data Items"))
	//void ScanPathForDataItems();
	
	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem", meta=(CompactNodeTitle="Data Items"))
	TArray<UOmegaDataItem*> GetAllDataItems();
	
	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	TArray<UOmegaDataItem*> GetAllDataItemsOfCategory(FGameplayTag CategoryTag, bool Exact);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	TArray<UOmegaDataItem*> GetAllDataItemsWithTags(FGameplayTagContainer Tags, bool Exact);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	TArray<UOmegaDataItem*> GetAllDataItemsWithTrait(TSubclassOf<UOmegaDataTrait> Trait);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	UOmegaDataItem* GetDataItemFromName(const FString& Name);
};
