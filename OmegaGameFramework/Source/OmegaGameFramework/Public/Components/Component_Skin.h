// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "Styling/SlateBrush.h"
#include "Components/SkeletalMeshComponent.h"
#include "Misc/GeneralDataObject.h"
#include "Component_Skin.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaBodyAppearanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	UOmegaBodyType* BodyType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	TMap<UOmegaBodySlot*, FVector> Params;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API USkinComponent : public UActorComponent
{
	GENERATED_BODY()

	USkinComponent();
	UPROPERTY() USkeletalMeshComponent* targetSkelMesh;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	                           
	UPROPERTY(EditAnywhere, Category="Omega")
	TSubclassOf<AOmegaSkin> Skin;

	UFUNCTION()
	void Update_Skin();

	UPROPERTY() UChildActorComponent* skinComponent;
	
	UFUNCTION(BlueprintCallable, Category="Omega")
	AOmegaSkin* SetSkin(TSubclassOf<AOmegaSkin> SkinClass);
	UFUNCTION(BlueprintPure,Category="Omega")
	AOmegaSkin* GetSkin() const;

	UFUNCTION(BlueprintPure,Category="Omega|Skin")
	USkeletalMeshComponent* GetTargetMesh() const
	{
		if(targetSkelMesh) { return targetSkelMesh;} return nullptr;
	}
	
	UFUNCTION(BlueprintCallable, Category="Omega", meta=(AdvancedDisplay="Preset"))
	void Assemble(USkeletalMeshComponent* OverrideMesh=nullptr);
	
	UPROPERTY()
	TArray<USkeletalMeshComponent*> MeshComponents;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FOmegaBodyAppearanceData Appearance;
	// BODY APPEARANCE
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyAppearanceData(FOmegaBodyAppearanceData AppearanceData);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBody_Type(UOmegaBodyType* BodyType);
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	UOmegaBodyType* GetBody_Type() const;

	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Vector(UOmegaBodySlot* Param, FVector Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	FVector GetBodyParam_Vector(UOmegaBodySlot* Param);

	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Bool(UOmegaBodySlot* Param, bool Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	bool GetBodyParam_Bool(UOmegaBodySlot* Param);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Int(UOmegaBodySlot* Param, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	int32 GetBodyParam_Int(UOmegaBodySlot* Param);

	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	void SetBodyParam_Float(UOmegaBodySlot* Param, float Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Skin|Body")
	float GetBodyParam_Float(UOmegaBodySlot* Param);
};

UCLASS(Blueprintable,BlueprintType,CollapseCategories,EditInlineNew,Abstract)
class OMEGAGAMEFRAMEWORK_API USkinModifier : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="Omega|Skins")
	UMaterialInstanceDynamic* CreateDynamicMaterial_FromSlot(USkeletalMeshComponent* MeshComp, FName Slot, bool ApplyToComponent);
	
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Skins")
	void ApplyModifier(AOmegaSkin* Skin, USkeletalMeshComponent* MeshComponent);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API USkinModifier_DynamicMaterial : public USkinModifier
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,Category="SkinModifier")
	TArray<FName> SlotsAppliedTo;

	virtual void ApplyModifier_Implementation(AOmegaSkin* Skin, USkeletalMeshComponent* MeshComponent) override;

	UFUNCTION(BlueprintNativeEvent,Category="Omega|Skins")
	void ApplyModifierMaterial(AOmegaSkin* Skin, USkeletalMeshComponent* MeshComponent, UMaterialInstanceDynamic* Material);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSkinFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Omega", DisplayName="Merge Meshes (Omega)")
	static USkeletalMesh* MergeMeshes_Omega(TArray<USkeletalMesh*> Meshes, USkeletalMesh* BaseMesh);

	UFUNCTION(BlueprintCallable, Category="Omega", DisplayName="Merge Meshe Components (Omega)")
	static USkeletalMesh* MergeComponentMeshes_Omega(TArray<USkeletalMeshComponent*> Meshes, USkeletalMesh* BaseMesh);

	UFUNCTION(BlueprintCallable, Category="Omega")
	static void SetSkinFromAsset(USkinComponent* SkinComponent, UObject* SourceAsset);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaSkin : public AActor
{
	GENERATED_BODY()
	AOmegaSkin();

public:
	UPROPERTY() USkinComponent* owning_component;
	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION(BlueprintImplementableEvent,Category="Skin")
	void OnSkinBuildFinished();

	//If true, skin will use a single character mesh applied to the owning character's mesh with material & transform changes. The Skin will then be destroyed.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bIsCompressedSkin;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin",meta=(EditCondition="!bIsCompressedSkin"))
	USkeletalMesh* MasterSkeleton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin",meta=(EditCondition="!bIsCompressedSkin"))
	UMaterialInterface* MasterSkeletonOverrideMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	TSubclassOf<UAnimInstance> AnimationClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bMerge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bForceFollowMasterComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	bool bHideBaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Skin")
	TArray<USkinModifier*> SkinModifiers;

private:
	void TrySetAnimation(USkeletalMeshComponent* TargetMesh);
	UFUNCTION() void local_applyModifiers(USkeletalMeshComponent* MeshComp);
public:
	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	USkeletalMeshComponent* GetCompressedMeshComponent();
	
	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	TArray<USkeletalMeshComponent*> GetMeshMergeComponents();

	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	USkeletalMeshComponent* GetMeshComponentBySlot(FGameplayTag Slot);
	
	UFUNCTION(BlueprintCallable,Category="Omega")
	void BuildSkin();
};

UINTERFACE(MinimalAPI) class UDataInterface_SkinSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_SkinSource
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Omega|Skin")
	TSubclassOf<AOmegaSkin> GetSkinClass();

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Omega|Skin")
	TArray<USkinModifier*> GetSkinModifiers();
};


// ======================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodyPreset : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	FOmegaBodyAppearanceData AppearanceData;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBodyType : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category="Omega")
	TSubclassOf<AOmegaSkin> DefaultSkin;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	TArray<UOmegaBodySlot*> DefaultSlots;
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
	FVector GetDefaultValue();
	UFUNCTION(BlueprintPure,Category="Body Slot")
	FVector GetMaxValue();
	UFUNCTION(BlueprintPure,Category="Body Option")
	EOmegaBodySlotType GetSlotType();
};

UCLASS(Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaBodySlotScript : public UOmegaInstancableObject
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