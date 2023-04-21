// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_SimpleMessage.h"
#include "Message/OmegaMessageSubsystem.h"
#include "OmegaDataItem.h"
#include "OmegaGameManager.h"
#include "OmegaLinearEventSubsystem.h"

FString ULinearEvent_SimpleMessage::GetLogString_Implementation() const
{
	FText SpeakerString;
	if(Instigator)
	{
		SpeakerString = Instigator->DisplayName;
	}

	const FText OutText = FText::Format(FText::FromString("{0}: {1}"), SpeakerString, Message);

	return OutText.ToString();
}

void ULinearEvent_SimpleMessage::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context,
                                                                   FText& Name, FText& Description)
{
	Description = Message;
}


void ULinearEvent_SimpleMessage::Native_Begin()
{
	Super::Native_Begin();

	UOmegaGameplayMessage* NewMessage = NewObject<UOmegaGameplayMessage>(GetWorld()->GetGameInstance(), UOmegaGameplayMessage::StaticClass());
	NewMessage->Temp_Text = Message;
	NewMessage->Temp_Instigator = Instigator;
	NewMessage->Temp_Tags = Tags;
	
	FOmegaGameplayMessageData LocalMessageData;
	LocalMessageData.Message = NewMessage;
	
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->FireGameplayMessage(LocalMessageData);
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &ULinearEvent_SimpleMessage::LocalGEvent);
	
}

void ULinearEvent_SimpleMessage::LocalGEvent(FName Event, UObject* Context)
{
	if(Event==FName("EndMessage"))
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.RemoveDynamic(this, &ULinearEvent_SimpleMessage::LocalGEvent);
		Finish("");
	}
	
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
}

void UFlowNode_SimpleMessage::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	UOmegaLinearEventSubsystem* SystemRef = GetWorld()->GetSubsystem<UOmegaLinearEventSubsystem>();
	
	ULinearEvent_SimpleMessage* LocalMessage = NewObject<ULinearEvent_SimpleMessage>(GetWorld()->GetGameInstance(), ULinearEvent_SimpleMessage::StaticClass());
	LocalMessage->EventEnded.AddDynamic(this, &UFlowNode_SimpleMessage::LocalFinish);
	LocalMessage->Instigator = Instigator;
	LocalMessage->Message = Message;
	LocalMessage->Tags = Tags;
	
	LocalMessage->Native_Begin();
	TriggerOutput("Begin", true, false);
}

#if WITH_EDITOR
FString UFlowNode_SimpleMessage::GetNodeDescription() const
{
	FText SpeakerString;
	if(Instigator)
	{
		SpeakerString = Instigator->DisplayName;
	}

	const FText OutText = FText::Format(FText::FromString("{0}: {1}"), SpeakerString, Message);

	return OutText.ToString();
}
#endif

void UFlowNode_SimpleMessage::LocalFinish(const FString& Flag)
{
	TriggerOutput("Finish", true, false);
}
