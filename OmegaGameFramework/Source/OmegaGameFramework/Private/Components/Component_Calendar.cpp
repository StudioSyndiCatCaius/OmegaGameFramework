// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Calendar.h"

#include "DataAssets/DA_Calendar.h"
#include "DataAssets/DA_Month.h"
#include "DataAssets/DA_Day.h"
#include "DataAssets/DA_DayPeriod.h"


FOmegaCalendarData UOmegaCalendarComponent::GetCurrentTime(int32 offset) const
{
	FOmegaCalendarData out=CalendarData;
	out.Period+=offset;
	out.Day+=offset;
	out.Month+=offset;
	out.Year+=offset;
	return out;
}

void UOmegaCalendarComponent::AdvanceTime()
{
	if(CalendarAsset)
	{
		CalendarData.Period+=1;
		if(CalendarAsset->DayPeriods.Num()<=CalendarData.Period)
		{
			CalendarData.Period=0;
			CalendarData.Day+=1;
			//Wrap Month
			if(GetMonth_Asset() && GetMonth_Asset()->NumberOfDays<GetDay_Number())
			{
				CalendarData.Day=0;
				CalendarData.Month+=1;
				//Wrap Year
				if(CalendarAsset->Months.Num()<=CalendarData.Month)
				{
					CalendarData.Month=0;
					SetYear(CalendarData.Year+1);
				}
				SetMonth(CalendarData.Month+1);
			}
			SetDay(CalendarData.Day);
		}
		SetPeriod(CalendarData.Period);
	}
}


void UOmegaCalendarComponent::SetTime(int32 period, int32 day, int32 month, int32 year)
{
	if(period>=0) { SetPeriod(period);}
	if(day>=0) { SetDay(day);}
	if(month>=0) { SetMonth(month);}
	if(year>=0) { SetYear(year);}
}


bool UOmegaCalendarComponent::IsCurrentTime_InBetween(FOmegaCalendarData A, FOmegaCalendarData B)
{
	return UOmegaCalendar_Functions::IsCalendarDate_InBetweenTime(CalendarData,A,B);
}

// =====================================================================================================================
// PERIOD
// =====================================================================================================================

void UOmegaCalendarComponent::SetPeriod(int32 index)
{
	CalendarData.Period=index;
	OnPeriodChanged.Broadcast(this,CalendarData.Period);
}

int32 UOmegaCalendarComponent::GetPeriod_Number() const
{
	return CalendarData.Period;
}

UOAsset_DayPeriod* UOmegaCalendarComponent::GetPeriod_Asset() const
{
	if(CalendarAsset)
	{
		if(CalendarAsset->DayPeriods.IsValidIndex(CalendarData.Period))
		{
			return CalendarAsset->DayPeriods[CalendarData.Period];
		}
	}
	return nullptr;
}

// =====================================================================================================================
// DAY
// =====================================================================================================================

void UOmegaCalendarComponent::SetDay(int32 index)
{
	CalendarData.Day=index;
	OnDayChanged.Broadcast(this,CalendarData.Day);
}

int32 UOmegaCalendarComponent::GetDay_Number() const
{
	return CalendarData.Day;
}

UOAsset_Day* UOmegaCalendarComponent::GetDay_Asset() const
{
	if(CalendarAsset)
	{
		GetMonth_Asset()->GetDay(GetDay_Number());
	}
	return nullptr;
}

// =====================================================================================================================
// MONTH
// =====================================================================================================================

void UOmegaCalendarComponent::SetMonth(int32 index)
{
	CalendarData.Month=index;
	OnMonthChanged.Broadcast(this,CalendarData.Month);
}

int32 UOmegaCalendarComponent::GetMonth_Number() const
{
	return CalendarData.Month;
}

UOAsset_Month* UOmegaCalendarComponent::GetMonth_Asset() const
{
	if(CalendarAsset)
	{
		return CalendarAsset->GetMonth_FromIndex(CalendarData.Month);
	}
	return nullptr;
}


// =====================================================================================================================
// YEAR
// =====================================================================================================================
void UOmegaCalendarComponent::SetYear(int32 index)
{
	CalendarData.Year=index;
	OnYearChanged.Broadcast(this,CalendarData.Year);
}

// =====================================================================================================================
// =====================================================================================================================
// FUNCTIONS
// =====================================================================================================================
// =====================================================================================================================

bool UOmegaCalendar_Functions::IsCalendarDate_InBetweenTime(FOmegaCalendarData Date, FOmegaCalendarData A,
	FOmegaCalendarData B)
{
	if((A.Period>=0 && B.Period>=0) && !UKismetMathLibrary::InRange_IntInt(Date.Period,A.Period,B.Period)) { return false;}
	if((A.Day>=0 && B.Day>=0) && !UKismetMathLibrary::InRange_IntInt(Date.Day,A.Day,B.Day)) { return false;}
	if((A.Month>=0 && B.Month>=0) && !UKismetMathLibrary::InRange_IntInt(Date.Month,A.Month,B.Month)) { return false;}
	if((A.Year>=0 && B.Year>=0) && !UKismetMathLibrary::InRange_IntInt(Date.Year,A.Year,B.Year)) { return false;}
	return true;
}