// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameFramework/Public/OmegaAbility.h"
#include "Ability_Jump.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API AAbility_Jump : public AOmegaAbility
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbility_Jump();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
