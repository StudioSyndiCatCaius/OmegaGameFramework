// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Curves/CurveFloat.h"

#include "GameFramework/Actor.h"
#include "Actor_Openable.generated.h"

class UActorStateComponent;
class UOmegaSaveStateComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaOpenableActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY() bool bIsOpening;
	UPROPERTY() bool bIsOpening_Forward;
public:
	// Sets default values for this actor's properties
	AOmegaOpenableActor();
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere,Category="Openable",meta=(ClampMax="1.0",ClampMin="0.0",UIMax="1.0",UIMin="0.0"))
	float Position;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Openable") UArrowComponent* RootPoint;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Openable") UArrowComponent* OpenPoint;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Openable") UArrowComponent* ClosedPoint;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="RandomizedMesh") UActorStateComponent* ActorState;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="RandomizedMesh") UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Openable")
	UCurveFloat* OpenAnimationCurve;

	UFUNCTION(BlueprintCallable,Category="Openable")
	void SetOpen_Blend(float Value);
	
	UFUNCTION(BlueprintCallable,Category="Openable")
	void SetOpen_State(bool bState,bool bSnap);
};
