// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Tick.h"


void UOmegaFunctions_Tick::RotateComponent_RotationRelative(float DeltaTime, USceneComponent* Component,
	FRotator Rotation, FVector Input, float RotationSpeed)
{
    if (!Component)
    {
        return;
    }

    // Get the axes from the input rotation (typically camera rotation)
    FRotationMatrix RotMatrix(Rotation);
    FVector RightAxis = RotMatrix.GetScaledAxis(EAxis::Y);    // Camera's right (Pitch axis)
    FVector UpAxis = RotMatrix.GetScaledAxis(EAxis::Z);       // Camera's up (Yaw axis)
    FVector ForwardAxis = RotMatrix.GetScaledAxis(EAxis::X);  // Camera's forward (Roll axis)

    // Calculate rotation amounts from input vector
    float YawAmount = Input.X * RotationSpeed * DeltaTime;    // X -> Left/Right
    float PitchAmount = Input.Y * RotationSpeed * DeltaTime;  // Y -> Up/Down
    float RollAmount = Input.Z * RotationSpeed * DeltaTime;   // Z -> Roll/Twist

    // Create quaternions for rotation around each camera axis
    FQuat YawQuat = FQuat(UpAxis, FMath::DegreesToRadians(YawAmount));
    FQuat PitchQuat = FQuat(RightAxis, FMath::DegreesToRadians(PitchAmount));
    FQuat RollQuat = FQuat(ForwardAxis, FMath::DegreesToRadians(RollAmount));

    // Get current rotation as quaternion
    FQuat CurrentQuat = Component->GetComponentRotation().Quaternion();

    // Apply rotations in order: Yaw, Pitch, then Roll
    FQuat NewQuat = YawQuat * PitchQuat * RollQuat * CurrentQuat;

    // Set the new rotation
    Component->SetWorldRotation(NewQuat);
}

void UOmegaFunctions_Tick::RotateComponent_TowardsTarget(float DeltaTime, USceneComponent* Component,
                                                         FVector TargetLocation, float RotationSpeed)
{
	if (!Component)
	{
		return;
	}

	FVector Direction = TargetLocation - Component->GetComponentLocation();
	FRotator TargetRotation = Direction.Rotation();
	FRotator NewRotation = FMath::RInterpTo(
		Component->GetComponentRotation(),
		TargetRotation,
		DeltaTime,
		RotationSpeed
	);

	Component->SetWorldRotation(NewRotation);
}

void UOmegaFunctions_Tick::MoveComponent_ToMouse(float DeltaTime, USceneComponent* Component, APlayerController* Player,
	FVector2D Offset, float Distance, float InterpSpeed, FVector LockPlane, bool bLockPlane_X, bool bLockPlane_Y,
	bool bLockPlane_Z)
{
	
    if (!Component || !Player)
    {
        return;
    }

    // Get mouse position in screen space
    float MouseX, MouseY;
    if (!Player->GetMousePosition(MouseX, MouseY))
    {
        return;
    }

    // Apply offset
    MouseX += Offset.X;
    MouseY += Offset.Y;

    // Deproject screen position to world space
    FVector WorldLocation, WorldDirection;
    if (!Player->DeprojectScreenPositionToWorld(MouseX, MouseY, WorldLocation, WorldDirection))
    {
        return;
    }

    FVector TargetLocation;

    // Check if we're locking to a plane
    bool bUsingPlaneLock = bLockPlane_X || bLockPlane_Y || bLockPlane_Z;

    if (bUsingPlaneLock)
    {
        // Calculate intersection with the locked plane
        FVector PlaneNormal = FVector::ZeroVector;
        
        // Build plane normal based on locked axes
        if (bLockPlane_X) PlaneNormal.X = 1.0f;
        if (bLockPlane_Y) PlaneNormal.Y = 1.0f;
        if (bLockPlane_Z) PlaneNormal.Z = 1.0f;
        
        PlaneNormal.Normalize();

        // Calculate plane intersection
        // Plane equation: dot(PlaneNormal, Point - LockPlane) = 0
        // Ray equation: Point = WorldLocation + t * WorldDirection
        // Solving for t: t = dot(PlaneNormal, LockPlane - WorldLocation) / dot(PlaneNormal, WorldDirection)
        
        float Denominator = FVector::DotProduct(PlaneNormal, WorldDirection);
        
        if (FMath::Abs(Denominator) > KINDA_SMALL_NUMBER)
        {
            float t = FVector::DotProduct(PlaneNormal, LockPlane - WorldLocation) / Denominator;
            TargetLocation = WorldLocation + (WorldDirection * t);
        }
        else
        {
            // Ray is parallel to plane, use current location
            TargetLocation = Component->GetComponentLocation();
        }
    }
    else
    {
        // Standard distance-based positioning
        float TargetDistance = Distance;
        
        if (Distance < 0.0f)
        {
            // Keep current distance from camera
            if (Player->PlayerCameraManager)
            {
                FVector CameraLocation = Player->PlayerCameraManager->GetCameraLocation();
                TargetDistance = FVector::Dist(Component->GetComponentLocation(), CameraLocation);
            }
            else
            {
                TargetDistance = 100.0f;
            }
        }

        TargetLocation = WorldLocation + (WorldDirection * TargetDistance);
    }

    // Apply locked axes from LockPlane position
    FVector FinalLocation = TargetLocation;
    FVector CurrentLocation = Component->GetComponentLocation();
    
    if (bLockPlane_X)
    {
        FinalLocation.X = LockPlane.X;
    }
    if (bLockPlane_Y)
    {
        FinalLocation.Y = LockPlane.Y;
    }
    if (bLockPlane_Z)
    {
        FinalLocation.Z = LockPlane.Z;
    }

    // Apply movement with optional interpolation
    if (InterpSpeed > 0.0f)
    {
        FVector NewLocation = FMath::VInterpTo(
            CurrentLocation,
            FinalLocation,
            DeltaTime,
            InterpSpeed
        );
        Component->SetWorldLocation(NewLocation);
    }
    else
    {
        Component->SetWorldLocation(FinalLocation);
    }
}
