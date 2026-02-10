// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Component_UtilMesh.generated.h"



UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UUtilMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

	
public:
	UUtilMeshComponent();

	UFUNCTION() void SetupUtilMesh(FLinearColor Color);
	void SetBoundsZ(USceneComponent* baseComp,float ExtraZ);
};

