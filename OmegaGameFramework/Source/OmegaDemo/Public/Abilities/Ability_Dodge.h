// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "GameFramework/Actor.h"
#include "Ability_Dodge.generated.h"

UCLASS()
class OMEGADEMO_API AAbility_Dodge : public AOmegaAbility
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbility_Dodge();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
