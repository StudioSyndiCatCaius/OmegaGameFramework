// Fill out your copyright notice in the Description page of Project Settings.


#include "Speaker/OmegaSpeakerComponent.h"
#include "OmegaStoryWorldSubsystem.h"


// Sets default values for this component's properties
UOmegaSpeakerComponent::UOmegaSpeakerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOmegaSpeakerComponent::BeginPlay()
{
	
	SubsystemRef = GetWorld()->GetSubsystem<UOmegaStoryWorldSubsystem>();		// Assign subsystem

	SubsystemRef->RegisterSpeaker(this);	//Register Speaker
	
	Super::BeginPlay();

	// ...
	
}

void UOmegaSpeakerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(SubsystemRef)
	{
		SubsystemRef->UnregisterSpeaker(this);
	}
	
	Super::EndPlay(EndPlayReason);
}


// Called every frame
void UOmegaSpeakerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

