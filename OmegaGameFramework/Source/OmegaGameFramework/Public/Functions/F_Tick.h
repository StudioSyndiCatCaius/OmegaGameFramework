// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Tick.generated.h"

UCLASS()
class UOmegaFunctions_Tick : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	// =========================================================================================================
	// Component
	// =========================================================================================================

	// Rotates a scene component in world space relative to a rotation input
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="TICK - Rotate Component (Rotation Relative)")
	static void RotateComponent_RotationRelative(
		float DeltaTime,
		USceneComponent* Component,
		FRotator Rotation,
		FVector Input,
		float RotationSpeed = 100.0f
	);
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="TICK - Rotate Component (Towards Target)")
	static void RotateComponent_TowardsTarget(float DeltaTime,USceneComponent* Component,FVector TargetLocation,float RotationSpeed = 5.0f);

	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="TICK - Move Component (To Mouse)")
	static void MoveComponent_ToMouse(
	    float DeltaTime,
	    USceneComponent* Component,
	    APlayerController* Player,
	    FVector2D Offset = FVector2D::ZeroVector,
	    float Distance = -1.0f,
	    float InterpSpeed = 0.0f,
	    FVector LockPlane = FVector::ZeroVector,
	    bool bLockPlane_X = false,
	    bool bLockPlane_Y = false,
	    bool bLockPlane_Z = false
	);
};


