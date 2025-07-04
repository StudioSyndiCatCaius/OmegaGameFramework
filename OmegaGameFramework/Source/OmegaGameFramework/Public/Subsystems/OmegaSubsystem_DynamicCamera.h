// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Camera/CameraActor.h"
#include "GameFramework/Pawn.h"
#include "Components/ActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "OmegaSubsystem_DynamicCamera.generated.h"

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

// ========================================================================================================================
// SUBSYSTEM
// ========================================================================================================================

UCLASS(DisplayName="Omega Subsystem: Dynamic Camera")
class OMEGAGAMEFRAMEWORK_API UOmegaDynamicCameraSubsystem : public ULocalPlayerSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY() float time_SinceLastCheck;
	UPROPERTY() bool is_DynamicCamerActive;
	UPROPERTY() APlayerController* REF_Controller;

public:
	virtual void PlayerControllerChanged(APlayerController* NewPlayerController) override;
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


	UPROPERTY() AOmegaDynamicCamera* override_camera;
	UPROPERTY() TArray<AOmegaDynamicCamera*> source_cameras;
	UPROPERTY() AOmegaDynamicCamera* master_camera;
	UPROPERTY() float last_delta;
	
	UFUNCTION()
	TSubclassOf<AOmegaDynamicCamera> GetDynamicCameraClass();

	UFUNCTION(BlueprintPure, Category="DynamicCamera",DisplayName="Get Master Camera")
	AOmegaDynamicCamera* GetDynamicCamera();
	UFUNCTION(BlueprintPure, Category="DynamicCamera",DisplayName="Get Source Camera")
	AOmegaDynamicCamera* GetSourceCamera();
	
	UFUNCTION() void SetCameraSourceRegistered(AOmegaDynamicCamera* Camera, bool IsActive);
	
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void SetDynamicCameraActive(bool IsActive);
	UFUNCTION(BlueprintPure,Category="Dynamic Camera")
	bool IsDynamicCameraActive() const { return is_DynamicCamerActive;}

	UFUNCTION()
	void InterpToTarget(AOmegaDynamicCamera* cam_source, AOmegaDynamicCamera* cam_master, float speed);

	//Overrides the Source camera with a specific camera. Doing this will active that camera. Deactivating it will ignore its override.
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void SetOverrideCamera(AOmegaDynamicCamera* Camera, bool bSnapTo);
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void ClearOverrideCamera();
	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void SnapToCurrentSource();

	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void SetAllCamerasWithTags_Active(FGameplayTagContainer Tags, bool bActive);
};


// ========================================================================================================================
// Actor
// ========================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaDynamicCamera : public APawn, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaDynamicCamera();

	FVector LOCAL_Average_Vector(TArray<FVector> inputs, FVector CurrentValue, float DeltaTime);
	float LOCAL_Average_Float(TArray<float> inputs, float CurrentValue, float DeltaTime);
	FTransform LOCAL_Average_Transform(TArray<FTransform> inputs, FTransform CurrentValue, float DeltaTime);
	
protected:

	UPROPERTY(VisibleAnywhere,Category="DynamicCamera",DisplayName="Sources")
	TArray<UObject*> REF_Sources;

	UPROPERTY()
	float ArmLength_target;
	UFUNCTION()
	TArray<UObject*> GetValidSources();

	virtual void BeginPlay() override;

	UPROPERTY() UOmegaDynamicCameraSubsystem* REF_Subsystem=nullptr;
	UPROPERTY() APlayerController* REF_SourcePlayer=nullptr;

public:
	
	virtual void Tick(float DeltaSeconds) override;

	//Tick when this is the Source Camera for a player
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera")
	void SourceTick(float deltaTime, APlayerController* SourcePlayer, UOmegaDynamicCameraSubsystem* Subsystem);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicCamera")
	USpringArmComponent* comp_spring;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicCamera")
	UCameraComponent* comp_camera;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicCamera")
	FName GlobalBinding;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicCamera")
	int32 Priority;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicCamera")
	bool CameraActive=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicCamera")
	float InterpSpeed=10.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicCamera")
	float InterpSpeed_Location;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicCamera")
	float InterpSpeed_Rotation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DynamicCamera")
	bool SetRotationToPlayerControl;

	float SpeedOffset(float offset) const { return  InterpSpeed+offset; }

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="DynamicCamera")
	FGameplayTagContainer CameraTags;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
};

UINTERFACE(MinimalAPI)
class UOmegaDynamicCameraSource : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IOmegaDynamicCameraSource
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Dynamic Camera")
	bool GetFieldOfView(float& FOV);
	UFUNCTION(BlueprintImplementableEvent,Category="Dynamic Camera")
	bool GetCameraBoomLength(float& Length);
	UFUNCTION(BlueprintImplementableEvent,Category="Dynamic Camera")
	bool GetCameraBoomOffset(FVector& Offset);
	UFUNCTION(BlueprintImplementableEvent,Category="Dynamic Camera")
	bool GetRootTransform(FTransform& Transform);
	UFUNCTION(BlueprintImplementableEvent,Category="Dynamic Camera")
	bool GetTargetLocation(FVector& Location);
};


