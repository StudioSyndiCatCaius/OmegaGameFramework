// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Widget/DataWidget.h"
#include "Widget/HUDLayer.h"
#include "F_Widget.generated.h"



UCLASS()
class UOmegaWidgetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static APlayerController* PlayerFromWorldContext(UObject* Context, APlayerController* Fallback);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate UI", meta=(AdvancedDisplay="Player", WorldContext="WorldContextObject"),DisplayName="🎮Control Widget - Set")
	static void ControlWidget_Set(UObject* WorldContextObject, UUserWidget* Widget, APlayerController* Player);
	UFUNCTION(BlueprintPure,Category="Omega|Slate UI", meta=(AdvancedDisplay="Player", WorldContext="WorldContextObject"),DisplayName="🎮Control Widget - Get")
	static  UUserWidget* ControlWidget_Get(UObject* WorldContextObject, UUserWidget* Widget, APlayerController* Player);
	UFUNCTION(BlueprintCallable,Category="Omega|Slate UI", meta=(AdvancedDisplay="Player", WorldContext="WorldContextObject"),DisplayName="🎮Control Widget - Clear")
	static  void ControlWidget_Clear(UObject* WorldContextObject, APlayerController* Player);
	
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


