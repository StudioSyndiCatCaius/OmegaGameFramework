// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/Widget_DynamicMeter.h"
#include "Kismet/KismetMathLibrary.h"


void UDynamicProgressMeter::Tick(float DeltaTime)
{
	if(bInterpGhostToPercent)
	{
		if(Percent_Progress!=Percent_Ghost)
		{
			float new_val=UKismetMathLibrary::FInterpTo_Constant(Percent_Ghost,Percent_Progress,DeltaTime,1/GhostInterpTime);
			SetPercent_Ghost(new_val);
		}
	}
}

void UDynamicProgressMeter::OnWidgetRebuilt()
{
	SetBrushFromMaterial(MeterMaterial);
    	if(GetDynamicMaterial())
    	{
    		SetProgress_Color(Progress_Color);
    		SetGhost_Color(Ghost_Color);
    		SetPercent_Progress(Percent_Progress);
    		SetPercent_Ghost(Percent_Ghost);
    	}
	Super::OnWidgetRebuilt();
}

void UDynamicProgressMeter::SetPercent_Progress(const float& value)
{
	if(GetDynamicMaterial())
	{
		Percent_Progress=value;
		GetDynamicMaterial()->SetScalarParameterValue(MaterialParam_Progress,value);
		if(bClampGhostToProgress)
		{
			SetPercent_Ghost(UKismetMathLibrary::FClamp(Percent_Ghost,Percent_Progress,1.0));
		}
	}
}

void UDynamicProgressMeter::SetPercent_Ghost(const float& value)
{
	if(GetDynamicMaterial())
	{
		Percent_Ghost=value;
		GetDynamicMaterial()->SetScalarParameterValue(MaterialParam_Ghost,Percent_Ghost);
	}
}

void UDynamicProgressMeter::SetProgress_Color(const FLinearColor& value)
{
	if(GetDynamicMaterial())
	{
		GetDynamicMaterial()->SetVectorParameterValue(MaterialParam_ProgressColor,value);
	}
}

void UDynamicProgressMeter::SetGhost_Color(const FLinearColor& value)
{
	if(GetDynamicMaterial())
	{
		GetDynamicMaterial()->SetVectorParameterValue(MaterialParam_GhostColor,value);
	}
}

