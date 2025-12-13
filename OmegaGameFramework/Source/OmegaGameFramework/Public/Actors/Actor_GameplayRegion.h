// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_AdvancedVolume.h"
#include "Components/Component_ActorIdentity.h"
#include "DataAssets/DA_ActorIdentity.h"
#include "GameFramework/Actor.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_Material.h"
#include "Actor_GameplayRegion.generated.h"

class UActorModifierScript;
class UActorIdentityComponent;
class UZoneEntityComponent;
class UBoxComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UGameplay_RegionAsset : public UOAsset_ActorIdentity
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Region")
	UMaterialInterface* DebugMaterial; 
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AGameplay_Region : public AAdvancedVolume, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	AGameplay_Region();
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Component") UActorIdentityComponent* ID;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Region")
	UGameplay_RegionAsset* RegionIdentity=nullptr;
};
