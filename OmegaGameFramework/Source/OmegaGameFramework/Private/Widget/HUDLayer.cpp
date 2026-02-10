// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/HUDLayer.h"
#include "Engine/GameInstance.h"
#include "Subsystems/Subsystem_Actors.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Message.h"
#include "Subsystems/Subsystem_Player.h"

//#include "Engine/Engine.h"

void UHUDLayer::NativeConstruct()
{
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

void UHUDLayer::Local_RemoveAnimFinished()
{
	bRemoving=false;
	SetVisibility(ESlateVisibility::Collapsed);
	RemoveFromParent();
}
