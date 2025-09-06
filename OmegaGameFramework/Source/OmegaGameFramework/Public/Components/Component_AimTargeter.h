// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameplayComponent.h"
#include "Components/ActorComponent.h"
#include "Component_AimTargeter.generated.h"


UINTERFACE(MinimalAPI) class UActorInterface_AimTarget : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_AimTarget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="Ω|Actor",DisplayName="Aim Target - Get LocatioN")
	FVector GetAimTargetLocation(const UAimTargetComponent* Component) const;
};



UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UAimTargetComponent : public UOmegaGameplayComponent
{
	GENERATED_BODY()

	FVector local_GetTargetLoc(AActor* target_actor) const;
	
public:

	UPROPERTY(EditAnywhere,Category="Aim Targeter")
	AActor* AimTarget;
	UPROPERTY(EditAnywhere,Category="Aim Targeter")
	FRotator RotationOffset;
	
	UFUNCTION(BlueprintCallable,Category="Aim Target")
	FVector GetSelf_AimRootLocation() const;

	UFUNCTION(BlueprintCallable,Category="Aim Target")
	FVector GetSelf_AimNormal() const;
	
	UFUNCTION(BlueprintCallable,Category="Aim Target")
	FVector GetTarget_AimLocation() const;

	UFUNCTION(BlueprintCallable,Category="Aim Target")
	AActor* GetAimTarget() const;

	UFUNCTION(BlueprintCallable,Category="Aim Target")
	void SetAimTarget(AActor* NewTarget);
	
	UFUNCTION(BlueprintCallable,Category="Aim Target")
	void ClearAimTarget();

	UFUNCTION(BlueprintCallable,Category="Aim Target")
	bool IsAimActive() const;
};
