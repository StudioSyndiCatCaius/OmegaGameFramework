// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Camera.h"

#include "Misc/OmegaUtils_Actor.h"


UFlowNode_Camera_Fade::UFlowNode_Camera_Fade()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finish")));
	OutputPins.Add(FFlowPin(TEXT("Begin")));
}

void UFlowNode_Camera_Fade::L_Finished()
{
	TriggerOutput(TEXT("Finish"), true);
}

void UFlowNode_Camera_Fade::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	if(APlayerController* pc=GetWorld()->GetFirstPlayerController())
	{
		pc->PlayerCameraManager->StartCameraFade(BeginAlpha,EndAlpha,Duration,Color,bFadeAudio,bHoldOnEnd);
		if(Duration>0.0)
		{
			GetWorld()->GetTimerManager().SetTimer(timer_handle,this,&UFlowNode_Camera_Fade::L_Finished,Duration,false);
		}
		else
		{
			L_Finished();
		}
	}
	TriggerOutput(TEXT("Begin"), false);
}


UFlowNode_Camera_Blend::UFlowNode_Camera_Blend()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finish")));
	OutputPins.Add(FFlowPin(TEXT("Begin")));
}

void UFlowNode_Camera_Blend::L_Finished()
{
	TriggerOutput(TEXT("Finish"), true);
}


void UFlowNode_Camera_Blend::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	TriggerOutput(TEXT("Begin"), false);
	if(APlayerController* pc=GetWorld()->GetFirstPlayerController())
	{
		if(BlendTarget)
		{
			if(BlendTarget->GetActors(GetWorld()).IsValidIndex(0))
			{
				if(AActor* ac=BlendTarget->GetActors(GetWorld())[0])
				{
					pc->SetViewTargetWithBlend(ac,Duration,BlendType,BlendExponent);
					if(Duration>0.0)
					{
						GetWorld()->GetTimerManager().SetTimer(timer_handle,this,&UFlowNode_Camera_Blend::L_Finished,Duration,false);
					}
					else
					{
						L_Finished();
					}
					return;
				}
			}
		}
	}
	TriggerOutput(TEXT("Finish"), true);
}


