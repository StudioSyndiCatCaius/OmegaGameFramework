// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Actor_ZoneEntityMesh.generated.h"

class UZoneEntityComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AZoneEntity_Mesh : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AZoneEntity_Mesh();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Mesh") UZoneEntityComponent* ZoneEntity;


};
