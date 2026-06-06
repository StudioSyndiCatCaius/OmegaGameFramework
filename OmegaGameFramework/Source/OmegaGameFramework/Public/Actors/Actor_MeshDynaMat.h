// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "Types/Struct_Material.h"
#include "Actor_MeshDynaMat.generated.h"

// A static mesh actor that applies dynamic material parameter sets at construction, enabling data-driven material customization without Blueprint subclasses.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AStaticMeshDynaMat : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	virtual void OnConstruction(const FTransform& Transform) override;

	// Dynamic material parameters applied to all material slots by default.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") FOmegaDynamicMaterialParams MaterialParams_Default;
	// Per-slot dynamic material parameter overrides applied in addition to the defaults.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TArray<FOmegaDynamicMaterialParams> MaterialParams_Slot;
	// Optional material assets that fully replace the mesh's materials before dynamic parameters are applied.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh") TArray<UMaterialInterface*> MaterialOverrides;
};
