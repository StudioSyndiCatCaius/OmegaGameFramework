// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_RandomizedMesh.h"
#include "Helpers/PCGBlueprintHelpers.h"
#include "Kismet/KismetMathLibrary.h"

AOmegaRandomizedMeshActor::AOmegaRandomizedMeshActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	MeshComponent=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(RootComponent);
	
	SetActorTickEnabled(false);
}

void AOmegaRandomizedMeshActor::OnConstruction(const FTransform& Transform)
{
	if(bSeedFromLocation)
	{
		stream_seed=FRandomStream(UPCGBlueprintHelpers::ComputeSeedFromPosition(GetActorLocation()));
	}
	if(Meshes.IsValidIndex(0))
	{
		MeshComponent->SetStaticMesh(Meshes[UKismetMathLibrary::RandomIntegerInRangeFromStream(stream_seed,0,Meshes.Num()-1)]);
	}
	FRotator rot=UKismetMathLibrary::RLerp(Rotation_Range,Rotation_Range*-1,UKismetMathLibrary::RandomFloatFromStream(stream_seed),true);
	MeshComponent->SetRelativeRotation(rot);
	float scale_val=UKismetMathLibrary::RandomFloatInRangeFromStream(stream_seed,Scale_Min,Scale_Max);
	MeshComponent->SetRelativeScale3D(FVector(scale_val,scale_val,scale_val));
	Super::OnConstruction(Transform);
}
