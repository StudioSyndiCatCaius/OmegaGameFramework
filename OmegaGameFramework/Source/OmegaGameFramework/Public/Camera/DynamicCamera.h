// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaGameplaySubsystem.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "DynamicCamera.generated.h"

class UOmegaSaveSubsystem;

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UDynamicCameraState : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Instanced, Category="Dynamic Camera")
	UDynamicCameraType* Type;
	
};

UCLASS(EditInlineNew, Abstract, Blueprintable, BlueprintType, CollapseCategories, Const)
class OMEGAGAMEFRAMEWORK_API UDynamicCameraType : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent, Category="Dynamic Camera")
	void GetTargetData(UOmegaDynamicCameraSubsystem* Subsystem, FVector& TargetLocation, FRotator& TargetRotation, float& FOV, float& InterpSpeed, float& TrackingRotationLerp) const;
};

UCLASS(DisplayName="Omega Subsystem: Dynamic Camera")
class OMEGAGAMEFRAMEWORK_API UOmegaDynamicCameraSubsystem : public ULocalPlayerSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:

	virtual void Tick(float DeltaTime) override;
	
	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables );
	}
	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}
	virtual bool IsTickableInEditor() const
	{
		return false;
	}
	// FTickableGameObject End

public:

	UFUNCTION()
	TSubclassOf<ACameraActor> GetDynamicCameraClass();

	UFUNCTION(BlueprintPure, Category="DynamicCamera")
	ACameraActor* GetDynamicCamera();
	
	//-------------------
	// ROOT TARGET
	//-------------------
	UPROPERTY()
	AActor* RootTarget = nullptr;
	UFUNCTION(BlueprintCallable, Category="DynamicCamera")
	void SetCameraRootTarget(AActor* NewRoot)
	{
		if(NewRoot)
		{
			RootTarget = NewRoot;
		}
	}

	//-------------------
	// Tracking Targets
	//-------------------
	UPROPERTY()
	TArray<AActor*> TrackingTargets;
	
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera|Tracking")
	void SetTrackingTargetActive(AActor* TrackingTarget, bool IsActive)
	{
		if(TrackingTarget)
		{
			if(IsActive)
			{
				TrackingTargets.AddUnique(TrackingTarget);
			}
			else if(TrackingTargets.Contains(TrackingTarget))
			{
				TrackingTargets.Remove(TrackingTarget);
			}
		}
	}
	
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera|Tracking")
	void SetTrackingTargets(TArray<AActor*> Targets)
	{
		TrackingTargets = Targets;
	}
	
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera|Tracking")
	void ClearTrackingTargets()
	{
		TrackingTargets.Empty();
	}
	
	UPROPERTY()
	ACameraActor* CamCompRef;
	
	//-------------------
	// Camera State
	//-------------------
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void SetCameraState (UDynamicCameraState* NewState, bool SnapToView);
	
	UPROPERTY(EditAnywhere)
	UDynamicCameraState* CameraState;

	UPROPERTY()
	UOmegaGameplaySubsystem* GameplaySubsys;

	void Local_SetCamData(bool Snap);

	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void SetDynamicCameraActive(bool IsActive);
	
};

