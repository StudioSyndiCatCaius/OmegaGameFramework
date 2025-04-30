// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_Day.h"

#include "Misc/GeneralDataObject.h"
#include "DA_Month.generated.h"

class UOAsset_Day;

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_Month : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Month")
	int32 NumberOfDays;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Month")
	TMap<int32,UOAsset_Day*> CustomDays;

	UFUNCTION(BlueprintPure,Category="Month")
	UOAsset_Day* GetDay(int32 day)
	{
		if(CustomDays.Contains(day)) { return CustomDays.FindOrAdd(day); }
		return GetMutableDefault<UOAsset_Day>();
	}
};
