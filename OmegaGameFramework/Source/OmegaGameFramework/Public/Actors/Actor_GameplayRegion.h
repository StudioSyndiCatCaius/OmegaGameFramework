// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_GameplayRegion.generated.h"

class UActorIdentityComponent;
class UZoneEntityComponent;
class UBoxComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UGameplay_RegionAsset : public UOmegaDataAsset
{
	GENERATED_BODY()

public:
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AGameplay_Region : public AActor, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	AGameplay_Region();
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Component") UBoxComponent* Range;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Component") UActorIdentityComponent* ID;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Region")
	UGameplay_RegionAsset* RegionID;
};
