// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Null.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaNullActor : public AActor
{
	GENERATED_BODY()

public:
	AOmegaNullActor();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="NullActor",meta=(ExposeOnSpawn)) FName NewActorLabel;


};
