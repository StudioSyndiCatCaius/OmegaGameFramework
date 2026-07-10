// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"
#include "F_Tick.generated.h"

class AOmegaDynamicCamera;
class USplineComponent;
class ACharacter;
class USceneComponent;
class USpringArmComponent;
class UCameraComponent;

/** Blueprint function library of helpers intended to be called each tick.
 *  All functions take a DeltaTime parameter and produce smooth, frame-rate-independent results. */
UCLASS()
class UOmegaFunctions_Tick : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	// =========================================================================================================
	// Component
	// =========================================================================================================

	/** Rotates a SceneComponent in world space each tick, driven by an Input vector scaled against a Rotation template at RotationSpeed (degrees/sec). */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Rotate Component (Rotation Relative)")
	static void RotateComponent_RotationRelative(
		float DeltaTime,
		USceneComponent* Component,
		FRotator Rotation,        // Base rotation axes to apply input along
		FVector Input,            // Directional input (e.g. from stick or WASD)
		float RotationSpeed = 100.0f
	);

	/** Smoothly rotates a SceneComponent to face TargetLocation each tick at RotationSpeed (interp scale). */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Rotate Component (Towards Target)")
	static void RotateComponent_TowardsTarget(
		float DeltaTime,
		USceneComponent* Component,
		FVector TargetLocation,
		float RotationSpeed = 5.0f,
		bool X=false,
		bool Y=false,
		bool Z=true);

	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Rotate Component (Towards Rotation)")
	static void RotateComponent_ToRotation(
		float DeltaTime,
		USceneComponent* Component,
		FRotator TargetRotation,
		float RotationSpeed = 5.0f,
		bool X=false,
		bool Y=false,
		bool Z=true);

	
	/** Moves a SceneComponent to follow the player's mouse cursor each tick.
	 *  Offset: 2D screen-space offset applied before deprojection.
	 *  Distance: depth from camera (-1 uses the component's current distance).
	 *  InterpSpeed: 0 = instant snap; >0 = smooth interpolation.
	 *  LockPlane / bLockPlane_*: clamp the resulting world position on individual axes. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Move Component (To Mouse)")
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

	/** Smoothly moves a SceneComponent toward a world-space TargetLocation each tick.
	 *  X/Y/Z flags control which axes are moved; disabled axes stay at their current value. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Move Component (Towards Target)")
	static void MoveComponent_TowardsTarget(
		float DeltaTime,
		USceneComponent* Component,
		FVector TargetLocation,
		float InterpSpeed = 5.0f,
		bool X = true,
		bool Y = true,
		bool Z = true
	);

	/** Moves a Character along a Spline each tick using InputScale to drive speed and direction.
	 *  DistanceOffset: how far along the spline to advance per unit of input.
	 *  bForceVelocity: override the character's velocity directly rather than using AddMovementInput. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Move Character (AlongSpline)")
	static void MoveCharacter_AlongSpline(
		float DeltaTime,
		USplineComponent* Spline,
		ACharacter* Character,
		float DistanceOffset = 1.0f,
		FVector InputScale=FVector(1,1,1),
		bool bForceVelocity=false
	);

	/** Rotates a Pawn to align with its current velocity direction each tick.
	 *  X/Y/Z flags control which rotation axes are affected. Speed controls the interpolation rate. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Rotate Pawn (To Velocity)")
	static void RotatePawn_ToVelocity(
		float DeltaTime,
		APawn* Pawn,
		float Speed,
		bool X=false,
		bool Y=false,
		bool Z=true
	);

	/** Interpolates a SceneComponent's location and/or rotation toward another SceneComponent each tick. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Interp Component (Scene)")
	static void Interp_SceneComponent(
		float DeltaTime,
		USceneComponent* Source,  // Component being moved
		USceneComponent* To,      // Target component to match
		float Speed,
		bool bLocation=true,
		bool bRotation=true
		);

	/** Interpolates a SpringArmComponent's properties (location, rotation, arm length, offsets) toward another SpringArm each tick. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Interp Component (Spring Arm)")
	static void Interp_SpringArm(
		float DeltaTime,
		USpringArmComponent* Source,  // Spring arm being modified
		USpringArmComponent* To,      // Target spring arm to match
		float Speed,
		bool bLocation=true,
		bool bRotation=true,
		bool ArmLength=true,          // Interpolate arm length
		bool bSocketOffset=false,     // Interpolate socket offset
		bool bTargetOffset=false      // Interpolate target offset
		);

	/** Interpolates a CameraComponent's transform and/or FOV toward another CameraComponent each tick. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Interp Component (Camera)")
	static void Interp_Camera(
		float DeltaTime,
		UCameraComponent* Source,  // Camera being modified
		UCameraComponent* To,      // Target camera to match
		float Speed,
		bool bLocation=true,
		bool bRotation=true,
		bool bFOV=true
	);

	/** Blends the Source camera's transform toward the weighted average of the Cameras array each tick,
	 *  where each camera's influence is determined by its proximity to TargetLocation. */
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Blend Dynamic Cameras")
	static void BlendDynamicCameras(
		float DeltaTime,
		FVector TargetLocation,           // Point used to compute distance-based weights
		AOmegaDynamicCamera* Source,      // Camera being blended
		TArray<AOmegaDynamicCamera*> Cameras, // Cameras to blend between
		float Speed,
		bool bLocation=true,
		bool bRotation=true,
		bool bSpringArm=true,
		bool bCamera=true
	);

};


