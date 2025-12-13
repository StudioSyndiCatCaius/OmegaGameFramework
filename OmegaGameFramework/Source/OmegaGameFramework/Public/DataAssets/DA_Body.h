// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_AssetLib.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "GameFramework/Character.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_Appearance.h"
#include "DA_Body.generated.h"

// ======================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodyPreset : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	FOmegaBodyAppearanceInfo AppearanceData;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodyType : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category="Omega")
	TSubclassOf<AOmegaSkin> DefaultSkin;
	UPROPERTY(EditAnywhere, Category="Omega")
	USkeleton* BaseSkeleton;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	TMap<FName,UOmegaBodySlot*> BodySlots;

	UFUNCTION(BlueprintCallable,Category="BodyType")
	USkeletalMesh* GenerateMesh_FromParams(FOmegaBodyAppearanceData data);
	UFUNCTION(BlueprintCallable,Category="BodyType")
	USkeletalMesh* GenerateMesh_FromSeed(int32 seed);

	UFUNCTION(BlueprintPure,Category="BodyType")
	TArray<UOmegaBodySlot*> GetSlots() const;
};

UENUM(BlueprintType)
enum class EOmegaBodySlotType: uint8
{
	BODYSLOT_BOOL, BODYSLOT_INTEGER, BODYSLOT_FLOAT, BODYSLOT_OBJECTLIST, BODYSLOT_COLOR
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodySlot : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(Instanced,EditAnywhere,Category="Body Slot")
	UOmegaBodySlotScript* Script;

	UFUNCTION(BlueprintPure,Category="Body Slot")
	static FVector GetDefaultValue();
	UFUNCTION(BlueprintPure,Category="Body Slot")
	FVector GetMaxValue() const;
	UFUNCTION(BlueprintPure,Category="Body Option")
	EOmegaBodySlotType GetSlotType();

	UFUNCTION(BlueprintPure,Category="Body Option")
	USkeletalMesh* GetMeshFromIndex(int32 index) const;
	
	UFUNCTION()
	bool PostMeshEdit(USkeletalMesh* Mesh) const;
};

UCLASS(Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaBodySlotScript : public UOmegaInstancableObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	USkeletalMesh* GetMeshFromIndex(int32 index) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	bool PostMeshCreationEdit(USkeletalMesh* Mesh) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	bool PostMaterialSlotEdit(USkeletalMesh* Mesh,int32 slotIndex, FName SlotName, UMaterialInterface* Material) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	EOmegaBodySlotType GetScriptSlotType() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	void OnApplied_ToSkin(AOmegaSkin* Skin, FVector OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	void OnApplied_ToMeshComponent(USkeletalMeshComponent* Component, FVector OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	FVector GetMaxValue() const;
};



UCLASS(Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaBodyOptionScript : public UOmegaInstancableObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	EOmegaBodySlotType GetScriptSlotType() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	void OnApplied_ToSkin(AOmegaSkin* Skin, FVector OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	void OnApplied_ToMeshComponent(USkeletalMeshComponent* Component, FVector OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	FVector GetMaxValue() const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodyOption : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
};