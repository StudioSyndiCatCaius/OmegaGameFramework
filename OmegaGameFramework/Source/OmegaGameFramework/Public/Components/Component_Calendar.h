// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_Calendar.generated.h"

class UOAsset_DayPeriod;
class UOAsset_Day;
class UOAsset_Month;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPeriodChanged, UOmegaCalendarComponent*, Component, int32, period);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDayChanged, UOmegaCalendarComponent*, Component, int32, day);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMonthChanged, UOmegaCalendarComponent*, Component, int32, month);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnYearChanged, UOmegaCalendarComponent*, Component, int32, year);

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaCalendarData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Period=-1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Day=-1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Month=-1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Year=-1;
};

class UOAsset_Calendar;

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCalendarComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable) FOnPeriodChanged OnPeriodChanged;
	UPROPERTY(BlueprintAssignable) FOnDayChanged OnDayChanged;
	UPROPERTY(BlueprintAssignable) FOnMonthChanged OnMonthChanged;
	UPROPERTY(BlueprintAssignable) FOnYearChanged OnYearChanged;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Calendar") FOmegaCalendarData CalendarData;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar")
	UOAsset_Calendar* CalendarAsset;

	UFUNCTION(BlueprintPure,Category="Calendar")
	FOmegaCalendarData GetCurrentTime(int32 offset) const;
	
	UFUNCTION(BlueprintCallable,Category="Calendar")
	void AdvanceTime();

	UFUNCTION(BlueprintCallable,Category="Calendar")
	void SetPeriod(int32 index);
	UFUNCTION(BlueprintPure,Category="Calendar")
	int32 GetPeriod_Number() const;
	UFUNCTION(BlueprintPure,Category="Calendar")
	UOAsset_DayPeriod* GetPeriod_Asset() const;
	
	UFUNCTION(BlueprintCallable,Category="Calendar")
	void SetDay(int32 index);
	UFUNCTION(BlueprintPure,Category="Calendar")
	int32 GetDay_Number() const;
	UFUNCTION(BlueprintPure,Category="Calendar")
	UOAsset_Day* GetDay_Asset() const;
	
	UFUNCTION(BlueprintCallable,Category="Calendar")
	void SetMonth(int32 index);
	UFUNCTION(BlueprintPure,Category="Calendar")
	int32 GetMonth_Number() const;
	UFUNCTION(BlueprintPure,Category="Calendar")
	UOAsset_Month* GetMonth_Asset() const;

	UFUNCTION(BlueprintCallable,Category="Calendar")
	void SetYear(int32 index);
	
	UFUNCTION(BlueprintCallable,Category="Calendar")
	void SetTime(int32 period=-1, int32 day=-1, int32 month=-1, int32 year=-1);

	UFUNCTION(BlueprintCallable,Category="Calendar")
	bool IsCurrentTime_InBetween(FOmegaCalendarData A, FOmegaCalendarData B);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCalendar_Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,Category="Omega|Calendar")
	static bool IsCalendarDate_InBetweenTime(FOmegaCalendarData Date, FOmegaCalendarData A, FOmegaCalendarData B);
};
