// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_DynamicCamera.h"
#include "Actor_DynamicCameras.generated.h"

UCLASS(DisplayName="Dynamic Camera - Look At Player")
class OMEGADEMO_API ADCam_LookAtPlayer : public AOmegaDynamicCamera
{
	GENERATED_BODY()

public:
	ADCam_LookAtPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SourceTick_Implementation(float deltaTime, APlayerController* SourcePlayer, UOmegaSubsystem_Player* Subsystem) override;
	
	UPROPERTY() FRotator initRot;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥Camera")
	float LookAtPlayerSpeed=5;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥Camera", meta=(ClampMin=0, ClampMax=1))
	float LookAtPlayerRatio=0.5;
};
