// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_SimpleMessage.h"

#include "OmegaDataItem.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "OmegaLinearEventSubsystem.h"
#include "Subsystems/OmegaSubsystem_Message.h"

UObject* ULinearEvent_SimpleMessage::local_GetInstigator() const
{
	if(UObject* out = Instigator_Actor->Private_GetActor(GetWorld()))
	{
		return out;
	}
	if(Instigator_Asset)
	{
		return Instigator_Asset;
	}
	return nullptr;
}

FString ULinearEvent_SimpleMessage::GetLogString_Implementation() const
{
	FString SpeakerString;
	if(local_GetInstigator())
	{
		SpeakerString = local_GetInstigator()->GetName();
	}

	const FText OutText = FText::Format(FText::FromString("{0}: {1}"), FText::FromString(SpeakerString), Message);

	return OutText.ToString();
}

void ULinearEvent_SimpleMessage::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context,
                                                                   FText& Name, FText& Description)
{
	Description = Message;
}


void ULinearEvent_SimpleMessage::Native_Begin(const FString& Flag)
{
	Super::Native_Begin();
	
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireGlobalEvent(FName("SimpleMessage"), this);
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &ULinearEvent_SimpleMessage::LocalGEvent);
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->FireCustomGameplayMessage(local_GetInstigator(),Message,MessageCategory,Tags,Brush,FLuaValue());
}

void ULinearEvent_SimpleMessage::LocalGEvent(FName Event, UObject* Context)
{
	if(Event==FName("EndMessage"))
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.RemoveDynamic(this, &ULinearEvent_SimpleMessage::LocalGEvent);
		Finish("");
	}
	
}

UObject* UFlowNode_SimpleMessage::local_GetInstigator() const
{
	if(UObject* out = Instigator_Actor->Private_GetActor(GetWorld()))
	{
		return out;
	}
	if(Instigator_Asset)
	{
		return Instigator_Asset;
	}
	return nullptr;
}

//####################################################
// FLOW NODE
//####################################################

UFlowNode_SimpleMessage::UFlowNode_SimpleMessage()
{
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finish")));
	OutputPins.Add(FFlowPin(TEXT("Begin")));
#if WITH_EDITOR
	Category = TEXT("GameFlow");
#endif
	MessageLabel=GetName();
}

void UFlowNode_SimpleMessage::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	UOmegaLinearEventSubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>();
	
	ULinearEvent_SimpleMessage* LocalMessage = NewObject<ULinearEvent_SimpleMessage>(GetWorld()->GetGameInstance(), ULinearEvent_SimpleMessage::StaticClass());
	LocalMessage->EventEnded.AddDynamic(this, &UFlowNode_SimpleMessage::LocalFinish);
	if(Instigator_Actor) { LocalMessage->Instigator_Actor= Instigator_Actor; }
	if(Instigator_Asset) { LocalMessage->Instigator_Asset= Instigator_Asset; }
	LocalMessage->Message = Message;
	LocalMessage->Tags=Tags;
	LocalMessage->Brush = Brush;
	LocalMessage->Native_Begin("");
	TriggerOutput("Begin", true,  EFlowPinActivationType::Default);
}

#if WITH_EDITOR
FString UFlowNode_SimpleMessage::GetNodeDescription() const
{
	FString SpeakerString;
	if(local_GetInstigator())
	{
		SpeakerString = local_GetInstigator()->GetName();
	}

	const FText OutText = FText::Format(FText::FromString("{0}: {1}"), FText::FromString(SpeakerString), Message);

	return OutText.ToString();
}
#endif

void UFlowNode_SimpleMessage::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label=MessageLabel;
}

void UFlowNode_SimpleMessage::LocalFinish(UOmegaLinearEvent* Event, const FString& Flag)
{
	TriggerOutput("Finish", true, EFlowPinActivationType::Default);
}
