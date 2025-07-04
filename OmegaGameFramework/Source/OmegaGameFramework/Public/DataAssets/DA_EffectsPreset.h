// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_TurnBasedManager.h"

#include "Functions/OmegaFunctions_ScriptedEffects.h"
#include "Misc/GeneralDataObject.h"
#include "DA_EffectsPreset.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_EffectsPreset : public UOmegaDataAsset, public IOmegaScriptedEffectsInterface, public IDataInterface_TurnTrackerSource
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
	FOmegaCustomScriptedEffects DefaultEffects;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
	TMap<FGameplayTag,FOmegaCustomScriptedEffects> TaggedEffects;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="TurnBased")
	int32 Turns_Initial;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="TurnBased")
	int32 Turns_Max;

	virtual int32 GetTurns_Init_Implementation() override { return Turns_Initial; }
	virtual int32 GetTurns_Max_Implementation() override {return Turns_Max;}
};
