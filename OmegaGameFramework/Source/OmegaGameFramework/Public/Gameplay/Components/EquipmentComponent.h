// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Gameplay/DataInterface_AttributeModifier.h"
#include "Engine/DataAsset.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "EquipmentComponent.generated.h"

class UDataAssetCollectionComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemEquipped, UPrimaryDataAsset*, Item, FString, Slot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemUnequipped, UPrimaryDataAsset*, Item, FString, Slot);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UEquipmentComponent : public UActorComponent, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEquipmentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category="Equipment")
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> Slots;
	
	UPROPERTY()
	TMap<FString, UPrimaryDataAsset*> EquippedItems;

	//Slot and Id converstion
	UEquipmentSlot* GetSlotFromID(const FString& ID);
	FString GetSlotID(UEquipmentSlot* Slot);

	UFUNCTION(BlueprintPure, Category="Equipment", meta=(CompactNodeTitle="Equipment"))
	TMap<FString, UPrimaryDataAsset*> GetEquipment();

	UFUNCTION(BlueprintPure, Category="Equipment", meta=(CompactNodeTitle="Equipment"))
	TArray<UPrimaryDataAsset*> GetEquippedItems();
	
	UFUNCTION(BlueprintCallable, Category="Equipment")
	void SetEquipment(TMap<FString, UPrimaryDataAsset*> Equipment);
	
	//Determines what assets can be accepted. Blank will accept all.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
	FGameplayTagContainer AcceptedItemTags;

	//Determines what assets can be accepted. Blank will reject none.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
	FGameplayTagContainer RejectedItemTags;
	
	bool IsItemAccepted(UPrimaryDataAsset* Item);
	bool IsItemRejected(UPrimaryDataAsset* Item);

	
	UFUNCTION(BlueprintCallable, Category="Equipment", DisplayName="Equip Item")
	bool EquipItemToSlot(UPrimaryDataAsset* Item, UEquipmentSlot* Slot);
	
	UFUNCTION(BlueprintCallable, Category="Equipment", DisplayName="Equip Item (Slot Label)")
	bool EquipItem(UPrimaryDataAsset* Item, FString Slot);
	
	UFUNCTION(BlueprintCallable, Category="Equipment")
	bool UnequipSlot(FString Slot);
	
	UFUNCTION(BlueprintPure, Category="Equipment")
	UPrimaryDataAsset* GetEquipmentInSlot(FString Slot, bool& bValidItem);

	UPROPERTY(BlueprintAssignable)
	FOnItemEquipped OnItemEquipped;

	UPROPERTY(BlueprintAssignable)
	FOnItemUnequipped OnItemUnequipped;

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;

	//##############################################################################################
	// Data Collect
	//##############################################################################################
	UPROPERTY()
	UDataAssetCollectionComponent* LinkedCollectionComp;
	
	UFUNCTION(BlueprintCallable, Category="Equipment", meta=(Keywords="set, get"))
	void LinkAssetCollectionComponent(UDataAssetCollectionComponent* Component);

	UFUNCTION(BlueprintCallable, Category="Equipment", meta=(Keywords="set, get"))
	void ClearLinkedAssetCollectionComponent(UDataAssetCollectionComponent* Component);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UEquipmentSlot : public UPrimaryDataAsset, public IDataInterface_AttributeModifier, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FText SlotName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FText SlotDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FSlateBrush SlotIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Equipment")
	FGameplayTagContainer AcceptedCategories;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Equipment", DisplayName="Accepted Tags")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Equipment")
	UEquipmentSlotScript* SlotScript;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag SlotCategory;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTagContainer SlotTags;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
	
	UFUNCTION(BlueprintCallable, Category="EquipmentSlot")
	TArray<UPrimaryDataAsset*> FilterEquippableItems(TArray<UPrimaryDataAsset*> Items, UEquipmentComponent* Component=nullptr);
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, Abstract, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UEquipmentSlotScript : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, Category="Equipment")
	bool CanEquipItem(UObject* Item, UEquipmentComponent* Component=nullptr) const; 
};