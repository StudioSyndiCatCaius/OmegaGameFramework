// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component_CombatantExtension.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Pawn.h"
#include "Components/ActorComponent.h"
#include "Component_AOE.generated.h"


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaAOEComponent : public UCombatantExtensionComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//UOmegaAOEComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:

};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaAOEInstance : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaAOEInstance();

};