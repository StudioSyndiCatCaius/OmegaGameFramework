// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/HUDLayer.h"
#include "OmegaGameManager.h"
#include "Message/OmegaMessageSubsystem.h"
#include "Player/OmegaPlayerSubsystem.h"

//#include "Engine/Engine.h"

void UHUDLayer::NativeConstruct()
{
	Local_BindGlobalEvent();
	Super::NativeConstruct();
	GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->OnGameplayMessage.AddDynamic(this, &UHUDLayer::OnGameplayMessage);
	GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->OnInputDeviceChanged.AddDynamic(this, &UHUDLayer::OnInputMethodChanged);
	PlayAnimationForward(GetAppearAnimation());
}

void UHUDLayer::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if(Animation==GetAppearAnimation() && !bRemoving)
	{
		
	}
	else if (Animation==GetAppearAnimation() && bRemoving)
	{
		Local_RemoveAnimFinished();
	}
	Super::OnAnimationFinished_Implementation(Animation);
}

void UHUDLayer::RemoveHUDLayer()
{
	if(this && IsVisible() && GetRemovedAnimation() && !bRemoving)
	{
		bRemoving=true;
		if(bReverseCloseAnim)
		{
			PlayAnimationReverse(GetRemovedAnimation());
		}
		else
		{
			PlayAnimationForward(GetRemovedAnimation());
		}
	}
	else
	{
		Local_RemoveAnimFinished();
	}
}


void UHUDLayer::Local_BindGlobalEvent()
{
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UHUDLayer::OnGlobalEvent);
}

void UHUDLayer::Local_RemoveAnimFinished()
{
	bRemoving=false;
	SetVisibility(ESlateVisibility::Collapsed);
	RemoveFromParent();
}
