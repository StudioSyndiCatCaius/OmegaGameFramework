// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Component_CursorEvents.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"

bool UOmegaCursorEventComponent::L_ActorUsesInterface(AActor* Actor)
{
    if (Actor && Actor->GetClass()->ImplementsInterface(UActorInterface_CursorEventTarget::StaticClass()))
    {
        return true;
    }
    return false;
}

UOmegaCursorEventComponent::UOmegaCursorEventComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    
    bIsTracingActive = false;
    TraceType = UEngineTypes::ConvertToTraceType(ECC_Visibility);
    TraceDistance = 10000.0f;
}

bool UOmegaCursorEventComponent::Actor_IsAcceptable(AActor* actor) const
{
    if (actor)
    {
        if (!AcceptedActors.IsEmpty() && !AcceptedActors.Contains(actor))
        {
            return false;
        }
        if (Query_CanHover.IsBound())
        {
            if (!Query_CanHover.Execute(actor))
            {
                return false;
            }
        }
        return true;
    }
    return false;
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
        if (Actor_IsAcceptable(CurrentHitResult.GetActor()))
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
            if (L_ActorUsesInterface(PreviousActor))
            {
                IActorInterface_CursorEventTarget::Execute_OnHover(PreviousActor,this,false);
            }
        }
        
        // Begin overlap with new actor
        if (CurrentActor)
        {
            OnCursor_BeginOverlapActor.Broadcast(this, CurrentActor);
            if (L_ActorUsesInterface(CurrentActor))
            {
                IActorInterface_CursorEventTarget::Execute_OnHover(CurrentActor,this,true);
            }
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
    
    // Store current hit for next frame (only if actor passed acceptance check)
    PreviousHitResult = CurrentActor ? CurrentHitResult : FHitResult();
}

bool UOmegaCursorEventComponent::TriggerOverlappedActor(FOmegaCommonMeta meta)
{
    if (AActor* a=GetCurrentOverlappedActor())
    {
        OnCursor_TriggerOverlappedActor.Broadcast(this,a,meta);
        if (L_ActorUsesInterface(a))
        {
            IActorInterface_CursorEventTarget::Execute_OnTrigger(a,this,meta);
        }
        return true;
    }
    return false;
}

AActor* UOmegaCursorEventComponent::GetCurrentOverlappedActor() const
{
    return PreviousHitResult.GetActor();
}

USceneComponent* UOmegaCursorEventComponent::GetCurrentOverlappedComponent() const
{
    return PreviousHitResult.GetComponent();
}
