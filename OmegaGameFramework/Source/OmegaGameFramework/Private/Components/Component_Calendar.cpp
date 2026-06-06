// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Calendar.h"

#include "DataAssets/DA_Calendar.h"
#include "DataAssets/DA_Month.h"
#include "DataAssets/DA_Day.h"
#include "DataAssets/DA_DayPeriod.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Save.h"


FOmegaCalendarData* UOmegaCalendarComponent::GetCalendarData()
{
	if (bBindToSave)
	{
		if (UOmegaSaveSubsystem* ss= OGF_Subsystems::oSave(this))
		{
			if (UOmegaSaveBase* sav=ss->GetSaveObject(false))
			{
				return &sav->CalendarData.FindOrAdd(SaveBinding);
			}
		}
	}
	return &CalendarData;
}

FOmegaCalendarData UOmegaCalendarComponent::GetCurrentTime(int32 offset)
{
	FOmegaCalendarData out=*GetCalendarData();
	out.Period+=offset;
	out.Day+=offset;
	out.Month+=offset;
	out.Year+=offset;
	return out;
}

FRandomStream UOmegaCalendarComponent::GetCurrentTimeSeed(int32 offset)
{
	FOmegaCalendarData time=GetCurrentTime(offset);
	int32 seed=time.Period+(time.Day*100)+(time.Month*10000)+(time.Year*1000000);
	return FRandomStream(seed); 
}

void UOmegaCalendarComponent::AdvanceTime()
{
	if(CalendarAsset)
	{
		GetCalendarData()->Period+=1;
		if(CalendarAsset->DayPeriods.Num()<=GetCalendarData()->Period)
		{
			GetCalendarData()->Period=0;
			GetCalendarData()->Day+=1;
			//Wrap Month
			if(GetMonth_Asset() && GetMonth_Asset()->NumberOfDays<GetDay_Number())
			{
				GetCalendarData()->Day=0;
				GetCalendarData()->Month+=1;
				//Wrap Year
				if(CalendarAsset->Months.Num()<=GetCalendarData()->Month)
				{
					GetCalendarData()->Month=0;
					SetYear(GetCalendarData()->Year+1);
				}
				SetMonth(GetCalendarData()->Month+1);
			}
			SetDay(GetCalendarData()->Day);
		}
		SetPeriod(GetCalendarData()->Period);
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
	GetCalendarData()->Period=index;
	OnPeriodChanged.Broadcast(this,GetCalendarData()->Period);
}

int32 UOmegaCalendarComponent::GetPeriod_Number()
{
	return GetCalendarData()->Period;
}

UOAsset_DayPeriod* UOmegaCalendarComponent::GetPeriod_Asset()
{
	if(CalendarAsset)
	{
		if(CalendarAsset->DayPeriods.IsValidIndex(GetCalendarData()->Period))
		{
			return CalendarAsset->DayPeriods[GetCalendarData()->Period];
		}
	}
	return nullptr;
}

// =====================================================================================================================
// DAY
// =====================================================================================================================

void UOmegaCalendarComponent::SetDay(int32 index)
{
	GetCalendarData()->Day=index;
	OnDayChanged.Broadcast(this,GetCalendarData()->Day);
}

int32 UOmegaCalendarComponent::GetDay_Number()
{
	return GetCalendarData()->Day;
}

UOAsset_Day* UOmegaCalendarComponent::GetDay_Asset()
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
	GetCalendarData()->Month=index;
	OnMonthChanged.Broadcast(this,GetCalendarData()->Month);
}

int32 UOmegaCalendarComponent::GetMonth_Number()
{
	return GetCalendarData()->Month;
}

UOAsset_Month* UOmegaCalendarComponent::GetMonth_Asset()
{
	if(CalendarAsset)
	{
		return CalendarAsset->GetMonth_FromIndex(GetCalendarData()->Month);
	}
	return nullptr;
}


// =====================================================================================================================
// YEAR
// =====================================================================================================================
void UOmegaCalendarComponent::SetYear(int32 index)
{
	GetCalendarData()->Year=index;
	OnYearChanged.Broadcast(this,GetCalendarData()->Year);
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