// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/GameSystem/GameplaySystemsComponent.h"

#include "OmegaGameplaySubsystem.h"

// Sets default values for this component's properties
UGameplaySystemsComponent::UGameplaySystemsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGameplaySystemsComponent::BeginPlay()
{
	Super::BeginPlay();
	Local_ActivateSystems();
	
	// ...
	
}

void UGameplaySystemsComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(!GetWorld()->bIsTearingDown)
	{
		Local_ShutdownSystems();
	}
	Super::EndPlay(EndPlayReason);
}

void UGameplaySystemsComponent::Local_ActivateSystems()
{
	for(const auto TempSys : GameplaySystems)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(TempSys, this, ActivationFlag);
	}
}

void UGameplaySystemsComponent::Local_ShutdownSystems()
{
	for(const auto TempSys : GameplaySystems)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ShutdownGameplaySystem(TempSys, ActivationFlag);
	}
}


// Called every frame
void UGameplaySystemsComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



