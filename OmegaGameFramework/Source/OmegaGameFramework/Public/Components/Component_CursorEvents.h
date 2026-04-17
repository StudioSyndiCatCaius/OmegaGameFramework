// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Condition/Condition_Actor.h"
#include "Engine/HitResult.h"
//#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Component_CursorEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCursorEventActor, UOmegaCursorEventComponent*, Component, AActor*, TargetActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCursorEventComponent, UOmegaCursorEventComponent*, Component, USceneComponent*, TargetComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCursorEventTrigger, UOmegaCursorEventComponent*, Component, AActor*, TargetActor, FOmegaCommonMeta, meta);

UINTERFACE(MinimalAPI) class UActorInterface_CursorEventTarget : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_CursorEventTarget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cursor Event",DisplayName="Cursor Target - On Hover")
	void OnHover(UOmegaCursorEventComponent* Component, bool bIsHovered);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cursor Event",DisplayName="Cursor Target - On Trigger")
	void OnTrigger(UOmegaCursorEventComponent* Component, FOmegaCommonMeta meta);
};


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCursorEventComponent : public UActorComponent
{
	GENERATED_BODY()

	static bool L_ActorUsesInterface(AActor* Actor);

public:
	UOmegaCursorEventComponent();
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable) FOnCursorEventActor OnCursor_BeginOverlapActor;
	UPROPERTY(BlueprintAssignable) FOnCursorEventActor OnCursor_EndOverlapActor;
	UPROPERTY(BlueprintAssignable) FOnCursorEventComponent OnCursor_BeginOverlapComponent;
	UPROPERTY(BlueprintAssignable) FOnCursorEventComponent OnCursor_EndOverlapComponent;
	UPROPERTY(BlueprintAssignable) FOnCursorEventTrigger OnCursor_TriggerOverlappedActor;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") bool bIsTracingActive=false;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") TEnumAsByte<ETraceTypeQuery> TraceType;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events") float TraceDistance = 10000.0f;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Cursor Events",DisplayName="❓️Filter Conditons") 
	FOmegaConditions_Actor Filter_Conditions;
	
	//Actors that can register cursor events. If none, allow all actors
	UPROPERTY(BlueprintReadWrite, Category="Cursor Events") TArray<AActor*> AcceptedActors;
	
	UFUNCTION(BlueprintCallable, Category="Cursor Events") bool TriggerOverlappedActor(FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintPure, Category="Cursor Events") AActor* GetCurrentOverlappedActor() const;
	UFUNCTION(BlueprintPure, Category="Cursor Events") USceneComponent* GetCurrentOverlappedComponent() const;
	
	// Get the screen position of the cursor - override this for virtual cursors
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

