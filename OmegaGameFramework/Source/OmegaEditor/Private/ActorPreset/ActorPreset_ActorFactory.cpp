// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "ActorPreset/ActorPreset_ActorFactory.h"
#include "Interfaces/I_ActorPreset.h"
#include "Misc/GeneralDataObject.h"   // UOmegaMinimalDataAsset
#include "Engine/DataAsset.h"
#include "Engine/Level.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

#define LOCTEXT_NAMESPACE "ActorFactory_ActorPreset"

UActorFactory_ActorPreset::UActorFactory_ActorPreset(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName            = LOCTEXT("DisplayName", "Actor Preset");
	NewActorClass          = AActor::StaticClass();
	bUseSurfaceOrientation = false;
	bShowInEditorQuickMenu = false;
}

bool UActorFactory_ActorPreset::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	if (!AssetData.IsValid() || !AssetData.IsInstanceOf(UOmegaMinimalDataAsset::StaticClass()))
	{
		return false;
	}

	UPrimaryDataAsset* Asset = Cast<UPrimaryDataAsset>(AssetData.GetAsset());
	if (!Asset || !Asset->Implements<UDataInterface_ActorPreset>())
	{
		return false;
	}

	TSubclassOf<AActor> ActorClass;
	bool bPreviewActor = false, bAllowWorldDrop = false, bPreviewThumbnail = false;
	IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(Asset, ActorClass, bPreviewActor, bAllowWorldDrop, bPreviewThumbnail);

	if (!bAllowWorldDrop)
	{
		OutErrorMsg = LOCTEXT("NoDrop", "This Asset Preset does not allow world placement.");
		return false;
	}

	return true;
}

AActor* UActorFactory_ActorPreset::SpawnActor(UObject* InAsset, ULevel* InLevel,
	const FTransform& InTransform, const FActorSpawnParameters& InSpawnParams)
{
	UPrimaryDataAsset* Preset = Cast<UPrimaryDataAsset>(InAsset);
	if (Preset && Preset->Implements<UDataInterface_ActorPreset>())
	{
		TSubclassOf<AActor> ActorClass;
		bool bPreviewActor = false, bAllowWorldDrop = false, bPreviewThumbnail = false;
		IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(Preset, ActorClass, bPreviewActor, bAllowWorldDrop, bPreviewThumbnail);

		if (ActorClass)
		{
			return InLevel->GetWorld()->SpawnActor<AActor>(ActorClass, InTransform.GetLocation(), InTransform.Rotator(), InSpawnParams);
		}
	}
	return Super::SpawnActor(InAsset, InLevel, InTransform, InSpawnParams);
}

void UActorFactory_ActorPreset::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);

	if (!NewActor) return;

	UPrimaryDataAsset* Preset = Cast<UPrimaryDataAsset>(Asset);
	if (Preset && Preset->Implements<UDataInterface_ActorPreset>())
	{
		IDataInterface_ActorPreset::Execute_ActorPreset_PreviewConstruct(Preset, NewActor);
	}
}

#undef LOCTEXT_NAMESPACE
