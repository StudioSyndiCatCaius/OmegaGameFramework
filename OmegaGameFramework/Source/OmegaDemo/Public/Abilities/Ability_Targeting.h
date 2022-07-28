// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "GameFramework/Actor.h"
#include "Ability_Targeting.generated.h"

UCLASS()
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
};
