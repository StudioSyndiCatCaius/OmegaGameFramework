// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Misc/GeneralDataObject.h"
#include "Kismet/KismetMathLibrary.h"
#include "DA_Calendar.generated.h"


class UOAsset_DayPeriod;
class UOAsset_Month;
class UOAsset_Weekday;

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_Calendar : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar")
	TArray<UOAsset_DayPeriod*> DayPeriods;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar")
	TArray<UOAsset_Weekday*> Weekdays;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar")
	TArray<UOAsset_Month*> Months;

	UFUNCTION(BlueprintPure,Category="Calendar")
	UOAsset_Month* GetMonth_FromIndex(int32 index) const
	{
		if(Months.IsValidIndex(index))
		{
			return Months[index];
		}
		return nullptr;
	}
	
	UFUNCTION(BlueprintPure,Category="Calendar")
	UOAsset_Weekday* GetWeekday_FromDayIndex(int32 day, int32 offset) const
	{
		int32 _in=UKismetMathLibrary::Wrap(day+offset,0,Weekdays.Num()-1);
		if(Weekdays.IsValidIndex(_in)) { return Weekdays[_in];}
		return nullptr;
	}
};
