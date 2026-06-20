// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Components/Widget.h"
#include "Widget/HUDLayer.h"
#include "F_Widget.generated.h"


class UWidget;
class UDataWidget;
class UHUDLayer;

UCLASS()
class UOmegaWidgetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static APlayerController* PlayerFromWorldContext(UObject* Context, APlayerController* Fallback);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate UI")
	static TArray<UWidget*> GetChildrenWidgets(UWidget* Parent, TSubclassOf<UWidget> FilterClass, bool bRecursive);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate UI", meta=(AdvancedDisplay="Context, Flag, Player", WorldContext="WorldContextObject"))
	static void SetHUDLayerActive(UObject* WorldContextObject, TSubclassOf<UHUDLayer> HUD, bool bActive, UObject* Context, const FString& Flag, APlayerController* Player);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate UI", meta=(AdvancedDisplay="Context, Flag, Player", WorldContext="WorldContextObject"))
	static void SetHUDLayersActive(UObject* WorldContextObject, TArray<TSubclassOf<UHUDLayer>> HUDs, bool bActive, UObject* Context, const FString& Flag, APlayerController* Player);

	//Get an Active Gameplay System by Class
	UFUNCTION(BlueprintCallable, Category="Omega|Slate UI", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="Class",ExpandBoolAsExecs = "Outcome",AdvancedDisplay="Player"),DisplayName="Ω🔴 Try Get HUD Layer")
	static UHUDLayer* TryGetHudLayer(const UObject* WorldContextObject, TSubclassOf<UHUDLayer> Class, APlayerController* Player, bool& Outcome);

	//Get an Active Gameplay System by Class
	UFUNCTION(BlueprintCallable, Category="Omega|Slate UI", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="Class",ExpandBoolAsExecs = "Outcome",AdvancedDisplay="Player"),DisplayName="Ω🔴 Try Get Data Widget (from slot)")
	static UDataWidget* TryGetDataWidget_FromSlot(const UObject* WorldContextObject, FGameplayTag SlotID, APlayerController* Player, bool& Outcome);
	
	UFUNCTION(BlueprintCallable,Category="Omega|DataList",meta=(DeterminesOutputType="ObjectClass"))
	static TArray<UObject*> GetSourceAssetsFromDataWidgets(TArray<UDataWidget*> Widgets, TSubclassOf<UObject> ObjectClass);
	
	// Walks up the widget hierarchy (starting from Widget itself) and returns the first valid SlateTheme found.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Omega Slate Theme", meta=(DefaultToSelf="Widget"))
	static UOmegaSlateTheme* GetWidgetSlateTheme(UWidget* Widget);
	
	/**
	 * Gets the true screen position of a UMG widget.
	 * 
	 * @param Widget         The widget to get the position of
	 * @param OutPosition    The resulting screen position
	 * @param bGetCenter     If true, returns the center of the widget; otherwise returns top-left
	 * @return               True if the position was successfully retrieved
	 */
	UFUNCTION(BlueprintPure,Category="Omega|Widget")
	static bool GetWidgetScreenPosition(const UWidget* Widget, FVector2D& OutPosition, bool bGetCenter = false);
	UFUNCTION(BlueprintPure,Category="Omega|Widget")
	static bool GetWidgetViewportPosition(const UWidget* Widget, FVector2D& OutViewportPosition, bool bGetCenter = false);
};


