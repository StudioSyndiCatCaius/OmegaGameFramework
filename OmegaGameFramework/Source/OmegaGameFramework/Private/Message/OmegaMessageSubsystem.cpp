// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Message/OmegaMessageSubsystem.h"

void UOmegaMessageSubsystem::FireGameplayMessage(FOmegaGameplayMessageData Message)
{
	//Make and log message
	FOmegaGameplayMessageData LoggedMessage = Message;
	LoggedMessage.MessageLog_Text = Message.Message->GetMessageText();
	MessageLog.Add(LoggedMessage);
	
	//Fire message delegate
	OnGameplayMessage.Broadcast(Message.Message, Message.Message->GetMessageCategory());
	
}

void UOmegaMessageSubsystem::FireCustomGameplayMessage(UObject* Instigator, FText Text, FGameplayTag MessageCategory)
{
	FOmegaGameplayMessageData LocalMessageData;
	LocalMessageData.Message = NewObject<UOmegaGameplayMessage>(UOmegaGameplayMessage::StaticClass());
	if(Instigator)
	{
		LocalMessageData.Message->Temp_Instigator = Instigator;
	}
	LocalMessageData.Message->Temp_Text = Text;
	LocalMessageData.Message->Temp_Tag = MessageCategory;

	FireGameplayMessage(LocalMessageData);
}



//##################################################################################
/// Gameplay Message Object
//##################################################################################

UObject* UOmegaGameplayMessage::GetMessageInstigator_Implementation()
{
	return Temp_Instigator;
}

FText UOmegaGameplayMessage::GetMessageText_Implementation()
{
	return Temp_Text;
}

FGameplayTag UOmegaGameplayMessage::GetMessageCategory_Implementation()
{
	return Temp_Tag;
}

FGameplayTagContainer UOmegaGameplayMessage::GetMessageTags_Implementation()
{
	return Temp_Tags;	
}
