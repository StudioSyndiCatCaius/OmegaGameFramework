// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "AsyncAction_PlayGameplayMessage.h"

#include "Functions/F_Message.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"

void UAsyncAction_PlayGameplayMessage::Native_OnMessageEnd(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory, FOmegaGameplayMessageMeta Meta)
{
	if (Message == ActiveMessage)
	{
		OGF_Subsystems::oWorld(LocalWorldContext)->OnGameplayMessage_End.RemoveDynamic(this, &UAsyncAction_PlayGameplayMessage::Native_OnMessageEnd);
		Finished.Broadcast(Message);
		SetReadyToDestroy();
	}
}

void UAsyncAction_PlayGameplayMessage::Activate()
{
	Super::Activate();

	if (!LocalWorldContext)
	{
		SetReadyToDestroy();
		return;
	}

	ActiveMessage = UOmegaFunctions_Message::Send(
		const_cast<UObject*>(LocalWorldContext),
		Param_Instigator,
		Param_Text,
		Param_CategoryTag,
		Param_Meta
	);

	if (!ActiveMessage)
	{
		SetReadyToDestroy();
		return;
	}

	Sent.Broadcast(ActiveMessage);
	OGF_Subsystems::oWorld(LocalWorldContext)->OnGameplayMessage_End.AddDynamic(this, &UAsyncAction_PlayGameplayMessage::Native_OnMessageEnd);
}

UAsyncAction_PlayGameplayMessage* UAsyncAction_PlayGameplayMessage::PlayGameplayMessage(
	const UObject* WorldContextObject,
	UObject* Instigator,
	FText Text,
	FGameplayTag CategoryTag,
	FOmegaGameplayMessageMeta meta)
{
	UAsyncAction_PlayGameplayMessage* NewNode = NewObject<UAsyncAction_PlayGameplayMessage>();
	NewNode->LocalWorldContext = WorldContextObject;
	NewNode->Param_Instigator = Instigator;
	NewNode->Param_Text = Text;
	NewNode->Param_CategoryTag = CategoryTag;
	NewNode->Param_Meta = meta;
	return NewNode;
}
