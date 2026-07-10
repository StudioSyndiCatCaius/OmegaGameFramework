// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaComponent.h"
#include "Components/ActorComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Component_Calendar.generated.h"

class UOAsset_DayPeriod;
class UOAsset_Day;
class UOAsset_Month;
class UOAsset_Weekday;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPeriodChanged, UOmegaCalendarComponent*, Component, int32, period);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDayChanged, UOmegaCalendarComponent*, Component, int32, day);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeekChanged, UOmegaCalendarComponent*, Component, int32, week);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMonthChanged, UOmegaCalendarComponent*, Component, int32, month);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnYearChanged, UOmegaCalendarComponent*, Component, int32, year);

// Represents a point in time within the game's calendar system (period, day, month, year).
USTRUCT(Blueprintable,BlueprintType)
struct FOmegaCalendarData
{
	GENERATED_BODY()
public:
	// Index of the current time-of-day period (e.g. 0 = morning, 1 = afternoon).
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Period=-1;
	// Index of the current day within the month.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Day=-1;
	// Index of the current month within the year.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Month=-1;
	// The current year number.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") int32 Year=-1;
};

class UOAsset_Calendar;

// Tracks and advances in-game calendar time (period, day, month, year). Supports save binding and broadcasts events on each unit change.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCalendarComponent : public UOmegaComponent
{
	GENERATED_BODY()

public:
	// Fires when the time period (e.g. morning/night) changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnPeriodChanged OnPeriodChanged;
	// Fires when the calendar day advances.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnDayChanged OnDayChanged;
	// Fires when the week changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnWeekChanged OnWeekChanged;
	// Fires when the month changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnMonthChanged OnMonthChanged;
	// Fires when the year changes.
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnYearChanged OnYearChanged;

	// When true, calendar state is loaded from and saved to the save system using SaveBinding as the key.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Calendar") bool bBindToSave;
	// The save key used to persist calendar data when bBindToSave is true.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Calendar") FName SaveBinding;
	// The in-memory calendar state used when not bound to a save slot.
	UPROPERTY(EditAnywhere,Category="Calendar",meta=(EditCondition="!bBindToSave")) FOmegaCalendarData CalendarData;

	FOmegaCalendarData* GetCalendarData();

	// The calendar asset that defines the period, day, and month definitions for this calendar.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Calendar") UOAsset_Calendar* CalendarAsset;

	// Returns the current calendar date with an optional numeric offset applied (e.g. to peek ahead).
	UFUNCTION(BlueprintPure,Category="Calendar") FOmegaCalendarData GetCurrentTime(int32 offset);
	// Returns a deterministic random stream seeded by the current calendar date plus an optional offset.
	UFUNCTION(BlueprintPure,Category="Calendar") FRandomStream GetCurrentTimeSeed(int32 offset);

	// Advances calendar time by one period; wraps day, month, and year as needed and fires change delegates.
	UFUNCTION(BlueprintCallable,Category="Calendar") void AdvanceTime();

	// Sets the current time period by index.
	UFUNCTION(BlueprintCallable,Category="Calendar") void SetPeriod(int32 index);
	// Returns the current time period as a numeric index.
	UFUNCTION(BlueprintPure,Category="Calendar") int32 GetPeriod_Number();
	// Returns the data asset that describes the current time period.
	UFUNCTION(BlueprintPure,Category="Calendar") UOAsset_DayPeriod* GetPeriod_Asset();
	
	// Returns the current weekday index derived from the current day, wrapping over the calendar's weekday list.
	UFUNCTION(BlueprintPure,Category="Calendar") int32 GetWeekday_Number();
	// Returns the data asset that describes the current weekday.
	UFUNCTION(BlueprintPure,Category="Calendar") UOAsset_Weekday* GetWeekday_Asset();

	// Sets the current day by index.
	UFUNCTION(BlueprintCallable,Category="Calendar") void SetDay(int32 index);
	// Returns the current day as a numeric index.
	UFUNCTION(BlueprintPure,Category="Calendar") int32 GetDay_Number();
	// Returns the data asset that describes the current day.
	UFUNCTION(BlueprintPure,Category="Calendar") UOAsset_Day* GetDay_Asset();

	// Sets the current month by index.
	UFUNCTION(BlueprintCallable,Category="Calendar") void SetMonth(int32 index);
	// Returns the current month as a numeric index.
	UFUNCTION(BlueprintPure,Category="Calendar") int32 GetMonth_Number();
	// Returns the data asset that describes the current month.
	UFUNCTION(BlueprintPure,Category="Calendar") UOAsset_Month* GetMonth_Asset();

	// Sets the current year directly.
	UFUNCTION(BlueprintCallable,Category="Calendar") void SetYear(int32 index);

	// Sets multiple calendar units at once; pass -1 to leave a unit unchanged.
	UFUNCTION(BlueprintCallable,Category="Calendar") void SetTime(int32 period=-1, int32 day=-1, int32 month=-1, int32 year=-1);

	// Returns true if the current calendar date falls between dates A and B (inclusive).
	UFUNCTION(BlueprintCallable,Category="Calendar") bool IsCurrentTime_InBetween(FOmegaCalendarData A, FOmegaCalendarData B);
};


// Blueprint function library for calendar date comparisons.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCalendar_Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Returns true if Date falls between calendar dates A and B (inclusive).
	UFUNCTION(BlueprintPure,Category="Omega|Calendar")
	static bool IsCalendarDate_InBetweenTime(FOmegaCalendarData Date, FOmegaCalendarData A, FOmegaCalendarData B);
};
