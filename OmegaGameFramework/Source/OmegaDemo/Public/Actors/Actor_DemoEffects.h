// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Actor_DemoEffects.generated.h"

class UTurnTrackerComponent;
class UOmegaSaveSubsystem;
class UOmegaSaveGame;

UCLASS()
class OMEGADEMO_API AGameplayEffect_TurnBased : public AOmegaGameplayEffect
{
	GENERATED_BODY()

	bool L_ContextHasValidInterface() const;

	UFUNCTION() void L_TurnTrackerUpdated(UTurnTrackerComponent* Component, int32 TurnsElapsed);

public:

	AGameplayEffect_TurnBased();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UTurnTrackerComponent* TurnTracker;

};

