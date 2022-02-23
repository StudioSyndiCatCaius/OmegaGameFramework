// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "GameplayTagContainer.h"
#include "OmegaWorldSettings.generated.h"

/**
 * 
 */
USTRUCT()
struct FOmegaZoneData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Ω|World")
	TArray<FName> StreamLevels;
};

UCLASS()
class OMEGAWORLD_API AOmegaWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditInstanceOnly, Category ="Zones")
	TMap<FGameplayTag, FOmegaZoneData> Zones;
	
};
