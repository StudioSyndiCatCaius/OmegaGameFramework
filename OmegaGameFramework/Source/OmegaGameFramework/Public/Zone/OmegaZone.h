// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Gameplay/BGM/OmegaBGMSubsystem.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "WorldPartition/DataLayer/ActorDataLayer.h"

#include "OmegaZone.generated.h"

class AOmegaGameplaySystem;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelData : public UPrimaryDataAsset, public  IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Description")
	FText DisplayDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Icon")
	FSlateBrush DisplayIcon;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTagContainer GameplayTags;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
	
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
class OMEGAGAMEFRAMEWORK_API UOmegaZoneData : public UPrimaryDataAsset, public  IDataInterface_General, public IGameplayTagsInterface
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

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTag ZoneCategory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
	FGameplayTagContainer ZoneTags;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FName> StreamedLevels;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FActorDataLayer> DataLayers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	UOmegaBGM* ZoneBGM;

	//Gameplay Systems will be activated when this zone is loaded and shutdown when it is unloaded. The Zone will be sued as the context.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
    TArray<TSubclassOf<AOmegaGameplaySystem>> SystemsActivatedInZone;
};