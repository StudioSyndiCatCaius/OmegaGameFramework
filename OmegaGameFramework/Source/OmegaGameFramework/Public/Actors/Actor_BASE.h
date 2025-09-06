// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/OmegaInterface_Json.h"
#include "Actor_BASE.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaBaseActor : public AActor, public  IDataInterface_Json
{
	GENERATED_BODY()

public:

	//OmegaBaseActor();
	
};
