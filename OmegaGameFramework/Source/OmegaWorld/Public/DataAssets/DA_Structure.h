// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_Structure.generated.h"


USTRUCT(BlueprintType)
struct FOmegaStructure_MeshLayer
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TArray<UMaterialInterface*> MaterialOverrides;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") FVector Offset;
	
};


UCLASS()
class OMEGAWORLD_API UOmegaStructure_Asset : public UPrimaryDataAsset
{
	GENERATED_BODY()
};
