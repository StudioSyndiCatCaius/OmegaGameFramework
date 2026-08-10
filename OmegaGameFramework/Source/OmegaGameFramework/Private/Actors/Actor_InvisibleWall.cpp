// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_InvisibleWall.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

AOmegaInvisibleWall::AOmegaInvisibleWall()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeFinder(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeFinder.Succeeded())
	{
		DefaultMesh = CubeFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BlockingMatFinder(
		TEXT("/OmegaGameFramework/Materials/Instances/VolumeDisplay/m_VolumeDisplay_Blocking.m_VolumeDisplay_Blocking"));
	if (BlockingMatFinder.Succeeded())
	{
		Material_Blocking = BlockingMatFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> FreeCamMatFinder(
		TEXT("/OmegaGameFramework/Materials/Instances/VolumeDisplay/m_VolumeDisplay_BlockingFreeCam.m_VolumeDisplay_BlockingFreeCam"));
	if (FreeCamMatFinder.Succeeded())
	{
		Material_BlockingFreeCam = FreeCamMatFinder.Object;
	}
}

void AOmegaInvisibleWall::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (UStaticMeshComponent* MeshComp = GetStaticMeshComponent())
	{
		if (!MeshComp->GetStaticMesh() && DefaultMesh)
		{
			MeshComp->SetStaticMesh(DefaultMesh);
		}

		if (bAllowCamera)
		{
			if (Material_BlockingFreeCam)
			{
				MeshComp->SetMaterial(0, Material_BlockingFreeCam);
			}
			MeshComp->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
		}
		else
		{
			if (Material_Blocking)
			{
				MeshComp->SetMaterial(0, Material_Blocking);
			}
			MeshComp->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);
		}
	}

	SetActorHiddenInGame(true);
}
