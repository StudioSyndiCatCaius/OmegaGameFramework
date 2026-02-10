// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "O_Wall.generated.h"


UCLASS()
class OMEGAWORLD_API UOA_WallStyle : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:

};


UCLASS()
class OMEGAWORLD_API AO_Wall : public AActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	AO_Wall();

	UPROPERTY()
	UOA_WallStyle* Style;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Wall",meta=(MakeEditWidget))
	FVector Driver=FVector(100,100,100);
};
