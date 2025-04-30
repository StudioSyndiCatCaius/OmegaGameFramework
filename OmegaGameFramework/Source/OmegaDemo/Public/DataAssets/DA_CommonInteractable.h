// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"

#include "Misc/GeneralDataObject.h"
#include "DA_CommonInteractable.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonInteractable : public UOmegaDataAsset, public IDataInterface_FlowAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	UFlowAsset* FlowAsset;

	//Flow Asset
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override {return FlowAsset;};

};
