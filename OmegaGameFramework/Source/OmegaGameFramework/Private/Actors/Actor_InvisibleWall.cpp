// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_InvisibleWall.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"


void AOmegaInvisibleWall::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (!GetStaticMeshComponent()->GetStaticMesh())
	{
		if (UStaticMesh* sm=LoadObject<UStaticMesh>(this, TEXT("/Engine/BasicShapes/Cube.Cube")))
		{
			GetStaticMeshComponent()->SetStaticMesh(sm);
		}
	}
	FString mat_path;
	if (bAllowCamera)
	{
		mat_path = "/OmegaGameFramework/Materials/Instances/VolumeDisplay/m_VolumeDisplay_BlockingFreeCam.m_VolumeDisplay_BlockingFreeCam";
		GetStaticMeshComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	}
	else
	{
		mat_path = "/OmegaGameFramework/Materials/Instances/VolumeDisplay/m_VolumeDisplay_Blocking.m_VolumeDisplay_Blocking";
		GetStaticMeshComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);
	}
	if (UMaterialInterface* mi=LoadObject<UMaterialInterface>(this, mat_path))
	{
		GetStaticMeshComponent()->SetMaterial(0, mi);	
	}
	
	SetActorHiddenInGame(true);
}
