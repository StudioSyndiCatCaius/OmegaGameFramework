// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "Components/SkeletalMeshComponent.h"
#include "SkinComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API USkinComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USkinComponent();

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

	UPROPERTY()
	UChildActorComponent* skinComponent;

	UFUNCTION(BlueprintCallable, Category="Omega")
	AOmegaSkin* SetSkin(TSubclassOf<AOmegaSkin> SkinClass);

	UFUNCTION(BlueprintPure,Category="Omega")
	AOmegaSkin* GetSkin();
	
	UFUNCTION(BlueprintCallable, Category="Omega", meta=(AdvancedDisplay="Preset"))
	void Assemble();
	
	
	UPROPERTY()
	TArray<USkeletalMeshComponent*> MeshComponents;
	
	
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
public:
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega")
	USkeletalMesh* MasterSkeleton;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega")
	TSubclassOf<UAnimInstance> AnimationClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega")
	bool bMerge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega")
	bool bForceFollowMasterComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Omega")
	bool bHideBaseMesh;
	
	UFUNCTION(BlueprintNativeEvent, Category="Omega")
	TArray<USkeletalMeshComponent*> GetMeshMergeComponents();

	UFUNCTION(BlueprintCallable,Category="Omega")
	void BuildSkin();
};