// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameplaySystem.h"
#include "GameFramework/Actor.h"
#include "OmegaDemoSystems.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API AOmegaDemoSystems : public AOmegaGameplaySystem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaDemoSystems();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SystemActivated_Implementation(UObject* Context, const FString& Flag) override;
	
};
