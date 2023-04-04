// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Gameplay/BGM/OmegaBGMSubsystem.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "WorldPartition/DataLayer/ActorDataLayer.h"

#include "OmegaZone.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaZoneData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText ZoneName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Description")
	FText ZoneDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Icon")
	FSlateBrush ZoneIcon;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag ZoneCategory;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTagContainer ZoneTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FName> StreamedLevels;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FActorDataLayer> DataLayers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	UOmegaBGM* ZoneBGM;
};