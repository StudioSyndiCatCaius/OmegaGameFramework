// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_GameplayRegion.h"

#include "Components/BoxComponent.h"
#include "Components/Component_ActorIdentity.h"

AGameplay_Region::AGameplay_Region()
{
	Range=CreateDefaultSubobject<UBoxComponent>("Range");
	RootComponent=Range;
	ID=CreateOptionalDefaultSubobject<UActorIdentityComponent>("ID");
	Range->ShapeColor=FColor::Yellow;
	Range->SetBoxExtent(FVector(200,200,200));
	Range->SetLineThickness(2.5);
}
