// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
//#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Component_CursorEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCursorEventActor, UOmegaCursorEventComponent*, Component, AActor*, TargetActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCursorEventComponent, UOmegaCursorEventComponent*, Component, USceneComponent*, TargetComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCursorEventTrigger, UOmegaCursorEventComponent*, Component, AActor*, TargetActor, FOmegaCommonMeta, meta);

DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FQuery_CursorActorCheck, AActor*, Actor);

// Implement on actors that should respond when the cursor hovers over or triggers them via UOmegaCursorEventComponent.
UINTERFACE(MinimalAPI, DisplayName="♎Actor🔵 - Cursor Event Target") class UActorInterface_CursorEventTarget : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_CursorEventTarget
{
	GENERATED_BODY()
public:

	// Called when the cursor begins or ends hovering over this actor.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cursor Event",DisplayName="Cursor Target - On Hover")
	void OnHover(UOmegaCursorEventComponent* Component, bool bIsHovered);

	// Called when the player confirms selection of this actor through the cursor.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cursor Event",DisplayName="Cursor Target - On Trigger")
	void OnTrigger(UOmegaCursorEventComponent* Component, FOmegaCommonMeta meta);
};


// Performs a line trace from the cursor each tick and fires Blueprint events when the traced actor changes or is triggered.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCursorEventComponent : public UActorComponent
{
	GENERATED_BODY()

	static bool L_ActorUsesInterface(AActor* Actor);

public:
	UOmegaCursorEventComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Fires when the cursor trace begins overlapping a new actor.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCursorEventActor OnCursor_BeginOverlapActor;
	// Fires when the cursor trace stops overlapping an actor.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCursorEventActor OnCursor_EndOverlapActor;
	// Fires when the cursor trace begins overlapping a scene component.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCursorEventComponent OnCursor_BeginOverlapComponent;
	// Fires when the cursor trace stops overlapping a scene component.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCursorEventComponent OnCursor_EndOverlapComponent;
	// Fires when TriggerOverlappedActor is called while an actor is hovered.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnCursorEventTrigger OnCursor_TriggerOverlappedActor;

	// When false the cursor line trace is paused and no events fire.
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") bool bIsTracingActive=false;
	// Collision channel used for the cursor line trace.
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") TEnumAsByte<ETraceTypeQuery> TraceType;
	// Maximum range of the cursor line trace in world units (cm).
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") float TraceDistance = 10000.0f;

	// Optional per-actor filter delegate; return false to prevent an actor from being hovered.
	UPROPERTY(BlueprintReadWrite, Category = "Cursor Events") FQuery_CursorActorCheck Query_CanHover;


	// Explicit allowlist of actors that can receive cursor events. Leave empty to accept all actors.
	UPROPERTY(BlueprintReadWrite, Category="Cursor Events") TArray<AActor*> AcceptedActors;

	// Confirms selection of the currently hovered actor and fires OnCursor_TriggerOverlappedActor.
	UFUNCTION(BlueprintCallable, Category="Cursor Events") bool TriggerOverlappedActor(FOmegaCommonMeta meta);

	// Returns the actor the cursor is currently hovering over, or null if none.
	UFUNCTION(BlueprintPure, Category="Cursor Events") AActor* GetCurrentOverlappedActor() const;
	// Returns the specific scene component the cursor trace hit, or null if none.
	UFUNCTION(BlueprintPure, Category="Cursor Events") USceneComponent* GetCurrentOverlappedComponent() const;

	// Returns the 2D screen position of the cursor. Override in Blueprint to support virtual or gamepad-driven cursors.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cursor Events")
	FVector2D GetCursorScreenPosition();

	bool Actor_IsAcceptable(AActor* actor) const;

protected:
	virtual void BeginPlay() override;

	// Perform the actual line trace from cursor position
	bool PerformCursorTrace(FHitResult& OutHitResult);

private:
	// Store the previous hit result to detect changes
	FHitResult PreviousHitResult;
};
