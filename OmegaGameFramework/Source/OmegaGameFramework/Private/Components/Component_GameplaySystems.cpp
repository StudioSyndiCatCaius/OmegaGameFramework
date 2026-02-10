// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Component_GameplaySystems.h"

#include "Functions/F_Common.h"
#include "Subsystems/Subsystem_Gameplay.h"

// Sets default values for this component's properties
UGameplaySystemsComponent::UGameplaySystemsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGameplaySystemsComponent::BeginPlay()
{
	Super::BeginPlay();
	Local_ActivateSystems();
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
	for(const auto& TempSys : GameplaySystems)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(TempSys, this, ActivationFlag);
	}
}

void UGameplaySystemsComponent::Local_ShutdownSystems()
{
	for(const auto& TempSys : GameplaySystems)
	{
		if(TempSys)
		{
			GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ShutdownGameplaySystem(TempSys, GetOwner(), ActivationFlag);
		}
	}
	UOmegaGameFrameworkBPLibrary::SetGameplaySystemsActive(this,PersistentSystems,false,"",this);
}


// Called every frame
void UGameplaySystemsComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	f_lastFeq+=DeltaTime;
	if(f_lastFeq>=PersistentSystems_Frequency)
	{
		f_lastFeq=0.0;
		UOmegaGameFrameworkBPLibrary::SetGameplaySystemsActive(this,PersistentSystems,true,"",this);
	}
}



