// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_RandomizedMesh.generated.h"

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
	UPROPERTY(EditDefaultsOnly,Category="Randomized Mesh",DisplayName="Seed",AdvancedDisplay)
	FRandomStream stream_seed;
	//UPROPERTY(EditDefaultsOnly,Category="Randomized Mesh",AdvancedDisplay) int32 mesh_index;
	
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	bool bSeedFromLocation;
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	float Scale_Min=1.0;
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	float Scale_Max=1.0;
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	FRotator Rotation_Range;
	UPROPERTY(EditAnywhere,Category="Randomized Mesh")
	TArray<UStaticMesh*> Meshes;
};
