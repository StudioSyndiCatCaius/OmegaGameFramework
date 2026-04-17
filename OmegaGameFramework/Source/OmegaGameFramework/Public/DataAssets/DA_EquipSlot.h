
// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Combatant.h"
#include "Misc/GeneralDataObject.h"
#include "DA_EquipSlot.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UEquipmentSlot : public UOmegaDataAsset, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()
public:
	//UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category="General")
	//TArray<UOmegaCondition_DataAsset*> EquipConditions;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Equipment")
	//TArray<UEquipmentSlotScript*> SlotScripts;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Equipment Slot",meta=(DeprecatedProperty),AdvancedDisplay)
	FGameplayTagContainer AcceptedCategories;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Equipment Slot",meta=(DeprecatedProperty),AdvancedDisplay)
	FGameplayTagContainer RequiredTags;
	
	UFUNCTION(BlueprintCallable, Category="Equipment Slot")
	bool CanSlotEquipItem(UPrimaryDataAsset* Item)
	{
		if(Item)
		{
			return true;
		}
		return false;
	}

};
