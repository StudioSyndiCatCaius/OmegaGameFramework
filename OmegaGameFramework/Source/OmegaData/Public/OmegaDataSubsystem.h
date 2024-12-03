// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataItemComponent.h"
#include "GameplayTagContainer.h"
#include "OmegaDataTrait.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaDataSubsystem.generated.h"

class UOmegaDataItem;
class UWorld;

UCLASS(DisplayName="Omega Subsystem: Data Items")
class OMEGADATA_API UOmegaDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY() TArray<UOmegaDataItem*> PrivateDataItems;
	UPROPERTY() TMap<FString,UOmegaDataItem*> NamedItems;
	UPROPERTY() TMap<FGameplayTag, UOmegaDataItem*> DataItemIDs;
public:

	//###########################################################################################
	// DATA ITEMS
	//###########################################################################################
	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem", meta=(CompactNodeTitle="Data Items"))
	TArray<UOmegaDataItem*> GetAllDataItems();

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem", meta=(CompactNodeTitle="Data Item"))
	UOmegaDataItem* GetDataItemOfID(FGameplayTag ID);
	
	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	TArray<UOmegaDataItem*> GetAllDataItemsOfCategory(FGameplayTag CategoryTag, bool Exact);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	TArray<UOmegaDataItem*> GetAllDataItemsWithTags(FGameplayTagContainer Tags, bool Exact);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	TArray<UOmegaDataItem*> GetAllDataItemsWithTrait(TSubclassOf<UOmegaDataTrait> Trait);
	
	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	TArray<UOmegaDataItem*> GetAllDataItemsWithInterface(TSubclassOf<UInterface> Interface);
	
	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem")
	UOmegaDataItem* GetDataItemFromName(const FString& Name);

	UFUNCTION(BlueprintCallable, Category="OmegaDataSubsytem")
	UOmegaDataItem* CreateDataItemFromString(FString StringData,TSubclassOf<UOmegaDataItemConstructor> ConstructorClass, FString ItemName);
	
	//###########################################################################################
	// DATA Component
	//###########################################################################################

	void RegisterDataComponent(UDataItemComponent* NewComponent);

	UPROPERTY()
	TArray<UDataItemComponent*> Local_DataComponentList;

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem|Data Item Component")
	TArray<UDataItemComponent*> GetActiveDataItemComponents();

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem|Data Item Component")
	UDataItemComponent* GetComponentByDataItem(UOmegaDataItem* DataItem);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem|Data Item Component")
	TArray<UDataItemComponent*> GetComponentsByDataItem(UOmegaDataItem* DataItem);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem|Data Item Component", meta=(AdvancedDisplay="Exact"))
	TArray<UDataItemComponent*> GetComponentsOfDataItemWithTags(UOmegaDataItem* DataItem, FGameplayTagContainer EntityTags, bool Exact);
	
	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem|Data Item Component")
	AActor* GetActorByDataItem(UOmegaDataItem* DataItem);

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem|Data Item Component")
	TArray<AActor*> GetActorsByDataItem(UOmegaDataItem* DataItem);

	//###########################################################################################
	// EXTERNALL FILES
	//###########################################################################################

	UFUNCTION(BlueprintPure, Category="OmegaDataSubsytem|Data Item Component")
	TArray<FString> LoadGameDataFiles(const FString& Extension);
	
};

UCLASS()
class OMEGADATA_API UOmegaDataItemFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Omega|Data Items", meta=(DeterminesOutputType="Class"))
	static UOmegaDataTrait* TryGetDataTraitByClass(UObject* Source, TSubclassOf<UOmegaDataTrait> Class);

	UFUNCTION(BlueprintCallable, Category="Omega|Data Items")
	static UOmegaDataTrait* TryGetDataTraitByInterface(UObject* Source, TSubclassOf<UInterface> Class);
};

UCLASS(Blueprintable, BlueprintType)
class OMEGADATA_API UOmegaDataItemConstructor : public UObject
{
	GENERATED_BODY()
	
protected:
	
	UOmegaDataItemConstructor(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(Transient)
	UWorld* WorldPrivate = nullptr;
	virtual UWorld* GetWorld() const override;

public:
	UFUNCTION(BlueprintImplementableEvent, Category="OmegaDataItem")
	void OnItemCreated(const FString& StringData, FText& Name, FText& Description, FSlateBrush& Icon, FGameplayTag& CategoryTag, FGameplayTagContainer& GameplayTags);
};