// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Widget/UI_Widgets.h"
#include "OmegaSettings_Slate.generated.h"

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

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Slate : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UOmegaSettings_Slate();

	FText L_FormatDataWidgetText(UDataWidget* w, FText t) const;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Overrides")
	TMap<TSoftObjectPtr<UPrimaryDataAsset>,FText> Override_AssetNames;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Overrides")
	TMap<TSoftObjectPtr<UPrimaryDataAsset>,FSlateBrush> Override_AssetIcon;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Overrides")
	TMap<TSoftObjectPtr<UPrimaryDataAsset>,FSlateBrush> Override_AssetColor;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts",AdvancedDisplay)
	TSubclassOf<UCommonTextStyle> Text_Header_1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts",AdvancedDisplay)
	TSubclassOf<UCommonTextStyle> Text_Header_2;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts",AdvancedDisplay)
	TSubclassOf<UCommonTextStyle> Text_Header_3;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts",AdvancedDisplay)
	TSubclassOf<UCommonTextStyle> Text_Paragraph;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts",AdvancedDisplay)
	TSubclassOf<UCommonTextStyle> Text_Tiny;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TMap<TEnumAsByte<EOmegaSlateTextType>,TSoftObjectPtr<UOmegaSlateStyle_Text>> Styled_Text;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TMap<FGameplayTag,TSoftClassPtr<UCommonTextStyle>> Tagged_Text;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Text")
    UOmegaTextFormater_Collection* TextFormater;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Text")
	bool DataWidgets_AutoFormatText=true;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Text")
	FGameplayTag DataWidgets_TextFormatTag;

	
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
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Texts")
	TMap<TEnumAsByte<EOmegaSlateBorderType>,TSoftObjectPtr<UOmegaSlateStyle_Border>> Styled_Borders;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Border")
	TMap<FGameplayTag,TSoftClassPtr<UCommonBorderStyle>> Tagged_Borders;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Color")
	FLinearColor Color_1=FLinearColor::Red;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Color")
	FLinearColor Color_3=FLinearColor::Green;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Color")
	FLinearColor Color_2=FLinearColor::Blue;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Color")
	FLinearColor Color_4=FLinearColor::White;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Color")
	TMap<FGameplayTag,FLinearColor> Colors_Tagged;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	UOmegaUIStyle_Background* Background_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	UOmegaSlateStyle_ProgressBar* ProgressBar_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	UOmegaSlateStyle_Button* Button_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	UOmegaSlateStyle_Slider* Slider_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	UOmegaSlateStyle_CheckBox* Checkbox_default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Elements")
	UOmegaSlateStyle_ComboBox*  ComboBox_Default;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Widgets")
	TSubclassOf<UDataWidget> DataWidget_SaveSlot;
	UPROPERTY(EditAnywhere, Category = "Widgets", meta=(MetaClass="OmegaHoverCursor"))
	FSoftClassPath HoverCursorClass;
	
	// Images
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	FSlateBrush LogoDefault;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	FSlateBrush LoadingIndicator;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	TArray<FSlateBrush> SplashImages;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	FSlateBrush GenericMenu_Background;

	// SOUNDS
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Hover;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Select;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Cycle;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Error;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Menu_Open;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound")
	USoundBase* Sound_Menu_Close;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="BGM")
	UOmegaBGM* BGM_Title;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Pause;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Confirm;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Info;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_NumInput;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_TextInput;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_SaveLoad;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Choice;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_CombatCommand;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Settings;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_NewGame;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TSubclassOf<UMenu> Menu_Extras;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Menu")
	TMap<FGameplayTag,TSoftClassPtr<UMenu>> Menus_Tagged;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TSubclassOf<UHUDLayer> HUD_Loading;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TSubclassOf<UHUDLayer> HUD_Exploration;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TSubclassOf<UHUDLayer> HUD_Dialogue;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TSubclassOf<UHUDLayer> HUD_Battle;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="HUD")
	TMap<FGameplayTag,TSoftClassPtr<UHUDLayer>> HUDs_Tagged;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSlateFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Settings", DisplayName="Get OMEGA Settings (Slate)")
	static UOmegaSettings_Slate* GetCurrentSlateStyle();

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_AllWidgets(UPanelWidget* Parent, EOmegaSlateTextType TextType, EOmegaSlateBorderType BorderType);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Text(UCommonTextBlock* widget, EOmegaSlateTextType Type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_WidgetChildren_Text(UPanelWidget* widget, EOmegaSlateTextType Type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Button(UButton* widget);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Border(UCommonBorder* widget, EOmegaSlateBorderType type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_ProgressBar(UProgressBar* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Slider(USlider* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Checkbox(UCheckBox* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static FLinearColor GetSlateColor_ByIndex(int32 index);	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static FLinearColor GetSlateColor_ByTag(FGameplayTag Tag, FLinearColor Fallback);
};

// ============================================
// styles
// ============================================

