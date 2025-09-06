// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Water.generated.h"

class USplineMeshComponent;
class USplineComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaWater_Style : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UMaterialInterface* Material_Plane;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UMaterialInterface* Material_River;

	void ApplyTo_Component(UPrimitiveComponent* comp, uint8 type)
	{
		if(comp)
		{
			UMaterialInterface* _inMat = nullptr;
			if(type==0) { _inMat=Material_Plane; }
			if(type==1) { _inMat=Material_River; }
			if(_inMat)
			{
				comp->SetMaterial(0,_inMat);
			}
		}
	}
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaWater_Plane : public AActor
{
	GENERATED_BODY()

public:
	AOmegaWater_Plane();
	
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UOmegaWater_Style* Style;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaWater_River : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY() TArray<USplineMeshComponent*> RiverMeshes;
	
	AOmegaWater_River();
	
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USplineComponent* Spline;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UOmegaWater_Style* Style;
};
