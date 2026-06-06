
// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Combatant.h"
#include "Misc/GeneralDataObject.h"
#include "DA_EquipSlot.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UEquipmentSlot : public UOmegaDataAsset, public IDataInterface_Combatant
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Equipment Slot",meta=(DeprecatedProperty))
	FGameplayTagContainer AcceptedCategories;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Equipment Slot",meta=(DeprecatedProperty))
	FGameplayTagQuery TagsQuery;
	
	UFUNCTION(BlueprintCallable, Category="Equipment Slot")
	bool CanSlotEquipItem(UPrimaryDataAsset* Item);
	
	UFUNCTION(BlueprintCallable, Category="Equipment Slot")
	bool CanSlotEquipItemOnCombatant(UCombatantComponent* Combatant, UPrimaryDataAsset* Item);

};
