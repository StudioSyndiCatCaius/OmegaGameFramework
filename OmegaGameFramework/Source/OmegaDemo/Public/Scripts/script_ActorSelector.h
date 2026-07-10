// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/OmegaUtils_Actor.h"
#include "script_ActorSelector.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADEMO_API UActorSelector_SoftReference : public UOmegaActorSelector
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,Category="ActorSelector") TSoftObjectPtr<AActor> Actors;
};


UCLASS()
class OMEGADEMO_API UActorSelector_Players : public UOmegaActorSelector
{
	GENERATED_BODY()
};
