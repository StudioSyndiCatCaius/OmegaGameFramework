// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
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

	//Get an Active Gameplay System by Class
	UFUNCTION(BlueprintCallable, Category="Omega|Slate UI", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="Class",ExpandBoolAsExecs = "Outcome",AdvancedDisplay="Player"),DisplayName="Ω🔴 Try Get HUD Layer")
	static UHUDLayer* TryGetHudLayer(const UObject* WorldContextObject, TSubclassOf<UHUDLayer> Class, APlayerController* Player, bool& Outcome);

	//Get an Active Gameplay System by Class
	UFUNCTION(BlueprintCallable, Category="Omega|Slate UI", meta = (WorldContext = "WorldContextObject", DeterminesOutputType="Class",ExpandBoolAsExecs = "Outcome",AdvancedDisplay="Player"),DisplayName="Ω🔴 Try Get Data Widget (from slot)")
	static UDataWidget* TryGetDataWidget_FromSlot(const UObject* WorldContextObject, FGameplayTag SlotID, APlayerController* Player, bool& Outcome);
	
	UFUNCTION(BlueprintCallable,Category="Omega|DataList",meta=(DeterminesOutputType="ObjectClass"))
	static TArray<UObject*> GetSourceAssetsFromDataWidgets(TArray<UDataWidget*> Widgets, TSubclassOf<UObject> ObjectClass);
};


