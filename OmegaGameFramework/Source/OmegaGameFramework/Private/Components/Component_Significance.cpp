// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Significance.h"

#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

USignificanceComponent::USignificanceComponent()
{
}

void USignificanceComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USignificanceComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
