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

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Style"))
class OMEGAGAMEFRAMEWORK_API UOmegaStyleSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Texts")
	TMap<TEnumAsByte<EOmegaSlateTextType>,TSoftObjectPtr<UOmegaSlateStyle_Text>> Styled_Text;
	
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Texts")
	TMap<TEnumAsByte<EOmegaSlateBorderType>,TSoftObjectPtr<UOmegaSlateStyle_Border>> Styled_Borders;
	
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Elements")
	TSoftObjectPtr<UOmegaUIStyle_Background> Background_Default;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Elements")
	TSoftObjectPtr<UOmegaSlateStyle_ProgressBar> ProgressBar_Default;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Elements")
	TSoftObjectPtr<UOmegaSlateStyle_Button> Button_Default;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Elements")
	TSoftObjectPtr<UOmegaSlateStyle_Slider> Slider_Default;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Elements")
	TSoftObjectPtr<UOmegaSlateStyle_CheckBox> Checkbox_default;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Elements")
	TSoftObjectPtr<UOmegaSlateStyle_ComboBox> ComboBox_Default;

	UPROPERTY(EditAnywhere, Category = "Misc", meta=(MetaClass="OmegaHoverCursor"))
	FSoftClassPath HoverCursorClass;
	
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Sound")
	TSoftObjectPtr<USoundBase> Sound_Hover;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Sound")
	TSoftObjectPtr<USoundBase> Sound_Select;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Sound")
	TSoftObjectPtr<USoundBase> Sound_Cycle;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Sound")
	TSoftObjectPtr<USoundBase> Sound_Error;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Sound")
	TSoftObjectPtr<USoundBase> Sound_Menu_Open;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Sound")
	TSoftObjectPtr<USoundBase> Sound_Menu_Close;

};


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
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Widgets")
	TSubclassOf<UDataWidget> DataWidget_SaveSlot;
	
	// Images
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	FSlateBrush LogoDefault;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	FSlateBrush LoadingIndicator;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	TArray<FSlateBrush> SplashImages;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Images")
	FSlateBrush GenericMenu_Background;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="BGM")
	UOmegaBGM* BGM_Title;
	
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
	static void SetSlateStyle_WidgetChildren_Text(UPanelWidget* widget, EOmegaSlateTextType Type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Button(UButton* widget);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Border(UOmegaBorder* widget, EOmegaSlateBorderType type);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_ProgressBar(UProgressBar* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Slider(USlider* widget);

	UFUNCTION(BlueprintCallable,Category="Omega|Slate")
	static void SetSlateStyle_Checkbox(UCheckBox* widget);
	
};

// ============================================
// styles
// ============================================

