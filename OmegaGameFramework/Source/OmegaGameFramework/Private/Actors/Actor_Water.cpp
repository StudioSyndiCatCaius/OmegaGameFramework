// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Water.h"

#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"

UStaticMesh* L_DefaultWater(UObject* outer)
{
	return LoadObject<UStaticMesh>(outer,TEXT("/OmegaGameFramework/Meshes/geo/SM_OMEGA_WaterPlane.SM_OMEGA_WaterPlane"));
}

AOmegaWater_Plane::AOmegaWater_Plane()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Mesh=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	if(UStaticMesh* _m=L_DefaultWater(this))
	{
		Mesh->SetStaticMesh(_m);	
	}
	
}

void AOmegaWater_Plane::BeginPlay()
{
	Super::BeginPlay();
}

void AOmegaWater_Plane::OnConstruction(const FTransform& Transform)
{
	if(Style)
	{
		Style->ApplyTo_Component(Mesh,0);
	}
}

AOmegaWater_River::AOmegaWater_River()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Spline=CreateOptionalDefaultSubobject<USplineComponent>("Spline");
	Spline->SetupAttachment(RootComponent);
}

void AOmegaWater_River::BeginPlay()
{
	Super::BeginPlay();
}

void AOmegaWater_River::OnConstruction(const FTransform& Transform)
{
	for(auto* m : RiverMeshes)
	{
		if(m)
		{
			m->DestroyComponent();
		}
	}
	RiverMeshes.Empty();
	if(Spline)
	{
		for (int i = 0; i < Spline->GetNumberOfSplinePoints()-1; ++i)
		{
			USplineMeshComponent* mesh_comp=Cast<USplineMeshComponent>(
				AddComponentByClass(USplineMeshComponent::StaticClass(),false,FTransform(),false));
			if(UStaticMesh* _m=L_DefaultWater(this))
			{
				mesh_comp->SetStaticMesh(_m);	
			}
			mesh_comp->SetStartAndEnd(
				Spline->GetLocationAtSplinePoint(i,ESplineCoordinateSpace::Local),
				Spline->GetTangentAtSplinePoint(i,ESplineCoordinateSpace::Local),
				Spline->GetLocationAtSplinePoint(i+1,ESplineCoordinateSpace::Local),
				Spline->GetTangentAtSplinePoint(i+1,ESplineCoordinateSpace::Local)
				);
			if(Style)
			{
				Style->ApplyTo_Component(mesh_comp,1);
			}
			RiverMeshes.Add(mesh_comp);
		}
	}
}
