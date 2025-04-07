// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDemo_HUDs.h"

void UHUD_Dialogue::OnGameplayMessage_Implementation(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FLuaValue meta)
{
	if(AllowedMessageTypes.IsEmpty() || AllowedMessageTypes.HasTagExact(MessageCategory))
	{
		if(UDataWidget* _dw = GetDataWidgetOnMessage(Message))
		{
			if(UWidgetSwitcher* _switch = GetWidgetSwitcher_MessageStyle())
			{
				_switch->SetActiveWidget(_dw);
				_dw->SetSourceAsset(Message);
			}
		}
	}
	Super::OnGameplayMessage_Implementation(Message, MessageCategory, meta);
}
