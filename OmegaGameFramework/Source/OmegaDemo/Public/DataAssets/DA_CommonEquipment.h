// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_CommonItem.h"

#include "Misc/GeneralDataObject.h"
#include "DA_CommonEquipment.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonEquipment : public UOAsset_CommonItem, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Item")
	TArray<FOmegaAttributeModifier> AttributeMods;
	
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override { return AttributeMods;};
};
