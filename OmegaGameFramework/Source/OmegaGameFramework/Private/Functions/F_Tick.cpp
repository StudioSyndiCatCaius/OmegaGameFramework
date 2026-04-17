// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Tick.h"

#include "Camera/CameraComponent.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"


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

void UOmegaFunctions_Tick::MoveCharacter_AlongSpline(float DeltaTime, USplineComponent* Spline, ACharacter* Character, float DistanceOffset, FVector InputScale, bool
                                                     bForceVelocity)
{
    if (Character && Spline)
    {
        FVector point_start=Character->GetActorLocation();
        float key_start= Spline->FindInputKeyClosestToWorldLocation(point_start)+(DistanceOffset*DeltaTime);
        FVector target_loc=Spline->GetLocationAtSplineInputKey(key_start,ESplineCoordinateSpace::World);
        
        FRotator target_dir=UKismetMathLibrary::FindLookAtRotation(point_start,target_loc);
        FVector target_vel=UKismetMathLibrary::Conv_RotatorToVector(target_dir);
        
        if (bForceVelocity)
        {
            Character->GetMovementComponent()->Velocity=target_vel*InputScale;
        }
        else
        {
            Character->AddMovementInput(target_vel*InputScale);
        }
    }
     
}

void UOmegaFunctions_Tick::RotatePawn_ToVelocity(float DeltaTime, APawn* Pawn, float Speed, bool X,
    bool Y, bool Z)
{
    if (Pawn)
    {
        FVector vel=Pawn->GetVelocity();
        FRotator target_rot=UKismetMathLibrary::Conv_VectorToRotator(vel);
        if (!X) { target_rot.Roll=0.0;}
        if (!Y) { target_rot.Pitch=0.0;}
        if (!Z) { target_rot.Yaw=0.0;}
        FRotator _r=UKismetMathLibrary::RInterpTo(Pawn->GetActorRotation(),target_rot,DeltaTime,Speed);
        Pawn->SetActorRotation(_r);
    }
}

void UOmegaFunctions_Tick::Interp_SceneComponent(float DeltaTime, USceneComponent* Source, USceneComponent* To,
    float Speed, bool bLocation, bool bRotation)
{
    if (Source && To)
    {
        if (bLocation)
        {
            Source->SetWorldLocation(UKismetMathLibrary::VInterpTo(Source->GetComponentLocation(),To->GetComponentLocation(),DeltaTime,Speed));    
        }
        if (bRotation)
        {
            Source->SetWorldRotation(UKismetMathLibrary::RInterpTo(Source->GetComponentRotation(),To->GetComponentRotation(),DeltaTime,Speed));    
        }
    }
}

void UOmegaFunctions_Tick::Interp_SpringArm(float DeltaTime, USpringArmComponent* Source, USpringArmComponent* To,
float Speed, bool bLocation, bool bRotation, bool ArmLength, bool bSocketOffset,bool bTargetOffset)
{
    if (Source && To)
    {
        Interp_SceneComponent(DeltaTime,Source,To,Speed,bLocation,bRotation);
        if (ArmLength)
        {
            Source->TargetArmLength=UKismetMathLibrary::FInterpTo(Source->TargetArmLength,To->TargetArmLength,DeltaTime,Speed);
        }
        if (bSocketOffset)
        {
            Source->SocketOffset=UKismetMathLibrary::VInterpTo(Source->SocketOffset,To->SocketOffset,DeltaTime,Speed);
        }
        if (bTargetOffset)
        {
            Source->TargetOffset=UKismetMathLibrary::VInterpTo(Source->TargetOffset,To->TargetOffset,DeltaTime,Speed);
        }
    }
}

void UOmegaFunctions_Tick::Interp_Camera(float DeltaTime, UCameraComponent* Source, UCameraComponent* To,
    float Speed, bool bLocation, bool bRotation, bool bFOV)
{
    if (Source && To)
    {
        Interp_SceneComponent(DeltaTime,Source,To,Speed,bLocation,bRotation);
        if (bFOV)
        {
            Source->SetFieldOfView(UKismetMathLibrary::FInterpTo(Source->FieldOfView,To->FieldOfView,DeltaTime,Speed));
        }
    }
}

