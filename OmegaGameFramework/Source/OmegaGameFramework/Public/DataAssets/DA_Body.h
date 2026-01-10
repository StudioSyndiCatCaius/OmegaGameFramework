// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_AssetLib.h"
#include "Functions/F_Component.h"
#include "GameFramework/Character.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_Appearance.h"
#include "DA_Body.generated.h"

// ======================================================================================================

USTRUCT(BlueprintType)
struct FOmegaBodyOptionValue
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly,Category="Body") float value_float;
	UPROPERTY(BlueprintReadOnly,Category="Body") FLinearColor value_color;
	UPROPERTY(BlueprintReadOnly,Category="Body") FVector value_vector;

	static FOmegaBodyOptionValue FromBodyData(FOmegaBodyAppearanceData data,FName s);
	
};


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

	void Post_CompMod(USkeletalMeshComponent* comp,FOmegaBodyAppearanceData data);
	
public:
	UPROPERTY(EditAnywhere, Category="Omega")
	TSubclassOf<AOmegaSkin> DefaultSkin;
	UPROPERTY(EditAnywhere, Category="Omega")
	USkeleton* BaseSkeleton;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	TMap<FName,UOmegaBodySlot*> BodySlots;

	UFUNCTION(BlueprintCallable,Category="BodyType")
	FOmegaBodyAppearanceData GenerateData_FromSeed(int32 seed);
	
	UFUNCTION(BlueprintCallable,Category="BodyType")
	USkeletalMesh* GenerateMesh_FromParams(FOmegaBodyAppearanceData data);
	UFUNCTION(BlueprintCallable,Category="BodyType")
	USkeletalMesh* GenerateMesh_FromSeed(int32 seed);

	UFUNCTION(BlueprintCallable,Category="BodyType")
	void GenerateOnComponent_FromParams(USkeletalMeshComponent* component, FOmegaBodyAppearanceData data);
	UFUNCTION(BlueprintCallable,Category="BodyType")
	void GenerateOnComponent_FromSeed(USkeletalMeshComponent* component, int32 seed);
	
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
	USkeletalMesh* GetMeshFromIndex(FOmegaBodyOptionValue OptionValue) const;
	
	UFUNCTION() bool PostMeshEdit(USkeletalMesh* Mesh,FOmegaBodyOptionValue OptionValue) const;
	UFUNCTION() bool PostComponentEdit(USkeletalMeshComponent* Mesh,FOmegaBodyOptionValue OptionValue) const;
};

UCLASS(Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaBodySlotScript : public UOmegaInstancableObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	USkeletalMesh* GetMeshFromIndex(FOmegaBodyOptionValue OptionValue) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	bool PostMeshCreationEdit(USkeletalMesh* Mesh, FOmegaBodyOptionValue OptionValue) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	bool PostMaterialSlotEdit(USkeletalMesh* Mesh,int32 slotIndex, FName SlotName, UMaterialInterface* Material, FOmegaBodyOptionValue OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	EOmegaBodySlotType GetScriptSlotType() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	void OnApplied_ToSkin(AOmegaSkin* Skin, FOmegaBodyOptionValue OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	void OnApplied_ToMeshComponent(USkeletalMeshComponent* Component, FOmegaBodyOptionValue OptionValue) const;
	
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
	void OnApplied_ToSkin(AOmegaSkin* Skin, FOmegaBodyOptionValue OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	void OnApplied_ToMeshComponent(USkeletalMeshComponent* Component, FOmegaBodyOptionValue OptionValue) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Body Option")
	FVector GetMaxValue() const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodyOption : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodyFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable,Category="Omega|Body")
	static void SetBodyDataParam_Int(UPARAM(ref) FOmegaBodyAppearanceData& data, FName param, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Body")
	static void SetBodyDataParam_float(UPARAM(ref) FOmegaBodyAppearanceData& data, FName param, float Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Body")
	static void SetBodyDataParam_Vector(UPARAM(ref) FOmegaBodyAppearanceData& data, FName param, FVector Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Body")
	static void SetBodyDataParam_Color(UPARAM(ref) FOmegaBodyAppearanceData& data, FName param, FLinearColor Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Body")
	static void SetBodyDataParam_bool(UPARAM(ref) FOmegaBodyAppearanceData& data, FName param, bool Value);

	UFUNCTION(BlueprintPure,Category="Omega|Body")
	static int32 GetBodyDataParam_Int(FOmegaBodyAppearanceData data, FName param);
	UFUNCTION(BlueprintPure,Category="Omega|Body")
	static float GetBodyDataParam_float(FOmegaBodyAppearanceData data, FName param);
	UFUNCTION(BlueprintPure,Category="Omega|Body")
	static FVector GetBodyDataParam_Vector(FOmegaBodyAppearanceData data, FName param);
	UFUNCTION(BlueprintPure,Category="Omega|Body")
	static FLinearColor GetBodyDataParam_Color(FOmegaBodyAppearanceData data, FName param);
	UFUNCTION(BlueprintPure,Category="Omega|Body")
	static bool GetBodyDataParam_bool(FOmegaBodyAppearanceData data, FName param);
};