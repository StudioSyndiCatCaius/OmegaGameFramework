// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Actor_InvisibleWall.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaInvisibleWall : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AOmegaInvisibleWall();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY() UStaticMesh* DefaultMesh = nullptr;
	UPROPERTY() UMaterialInterface* Material_Blocking = nullptr;
	UPROPERTY() UMaterialInterface* Material_BlockingFreeCam = nullptr;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Wall") bool bAllowCamera;
};
