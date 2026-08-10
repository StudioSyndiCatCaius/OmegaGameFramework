// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Minimap.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneCaptureComponent2D;

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaMinimapActor : public AActor
{
	GENERATED_BODY()

public:
	AOmegaMinimapActor();
	
	virtual void BeginPlay() override;

};

// ------------------------------------------------------------------------------------------------------------
// Display Mesh
// ------------------------------------------------------------------------------------------------------------
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaMinimapMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UOmegaMinimapMeshComponent();
	
	virtual void BeginPlay() override;
	
	void L_Refresh();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Minimap")
	bool bLockRotation;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Minimap",meta=(EditCondition="bLockRotation"))
	FRotator LockedRotation;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaMinimap_Mesh : public AOmegaMinimapActor
{
	GENERATED_BODY()

public:
	AOmegaMinimap_Mesh();
	
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Minimap") UOmegaMinimapMeshComponent* StaticMeshComponent;
};

// ------------------------------------------------------------------------------------------------------------
// Camera
// ------------------------------------------------------------------------------------------------------------


UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaMinimap_Camera : public APawn
{
	GENERATED_BODY()

	AOmegaMinimap_Camera();
public:

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ZoneEntityViewCamera") USceneCaptureComponent2D* SceneCaptureComponent;
};

// ------------------------------------------------------------------------------------------------------------
// Functions
// ------------------------------------------------------------------------------------------------------------


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Minimap : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintPure,Category="Omega|Minimap",meta=(WorldContext="WorldContextObject"),DisplayName="🗺️Minimap - Get Camera")
	static AOmegaMinimap_Camera* GetCamera(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Minimap",meta=(WorldContext="WorldContextObject"),DisplayName="🗺️Minimap - Reigster View Component")
	static void RegisterViewComponent(UObject* WorldContextObject, UPrimitiveComponent* Component,bool bRegistered);
	
};
