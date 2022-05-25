// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Grid/GridManagerComponent.h"

#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UGridManagerComponent::UGridManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UGridManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGridManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UGridManagerComponent::BuildGrid()
{
	Coords.Empty();

	UInstancedStaticMeshComponent* PreviewComp = Cast<UInstancedStaticMeshComponent>(GetOwner()->AddComponentByClass(UInstancedStaticMeshComponent::StaticClass(), false, GetRelativeTransform(), false));
	return false;
}

