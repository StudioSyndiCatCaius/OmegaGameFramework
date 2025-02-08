// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Component_AimTargeter.generated.h"


UINTERFACE(MinimalAPI) class UActorInterface_AimTarget : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_AimTarget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="Aim Target")
	FVector GetAimTargetLocation(const UAimTargetComponent* Component) const;
};



UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UAimTargetComponent : public UActorComponent
{
	GENERATED_BODY()

	FVector local_GetTargetLoc(AActor* target_actor) const;

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	
public:

	UPROPERTY(EditAnywhere,Category="Aim Targeter")
	AActor* AimTarget;

	UFUNCTION(BlueprintCallable,Category="Aim Target")
	FVector GetSelf_AimRootLocation() const;
	
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
