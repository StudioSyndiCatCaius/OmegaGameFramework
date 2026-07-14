// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Widget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Player.h"
#include "Widget/DataWidget.h"
#include "Widget/UI_Widgets.h"

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

TArray<UWidget*> UOmegaWidgetFunctions::GetChildrenWidgets(UWidget* Parent, TSubclassOf<UWidget> FilterClass,
	bool bRecursive)
{
	TArray<UWidget*> Result;
	if (!Parent) return Result;

	UPanelWidget* Panel = Cast<UPanelWidget>(Parent);
	if (!Panel) return Result;

	for (int32 i = 0; i < Panel->GetChildrenCount(); i++)
	{
		UWidget* Child = Panel->GetChildAt(i);
		if (!Child) continue;

		if (!FilterClass || Child->IsA(FilterClass))
		{
			Result.Add(Child);
		}

		if (bRecursive)
		{
			Result.Append(GetChildrenWidgets(Child, FilterClass, true));
		}
	}

	return Result;
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

UDataWidget* UOmegaWidgetFunctions::DataWidgets_GetFirstFromSource(const UObject* WorldContextObject,
	APlayerController* Player, UObject* Source, TSubclassOf<UDataWidget> Class)
{
	TArray<UDataWidget*> temp=DataWidgets_GetFromSources(WorldContextObject,Player,{Source},Class);
	if(temp.Num()>0) { return temp[0];}
	return nullptr;
}

TArray<UDataWidget*> UOmegaWidgetFunctions::DataWidgets_GetFromSources(const UObject* WorldContextObject,
                                                                       APlayerController* Player, TArray<UObject*> Sources, TSubclassOf<UDataWidget> Class)
{
	APlayerController* in_player=WorldContextObject->GetWorld()->GetFirstPlayerController();
	if(Player) { in_player=Player;}
	
	TArray<UUserWidget*> temp;
	TSubclassOf<UUserWidget> temp_class=UUserWidget::StaticClass();
	if (Class) { temp_class=Class;}
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(in_player,temp,temp_class,false);
	
	TArray<UDataWidget*> out;
	for(UUserWidget* temp_widget : temp)
	{
		UDataWidget* data_widget=Cast<UDataWidget>(temp_widget);
		if(data_widget && Sources.Contains(data_widget->ReferencedAsset))
		{
			out.Add(data_widget);
		}
	}
	
	return out;
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

UOmegaSlateTheme* UOmegaWidgetFunctions::GetWidgetSlateTheme(UWidget* Widget)
{
	if (Widget)
	{
		return UOmegaWidgetInterface::GetTheme(Widget);
	}
	return nullptr;
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
