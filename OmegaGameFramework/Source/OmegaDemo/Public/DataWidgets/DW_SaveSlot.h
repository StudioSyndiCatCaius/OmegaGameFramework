// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/DataWidget.h"
#include "DW_SaveSlot.generated.h"

class UWidgetSwitcher;
class UTextBlock;
class UImage;
class UOmegaSaveGame;

// ==============================================================================================================
// Save Slot
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_SaveSlot : public UDataWidget
{
	GENERATED_BODY()

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,Category="Save")
	void OnSaveWidgetInit(UOmegaSaveGame* Save);

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void GetDataWidgetBindings(UWidgetSwitcher*& switcher_ValidSave,
		UTextBlock*& txt_playtime,
		UTextBlock*& txt_levelname,
		UTextBlock*& txt_zonename,
		UImage*& img_screenshot);

};
