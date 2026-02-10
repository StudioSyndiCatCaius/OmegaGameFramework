// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Actor_Null.generated.h"

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaBASEActor : public AActor
{
	GENERATED_BODY()

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaBASEPawn : public APawn
{
	GENERATED_BODY()

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

};



UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaNullActor : public AActor
{
	GENERATED_BODY()

public:
	AOmegaNullActor();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="NullActor",meta=(ExposeOnSpawn)) FName NewActorLabel;


};
