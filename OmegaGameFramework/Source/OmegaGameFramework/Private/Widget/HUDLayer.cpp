// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/HUDLayer.h"
#include "Engine/GameInstance.h"
#include "TimerManager.h"
#include "Subsystems/Subsystem_World.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Player.h"

//#include "Engine/Engine.h"

void UHUDLayer::NativeConstruct()
{
	if(GetAppearAnimation())
	{
		PlayAnimationForward(GetAppearAnimation());
	}
	else if(AddRemove_OpacityFade)
	{
		// No appear animation: fade opacity in instead.
		StartOpacityFade(false);
	}
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
	else if(this != nullptr && IsVisible() && !GetRemovedAnimation() && AddRemove_OpacityFade && !bRemoving)
	{
		// No removed animation: fade opacity out, then clear the layer.
		bRemoving=true;
		StartOpacityFade(true);
	}
	else
	{
		Local_RemoveAnimFinished();
	}
}

void UHUDLayer::StartOpacityFade(bool bFadeOut)
{
	UWorld* World = GetWorld();
	if(!World)
	{
		// Can't drive a timed fade without a world; resolve immediately.
		if(bFadeOut) { Local_RemoveAnimFinished(); }
		else { SetRenderOpacity(1.f); }
		return;
	}

	bFadeOutDirection = bFadeOut;
	FadeStartTime = World->GetTimeSeconds();
	SetRenderOpacity(bFadeOut ? 1.f : 0.f);
	World->GetTimerManager().SetTimer(FadeTimerHandle, this, &UHUDLayer::Local_TickOpacityFade, 1.f/60.f, true);
}

void UHUDLayer::Local_TickOpacityFade()
{
	UWorld* World = GetWorld();
	if(!World)
	{
		if(bFadeOutDirection) { Local_RemoveAnimFinished(); }
		return;
	}

	const float Duration = FMath::Max(AddRemove_OpacityFadeTime, KINDA_SMALL_NUMBER);
	const float Alpha = FMath::Clamp((World->GetTimeSeconds() - FadeStartTime) / Duration, 0.f, 1.f);
	SetRenderOpacity(bFadeOutDirection ? (1.f - Alpha) : Alpha);

	if(Alpha >= 1.f)
	{
		World->GetTimerManager().ClearTimer(FadeTimerHandle);
		if(bFadeOutDirection)
		{
			Local_RemoveAnimFinished();
		}
	}
}

void UHUDLayer::Local_RemoveAnimFinished()
{
	bRemoving=false;
	if(UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(FadeTimerHandle);
	}
	SetRenderOpacity(1.f);
	SetVisibility(ESlateVisibility::Collapsed);
	RemoveFromParent();
}
