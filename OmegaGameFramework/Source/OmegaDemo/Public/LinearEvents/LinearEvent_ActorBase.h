// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Event/OmegaLinearEvent.h"
#include "Misc/OmegaUtils_Actor.h"
#include "UObject/Object.h"
#include "LinearEvent_ActorBase.generated.h"


UCLASS(Abstract)
class OMEGADEMO_API UOmegaActorEventBase : public UOmegaLinearEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(Instanced,BlueprintReadOnly,Instanced,EditAnywhere,Category="Event")
	UOmegaActorSelector* ActorSource;

	UFUNCTION(BlueprintPure,Category="Event")
	AActor* GetEventActor();
	UFUNCTION(BlueprintPure,Category="Event")
	TArray<AActor*> GetEventActorList();
};

UCLASS(DisplayName="(Event) Actor - Teleport")
class OMEGADEMO_API UOmegaActorEvent_Teleport : public UOmegaActorEventBase
{
	GENERATED_BODY()

public:
	virtual void Native_Begin(const FString& Flag) override;
	
	UPROPERTY(Instanced,BlueprintReadOnly,Instanced,EditAnywhere,Category="Event")
	UOmegaActorSelector* TargetPoint;
	
};


