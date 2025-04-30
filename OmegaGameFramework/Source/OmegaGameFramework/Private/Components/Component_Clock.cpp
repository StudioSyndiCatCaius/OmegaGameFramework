// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Clock.h"


void UOmegaClockComponent::BeginPlay()
{
	if(bAutostart)
	{
		SetClockPlaying(true);
	}
	Super::BeginPlay();
}

void UOmegaClockComponent::SetClockPlaying(bool bPlaying)
{
	if(bPlaying !=IsClockPlaying())
	{
		if(bPlaying)
		{
			L_InitClock();
			GetWorld()->GetTimerManager().UnPauseTimer(l_timeHandle);
			OnClockStateChange.Broadcast(this,true);
		}
		else
		{
			GetWorld()->GetTimerManager().PauseTimer(l_timeHandle);
			OnClockStateChange.Broadcast(this,false);
		}
	}
}

bool UOmegaClockComponent::IsClockPlaying() const
{
	return GetWorld()->GetTimerManager().IsTimerActive(l_timeHandle);
}

void UOmegaClockComponent::local_UpdateTime()
{
	Time += FTimespan::FromSeconds(UpdateRate);
	OnClockUpdate.Broadcast(this,Time);
}

void UOmegaClockComponent::L_InitClock()
{
	if(!l_IsInit)
	{
		l_IsInit=true;
		GetWorld()->GetTimerManager().SetTimer(l_timeHandle,this,&UOmegaClockComponent::local_UpdateTime,UpdateRate,true);
	}
}
