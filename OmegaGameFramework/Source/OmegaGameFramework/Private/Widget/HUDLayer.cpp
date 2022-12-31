// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/HUDLayer.h"
#include "OmegaGameManager.h"
//#include "Engine/Engine.h"

void UHUDLayer::NativeConstruct()
{
	Local_BindGlobalEvent();
	Super::NativeConstruct();
}

void UHUDLayer::Local_BindGlobalEvent()
{
	
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &UHUDLayer::OnGlobalEvent);
}
