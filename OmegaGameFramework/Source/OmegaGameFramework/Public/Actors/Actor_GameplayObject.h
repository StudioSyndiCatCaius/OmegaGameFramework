// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Actor_GameplayObject.generated.h"

class UActorStateComponent;
class UOmegaSaveStateComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayObjectActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaGameplayObjectActor();
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="RandomizedMesh") UActorStateComponent* ActorState;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="RandomizedMesh") UOmegaSaveStateComponent* SaveVisibility;

protected:
	//virtual void OnConstruction(const FTransform& Transform) override;

public:

};
