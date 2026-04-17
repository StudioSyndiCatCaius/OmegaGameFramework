// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Zone.generated.h"

class AOmegaGameplaySystem;
class UOmegaEncounter_Asset;
class UOmegaBGM;
class AZoneEntityDisplayActor;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelData : public UOmegaDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Level")
	UOmegaZoneData* DefaultZone;

	//If Default zone is empty, this custom zone data will be defaulted to.
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category="Level")
	UOmegaZoneData* OverrideZoneData;

	UOmegaZoneData* GetDefaultZoneData() const
	{
		if(DefaultZone) {return DefaultZone;}
		if(OverrideZoneData) {return  OverrideZoneData;}
		return nullptr;
	}
	
};

UCLASS(EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaZoneData : public UOmegaDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FName> StreamedLevels;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FActorDataLayer> DataLayers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	UOmegaBGM* ZoneBGM;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	UOmegaEncounter_Asset* Default_Encounter;
	//Gameplay Systems will be activated when this zone is loaded and shutdown when it is unloaded. The Zone will be sued as the context.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<TSubclassOf<AOmegaGameplaySystem>> SystemsActivatedInZone;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UZoneLegendAsset : public UOmegaDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly,Category="Legend")
	TSubclassOf<AZoneEntityDisplayActor> DefaultDisplayActor;
};