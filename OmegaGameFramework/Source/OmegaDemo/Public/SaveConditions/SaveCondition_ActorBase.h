// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "Misc/OmegaUtils_Actor.h"
#include "SaveCondition_ActorBase.generated.h"


UCLASS(Abstract)
class OMEGADEMO_API USaveCondition_ActorBase : public UOmegaSaveCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(Instanced,BlueprintReadOnly,Instanced,EditAnywhere,Category="Event")
	UOmegaActorSelector* ActorSource;

	UFUNCTION(BlueprintPure,Category="Event")
	AActor* GetConditionActor();
	
};


