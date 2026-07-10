// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Misc/OmegaUtils_Structs.h"
#include "UObject/Object.h"
#include "Widget/UI_Widgets.h"
#include "OmegaSettings_Slate.generated.h"

class UOmegaHoverCursor;
class UOmegaUIStyle_Background;
class UOmegaBGM;
class UOmegaTextFormater_Collection;
class UHUDLayer;
class UMenu;
class UCommonBorderStyle;
class UCommonTextStyle;
class UProgressBar;
class USlider;
class UCheckBox;
class UDataWidget;

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Style"))
class OMEGAGAMEFRAMEWORK_API UOmegaStyleSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	TArray<UOmegaTextFormater_Collection*> L_GetTextFormaters();
	FText L_FormatGameplayText(FText text, UObject* WorldContext,FGameplayTag Tag,FOmegaCommonMeta meta);
	UPROPERTY(EditAnywhere, Category = "Slate") TSoftClassPtr<UHUDLayer> MainGlobalHUD;
	UPROPERTY(EditAnywhere, Category = "Slate") TSoftClassPtr<UHUDLayer> MainPlayerHUD;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Slate")
	TSoftObjectPtr<UOmegaSlateTheme> DefaultSlateTheme;

	UPROPERTY(EditAnywhere, Category = "Slate")
	TSoftClassPtr<UOmegaHoverCursor> HoverCursorClass;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Text")
	TArray<TSoftObjectPtr<UOmegaTextFormater_Collection>> TextFormaters;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Text")
	FGameplayTag DefaultTextFormatTag;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Text")
	bool bAutoFormatText_onDataWidgets=true;
	


};


// ============================================
// styles
// ============================================

