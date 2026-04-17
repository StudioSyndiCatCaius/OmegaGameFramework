// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDemo_HUDs.h"

#include "OmegaDemo_Const.h"
#include "Animation/WidgetAnimation.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"


void UHudBase_Dialogue::NativeConstruct()
{
	OnMessageStateBlendUpdate(0.0);
	if (AllowedMessageTypes.IsEmpty())
	{
		OGF_Log::Warning("UHudBase_Dialogue has not `Allowed Message Types` set. This means ANY messages sent will be dispalyed by it.");	
	}
	Super::NativeConstruct();
}

void UHudBase_Dialogue::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(f_MessageStateTarget!=f_MessageStateBlend)
	{
		f_MessageStateBlend=UKismetMathLibrary::FInterpTo_Constant(f_MessageStateBlend,f_MessageStateTarget,InDeltaTime,1/MessageState_BlendTime);
		OnMessageStateBlendUpdate(f_MessageStateBlend);
	}
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UHudBase_Dialogue::OnGameplayMessage_Implementation(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
                                                         FOmegaGameplayMessageMeta meta)
{
	if(Message)
	{
		if(AllowedMessageTypes.IsEmpty() || AllowedMessageTypes.HasTagExact(MessageCategory))
		{
			l_LastMessage=Message;
			if(UDataWidget* _dw = GetDataWidgetOnMessage(Message))
			{
				if(UWidgetSwitcher* _switch = GetWidgetSwitcher_MessageStyle())
				{
					_switch->SetActiveWidget(_dw);
					_dw->SetSourceAsset(Message);
				}
			}
		}
		if(Message==l_LastMessage)
		{
			f_MessageStateTarget=1.0;
			b_messageVisible=true;
		}
	}
	Super::OnGameplayMessage_Implementation(Message, MessageCategory, meta);
}

void UHudBase_Dialogue::OnGameplayMessageEnd_Implementation(UOmegaGameplayMessage* Message,
	FGameplayTag MessageCategory, FOmegaGameplayMessageMeta meta)
{
	Super::OnGameplayMessageEnd_Implementation(Message, MessageCategory, meta);
	if(Message==l_LastMessage)
	{
		b_messageVisible=false;
		GetWorld()->GetTimerManager().SetTimer(timer_waitNextmsg,this,&UHudBase_Dialogue::L_WaitNextMsg_Finish,MessageEnd_WaitForNext);
	}
}


void UHudBase_Dialogue::L_WaitNextMsg_Finish()
{
	if(!b_messageVisible)
	{
		f_MessageStateTarget=0.0;
	}
}
