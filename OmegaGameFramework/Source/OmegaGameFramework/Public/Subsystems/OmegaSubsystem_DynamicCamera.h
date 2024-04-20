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
	TSubclassOf<AOmegaDynamicCamera> GetDynamicCameraClass();

	UFUNCTION(BlueprintPure, Category="DynamicCamera")
	AOmegaDynamicCamera* GetDynamicCamera();

	UPROPERTY()
	AOmegaDynamicCamera* ref_camera;


	UFUNCTION(BlueprintCallable, Category="Dynamic Camera")
	void SetDynamicCameraActive(bool IsActive);
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaDynamicCamera : public APawn
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
	UPROPERTY()
	float InterpSpeed;

	UFUNCTION()
	TArray<UObject*> GetValidSources();

public:
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicCamera")
	USpringArmComponent* comp_spring;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicCamera")
	UCameraComponent* comp_camera;
	
	UFUNCTION(BlueprintCallable,Category="Omega|DynamicCamera")
	void SetSourceActive(UObject* source, bool bActive);
	UFUNCTION(BlueprintCallable,Category="Omega|DynamicCamera")
	void SetSourceList(TArray<UObject*> Sources);
	UFUNCTION(BlueprintCallable,Category="Omega|DynamicCamera")
	void ClearSources();
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


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDynamicCameraFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|DynamicCamera",meta=(WorldContext="WorldContextObject", AdvancedDisplay="player"))
	static void SetDynamicCamera_Active(UObject* WorldContextObject, APlayerController* player, bool bActive);
	UFUNCTION(BlueprintCallable,Category="Omega|DynamicCamera",meta=(WorldContext="WorldContextObject", AdvancedDisplay="player"))
	static void SetDynamicCamera_SourceActive(UObject* WorldContextObject, APlayerController* player,UObject* Source, bool bActive);
	UFUNCTION(BlueprintCallable,Category="Omega|DynamicCamera",meta=(WorldContext="WorldContextObject", AdvancedDisplay="player"))
	static void SetDynamicCamera_SourceList(UObject* WorldContextObject, APlayerController* player,TArray<UObject*> Sources);
	UFUNCTION(BlueprintCallable,Category="Omega|DynamicCamera",meta=(WorldContext="WorldContextObject", AdvancedDisplay="player"))
	static void ClearDynamicCameraSources(UObject* WorldContextObject, APlayerController* player);
};