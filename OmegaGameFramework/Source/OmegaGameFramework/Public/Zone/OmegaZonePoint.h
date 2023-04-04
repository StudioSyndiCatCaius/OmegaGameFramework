// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaZone.h"
#include "VolumeUtils.h"
#include "GameFramework/Actor.h"
#include "OmegaZonePoint.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaZonePoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	//AOmegaZonePoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	//virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY()
	UStaticMesh* ShapeMeshRef_sphere;
	

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Zone")
	UOmegaZoneData* ZoneToLoad;

	UPROPERTY(EditAnywhere, Category="Zone")
	FGameplayTag ZonePointID;

	
};
