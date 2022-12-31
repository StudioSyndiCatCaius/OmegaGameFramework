// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_Delay.h"

void ULinearEvent_Delay::Native_Begin()
{
	GetWorld()->GetTimerManager().SetTimer(Local_TimerHandle, this, &ULinearEvent_Delay::Local_TimerEnd, Duration, false);
	Super::Native_Begin();
}

void ULinearEvent_Delay::Local_TimerEnd()
{
	Finish("");
}
