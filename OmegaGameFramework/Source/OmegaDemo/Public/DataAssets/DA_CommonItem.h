// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Functions/OmegaFunctions_ScriptedEffects.h"

#include "Misc/GeneralDataObject.h"
#include "DA_CommonItem.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonItem : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	int32 Rank;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	TMap<UPrimaryDataAsset*, int32> TradeCosts;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	int32 CollectionMax=99;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	FComponentMod_StaticMesh StaticMesh;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	TSoftClassPtr<AActor> ActorSkin;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
	FOmegaCustomScriptedEffects Effects_Target;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
	FOmegaCustomScriptedEffects Effects_Instigator;
};
