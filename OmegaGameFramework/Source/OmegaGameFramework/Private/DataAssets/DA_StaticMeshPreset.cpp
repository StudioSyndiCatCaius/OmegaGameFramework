// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_StaticMeshPreset.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"

void UOmegaStaticMeshPreset::ActorPreset_GetConfig_Implementation(
	TSubclassOf<AActor>& ActorClass,
	bool& bPreviewActor,
	bool& bAllowWorldDrop,
	bool& bPreviewThumbnailFromActor)
{
	ActorClass                 = AStaticMeshActor::StaticClass();
	bPreviewActor              = true;
	bAllowWorldDrop            = true;
	bPreviewThumbnailFromActor = true;
}

bool UOmegaStaticMeshPreset::ActorPreset_PreviewConstruct_Implementation(AActor* Actor)
{
	if (!Actor) return false;

	AStaticMeshActor* MeshActor = Cast<AStaticMeshActor>(Actor);
	if (!MeshActor) return false;

	UStaticMeshComponent* MeshComp = MeshActor->GetStaticMeshComponent();
	if (!MeshComp) return false;

	MeshComp->SetStaticMesh(StaticMesh);
	MeshComp->SetRelativeScale3D(Scale);

	// Materials by index
	for (int32 i = 0; i < Materials_ByIndex.Num(); i++)
	{
		if (Materials_ByIndex[i])
		{
			MeshComp->SetMaterial(i, Materials_ByIndex[i]);
		}
	}

	// Materials by slot name
	for (const auto& Pair : Materials_BySlot)
	{
		const int32 SlotIndex = MeshComp->GetMaterialIndex(Pair.Key);
		if (SlotIndex != INDEX_NONE && Pair.Value)
		{
			MeshComp->SetMaterial(SlotIndex, Pair.Value);
		}
	}

	MeshComp->SetCollisionObjectType(CollisionChannel);
	MeshComp->SetHiddenInGame(bHiddenInGame);

	Actor->Tags.Append(ActorTags);

	return true;
}
