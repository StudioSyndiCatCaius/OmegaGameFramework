// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "Components/SkeletalMeshComponent.h"
#include "Component_Skin.generated.h"


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
	
	UFUNCTION(BlueprintCallable, Category="Omega", DisplayName="Merge Meshes (Omega)")
	static USkeletalMesh* MergeMeshes_Omega(TArray<USkeletalMesh*> Meshes, USkeletalMesh* BaseMesh);

	UFUNCTION(BlueprintCallable, Category="Omega", DisplayName="Merge Meshe Components (Omega)")
	static USkeletalMesh* MergeComponentMeshes_Omega(TArray<USkeletalMeshComponent*> Meshes, USkeletalMesh* BaseMesh);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaSkin : public AActor
{
	GENERATED_BODY()
	AOmegaSkin();

	
public:
	UPROPERTY() USkinComponent* owning_component;
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
	USkeletalMesh* MasterSkeleton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skin")
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
	UFUNCTION() void local_applyModifiers(USkeletalMeshComponent* MeshComp);
public:
	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	TArray<USkeletalMeshComponent*> GetMeshMergeComponents();

	UFUNCTION(BlueprintCallable,Category="Omega")
	void BuildSkin();
};