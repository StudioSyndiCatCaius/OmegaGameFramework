// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Water.h"

#include "Components/BoxComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Misc/OmegaUtils_BP.h"

AOmegaWater_Plane::AOmegaWater_Plane()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Mesh=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	
	Mesh_Surface=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh_Surface");
	Mesh_Surface->SetupAttachment(RootComponent);
	Mesh_Surface->bHiddenInGame=true;
	if(UStaticMesh* _m=OGF_BP::Mesh_WaterPlane(this))
	{
		Mesh->SetStaticMesh(_m);	
		Mesh_Surface->SetStaticMesh(_m);
		if(UMaterialInterface* m=OGF_BP::Mat_Blocking(this))
		{
			Mesh_Surface->SetMaterial(0,m);
		}
	}

	PostProcess=CreateOptionalDefaultSubobject<UPostProcessComponent>("PostProcess");
	PostProcess->SetupAttachment(RootComponent);
	PostProcess_Range=CreateOptionalDefaultSubobject<UBoxComponent>("Range");
	PostProcess_Range->SetupAttachment(RootComponent);
}

void AOmegaWater_Plane::BeginPlay()
{
	Super::BeginPlay();
}

void AOmegaWater_Plane::OnConstruction(const FTransform& Transform)
{
	if(Style)
	{
		Style->ApplyTo_Component(Mesh,0,PostProcess);
	}
	Depth.X=0;
	Depth.Y=0;
	Config.Depth=Depth.Z*-1;
	PostProcess_Range->SetRelativeLocation(FVector(0,0,Config.Depth/-2));
	PostProcess_Range->SetBoxExtent(FVector(50,50,Config.Depth/2));
	Mesh_Surface->SetRelativeLocation(FVector(0,0,Config.Depth/-1));
}

void AOmegaWater_Plane::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if(OtherActor && !OverlappedActors.Contains(OtherActor))
	{
		OverlappedActors.Add(OtherActor);
		if(Style)
		{
			Style->OnOverlap_Start(OtherActor);
		}
	}
}

void AOmegaWater_Plane::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	if(OtherActor && OverlappedActors.Contains(OtherActor))
	{
		OverlappedActors.Remove(OtherActor);
		if(Style)
		{
			Style->OnOverlap_End(OtherActor);
		}
	}
	
}

AOmegaWater_River::AOmegaWater_River()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Spline=CreateOptionalDefaultSubobject<USplineComponent>("Spline");
	Spline->SetupAttachment(RootComponent);

	PostProcess=CreateOptionalDefaultSubobject<UPostProcessComponent>("PostProcess");
	PostProcess->SetupAttachment(RootComponent);
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
			if(UStaticMesh* _m=OGF_BP::Mesh_WaterPlane(this))
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
				Style->ApplyTo_Component(mesh_comp,1,PostProcess);
			}
			RiverMeshes.Add(mesh_comp);
		}
	}
}
