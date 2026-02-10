// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Player.h"

#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Functions/F_Utility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

FVector UOmegaPlayerFunctions::OffsetScreenPositionToWorld(APlayerController* Player, FVector2D ScreenPosition,
	FVector Offset)
{
	FVector start_pos;
	FVector start_dir;
	UGameplayStatics::DeprojectScreenToWorld(Player,ScreenPosition,start_pos,start_dir);
	return UOmegaMathFunctions::Offset_Vector(start_pos,UKismetMathLibrary::Conv_VectorToRotator(start_dir),Offset);
}

FRotator UOmegaPlayerFunctions::GetRotationFrom2DDirection(APlayerController* Player, FVector2D Start, FVector2D Target,
                                                           FVector Start_Offset, FVector End_Offset)
{
	if(Player)
	{
		FVector loc_start=OffsetScreenPositionToWorld(Player,Start,Start_Offset);
		FVector loc_end=OffsetScreenPositionToWorld(Player,Target,End_Offset);
		return UKismetMathLibrary::FindLookAtRotation(loc_start,loc_end);
	}
	return FRotator();
}

AOmegaPlayer* UOmegaPlayerFunctions::GetOmegaPlayer(UObject* WorldContextObject, int32 Index)
{
	if(WorldContextObject)
	{
		if(AOmegaPlayer* p=Cast<AOmegaPlayer>(UGameplayStatics::GetPlayerController(WorldContextObject,Index)))
		{
			return p;
		}
	}
	return nullptr;
}

TArray<AOmegaPlayer*> UOmegaPlayerFunctions::GetAllOmegaPlayers(UObject* WorldContextObject)
{
	TArray<AOmegaPlayer*> out;
	for (int i = 0; i < UGameplayStatics::GetNumPlayerControllers(WorldContextObject); ++i)
	{
		if(AOmegaPlayer* p=GetOmegaPlayer(WorldContextObject,i))
		{
			out.Add(p);
		}
	}
	return out;
}

FHitResult UOmegaPlayerFunctions::MouseHitForSceneCapture(APlayerController* Player, USceneCaptureComponent2D* SceneCapture, 
	ETraceTypeQuery TraceType, bool TraceComplex, bool OnlyVisibleActorsAndComponents, float TraceDistance)
{
    FHitResult HitResult;
    
    if (!Player || !SceneCapture)
    {
        return HitResult;
    }

    UTextureRenderTarget2D* RenderTarget = SceneCapture->TextureTarget;
    if (!RenderTarget)
    {
        return HitResult;
    }

    // Get mouse position in viewport
    float MouseX, MouseY;
    if (!Player->GetMousePosition(MouseX, MouseY))
    {
        return HitResult;
    }

    // Get viewport size
    int32 ViewportSizeX, ViewportSizeY;
    Player->GetViewportSize(ViewportSizeX, ViewportSizeY);

    // Convert to normalized coordinates (0-1)
    FVector2D NormalizedMousePos(MouseX / ViewportSizeX, MouseY / ViewportSizeY);

    // Get the SceneCapture's transform
    FTransform CaptureTransform = SceneCapture->GetComponentTransform();
    FVector CaptureLocation = CaptureTransform.GetLocation();
    FRotator CaptureRotation = CaptureTransform.Rotator();

    // Get the FOV
    float FOV = SceneCapture->FOVAngle;

    // Calculate aspect ratio
    float AspectRatio = (float)RenderTarget->SizeX / (float)RenderTarget->SizeY;

    // Convert normalized screen position to view space
    // Adjust for screen center (0,0) and flip Y
    float ViewSpaceX = (NormalizedMousePos.X - 0.5f) * 2.0f;
    float ViewSpaceY = (0.5f - NormalizedMousePos.Y) * 2.0f;

    // Calculate tan of half FOV
    float TanHalfFOV = FMath::Tan(FMath::DegreesToRadians(FOV * 0.5f));

    // Convert to world space direction
    FVector ViewDirection;
    ViewDirection.X = 1.0f; // Forward in view space
    ViewDirection.Y = ViewSpaceX * TanHalfFOV * AspectRatio;
    ViewDirection.Z = ViewSpaceY * TanHalfFOV;

    // Transform direction from view space to world space
    FVector WorldDirection = CaptureRotation.RotateVector(ViewDirection.GetSafeNormal());

    // Set up trace parameters
    FVector TraceStart = CaptureLocation;
    FVector TraceEnd = CaptureLocation + (WorldDirection * TraceDistance);

    // Perform line trace
    FCollisionQueryParams QueryParams;
    QueryParams.bTraceComplex = TraceComplex;
    QueryParams.bReturnPhysicalMaterial = true;
    
    if (OnlyVisibleActorsAndComponents)
    {
        QueryParams.bIgnoreBlocks = false;
    }

    // Convert TraceTypeQuery to CollisionChannel
    ECollisionChannel CollisionChannel = UEngineTypes::ConvertToCollisionChannel(TraceType);

    // Perform the trace
    Player->GetWorld()->LineTraceSingleByChannel(
        HitResult,
        TraceStart,
        TraceEnd,
        CollisionChannel,
        QueryParams
    );

    return HitResult;
}

FVector2D UOmegaPlayerFunctions::Mouse_GetNormalizedPosition(APlayerController* PlayerController)
{
	// Use correct types for the getter functions
	float MouseX, MouseY;
	int32 ViewportX, ViewportY;
    
	// Get mouse position (expects float&)
	PlayerController->GetMousePosition(MouseX, MouseY);
    
	// Get viewport size (expects int32&)
	PlayerController->GetViewportSize(ViewportX, ViewportY);
    
	// Convert to normalized coordinates (-1 to 1, center at 0,0)
	FVector2D NormalizedPos;
	NormalizedPos.X = (MouseX / ViewportX) * 2.0 - 1.0;
	NormalizedPos.Y = (MouseY / ViewportY) * 2.0 - 1.0;
    
	// Invert Y since Unreal's screen Y is top-down
	NormalizedPos.Y = -NormalizedPos.Y;
    
	return NormalizedPos;
}

float UOmegaPlayerFunctions::Keys_CombinePressedWeights(TMap<FKey, float> Keys, bool b1Clamped,
	APlayerController* PlayerController)
{
	if (!PlayerController)
	{
		return 0.0f;
	}
    
	float CombinedWeight = 0.0f;
    
	// Check each key and add its weight if currently pressed
	for (const TPair<FKey, float>& KeyPair : Keys)
	{
		if (PlayerController->IsInputKeyDown(KeyPair.Key))
		{
			CombinedWeight += KeyPair.Value;
		}
	}
    
	// Clamp between -1 and 1 if requested
	if (b1Clamped)
	{
		CombinedWeight = FMath::Clamp(CombinedWeight, -1.0f, 1.0f);
	}
    
	return CombinedWeight;
}

