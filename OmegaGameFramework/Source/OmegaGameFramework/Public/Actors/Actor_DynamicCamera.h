// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaActors.h"
#include "Actor_DynamicCamera.generated.h"

class UOmegaSubsystem_Player;
class USpringArmComponent;
class UCameraComponent;


// Implement on actors that expose a spring arm and camera to the dynamic camera system.
UINTERFACE(MinimalAPI)
class UActorInterface_DynamicCameraSource : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IActorInterface_DynamicCameraSource
{
	GENERATED_BODY()
public:

	// Returns the spring arm and camera components this actor exposes as a dynamic camera.
	UFUNCTION(BlueprintNativeEvent,Category="Omega|DynamicCamera")
	void DynaCam_GetComponents(USpringArmComponent*& spring_arm,UCameraComponent*& camera);

};

// A pawn-based camera actor that interpolates smoothly toward target positions and integrates with the player camera subsystem.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaDynamicCamera : public AOmegaPawnBASE, public IActorInterface_DynamicCameraSource
{
	GENERATED_BODY()

	UPROPERTY() APlayerController* REF_SourcePlayer=nullptr;

public:
	AOmegaDynamicCamera();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY() TArray<APlayerController*> restricted_players;

	bool L_CanPlayerUse(APlayerController* Player) const;
	float SpeedOffset(float offset) const { return  InterpSpeed+offset; }
	FVector L_Average_Vector(TArray<FVector> inputs, FVector CurrentValue, float DeltaTime) const;
	float L_Average_Float(TArray<float> inputs, float CurrentValue, float DeltaTime);
	FTransform L_Average_Transform(TArray<FTransform> inputs, FTransform CurrentValue, float DeltaTime);

	virtual void DynaCam_GetComponents_Implementation(USpringArmComponent*& spring_arm, UCameraComponent*& camera) override;

	// Called each tick while this camera is the active source for a player. Override in Blueprint or C++ to drive custom camera logic.
	UFUNCTION(BlueprintNativeEvent,Category="DynamicCamera")
	void SourceTick(float deltaTime, APlayerController* SourcePlayer, UOmegaSubsystem_Player* Subsystem);

	// Called in Blueprint when this camera becomes the active camera for a player.
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera")
	void OnBeginAsTargetCamera(APlayerController* SourcePlayer);
	// Called in Blueprint when this camera is no longer the active camera for a player.
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera")
	void OnEndAsTargetCamera(APlayerController* SourcePlayer);

	// Save/load key used to persist or restore this camera as the active camera via the save system.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") FName GlobalBinding;
	// Higher-priority cameras override lower-priority ones when multiple cameras compete for a player.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") int32 Priority;
	// When false, this camera is ignored by the player camera subsystem even if it has the highest priority.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") bool CameraActive=true;
	// Default interpolation speed applied to both location and rotation when no per-axis override is set.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") float InterpSpeed=10.0;
	// Per-axis interpolation speed override for location; 0 uses the base InterpSpeed.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") float InterpSpeed_Location;
	// Per-axis interpolation speed override for rotation; 0 uses the base InterpSpeed.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") float InterpSpeed_Rotation;
	// When true, the camera's rotation is driven by the owning player's control rotation instead of interpolating.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") bool SetRotationToPlayerControl;

	// Spring arm component that drives the camera's offset and collision avoidance.
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (ShowOnlyInnerProperties), Category="Components") USpringArmComponent* comp_spring;
	// The camera component rendered for the player.
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (ShowOnlyInnerProperties), Category="Components") UCameraComponent* comp_camera;

	// Called in Blueprint when a gameplay message ends while this camera is active.
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera",DisplayName="Message - On Begin")
	void K2_OnGameMessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	// Called in Blueprint when a gameplay message begins while this camera is active.
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera",DisplayName="Message - On End")
	void K2_OnGameMessageBegin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
};
