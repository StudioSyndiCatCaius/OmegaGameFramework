// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "DataAssets/DA_AssetLib.h"
#include "Functions/OmegaFunctions_ComponentMod.h"

#include "Misc/GeneralDataObject.h"
#include "DA_CommonCharacter.generated.h"

class AOmegaSkin;
class UOmegaFaction;
class UEquipmentSlot;

UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonCharacter : public UOmegaDataAsset, public IDataInterface_FlowAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	FComponentMod_SkeletalMesh Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	TSoftClassPtr<AOmegaSkin> ActorSkin;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	UOmegaAssetLibrary_Sound* Library_Sound;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	UOmegaAssetLibrary_Animation* Library_Animation;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character")
	UFlowAsset* FlowAsset;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Inventory")
	TMap<UEquipmentSlot*,UPrimaryDataAsset*> Equipment;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Inventory")
	TMap<UPrimaryDataAsset*,int32> Inventory;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	int32 Level=1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	TMap<UOmegaAttribute*,float> Attribute_Overrides;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	TArray<UPrimaryDataAsset*> Skills_Innate;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	TMap<UPrimaryDataAsset*,int32> Skills_ByLevel;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	UOmegaFaction* Faction;

	// Function
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override {return FlowAsset;};
};
