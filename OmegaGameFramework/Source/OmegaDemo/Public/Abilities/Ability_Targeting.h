// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "Ability_Targeting.generated.h"

class USphereComponent;
class UWidgetComponent;
class UCameraComponent;

UCLASS(Abstract)
class OMEGADEMO_API AAbility_Targeting : public AOmegaAbility
{
	GENERATED_BODY()

		
public:
	// Sets default values for this actor's properties
	AAbility_Targeting();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Native_ActivatedTick(float DeltaTime) override;
	virtual void Native_AbilityActivated(UObject* Context) override;
	virtual void Native_AbilityFinished(bool Cancelled) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	////////////////////////////
	//----------HUD----------//
	////////////////////////////
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="HUD")
	UWidgetComponent* TargetReticle;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Targeting")
	USphereComponent* TargetRegistryRange;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Targeting")
	bool CameraTracksTargets();

	UFUNCTION(BlueprintImplementableEvent, Category="Targeting")
	UCameraComponent* GetOwnerCameraComponent();
	
	////////////////////////////
	//----------Sound----------//
	////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category="Sound")
	USoundBase* TargetingBeginSound;
	UPROPERTY(EditDefaultsOnly, Category="Sound")
	USoundBase* TargetingChangeSound;
	UPROPERTY(EditDefaultsOnly, Category="Sound")
	USoundBase* TargetingEndSound;

	////////////////////////////
	//----------Look----------//
	////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bFaceTarget;
	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	float FaceTargetInterpSeed = 10;
	
	////////////////////////////
	//----------CameraLook----------//
	////////////////////////////
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	float CameraInterpSpeed = 5;
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FVector LookTargetOffset;
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	float MaxCameraRange = 45;
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	float MinCameraRange = -45;

	//----------Targets----------//
	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetRegistered(UCombatantComponent* Target);
	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetUnregistered(UCombatantComponent* Target);
};

