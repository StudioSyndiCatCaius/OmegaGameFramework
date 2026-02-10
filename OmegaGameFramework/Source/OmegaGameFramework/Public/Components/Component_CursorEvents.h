// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_CursorEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCursorEventActor, UOmegaCursorEventComponent*, Component, AActor*, TargetActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCursorEventComponent, UOmegaCursorEventComponent*, Component, USceneComponent*, TargetComponent);


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCursorEventComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UOmegaCursorEventComponent();
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable) FOnCursorEventActor OnCursor_BeginOverlapActor;
	UPROPERTY(BlueprintAssignable) FOnCursorEventActor OnCursor_EndOverlapActor;
	
	UPROPERTY(BlueprintAssignable) FOnCursorEventComponent OnCursor_BeginOverlapComponent;
	UPROPERTY(BlueprintAssignable) FOnCursorEventComponent OnCursor_EndOverlapComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") bool bIsTracingActive=false;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") TEnumAsByte<ETraceTypeQuery> TraceType;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") float TraceDistance = 10000.0f;
	
	//Actors that can register cursor events. If none, allow all actors
	UPROPERTY(BlueprintReadWrite, Category="Cursor Events") TArray<AActor*> AcceptedActors;
	
	UFUNCTION(BlueprintPure, Category="Cursor Events") AActor* GetCurrentOverlappedActor() const;
	UFUNCTION(BlueprintPure, Category="Cursor Events") USceneComponent* GetCurrentOverlappedComponent() const;
	
	// Get the screen position of the cursor - override this for virtual cursors
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cursor Events")
	FVector2D GetCursorScreenPosition();

protected:
	virtual void BeginPlay() override;
	
	// Perform the actual line trace from cursor position
	bool PerformCursorTrace(FHitResult& OutHitResult);

private:
	// Store the previous hit result to detect changes
	FHitResult PreviousHitResult;
};