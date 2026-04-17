// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Spline.generated.h"

class UInstancedStaticMeshComponent;
class USplineComponent;
class UDynamicMeshComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaSplineActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	UMaterialInstanceDynamic* DynaMat=nullptr;
	const float PointDistance=100;
	void L_SetupMeshComp(UInstancedStaticMeshComponent* comp);
	
public:
	bool bDrawPreviewPoints=true;
	AOmegaSplineActor();
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere,Category="Spline") FLinearColor PointColor=FLinearColor::Red;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") USplineComponent* Spline;
	UPROPERTY() UInstancedStaticMeshComponent* DisplayPoint;
	UPROPERTY() UInstancedStaticMeshComponent* DisplayLine;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmega_DynamicMesh_SplineBlock : public AOmegaSplineActor
{
	GENERATED_BODY()
public:
	AOmega_DynamicMesh_SplineBlock();
	void RebuildCollision();
	void RebuildMesh();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Spline") UDynamicMeshComponent* DynamicMeshComponent;
	
	UPROPERTY(EditAnywhere,Category="DynamicSpline")
	bool bIsBoolean;
	UPROPERTY(EditAnywhere,Category="DynamicSpline",meta=(EditCondition="bIsBoolean"))
	TArray<AOmega_DynamicMesh_SplineBlock*> Boolean_Targets;
	
	UPROPERTY(EditAnywhere,Category="DynamicSpline")
	UMaterialInterface* MeshblockMaterial;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicSpline")
	bool bClosedLoop=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicSpline")
	float ClampSplineRange=1;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicSpline")
	bool bBuildMeshblockFromSpline;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicSpline")
	float MeshblockHeight=100;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicSpline")
	bool bMeshblockOffsetFromHeight;
};