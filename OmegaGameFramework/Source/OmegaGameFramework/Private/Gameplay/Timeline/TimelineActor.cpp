// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Timeline/TimelineActor.h"

// Sets default values
ATimelineActor::ATimelineActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATimelineActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimelineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

