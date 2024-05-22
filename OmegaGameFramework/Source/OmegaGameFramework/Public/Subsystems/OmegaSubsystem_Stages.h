// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OmegaSubsystem_Stages.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaStagesSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaStageTrait : public UObject
{
	GENERATED_BODY()
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaStageManager : public AActor
{
	GENERATED_BODY()

public:
};
