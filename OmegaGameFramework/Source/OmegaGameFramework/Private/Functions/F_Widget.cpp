// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Widget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Player.h"

APlayerController* UOmegaWidgetFunctions::PlayerFromWorldContext(UObject* Context, APlayerController* Fallback)
{
	if (Fallback)
	{
		return Fallback;
	}
	if (Context)
	{
		if (UUserWidget* w=Cast<UUserWidget>( Context))
		{
			return w->GetOwningPlayer();
		}
		if (Context->GetWorld())
		{
			return Context->GetWorld()->GetFirstPlayerController();
		}
	}
	return nullptr;
}

void UOmegaWidgetFunctions::ControlWidget_Set(UObject* WorldContextObject, UUserWidget* Widget,
	APlayerController* Player)
{
	if (!Widget) { return; }
	if (APlayerController* p=PlayerFromWorldContext(WorldContextObject,Player))
	{
		UOmegaSubsystem_Player* SS_player=OGF_Subsystems::oPlayer(p);
		SS_player->SetControlWidget(Widget);
	}
}

UUserWidget* UOmegaWidgetFunctions::ControlWidget_Get(UObject* WorldContextObject, UUserWidget* Widget,
	APlayerController* Player)
{
	if (APlayerController* p=PlayerFromWorldContext(WorldContextObject,Player))
	{
		UOmegaSubsystem_Player* SS_player=OGF_Subsystems::oPlayer(p);
		return  SS_player->FocusMenu;
	}
	return nullptr;
}

void UOmegaWidgetFunctions::ControlWidget_Clear(UObject* WorldContextObject, APlayerController* Player)
{
	if (APlayerController* p=PlayerFromWorldContext(WorldContextObject,Player))
	{
		UOmegaSubsystem_Player* SS_player=OGF_Subsystems::oPlayer(p);
		return  SS_player->ClearControlWidget();
	}
}

void UOmegaWidgetFunctions::SetHUDLayerActive(UObject* WorldContextObject, TSubclassOf<UHUDLayer> HUD, bool bActive, UObject* Context, const FString& Flag,
                                              APlayerController* Player)
{
	APlayerController* ref_player=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if(Player)
	{
		ref_player=Player;
	}
	UOmegaSubsystem_Player* ref_subsystem = ref_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
	if(bActive)
	{
		ref_subsystem->AddHUDLayer(HUD,Context);
	}
	else
	{
		ref_subsystem->RemoveHUDLayer(HUD,Flag);
	}
}

void UOmegaWidgetFunctions::SetHUDLayersActive(UObject* WorldContextObject, TArray<TSubclassOf<UHUDLayer>> HUDs,
	bool bActive, UObject* Context, const FString& Flag, APlayerController* Player)
{
	for(TSubclassOf<UHUDLayer> temp_hud : HUDs)
	{
		SetHUDLayerActive(WorldContextObject,temp_hud,bActive,Context,Flag,Player);
	}
}

UHUDLayer* UOmegaWidgetFunctions::TryGetHudLayer(const UObject* WorldContextObject, TSubclassOf<UHUDLayer> Class,
	APlayerController* Player, bool& Outcome)
{
	APlayerController* in_player=WorldContextObject->GetWorld()->GetFirstPlayerController();
	if(Player) { in_player=Player;}
	if(UHUDLayer* output = in_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->GetHUDLayerByClass(Class))
	{
		Outcome=true;
		return output;
	}
	Outcome=false;
	return nullptr;
}

UDataWidget* UOmegaWidgetFunctions::TryGetDataWidget_FromSlot(const UObject* WorldContextObject, FGameplayTag SlotID,
	APlayerController* Player, bool& Outcome)
{
	APlayerController* in_player=WorldContextObject->GetWorld()->GetFirstPlayerController();
	if(Player) { in_player=Player;}
	if(UDataWidget* output = in_player->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->SlottedDataWidgets.FindOrAdd(SlotID))
	{
		Outcome=true;
		return output;
	}
	Outcome=false;
	return nullptr;
}

TArray<UObject*> UOmegaWidgetFunctions::GetSourceAssetsFromDataWidgets(TArray<UDataWidget*> Widgets, TSubclassOf<UObject> ObjectClass)
{
	TArray<UObject*> out;
	for (auto* temp_widget : Widgets)
	{
		if(temp_widget && (!ObjectClass || temp_widget->GetClass()->IsChildOf(ObjectClass))) { out.Add(temp_widget->ReferencedAsset);}
	}
	return out;
}

bool UOmegaWidgetFunctions::GetWidgetScreenPosition(const UWidget* Widget, FVector2D& OutPosition, bool bGetCenter)
{
	if (!Widget)
	{
		return false;
	}

	const FGeometry& CachedGeometry = Widget->GetCachedGeometry();
    
	// Verify the widget has valid geometry (has been laid out)
	if (CachedGeometry.GetLocalSize().IsNearlyZero())
	{
		return false;
	}

	if (bGetCenter)
	{
		const FVector2D LocalCenter = CachedGeometry.GetLocalSize() * 0.5f;
		OutPosition = CachedGeometry.LocalToAbsolute(LocalCenter);
	}
	else
	{
		OutPosition = CachedGeometry.GetAbsolutePosition();
	}

	return true;
}

bool UOmegaWidgetFunctions::GetWidgetViewportPosition(const UWidget* Widget, FVector2D& OutViewportPosition,
	bool bGetCenter)
{
	if (!Widget)
	{
		return false;
	}

	FVector2D AbsolutePosition;
	if (!GetWidgetScreenPosition(Widget, AbsolutePosition, bGetCenter))
	{
		return false;
	}

	// Get viewport scale to convert from absolute to viewport space
	const UWorld* World = Widget->GetWorld();
	if (!World)
	{
		return false;
	}

	const float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(World);
	if (FMath::IsNearlyZero(ViewportScale))
	{
		return false;
	}

	OutViewportPosition = AbsolutePosition / ViewportScale;
	return true;
}
