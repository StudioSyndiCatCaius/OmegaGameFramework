// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Openable.h"
#include "Components/Component_ActorState.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/OmegaSubsystem_Save.h"

AOmegaOpenableActor::AOmegaOpenableActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Openable");
	
	RootPoint=CreateOptionalDefaultSubobject<UArrowComponent>("Point - Root");
	RootPoint->SetupAttachment(RootComponent);
	RootPoint->SetArrowColor(FColor::Blue);
	
	OpenPoint=CreateOptionalDefaultSubobject<UArrowComponent>("Point - Opened");
	OpenPoint->SetupAttachment(RootComponent);
	OpenPoint->SetArrowColor(FColor::Green);
	
	ClosedPoint=CreateOptionalDefaultSubobject<UArrowComponent>("Point - Closed");
	ClosedPoint->SetupAttachment(RootComponent);
	ClosedPoint->SetArrowColor(FColor::Red);
}

void AOmegaOpenableActor::Tick(float DeltaSeconds)
{
	if(OpenAnimationCurve && bIsOpening)
	{
		float temp_blend;
		if(bIsOpening_Forward)
		{
			temp_blend=Position+DeltaSeconds;
		}
		else
		{
			temp_blend=Position-DeltaSeconds;
		}
		float time_min;
		float time_max;
		OpenAnimationCurve->GetTimeRange(time_min,time_max);
		SetOpen_Blend(UKismetMathLibrary::FClamp(time_min,time_max,temp_blend));
		if(!bIsOpening_Forward && Position<=time_min)
		{
			//bIsOpening=false;
		}
		if(bIsOpening_Forward && Position>=time_max)
		{
			//bIsOpening=false;
		}
	}
	Super::Tick(DeltaSeconds);
}

void AOmegaOpenableActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetOpen_Blend(Position);
}

void AOmegaOpenableActor::SetOpen_Blend(float Value)
{
	if(RootPoint && OpenPoint && ClosedPoint)
	{
		Position=Value;
		RootPoint->SetRelativeTransform(UKismetMathLibrary::TLerp(
			ClosedPoint->GetRelativeTransform(),
			OpenPoint->GetRelativeTransform(),
			Value, ELerpInterpolationMode::EulerInterp));
	}
}

void AOmegaOpenableActor::SetOpen_State(bool bState, bool bSnap)
{
	bIsOpening_Forward=bState;
	if(bSnap)
	{
		float time_min;
		float time_max;
		OpenAnimationCurve->GetTimeRange(time_min,time_max);
		if(!bState) { SetOpen_Blend(time_min);}
		if(bState) { SetOpen_Blend(time_max);}
	}
	else
	{
		bIsOpening=true;
	}
}

