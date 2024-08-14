// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Materials/MaterialExpression.h"
#include "MaterialCompiler.h"
#include "Subsystems/WorldSubsystem.h"
#include "OmegaSubsystem_VVP.generated.h"

UCLASS(DisplayName="Get VoxelVectorPaint Value")
class OMEGAGAMEFRAMEWORK_API UOmegaMatExp_GetVVP : public UMaterialExpression
{
	GENERATED_BODY()

public:
	UOmegaMatExp_GetVVP();
	
	// Override the method to generate the expression's code
	
	//virtual TArray<FExpressionOutput>& GetOutputs() override;
	
	
	virtual FName GetParameterName() const override;

	// Custom functionality to get the Vector4 value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel Vector Painting")
	FVector4 OutputValue;

	//~ Begin UMaterialExpression Interface

	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaVoxelVectorPaintSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	FVector4 GetVector4Value() const;

	UPROPERTY()
	TArray<AOmegaVoxelVectorPaintedVolume*> sources;

private:
	UPROPERTY()
	FVector4 Vector4Value;
};

UCLASS(EditInlineNew,Blueprintable,BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaVoxelVectorPaintScript : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent, Category="Voxel Vector Paint")
	FVector4 GetLocalVoxelVectorPaintData(AOmegaVoxelVectorPaintedVolume* Actor, int32 index, FVector Vector);
};


UINTERFACE(MinimalAPI)
class UVoxelVertexPaintingInterface : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IVoxelVertexPaintingInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent,Category="Omega|VVP")
	FVector4 GetVoxelVertexPaintingData(int32 index, FVector position);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaVoxelVectorPaintedVolume : public AActor, public IVoxelVertexPaintingInterface
{
	GENERATED_BODY()

public:

	AOmegaVoxelVectorPaintedVolume();

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Default")
	FVector BoxExtent=FVector(100,100,100);

	virtual FVector4 GetVoxelVertexPaintingData_Implementation(int32 index, FVector position);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Instanced, Category="Default")
	UOmegaVoxelVectorPaintScript* Script;
};
