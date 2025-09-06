// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Spline.generated.h"

class UInstancedStaticMeshComponent;
class USplineComponent;
class UMaterialInstanceDynamic;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaSplineActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	UMaterialInstanceDynamic* DynaMat=nullptr;
	const float PointDistance=100;
	void L_SetupMeshComp(UInstancedStaticMeshComponent* comp);
	
public:

	AOmegaSplineActor();
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere,Category="Spline") FLinearColor PointColor=FLinearColor::Red;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") USplineComponent* Spline;
	UPROPERTY() UInstancedStaticMeshComponent* DisplayPoint;
	UPROPERTY() UInstancedStaticMeshComponent* DisplayLine;

};
