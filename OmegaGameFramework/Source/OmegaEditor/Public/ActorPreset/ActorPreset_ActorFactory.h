// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "ActorPreset_ActorFactory.generated.h"

UCLASS()
class UActorFactory_ActorPreset : public UActorFactory
{
	GENERATED_UCLASS_BODY()

	virtual bool  CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override;
	virtual AActor* SpawnActor(UObject* InAsset, ULevel* InLevel, const FTransform& InTransform, const FActorSpawnParameters& InSpawnParams) override;
	virtual void  PostSpawnActor(UObject* Asset, AActor* NewActor) override;
};
