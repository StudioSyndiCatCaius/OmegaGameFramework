// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Actor_ActorProcessor.generated.h"




UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaActorProcessor : public AActor
{
	GENERATED_BODY()

	UPROPERTY() TArray<AActor*> REF_TrackedActors;

public:

	UFUNCTION(BlueprintCallable,Category="ActorProcessor")
	TArray<AActor*> GetRegisteredActors();
	
	UFUNCTION(BlueprintCallable,Category="ActorProcessor")
	void SetActorRegisteredToProcessor(AActor* Actor, bool bIsRegistered);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorRegistered(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorUnregistered(AActor* Actor);
};
