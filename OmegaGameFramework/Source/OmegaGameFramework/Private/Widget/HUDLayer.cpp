// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/HUDLayer.h"
#include "Engine/GameInstance.h"
#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Subsystems/OmegaSubsystem_Message.h"
#include "Subsystems/OmegaSubsystem_Player.h"

//#include "Engine/Engine.h"

void UHUDLayer::NativeConstruct()
{
	Local_BindGlobalEvent();
	GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->OnGameplayMessage.AddDynamic(this, &UHUDLayer::OnGameplayMessage);
	GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->OnInputDeviceChanged.AddDynamic(this, &UHUDLayer::OnInputMethodChanged);
	PlayAnimationForward(GetAppearAnimation());
	Super::NativeConstruct();
}

void UHUDLayer::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if(Animation==GetAppearAnimation() && !bRemoving)
	{
		
	}
	else if (Animation==GetRemovedAnimation() && bRemoving)
	{
		Local_RemoveAnimFinished();
	}
	Super::OnAnimationFinished_Implementation(Animation);
}

void UHUDLayer::RemoveHUDLayer()
{
	if(this != nullptr && IsVisible() && GetRemovedAnimation() && !bRemoving)
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


void UHUDLayer::OnGlobalEvent_Implementation(FName Event, UObject* Context)
{
}

void UHUDLayer::OnTaggedGlobalEvent_Implementation(FGameplayTag Event, UObject* Context)
{
}

void UHUDLayer::Local_BindGlobalEvent()
{
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UHUDLayer::OnGlobalEvent);
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnTaggedGlobalEvent.AddDynamic(this, &UHUDLayer::OnTaggedGlobalEvent);
}

void UHUDLayer::OnGameplayMessage_Implementation(UOmegaGameplayMessage* Message, FGameplayTag MessageCategory,
	FOmegaGameplayMessageMeta meta)
{
}

void UHUDLayer::Local_RemoveAnimFinished()
{
	bRemoving=false;
	SetVisibility(ESlateVisibility::Collapsed);
	RemoveFromParent();
}
