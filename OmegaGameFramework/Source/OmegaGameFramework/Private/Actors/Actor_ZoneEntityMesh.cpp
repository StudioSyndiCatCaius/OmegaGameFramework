// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_ZoneEntityMesh.h"

#include "Subsystems/Subsystem_Zone.h"

AZoneEntity_Mesh::AZoneEntity_Mesh()
{
	ZoneEntity=CreateOptionalDefaultSubobject<UZoneEntityComponent>("ZoneEntity");
	ZoneEntity->UseParentAsDisplayActor=true;
	AActor::SetActorHiddenInGame(true);
	if(GetStaticMeshComponent())
	{
		//GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetStaticMeshComponent()->CastShadow=false;
	}
}

void AZoneEntity_Mesh::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(false);
	GetStaticMeshComponent()->bVisibleInSceneCaptureOnly=true;
}
