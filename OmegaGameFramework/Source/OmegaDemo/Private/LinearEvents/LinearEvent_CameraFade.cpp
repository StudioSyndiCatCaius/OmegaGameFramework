// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_CameraFade.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

void ULinearEvent_CameraFade::Native_Begin()
{
	UGameplayStatics::GetPlayerCameraManager(this, 0)->StartCameraFade(BeginAlpha, EndAlpha, Duration, Color, false, true);
	GetWorld()->GetTimerManager().SetTimer(Local_TimerHandle, this, &ULinearEvent_CameraFade::Local_TimerEnd, Duration, false);
	Super::Native_Begin();
}

void ULinearEvent_CameraFade::Local_TimerEnd()
{
	Finish("");
}

//####################################################
// FLOW NODE
//####################################################

UFlowNode_Camera_Fade::UFlowNode_Camera_Fade()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finish")));
	OutputPins.Add(FFlowPin(TEXT("Begin")));
#if WITH_EDITOR
	Category = TEXT("GameFlow");
#endif
}

void UFlowNode_Camera_Fade::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	//UOmegaLinearEventSubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>();
	
	ULinearEvent_CameraFade* LocalEvent = NewObject<ULinearEvent_CameraFade>(GetWorld()->GetGameInstance(), ULinearEvent_CameraFade::StaticClass());
	LocalEvent->EventEnded.AddDynamic(this, &UFlowNode_Camera_Fade::LocalFinish);
	LocalEvent->Color = Color;
	LocalEvent->Duration = Duration;
	LocalEvent->BeginAlpha = BeginAlpha;
	LocalEvent->EndAlpha = EndAlpha;
	
	LocalEvent->Native_Begin();
	TriggerOutput("Begin", true, false);
}


void UFlowNode_Camera_Fade::LocalFinish(const FString& Flag)
{
	TriggerOutput("Finish", true, false);
}
