// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "TimelineActor.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API ATimelineActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATimelineActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category="Timeline Actor")
	UTimelineComponent* GetRootTimeline();
};
