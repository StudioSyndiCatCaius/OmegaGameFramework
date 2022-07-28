// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Ability_Targeting.h"


// Sets default values
AAbility_Targeting::AAbility_Targeting()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbility_Targeting::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbility_Targeting::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

