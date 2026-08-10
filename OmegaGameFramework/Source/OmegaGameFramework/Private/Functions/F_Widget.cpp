// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Widget.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Player.h"
#include "Widgets/SWidget.h"
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

namespace OmegaWidgetPosition_Private
{
	/** Resolve the best available geometry for a UMG widget that has been realized in Slate. */
	static bool TryGetWidgetGeometry(const UWidget* Widget, FGeometry& OutGeometry)
	{
		OutGeometry = FGeometry();
		if (!IsValid(Widget))
		{
			return false;
		}

		// Prefer an already-realized slate widget. Without one, geometry is uninitialized (0 size / 0 pos).
		TSharedPtr<SWidget> SlateWidget = Widget->GetCachedWidget();
		if (!SlateWidget.IsValid())
		{
			// Realize the slate representation if possible (safe for widgets already in a tree).
			SlateWidget = const_cast<UWidget*>(Widget)->TakeWidget();
		}
		if (!SlateWidget.IsValid())
		{
			return false;
		}

		// Paint/tick space are more reliable than the legacy cached path on some UE versions / cull cases.
		OutGeometry = Widget->GetPaintSpaceGeometry();
		if (OutGeometry.GetLocalSize().IsNearlyZero())
		{
			OutGeometry = Widget->GetTickSpaceGeometry();
		}
		if (OutGeometry.GetLocalSize().IsNearlyZero())
		{
			OutGeometry = Widget->GetCachedGeometry();
		}

		// User widgets that are constructed but not yet arranged can still prepass for a usable size.
		if (OutGeometry.GetLocalSize().IsNearlyZero())
		{
			if (const UUserWidget* UserWidget = Cast<UUserWidget>(Widget))
			{
				const_cast<UUserWidget*>(UserWidget)->ForceLayoutPrepass();
				OutGeometry = Widget->GetCachedGeometry();
				if (OutGeometry.GetLocalSize().IsNearlyZero())
				{
					OutGeometry = Widget->GetPaintSpaceGeometry();
				}
			}
		}

		// Realized slate widget is enough. Position may still be (0,0) until the first arrange/paint
		// (do not reject on zero local size — that was failing for valid on-screen widgets).
		return true;
	}

	static UObject* ResolveWorldContext(const UWidget* Widget)
	{
		if (!IsValid(Widget))
		{
			return nullptr;
		}
		if (UWorld* World = Widget->GetWorld())
		{
			return World;
		}
		if (const UUserWidget* UserWidget = Cast<UUserWidget>(Widget))
		{
			if (APlayerController* PC = UserWidget->GetOwningPlayer())
			{
				return PC;
			}
			if (ULocalPlayer* LP = UserWidget->GetOwningLocalPlayer())
			{
				return LP;
			}
		}
		return nullptr;
	}
}

bool UOmegaWidgetFunctions::GetWidgetScreenPosition(const UWidget* Widget, FVector2D& OutPosition, bool bGetCenter)
{
	OutPosition = FVector2D::ZeroVector;

	FGeometry Geometry;
	if (!OmegaWidgetPosition_Private::TryGetWidgetGeometry(Widget, Geometry))
	{
		return false;
	}

	// Desktop/slate absolute coordinates (not DPI-scaled viewport units).
	const FVector2D LocalCoord = bGetCenter ? FVector2D(0.5f, 0.5f) : FVector2D::ZeroVector;
	OutPosition = Geometry.GetAbsolutePositionAtCoordinates(LocalCoord);
	return true;
}

bool UOmegaWidgetFunctions::GetWidgetViewportPosition(const UWidget* Widget, FVector2D& OutViewportPosition,
	bool bGetCenter)
{
	OutViewportPosition = FVector2D::ZeroVector;

	FGeometry Geometry;
	if (!OmegaWidgetPosition_Private::TryGetWidgetGeometry(Widget, Geometry))
	{
		return false;
	}

	UObject* WorldContext = OmegaWidgetPosition_Private::ResolveWorldContext(Widget);
	if (!WorldContext)
	{
		return false;
	}

	// LocalToViewport expects local-space units (pixels), not normalized 0-1 coordinates.
	const FVector2D LocalCoord = bGetCenter ? (Geometry.GetLocalSize() * 0.5f) : FVector2D::ZeroVector;
	FVector2D PixelPosition = FVector2D::ZeroVector;
	// Absolute/desktop → pixel + viewport. Do NOT just divide absolute pos by viewport scale:
	// absolute coords include the viewport's desktop origin (windowed / multi-monitor).
	USlateBlueprintLibrary::LocalToViewport(WorldContext, Geometry, LocalCoord, PixelPosition, OutViewportPosition);
	return true;
}
