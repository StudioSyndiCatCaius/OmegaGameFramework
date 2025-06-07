// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Interpolator.h"

#include "Kismet/KismetMathLibrary.h"

UInterpolatorComponent::UInterpolatorComponent()
{
	PrimaryComponentTick.bCanEverTick=true;
	PrimaryComponentTick.bStartWithTickEnabled=true;
}

void UInterpolatorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	if(!UKismetMathLibrary::InRange_FloatFloat(f_valCurrent,MinValue,MaxValue))
	{
		f_valCurrent=UKismetMathLibrary::FInterpTo(f_valCurrent,f_valTarget,DeltaTime,InterpSpeed);
		OnInterpolatorUpdate.Broadcast(this,f_valCurrent);
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInterpolatorComponent::AddValue(float amount)
{
	SetValue(f_valTarget+amount);
}

void UInterpolatorComponent::SetValue(float amount)
{
	f_valTarget=amount;
}
