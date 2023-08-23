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
}

void UHUDLayer::Local_BindGlobalEvent()
{
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UHUDLayer::OnGlobalEvent);
}
