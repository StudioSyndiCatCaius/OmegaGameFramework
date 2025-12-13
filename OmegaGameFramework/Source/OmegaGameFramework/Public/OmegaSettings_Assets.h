// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaSettings_Assets.generated.h"

class UOmegaDamageType;
class UOmegaDamageTypeReactionAsset;
class UOmegaAttributeSet;
class UOmegaFaction;
class UOmegaAttribute;
class UEquipmentSlot;


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAppendedTraitSet : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TMap<UPrimaryDataAsset*,FOmegaObjectTraits> AppendedTraits;
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Assets : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	TMap<UEquipmentSlot*,UPrimaryDataAsset*> Conv_NamedEquipment(TMap<FName, UPrimaryDataAsset*>  in) const;
	
	FOmegaObjectTraits L_GetAppendedTraits(UObject* o);

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Named")
	TMap<FName,UPrimaryDataAsset*> Named_DataAssets;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Named")
	TMap<FName,UOmegaAttribute*> Named_Attributes;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Named")
	TMap<FName,UEquipmentSlot*> Named_EquipSlots;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Named")
	TMap<FName,UOmegaDamageType*> Named_DamageTypes;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Named")
	TMap<FName,UOmegaDamageTypeReactionAsset*> Named_DamageTypeReactions;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Named")
	TMap<EOmegaGender,UPrimaryDataAsset*> Gender_Assets;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TMap<FGameplayTag, TSoftObjectPtr<UPrimaryDataAsset>> Tagged_DataAssets;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TMap<FGameplayTag, TSoftObjectPtr<UOmegaAttribute>> Tagged_Attributes;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TMap<FGameplayTag, TSoftObjectPtr<UEquipmentSlot>> Tagged_EquipSlots;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TArray<UOmegaAppendedTraitSet*> AppendedTraitSets;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	TMap<UPrimaryDataAsset*,FOmegaObjectTraits> AppendedTraits;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	TSoftObjectPtr<UOmegaAttributeSet> Default_AttributeSet;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	TSoftObjectPtr<UOmegaFaction> Default_Faction;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TSoftObjectPtr<UEquipmentSlot> EquipSlot_Gender;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TSoftObjectPtr<UEquipmentSlot> EquipSlot_Class;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Equipment")
	TSoftObjectPtr<UEquipmentSlot> EquipSlot_Race;


};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_AssetsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Settings", DisplayName="Get OMEGA Settings (Assets)")
	static UOmegaSettings_Assets* GetCurrentAssetSettings();
	
	UFUNCTION(BlueprintPure,Category="Omega|Gameplay|GlobalDataAssets",DisplayName="Get Global DataAsset (Common)",meta=(CompactNodeTitle="DA Common"))
	static UPrimaryDataAsset* GetGlobalTagged_DataAsset(FGameplayTag Tag);
	UFUNCTION(BlueprintPure,Category="Omega|Gameplay|GlobalDataAssets",DisplayName="Get Global DataAsset (Attribute)",meta=(CompactNodeTitle="GDA Attribute"))
	static UOmegaAttribute* GetGlobalTagged_Attribute(FGameplayTag Tag);
	UFUNCTION(BlueprintPure,Category="Omega|Gameplay|GlobalDataAssets",DisplayName="Get Global DataAsset (Equipment Slot)",meta=(CompactNodeTitle="GDA EquipSlot"))
	static UEquipmentSlot* GetGlobalTagged_EquipSlot(FGameplayTag Tag);

};
