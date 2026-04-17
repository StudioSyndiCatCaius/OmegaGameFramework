// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"
#include "F_Tick.generated.h"

class USplineComponent;
class ACharacter;
class USceneComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class UOmegaFunctions_Tick : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	// =========================================================================================================
	// Component
	// =========================================================================================================

	// Rotates a scene component in world space relative to a rotation input
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Rotate Component (Rotation Relative)")
	static void RotateComponent_RotationRelative(
		float DeltaTime,
		USceneComponent* Component,
		FRotator Rotation,
		FVector Input,
		float RotationSpeed = 100.0f
	);
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Rotate Component (Towards Target)")
	static void RotateComponent_TowardsTarget(float DeltaTime,USceneComponent* Component,FVector TargetLocation,float RotationSpeed = 5.0f);

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
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Move Character (AlongSpline)")
	static void MoveCharacter_AlongSpline(
		float DeltaTime,
		USplineComponent* Spline,
		ACharacter* Character,
		float DistanceOffset = 1.0f,
		FVector InputScale=FVector(1,1,1),
		bool bForceVelocity=false
	);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Rotate Pawn (To Velocity)")
	static void RotatePawn_ToVelocity(
		float DeltaTime,
		APawn* Pawn,
		float Speed,
		bool X=false,
		bool Y=false,
		bool Z=true
	);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Interp Component (Scene)")
	static void Interp_SceneComponent(
		float DeltaTime,
		USceneComponent* Source,
		USceneComponent* To,
		float Speed,
		bool bLocation=true,
		bool bRotation=true
		);
	
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Interp Component (Spring Arm)")
	static void Interp_SpringArm(
		float DeltaTime,
		USpringArmComponent* Source,
		USpringArmComponent* To,
		float Speed,
		bool bLocation=true,
		bool bRotation=true,
		bool ArmLength=true,
		bool bSocketOffset=false,
		bool bTargetOffset=false
		);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Tick",DisplayName="🕰️TICK - Interp Component (Camera)")
	static void Interp_Camera(
		float DeltaTime,
		UCameraComponent* Source,
		UCameraComponent* To,
		float Speed,
		bool bLocation=true,
		bool bRotation=true,
		bool bFOV=true
	);
	
};


