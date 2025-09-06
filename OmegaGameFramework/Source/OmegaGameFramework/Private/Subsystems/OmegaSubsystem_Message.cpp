// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_Message.h"

void UOmegaMessageSubsystem::FireGameplayMessage(FOmegaGameplayMessageData Message)
{
	//Make and log message
	FOmegaGameplayMessageData LoggedMessage = Message;
	LoggedMessage.MessageLog_Text = Message.Message->GetMessageText();
	MessageLog.Add(LoggedMessage);
	
	//Fire message delegate
	OnGameplayMessage.Broadcast(Message.Message, Message.Message->GetMessageCategory(),Message.Message->meta);
	
}

FOmegaGameplayMessageData UOmegaMessageSubsystem::FireCustomGameplayMessage(UObject* Instigator, FText Text, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta meta)
{
	FOmegaGameplayMessageData LocalMessageData;
	LocalMessageData.Message = NewObject<UOmegaGameplayMessage>(UOmegaGameplayMessage::StaticClass());
	if(Instigator)
	{
		LocalMessageData.Message->Temp_Instigator = Instigator;
	}
	LocalMessageData.Message->Temp_Text = Text;
	LocalMessageData.Message->Temp_Tag = MessageCategory;
	LocalMessageData.Message->meta=meta;
	
	FireGameplayMessage(LocalMessageData);
	return LocalMessageData;
}

bool UOmegaMessageTrait::OnMessageFired_Implementation(UOmegaMessageSubsystem* subsystem,
	UOmegaGameplayMessage* message) const
{
	return false;
}

UObject* UOmegaGameplayMessage::TryGetMessageInstigator(TSubclassOf<UObject> Class, bool& result)
{
	if(UObject* _temp=GetMessageInstigator())
	{
		if(!Class || _temp->GetClass()->IsChildOf(Class))
		{
			result=true;
			return _temp;
		}
	}
	result=false;
	return nullptr;
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
	return meta.Tags;	
}
