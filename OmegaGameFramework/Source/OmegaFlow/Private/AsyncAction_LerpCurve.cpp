// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_LerpCurve.h"
#include "Engine/World.h"


void UAsyncAction_LerpCurve::Tick(float DeltaTime)
{
	if (local_playing)
	{
		local_reversed ? elapsed_time -= DeltaTime * local_PlayRate : elapsed_time += DeltaTime * local_PlayRate;
        
		if (local_curve)
		{
			new_value = local_curve->GetFloatValue(elapsed_time);
		}
        
		bool should_end = local_reversed ? (elapsed_time <= 0) : (elapsed_time >= time_max); // Assuming BlendDuration is the end time

		if (should_end)
		{
			local_playing = false;
			Finished.Broadcast(); // Make sure delegate is valid
			SetReadyToDestroy();
		}
		else
		{
			Updated.Broadcast(new_value); // Make sure delegate is valid
		}
	}
}


void UAsyncAction_LerpCurve::Activate()
{
	if(local_curve && local_PlayRate>0.0f)
	{
		local_curve->GetTimeRange(time_min,time_max);
		
		elapsed_time=0.0;
		if(local_reversed)
		{
			elapsed_time=time_max;
		}
		
		local_playing=true;
	}
	else
	{
		SetReadyToDestroy();
	}
}

UAsyncAction_LerpCurve* UAsyncAction_LerpCurve::LerpAlongCurve(UObject* WorldContextObject, UCurveFloat* Curve,
	float PlayRate, bool bReverse)
{
	UAsyncAction_LerpCurve* NewNode = NewObject<UAsyncAction_LerpCurve>();
	NewNode->local_curve=Curve;
	NewNode->local_PlayRate=PlayRate;
	NewNode->local_reversed = bReverse;
	return NewNode;
}


