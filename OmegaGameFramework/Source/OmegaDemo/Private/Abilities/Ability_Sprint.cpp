// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Ability_Sprint.h"

#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AAbility_Sprint::AAbility_Sprint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbility_Sprint::BeginPlay()
{
	if(GetAbilityOwnerCharacterMoveComponent())
	{
		GetAbilityOwnerCharacterMoveComponent()->MaxWalkSpeed;
	}
	Super::BeginPlay();
	
}

// Called every frame
void AAbility_Sprint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AAbility_Sprint::GetSprintSpeedMultiplier_Implementation()
{
	return DefaultSpeedMultiplier;
}
