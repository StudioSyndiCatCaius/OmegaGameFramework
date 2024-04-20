// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "CommonTextBlock.h"
#include "CommonBorder.h"
#include "Widget/HUDLayer.h"
#include "Widget/Menu.h"
#include "Components/CheckBox.h"
#include "Components/ComboBox.h"
#include "Components/ComboBoxString.h"
#include "Components/ProgressBar.h"
#include "Components/Slider.h"
#include "OmegaStyle_Slate.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TSubclassOf<UCommonTextStyle> Text_Header_1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TSubclassOf<UCommonTextStyle> Text_Header_2;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TSubclassOf<UCommonTextStyle> Text_Header_3;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TSubclassOf<UCommonTextStyle> Text_Paragraph;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TSubclassOf<UCommonTextStyle> Text_Tiny;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Border")
	TSubclassOf<UCommonBorderStyle> Border_Big;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Border")
	TSubclassOf<UCommonBorderStyle> Border_Medium;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Border")
	TSubclassOf<UCommonBorderStyle> Border_Small;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Border")
	TSubclassOf<UCommonBorderStyle> Border_Button;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Border")
	TSubclassOf<UCommonBorderStyle> Border_Minimal;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Border")
	TSubclassOf<UCommonBorderStyle> Border_Background;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Misc")
	FProgressBarStyle ProgressBar_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Misc")
	FButtonStyle Button_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Misc")
	FSliderStyle Slider_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Misc")
	FCheckBoxStyle Checkbox_default;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	FComboBoxStyle ComboBox_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	FTableRowStyle ComboBoxItem_Default;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Hover;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Select;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Error;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Menu_Open;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Menu_Close;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Pause;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Confirm;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Info;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_SaveLoad;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Choice;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_CombatCommand;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TSubclassOf<UHUDLayer> HUD_Loading;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TSubclassOf<UHUDLayer> HUD_Exploration;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TSubclassOf<UHUDLayer> HUD_Dialogue;
};

UENUM()
enum EOmegaSlateTextType
{
	Header1,
	Header2,
	Header3,
	Paragraph,
	Tiny,
};

UENUM()
enum EOmegaSlateBorderType
{
	Big,
	Medium,
	Small,
	Button,
	Minimal,
	Background,
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSlateFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Slate")
	static UOmegaSlateStyle* GetCurrentSlateStyle();

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Text(UCommonTextBlock* widget, EOmegaSlateTextType Type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_WidgetChildren_Text(UPanelWidget* widget, EOmegaSlateTextType Type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Border(UCommonBorder* widget, EOmegaSlateBorderType type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_ProgressBar(UProgressBar* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Slider(USlider* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Checkbox(UCheckBox* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_ComboBox(UComboBoxString* widget);
};

// ============================================
// styles
// ============================================

