// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_RandomizedMesh.h"
#include "Helpers/PCGBlueprintHelpers.h"
#include "Kismet/KismetMathLibrary.h"

AOmegaRandomizedMeshActor::AOmegaRandomizedMeshActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent->SetMobility(EComponentMobility::Static);
	MeshComponent=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(RootComponent);
	//MeshComponent->SetMobility(EComponentMobility::Static);
	
	SetActorTickEnabled(false);
}

void AOmegaRandomizedMeshActor::OnConstruction(const FTransform& Transform)
{
	FOmegaRandomizedMeshInfo _info=Settings;
	if(Preset)
	{
		_info=Preset->Settings;
	}

	if(bSeedFromLocation)
	{
		stream_seed=FRandomStream(UPCGBlueprintHelpers::ComputeSeedFromPosition(GetActorLocation()));
	}
	if(_info.Meshes.IsValidIndex(0))
	{
		MeshComponent->SetStaticMesh(_info.Meshes[UKismetMathLibrary::RandomIntegerInRangeFromStream(stream_seed,0,_info.Meshes.Num()-1)]);
	}
	FRotator rot=UKismetMathLibrary::RLerp(_info.Rotation_Range,_info.Rotation_Range*-1,UKismetMathLibrary::RandomFloatFromStream(stream_seed),true);
	MeshComponent->SetRelativeRotation(rot);
	FVector scale_val;
	scale_val.X=UKismetMathLibrary::RandomFloatInRangeFromStream(stream_seed,_info.Scale_Min.X,_info.Scale_Max.X);
	scale_val.Y=UKismetMathLibrary::RandomFloatInRangeFromStream(stream_seed,_info.Scale_Min.Y,_info.Scale_Max.Y);
	scale_val.Z=UKismetMathLibrary::RandomFloatInRangeFromStream(stream_seed,_info.Scale_Min.Z,_info.Scale_Max.Z);
	MeshComponent->SetRelativeScale3D(scale_val);

	TArray<FName> slot_list;
	_info.MaterialSlotOverrides.GetKeys(slot_list);

	for(FName n : slot_list)
	{
		int32 ind=MeshComponent->GetMaterialSlotNames().Find(n);
		if(ind>=0)
		{
			MeshComponent->SetMaterial(ind,_info.MaterialSlotOverrides[n]);
		}
	}
	
	Super::OnConstruction(Transform);
}
