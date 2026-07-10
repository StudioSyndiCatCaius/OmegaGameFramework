// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_AdvancedVolume.h"
#include "Components/Component_GameplayActor.h"
#include "DataAssets/DA_ActorIdentity.h"
#include "GameFramework/Actor.h"
#include "Interfaces/I_Common.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_Material.h"
#include "Actor_GameplayRegion.generated.h"

class UActorModifierScript;
class UGameplayActorComponent;
class UZoneEntityComponent;
class UBoxComponent;

// An actor identity asset that also carries a debug material for visualizing the region in the editor.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UGameplay_RegionAsset : public UOAsset_ActorIdentity
{
	GENERATED_BODY()

public:

	// Material applied to the region's debug volume mesh in the editor for visual identification.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Region")
	UMaterialInterface* DebugMaterial;

};

// An advanced volume actor with a UGameplayActorComponent, giving it a named identity, tags, and subscript support.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AGameplay_Region : public AAdvancedVolume, public IDataInterface_General
{
	GENERATED_BODY()

public:
	AGameplay_Region();
	virtual void OnConstruction(const FTransform& Transform) override;

	// The identity component that provides this region's name, tags, and subscript behavior.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Component") UGameplayActorComponent* ID;

	// The identity asset that defines this region's display name, tags, and debug material.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Region")
	UGameplay_RegionAsset* RegionIdentity=nullptr;
};
