// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_GameplayRegion.h"

#include "Components/BoxComponent.h"
#include "Components/Component_ActorIdentity.h"
#include "Functions/F_Component.h"


AGameplay_Region::AGameplay_Region()
{
	ID=CreateOptionalDefaultSubobject<UActorIdentityComponent>("ID");
}
void AGameplay_Region::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if(RegionIdentity)
	{
		if(ID)
		{
			ID->SetIdentitySourceAsset(RegionIdentity);
		}
		if(RegionIdentity->DebugMaterial)
		{
			Volume->SetMaterial(0,RegionIdentity->DebugMaterial);
		}
	}
}

