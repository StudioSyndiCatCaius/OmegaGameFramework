// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_RandomizedMesh.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaRandomizedMeshInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	FVector Scale_Min=FVector::One();
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	FVector Scale_Max=FVector::One();
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	FRotator Rotation_Range=FRotator();
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	TArray<UStaticMesh*> Meshes;
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	TMap<FName,UMaterialInterface*> MaterialSlotOverrides;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaRandomizedMeshPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,Category="RandomizedMesh")
	FOmegaRandomizedMeshInfo Settings;
	
	UPROPERTY() FVector Scale_Min=FVector::One();
	UPROPERTY() FVector Scale_Max=FVector::One();
	UPROPERTY() FRotator Rotation_Range;
	UPROPERTY() TArray<UStaticMesh*> Meshes;
	UPROPERTY() TMap<FName,UMaterialInterface*> MaterialSlotOverrides;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaRandomizedMeshActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaRandomizedMeshActor();
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="RandomizedMesh") UStaticMeshComponent* MeshComponent;

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	UPROPERTY(EditAnywhere,Category="Randomized Mesh",DisplayName="Seed",AdvancedDisplay)
	FRandomStream stream_seed;
	
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	bool bSeedFromLocation;
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	UOmegaRandomizedMeshPreset* Preset;

	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	FOmegaRandomizedMeshInfo Settings;
	

};
