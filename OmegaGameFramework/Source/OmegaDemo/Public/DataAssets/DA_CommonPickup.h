// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Pickup.h"
#include "Condition/Condition_Actor.h"
#include "Functions/F_Component.h"
#include "Functions/F_GlobalScripting.h"
#include "Interfaces/I_ActorPreset.h"
#include "Misc/GeneralDataObject.h"
#include "DA_CommonPickup.generated.h"

/**
 * 
 */
UCLASS(DisplayName="♎Demo - Pickup (Common)")
class OMEGADEMO_API UOAsset_Pickup_Common : public UOmegaDemoDataAsset, public IDataInterface_Pickup, public IDataInterface_ActorPreset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Pickup")
	FOmegaConditions_Actor PickupConditions;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Pickup")
	FActorModifiers PickupEffects;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Pickup")
	FOmegaGlobalScripts GlobalScriptsOnPickup;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Pickup", meta=(ShowOnlyInnerProperties))
	FOmegaPickupConfig Config;
	
	virtual bool CanPickup_Implementation(APawn* Pawn, APlayerController* Controller) override;
	virtual int32 OnPickup_Implementation(APawn* Pawn, APlayerController* Controller) override;
	virtual FOmegaPickupConfig GetPickupConfig_Implementation() override { return Config; };
};
