﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Interfaces/OmegaInterface_Skill.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Component_Equipment.generated.h"

class UDataAssetCollectionComponent;

UINTERFACE(MinimalAPI) class UDataInterface_Equipable : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Equipable
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Equipment")
	bool CanEquipItem(UEquipmentComponent* Component);

	UFUNCTION(BlueprintNativeEvent, Category="Equipment")
	bool CanEquipItem_InSlot(UEquipmentSlot* Slot) const;
};

UINTERFACE(MinimalAPI) class UDataInterface_EquipmentSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_EquipmentSource
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Equipment")
	TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetEquipment();


};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemEquipped, UPrimaryDataAsset*, Item, UEquipmentSlot*, Slot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemUnequipped, UPrimaryDataAsset*, Item, UEquipmentSlot*, Slot);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UEquipmentComponent : public UActorComponent, public IDataInterface_AttributeModifier, public IDataInterface_SkillSource
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

	UPROPERTY(EditAnywhere, Category="Equipment",DisplayName="Equipment")
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> Slots;
	
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Equipment")
	UEquipmentScript* Script;

	UFUNCTION(BlueprintPure, Category="Equipment", meta=(CompactNodeTitle="Equipment"))
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> GetEquipment();
	UFUNCTION(BlueprintCallable, Category="Equipment")
	void SetEquipment(TMap<UEquipmentSlot*, UPrimaryDataAsset*> Equipment);
	UFUNCTION(BlueprintCallable, Category="Equipment",DisplayName="Set Equipment (From Source)")
	void SetEquipment_FromSource(UObject* Source);
	
	UFUNCTION(BlueprintPure, Category="Equipment", meta=(CompactNodeTitle="Equipment"))
	TArray<UPrimaryDataAsset*> GetEquippedItems();
	
	//Determines what assets can be accepted. Blank will accept all.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
	FGameplayTagContainer AcceptedItemTags;

	//Determines what assets can be accepted. Blank will reject none.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
	FGameplayTagContainer RejectedItemTags;
	

	
	bool IsItemAccepted(UPrimaryDataAsset* Item);
	bool IsItemRejected(UPrimaryDataAsset* Item);

	UFUNCTION(BlueprintCallable, Category="Equipment")
	bool CanEquipItem(UPrimaryDataAsset* Item, UEquipmentSlot* Slot);

	UFUNCTION(BlueprintCallable, Category="Equipment")
	TArray<UPrimaryDataAsset*> FilterEquippableItems(TArray<UPrimaryDataAsset*> Items, UEquipmentSlot* Slot);
	
	UFUNCTION(BlueprintCallable, Category="Equipment", DisplayName="Equip Item")
	bool EquipItem(UPrimaryDataAsset* Item, UEquipmentSlot* Slot);
	
	UFUNCTION(BlueprintCallable, Category="Equipment")
	bool UnequipSlot(UEquipmentSlot* Slot);
	
	UFUNCTION(BlueprintPure, Category="Equipment")
	UPrimaryDataAsset* GetEquipmentInSlot(UEquipmentSlot* Slot, bool& bValidItem);
	
	UPROPERTY(BlueprintAssignable)
	FOnItemEquipped OnItemEquipped;

	UPROPERTY(BlueprintAssignable)
	FOnItemUnequipped OnItemUnequipped;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment|Combatant")
    bool bModifyAttributes=true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment|Combatant")
	bool bIsSkillSource=true;
	
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;

	//----------------------
	// Data Collect
	//----------------------
	UPROPERTY()
	UDataAssetCollectionComponent* LinkedCollectionComp;
	
	UFUNCTION(BlueprintCallable, Category="Equipment", meta=(Keywords="set, get"))
	void LinkAssetCollectionComponent(UDataAssetCollectionComponent* Component);

	UFUNCTION(BlueprintCallable, Category="Equipment", meta=(Keywords="set, get"))
	void ClearLinkedAssetCollectionComponent(UDataAssetCollectionComponent* Component);
};

//##############################################################################################
// Equipment Script
//##############################################################################################

USTRUCT(BlueprintType)
struct FOmegaEquipmentData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combatant")
	TArray<FOmegaAttributeModifier> AttributesMods;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combatant")
	TArray<UPrimaryDataAsset*> Skills;
};


UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, Abstract, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UEquipmentScript : public UObject
{
	GENERATED_BODY()

	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;

	UEquipmentScript(const FObjectInitializer& ObjectInitializer);

public:
	

};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, Abstract, CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UEquipmentSlotScript : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, Category="Equipment")
	void OnEquip(UEquipmentComponent* Component, UObject* Item) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Equipment")
	void OnUnequip(UEquipmentComponent* Component, UObject* Item) const;
	
	UFUNCTION(BlueprintNativeEvent, Category="Equipment")
	bool CanEquipItem(UObject* Item) const;
	
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
	TArray<UEquipmentSlotScript*> SlotScripts;
	

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
	bool CanSlotEquipItem(UPrimaryDataAsset* Item);
	
};

UCLASS()
class UOmegaEquipmentFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Equipment", meta=(ExpandBoolAsExecs = "Outcome"))
	static UPrimaryDataAsset* TryGetEquipmentInSlot(UObject* Target,UEquipmentSlot* Slot, bool& Outcome);
	
};
