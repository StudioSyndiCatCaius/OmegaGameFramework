// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "GameFramework/Actor.h"
#include "Ability_Sprint.generated.h"

UCLASS()
class OMEGADEMO_API AAbility_Sprint : public AOmegaAbility
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbility_Sprint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY()
	float DefaultMoveSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Sprint")
	float DefaultSpeedMultiplier = 1.5;
	
	UFUNCTION(BlueprintNativeEvent, Category="Sprint")
	float GetSprintSpeedMultiplier();
};

float AAbility_Sprint::GetSprintSpeedMultiplier_Implementation()
{
	return DefaultSpeedMultiplier;
}
