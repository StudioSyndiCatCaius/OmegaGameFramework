// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UI_InputAction.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Functions/F_Platforms.h"
#include "Functions/F_Player.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Player.h"


void UOmegaUI_InputAction::L_Trigger()
{
	OnInputBegin.Broadcast(this);
}

void UOmegaUI_InputAction::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	UImage* _img_ico=nullptr;
	UTextBlock* _text_block=nullptr;
	UButton* _button=nullptr;
	GetWidget_Bindings(_img_ico,_text_block,_button);
	L_OnInputDeviceChange(bPreviewGamepad);
	if(_text_block)
	{
		if (bShow_Text)
		{
			_text_block->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			if (CustomName.IsEmpty())
			{
				_text_block->SetText(UOmegaPlayerFunctions::GetInputActionConfig(this,InputAction).DisplayName);	
			}
			else
			{
				_text_block->SetText(CustomName);
			}
			
		}
		else
		{
			_text_block->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
	if (_button)
	{
		_button->OnPressed.AddDynamic(this,&UOmegaUI_InputAction::L_Trigger);
	}
	
}

void UOmegaUI_InputAction::NativeConstruct()
{
	Super::NativeConstruct();
	if (UOmegaSubsystem_Player* ss=OGF_Subsystems::oPlayer(GetOwningPlayer()))
	{
		ss->OnInputDeviceChanged.AddDynamic(this,&UOmegaUI_InputAction::L_OnInputDeviceChange);
		L_OnInputDeviceChange(ss->IsUsingGamepad());
		UOmegaPlayerFunctions::SetInputActionTargetActive(GetOwningPlayer(),this,true);	
	}
	
}

void UOmegaUI_InputAction::L_OnInputDeviceChange(bool bIsUsingGamepad)
{
	UImage* _img_ico=nullptr;
	UTextBlock* _text_block=nullptr;
	UButton* _button=nullptr;
	GetWidget_Bindings(_img_ico,_text_block,_button);
	if (_img_ico)
	{
		if (bShow_Image)
		{
			_img_ico->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			FSlateBrush _brush=UOmegaPlatformFunctions::GetCurrentPlatformKeyIcon(this,
			UOmegaPlayerFunctions::GetFirstDeviceKeyFromInputAction(this,InputAction,bIsUsingGamepad),GetOwningPlayer());
			_img_ico->SetBrush(_brush);
			_img_ico->SetDesiredSizeOverride(IconSize);
		}
		else
		{
			_img_ico->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}

void UOmegaUI_InputAction::NativeDestruct()
{
	Super::NativeDestruct();
	if (UOmegaSubsystem_Player* ss=OGF_Subsystems::oPlayer(GetOwningPlayer()))
	{
		UOmegaPlayerFunctions::SetInputActionTargetActive(GetOwningPlayer(),this,true);
	}
}

bool UOmegaUI_InputAction::InputAction_Disabled_Implementation(APlayerController* Player, FGameplayTag Action)
{
	return !IsRendered();
}

void UOmegaUI_InputAction::OnInputAction_Begin_Implementation(APlayerController* Player, FGameplayTag Action,
	FVector axis)
{
	if (Action==InputAction && Player==GetOwningPlayer())
	{
		OnInputBegin.Broadcast(this);
	}
}

void UOmegaUI_InputAction::OnInputAction_End_Implementation(APlayerController* Player, FGameplayTag Action,
	FVector axis)
{
	if (Action==InputAction && Player==GetOwningPlayer())
	{
		OnInputEnd.Broadcast(this);
	}
}

