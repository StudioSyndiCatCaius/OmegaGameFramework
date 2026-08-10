// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_UI.h"

#include "TimerManager.h"
#include "Engine/World.h"
#include "Functions/F_Player.h"

UFlowNode_Image_Set::UFlowNode_Image_Set()
{
	
}

void UFlowNode_Image_Set::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (GetWorld())
	{
		if (RemoveImage)
		{
			UOmegaPlayerFunctions::Image_Clear(this,ImageTag);
		}
		else
		{
			UOmegaPlayerFunctions::Image_Set(this,ImageTag,Image);
		}
	}
	if (Delay>0.0f)
	{
		FTimerHandle MyTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(
		MyTimerHandle,
		FTimerDelegate::CreateWeakLambda(this, [this]() {
			TriggerFirstOutput(true);
		}),
		Delay,
		false);
	}
	else
	{
		TriggerFirstOutput(true);
	}
}

#if WITH_EDITOR
FString UFlowNode_Image_Set::GetNodeDescription() const
{
	return Super::GetNodeDescription();
}
#endif
