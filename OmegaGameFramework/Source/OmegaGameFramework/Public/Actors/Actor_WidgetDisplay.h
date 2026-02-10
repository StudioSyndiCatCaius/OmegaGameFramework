// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Actor_WidgetDisplay.generated.h"

class USpringArmComponent;
class USceneCaptureComponent2D;

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaWidgetDisplayActor : public APawn
{
	GENERATED_BODY()

public:
	AOmegaWidgetDisplayActor();

	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION(BlueprintNativeEvent,Category="SceneCapture")
	TArray<AActor*> GetRendered_Actors();
	UFUNCTION(BlueprintNativeEvent,Category="SceneCapture")
	TArray<UPrimitiveComponent*> GetRendered_Components();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USceneCaptureComponent2D* SceneCapture;
};
