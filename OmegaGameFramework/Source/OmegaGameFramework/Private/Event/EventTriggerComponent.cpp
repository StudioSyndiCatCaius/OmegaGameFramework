// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/EventTriggerComponent.h"

#include "OmegaGameManager.h"
#include "Event/SoftEventInterface.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UEventTriggerComponent::UEventTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEventTriggerComponent::BeginPlay()
{
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UEventTriggerComponent::Native_TriggerEvent);
	Super::BeginPlay();

	// ...
	
}

void UEventTriggerComponent::Native_TriggerEvent(FName Event, UObject* Instigator)
{
	//Trigger global Events
	Local_EventOnActor(GetOwner(), Event, Instigator);
}

// Trigger Events across actor and its components
void UEventTriggerComponent::Local_EventOnActor(AActor* Actor, FName Event, UObject* Instigator)
{
	if(Actor->GetClass()->ImplementsInterface(USoftEventInterface::StaticClass()))
	{
		//Fire Event on Actor
		ISoftEventInterface::Execute_OnEventTriggered(Actor, Event, GetOwner());
		for(UActorComponent* TempComp : Actor->GetComponents())
		{
			if(TempComp->GetClass()->ImplementsInterface(USoftEventInterface::StaticClass()))
			{
				//Fire Event on Components
				ISoftEventInterface::Execute_OnEventTriggered(TempComp, Event, GetOwner());
			}
		}
	}
}


// Called every frame
void UEventTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEventTriggerComponent::TriggerLocalEvent(FName Event)
{
	for (AActor* TempActor : LocalListeningActors)
	{
		Local_EventOnActor(TempActor, Event, GetOwner());
	}
}

void UEventTriggerComponent::TriggerGlobalEvent(FName Event)
{
	UGameplayStatics::GetGameInstance(this)->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.Broadcast(Event, this);
}



