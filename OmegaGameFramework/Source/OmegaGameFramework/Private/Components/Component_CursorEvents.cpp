// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Component_CursorEvents.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"

UOmegaCursorEventComponent::UOmegaCursorEventComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    
    bIsTracingActive = false;
    TraceType = UEngineTypes::ConvertToTraceType(ECC_Visibility);
    TraceDistance = 10000.0f;
}

void UOmegaCursorEventComponent::BeginPlay()
{
    Super::BeginPlay();
    
    // Initialize previous hit result
    PreviousHitResult = FHitResult();
}

FVector2D UOmegaCursorEventComponent::GetCursorScreenPosition_Implementation()
{
    // Default implementation: get mouse position
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC)
    {
        return FVector2D::ZeroVector;
    }
    
    float MouseX, MouseY;
    PC->GetMousePosition(MouseX, MouseY);
    
    return FVector2D(MouseX, MouseY);
}

bool UOmegaCursorEventComponent::PerformCursorTrace(FHitResult& OutHitResult)
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC)
    {
        return false;
    }
    
    // Get cursor screen position (can be overridden for virtual cursor)
    FVector2D ScreenPosition = GetCursorScreenPosition();
    
    // Convert screen position to world space ray
    FVector WorldLocation, WorldDirection;
    if (!PC->DeprojectScreenPositionToWorld(ScreenPosition.X, ScreenPosition.Y, WorldLocation, WorldDirection))
    {
        return false;
    }
    
    // Calculate end point for line trace
    FVector TraceEnd = WorldLocation + (WorldDirection * TraceDistance);
    
    // Perform line trace
    return UKismetSystemLibrary::LineTraceSingle(
        GetWorld(),
        WorldLocation,
        TraceEnd,
        TraceType,
        false, // bTraceComplex
        TArray<AActor*>(), // ActorsToIgnore
        EDrawDebugTrace::None,
        OutHitResult,
        true // bIgnoreSelf
    );
}

void UOmegaCursorEventComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    if (!bIsTracingActive)
    {
        return;
    }
    
    // Perform line trace from cursor
    FHitResult CurrentHitResult;
    bool bHit = PerformCursorTrace(CurrentHitResult);
    
    // Check if we hit something valid
    AActor* CurrentActor = nullptr;
    USceneComponent* CurrentComponent = nullptr;
    
    if (bHit && CurrentHitResult.GetActor())
    {
        // Check if actor is in accepted list (if list has entries)
        if (AcceptedActors.Num() > 0)
        {
            if (AcceptedActors.Contains(CurrentHitResult.GetActor()))
            {
                CurrentActor = CurrentHitResult.GetActor();
                CurrentComponent = CurrentHitResult.GetComponent();
            }
        }
        else
        {
            // No filter, accept all actors
            CurrentActor = CurrentHitResult.GetActor();
            CurrentComponent = CurrentHitResult.GetComponent();
        }
    }
    
    AActor* PreviousActor = PreviousHitResult.GetActor();
    USceneComponent* PreviousComponent = PreviousHitResult.GetComponent();
    
    // Check for actor changes
    if (CurrentActor != PreviousActor)
    {
        // End overlap with previous actor
        if (PreviousActor)
        {
            OnCursor_EndOverlapActor.Broadcast(this, PreviousActor);
        }
        
        // Begin overlap with new actor
        if (CurrentActor)
        {
            OnCursor_BeginOverlapActor.Broadcast(this, CurrentActor);
        }
    }
    
    // Check for component changes
    if (CurrentComponent != PreviousComponent)
    {
        // End overlap with previous component
        if (PreviousComponent)
        {
            OnCursor_EndOverlapComponent.Broadcast(this, PreviousComponent);
        }
        
        // Begin overlap with new component
        if (CurrentComponent)
        {
            OnCursor_BeginOverlapComponent.Broadcast(this, CurrentComponent);
        }
    }
    
    // Store current hit for next frame
    PreviousHitResult = CurrentHitResult;
}

AActor* UOmegaCursorEventComponent::GetCurrentOverlappedActor() const
{
    return PreviousHitResult.GetActor();
}

USceneComponent* UOmegaCursorEventComponent::GetCurrentOverlappedComponent() const
{
    return PreviousHitResult.GetComponent();
}