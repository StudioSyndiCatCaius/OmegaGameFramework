// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "Types/Struct_Material.h"
#include "Actor_MeshDynaMat.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API AStaticMeshDynaMat : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") FOmegaDynamicMaterialParams MaterialParams_Default;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TArray<FOmegaDynamicMaterialParams> MaterialParams_Slot;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TArray<UMaterialInterface*> MaterialOverrides;


};
