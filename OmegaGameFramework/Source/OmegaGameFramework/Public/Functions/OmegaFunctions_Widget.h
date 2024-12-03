// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Widget/DataWidget.h"
#include "Widget/HUDLayer.h"
#include "OmegaFunctions_Widget.generated.h"



UCLASS()
class UOmegaWidgetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Slate UI", meta=(AdvancedDisplay="Context, Flag, Player", WorldContext="WorldContextObject"))
	static void SetHUDLayerActive(UObject* WorldContextObject, TSubclassOf<UHUDLayer> HUD, bool bActive, UObject* Context, const FString& Flag, APlayerController* Player);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate UI", meta=(AdvancedDisplay="Context, Flag, Player", WorldContext="WorldContextObject"))
	static void SetHUDLayersActive(UObject* WorldContextObject, TArray<TSubclassOf<UHUDLayer>> HUDs, bool bActive, UObject* Context, const FString& Flag, APlayerController* Player);

	UFUNCTION(BlueprintCallable,Category="Omega|DataList",meta=(DeterminesOutputType="ObjectClass"))
	static TArray<UObject*> GetSourceAssetsFromDataWidgets(TArray<UDataWidget*> Widgets, TSubclassOf<UObject> ObjectClass);
};


