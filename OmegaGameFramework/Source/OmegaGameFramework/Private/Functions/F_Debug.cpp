// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Debug.h"


void UOmegaFunctions_Debug::Draw_DebugComponent(USceneComponent* Component, FLinearColor Color, bool bAsSphere,
	float Duration, float Thickness, float AxisLength,bool bDrawAxes,bool bDrawBounds, float BoundsScale)
{
    if (!Component)
    {
        return;
    }

    UWorld* World = Component->GetWorld();
    if (!World)
    {
        return;
    }

    FVector Location = Component->GetComponentLocation();
    FRotator Rotation = Component->GetComponentRotation();
    FColor DrawColor = Color.ToFColor(true);

    // Draw location marker (with bounds scale applied if drawing bounds)
    float MarkerScale = (bDrawBounds && bAsSphere) ? BoundsScale : 1.0f;
    
    if (bAsSphere)
    {
        DrawDebugSphere(
            World,
            Location,
            (AxisLength * 0.5f) * MarkerScale,
            12,
            DrawColor,
            false,
            Duration,
            0,
            Thickness
        );
    }
    else
    {
        DrawDebugPoint(
            World,
            Location,
            Thickness * 5.0f,
            DrawColor,
            false,
            Duration
        );
    }

    // Draw rotation axes (optionally scale with bounds)
    if (bDrawAxes)
    {
        float AxisScale = bDrawBounds ? BoundsScale : 1.0f;
        float ScaledAxisLength = AxisLength * AxisScale;
        
        FRotationMatrix RotMatrix(Rotation);
        FVector ForwardAxis = RotMatrix.GetScaledAxis(EAxis::X);
        FVector RightAxis = RotMatrix.GetScaledAxis(EAxis::Y);
        FVector UpAxis = RotMatrix.GetScaledAxis(EAxis::Z);

        // X-Axis (Forward) - Red
        DrawDebugDirectionalArrow(
            World,
            Location,
            Location + (ForwardAxis * ScaledAxisLength),
            ScaledAxisLength * 0.3f,
            FColor::Red,
            false,
            Duration,
            0,
            Thickness
        );

        // Y-Axis (Right) - Green
        DrawDebugDirectionalArrow(
            World,
            Location,
            Location + (RightAxis * ScaledAxisLength),
            ScaledAxisLength * 0.3f,
            FColor::Green,
            false,
            Duration,
            0,
            Thickness
        );

        // Z-Axis (Up) - Blue
        DrawDebugDirectionalArrow(
            World,
            Location,
            Location + (UpAxis * ScaledAxisLength),
            ScaledAxisLength * 0.3f,
            FColor::Blue,
            false,
            Duration,
            0,
            Thickness
        );
    }

    // Draw bounds if requested
    if (bDrawBounds)
    {
        FBoxSphereBounds Bounds = Component->Bounds;
        
        // Apply bounds scale
        FVector ScaledExtent = Bounds.BoxExtent * BoundsScale;
        
        // Draw box bounds
        DrawDebugBox(
            World,
            Bounds.Origin,
            ScaledExtent,
            DrawColor,
            false,
            Duration,
            0,
            Thickness
        );
        
        // Draw sphere bounds
        DrawDebugSphere(
            World,
            Bounds.Origin,
            Bounds.SphereRadius * BoundsScale,
            16,
            DrawColor,
            false,
            Duration,
            0,
            Thickness * 0.5f
        );
    }
}

void UOmegaFunctions_Debug::Draw_DebugLineBetweenComponents(USceneComponent* ComponentA, USceneComponent* ComponentB,
	FLinearColor Color, float Duration, float Thickness)
{
	
	if (!ComponentA || !ComponentB)
	{
		return;
	}

	UWorld* World = ComponentA->GetWorld();
	if (!World)
	{
		return;
	}

	DrawDebugLine(
		World,
		ComponentA->GetComponentLocation(),
		ComponentB->GetComponentLocation(),
		Color.ToFColor(true),
		false,
		Duration,
		0,
		Thickness
	);
}
