// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaActorPresetAsset.h"
#include "GameFramework/Actor.h"

void UOmegaActorPresetAsset::ActorPreset_GetConfig_Implementation(
	TSubclassOf<AActor>& ActorClass,
	bool& bPreviewActor,
	bool& bAllowWorldDrop,
	bool& bPreviewThumbnailFromActor)
{
	ActorClass                = AActor::StaticClass();
	bPreviewActor             = true;
	bAllowWorldDrop           = true;
	bPreviewThumbnailFromActor = false;
}

bool UOmegaActorPresetAsset::ActorPreset_PreviewConstruct_Implementation(AActor* Actor)
{
	return true;
}
