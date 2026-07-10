// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "GameFramework/Actor.h"
#include "sys_TurnBasedCombat.generated.h"

class UCombatantComponent;
class UOmegaCombatEncounter_Component;
class UTurnBasedManagerComponent;

UCLASS(Abstract)
class OMEGADEMO_API AOmegaDemoSystem_TurnBasedCombat : public AOmegaGameplaySystem
{
	GENERATED_BODY()

public:

	AOmegaDemoSystem_TurnBasedCombat();

protected:

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SystemActivated_Implementation(UObject* Context, const FString& Flag) override;
};


