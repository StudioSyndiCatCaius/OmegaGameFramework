// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_Message.h"

void UOmegaMessageSubsystem::FireGameplayMessage(FOmegaGameplayMessageData Message)
{
	//Make and log message
	FOmegaGameplayMessageData LoggedMessage = Message;
	LoggedMessage.MessageLog_Text = Message.Message->GetMessageText();
	MessageLog.Add(LoggedMessage);
	
	//Fire message delegate
	OnGameplayMessage.Broadcast(Message.Message, Message.Message->GetMessageCategory(),Message.Message->GetValue_Implementation(""));
	
}

void UOmegaMessageSubsystem::FireCustomGameplayMessage(UObject* Instigator, FText Text, FGameplayTag MessageCategory,FGameplayTagContainer Tags, FSlateBrush Brush, FLuaValue meta,UObject* Context)
{
	FOmegaGameplayMessageData LocalMessageData;
	LocalMessageData.Message = NewObject<UOmegaGameplayMessage>(UOmegaGameplayMessage::StaticClass());
	if(Instigator)
	{
		LocalMessageData.Message->Temp_Instigator = Instigator;
	}
	LocalMessageData.Message->Temp_Tags=Tags;
	LocalMessageData.Message->Temp_Brush=Brush;
	LocalMessageData.Message->Temp_Text = Text;
	LocalMessageData.Message->Temp_Tag = MessageCategory;
	LocalMessageData.Message->lua_val=meta;
	LocalMessageData.Message->Context=Context;
	
	FireGameplayMessage(LocalMessageData);
}

FSlateBrush UOmegaGameplayMessage::GetMessageBrush_Implementation()
{
	return  Temp_Brush;
}

FLuaValue UOmegaGameplayMessage::GetValue_Implementation(const FString& Field) { return lua_val; }
FLuaValue UOmegaGameplayMessage::GetKey_Implementation() { return lua_key; }
void UOmegaGameplayMessage::SetKey_Implementation(FLuaValue Key) { lua_key=Key; }
void UOmegaGameplayMessage::SetValue_Implementation(FLuaValue Value, const FString& Field) { lua_val=Value; }


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
