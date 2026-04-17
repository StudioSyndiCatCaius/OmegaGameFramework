// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaActors.h"
#include "Actor_DynamicCamera.generated.h"

class UOmegaSubsystem_Player;
class USpringArmComponent;
class UCameraComponent;


UINTERFACE(MinimalAPI)
class UActorInterface_DynamicCameraSource : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IActorInterface_DynamicCameraSource
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="Omega|DynamicCamera")
	void DynaCam_GetComponents(USpringArmComponent*& spring_arm,UCameraComponent*& camera);
	
};

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
	
	//Tick when this is the Source Camera for a player
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera")
	void SourceTick(float deltaTime, APlayerController* SourcePlayer, UOmegaSubsystem_Player* Subsystem);

	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera")
	void OnBeginAsTargetCamera(APlayerController* SourcePlayer);
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera")
	void OnEndAsTargetCamera(APlayerController* SourcePlayer);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") FName GlobalBinding;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") int32 Priority;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") bool CameraActive=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") float InterpSpeed=10.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") float InterpSpeed_Location;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") float InterpSpeed_Rotation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🎥DynamicCamera") bool SetRotationToPlayerControl;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, meta = (ShowOnlyInnerProperties), Category="Components") USpringArmComponent* comp_spring;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, meta = (ShowOnlyInnerProperties), Category="Components") UCameraComponent* comp_camera;
	
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera",DisplayName="Message - On Begin")
	void K2_OnGameMessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicCamera",DisplayName="Message - On End")
	void K2_OnGameMessageBegin(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta);
};

