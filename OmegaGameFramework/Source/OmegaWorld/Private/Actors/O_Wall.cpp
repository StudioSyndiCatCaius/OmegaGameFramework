// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/O_Wall.h"


// Sets default values
AO_Wall::AO_Wall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AO_Wall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
