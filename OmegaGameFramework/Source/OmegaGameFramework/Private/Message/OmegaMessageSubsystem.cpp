// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Message/OmegaMessageSubsystem.h"

void UOmegaMessageSubsystem::FireGameplayMessage(FOmegaGameplayMessageData Message)
{
	//Make and log message
	FOmegaGameplayMessageData LoggedMessage = Message;
	LoggedMessage.MessageLog_Text = Message.Message->GetMessageText();
	MessageLog.Add(LoggedMessage);
	
	//Fire message delegate
	OnGameplayMessage.Broadcast(Message.Message);
	
}

void UOmegaMessageSubsystem::FireCustomGameplayMessage(FText Text, FGameplayTag MessageCategory)
{
	FOmegaGameplayMessageData LocalMessageData;
	LocalMessageData.Message = NewObject<UOmegaGameplayMessage>(UOmegaGameplayMessage::StaticClass());
	LocalMessageData.Message->Temp_Text = Text;
	LocalMessageData.Message->Temp_Tag = MessageCategory;

	FireGameplayMessage(LocalMessageData);
}


//##################################################################################
/// Gameplay Message Object
//##################################################################################

UObject* UOmegaGameplayMessage::GetMessageInstigator_Implementation()
{
	return nullptr;
}

FText UOmegaGameplayMessage::GetMessageText_Implementation()
{
	return Temp_Text;
}

FGameplayTag UOmegaGameplayMessage::GetMessageCategory_Implementation()
{
	return Temp_Tag;
}