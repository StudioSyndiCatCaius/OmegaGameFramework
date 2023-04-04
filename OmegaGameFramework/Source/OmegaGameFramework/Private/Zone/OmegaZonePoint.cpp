// Fill out your copyright notice in the Description page of Project Settings.


// Sets default values

#include "Zone/OmegaZonePoint.h"

#include "Zone/OmegaZoneSubsystem.h"

void AOmegaZonePoint::BeginPlay()
{
	GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->ZonePoints.AddUnique(this);
	
}

void AOmegaZonePoint::Destroyed()
{
	GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->ZonePoints.Remove(this);;
}
