// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/ComboBox.h"
#include "Components/ComboBoxString.h"
#include "Components/ExpandableArea.h"
#include "Components/ProgressBar.h"
#include "Components/RichTextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/Struct_Material.h"

#include "Engine/DataAsset.h"
#include "UI_Widgets.generated.h"

USTRUCT(BlueprintType)
struct FOmegaWidgetPostProcess
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Category="PostProcess") FOmegaDynamicMaterialParams MaterialParams;

	void Apply(UMaterialInstanceDynamic* Mat) const;
};

class UWidget;

UCLASS(Abstract) class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle : public UPrimaryDataAsset
{
	GENERATED_BODY() public:
	
	UPROPERTY(EditAnywhere,Category="PostProcess",meta=(ShowOnlyInnerProperties)) FOmegaWidgetPostProcess PostProcess;

	/** Applies PostProcess from this style asset first, then from the active theme. Call after Apply(). */
	void ApplyPostProcess(UWidget* Widget) const;

	virtual void ApplyStyleAgnostic(UWidget* Widget)
	{

	}

	virtual FSlateBrush GetMainSlateBrush() const { return FSlateBrush(); }
	
};


UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Button: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FButtonStyle ButtonStyle;
	UPROPERTY(EditAnywhere,Category="Style") FLinearColor ButtonColor;
	UPROPERTY(EditAnywhere,Category="Style") FLinearColor BackgroundColor;

	UFUNCTION() void Apply(UButton* button);
	
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UButton* _wg=Cast<UButton>(Widget))
		{
			Apply(_wg);
		}
	}
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Slider: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FSliderStyle Brush_Slider;
	
	virtual FSlateBrush GetMainSlateBrush() const override { return Brush_Slider.NormalBarImage; };
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (USlider* _wg=Cast<USlider>(Widget))
		{
			_wg->SetWidgetStyle(Brush_Slider);
		}
	}
};
UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_ProgressBar: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FProgressBarStyle Brush_ProgressBar;
	
	virtual FSlateBrush GetMainSlateBrush() const override { return Brush_ProgressBar.FillImage; };
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UProgressBar* _wg=Cast<UProgressBar>(Widget))
		{
			_wg->SetWidgetStyle(Brush_ProgressBar);
		}
	}
};
UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_CheckBox: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FCheckBoxStyle CheckBox;
	
	virtual FSlateBrush GetMainSlateBrush() const override { return CheckBox.CheckedImage; };
	UFUNCTION() void Apply(UCheckBox* widget);
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UCheckBox* _wg=Cast<UCheckBox>(Widget))
		{
			Apply(_wg);
		}
	}
};
UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_ComboBox: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FComboBoxStyle ComboBox;
	UPROPERTY(EditAnywhere,Category="Style") FTableRowStyle Item;
	UPROPERTY(EditAnywhere,Category="Style") FScrollBarStyle ScrollBar;
	UPROPERTY(EditAnywhere,Category="Style") FSlateFontInfo Font;
	UPROPERTY(EditAnywhere,Category="Style") FMargin ContentPadding;

	UFUNCTION() void Apply(UComboBoxString* box);
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UComboBoxString* _wg=Cast<UComboBoxString>(Widget))
		{
			Apply(_wg);
		}
	}
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Border: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FSlateBrush Brush;
	UPROPERTY(EditAnywhere,Category="Style") FMargin Padding;
	
	virtual FSlateBrush GetMainSlateBrush() const override { return Brush; };
	UFUNCTION() void Apply(UBorder* widget);
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UBorder* _wg=Cast<UBorder>(Widget))
		{
			Apply(_wg);
		}
	}
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Text: public UOmegaSlateStyle {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FSlateFontInfo Font;
	UPROPERTY(EditAnywhere,Category="Style") FSlateColor Color;
	UPROPERTY(EditAnywhere,Category="Style") FSlateBrush StrikeBrush;
	UPROPERTY(EditAnywhere,Category="Style") FVector2D ShadowOffset;
	UPROPERTY(EditAnywhere,Category="Style") FLinearColor ShadowColor;
	UPROPERTY(EditAnywhere,Category="Style") FMargin Margins;
	UPROPERTY(EditAnywhere,Category="Style") float LineHeightPercentage;

	UFUNCTION() void Apply(UTextBlock* widget);
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UTextBlock* _wg=Cast<UTextBlock>(Widget))
		{
			Apply(_wg);
		}
	}
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_RichText: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		
	}
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_ExpandableArea: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FExpandableAreaStyle Style;

	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UExpandableArea* _wg=Cast<UExpandableArea>(Widget))
		{
			_wg->SetStyle(Style);
		}
	}
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_ScrollBox: public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FScrollBoxStyle ScrollBoxStyle;
	UPROPERTY(EditAnywhere,Category="Style") FScrollBarStyle ScrollBarStyle;

	UFUNCTION() void Apply(UScrollBox* widget);
	virtual void ApplyStyleAgnostic(UWidget* Widget) override
	{
		if (UScrollBox* _wg=Cast<UScrollBox>(Widget))
		{
			Apply(_wg);
		}
	}
};

// ---------------------------------------------------------------------------------------------------------------------
// Panel style  (UOmegaUI_Panel forward-declared; Apply implemented in UI_Widgets.cpp)
// ---------------------------------------------------------------------------------------------------------------------

class UOmegaUI_Panel;

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Panel : public UOmegaSlateStyle
{
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Title") FSlateBrush TitleBorder_Brush;
	UPROPERTY(EditAnywhere,Category="Title") FMargin TitleBorder_InnerPadding;
	UPROPERTY(EditAnywhere,Category="Title") FMargin TitleBorder_OuterPadding;
	UPROPERTY(EditAnywhere,Category="Title") FSlateFontInfo TitleText;
	UPROPERTY(EditAnywhere,Category="Body") FSlateBrush BodyBorder_Brush;
	UPROPERTY(EditAnywhere,Category="Body") FMargin BodyBorder_InnerPadding;
	UPROPERTY(EditAnywhere,Category="Body") FMargin BodyBorder_OuterPadding;

	UFUNCTION() void Apply(UOmegaUI_Panel* Panel);
	virtual void ApplyStyleAgnostic(UWidget* Widget) override;
};

// ---------------------------------------------------------------------------------------------------------------------
// Themes
// ---------------------------------------------------------------------------------------------------------------------

// UOmegaUIStyle_Background forward-declared; full type available via Widget/UI_Background.h
class UOmegaUIStyle_Background;

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateTheme : public UPrimaryDataAsset
{
	GENERATED_BODY() public:

	UPROPERTY(EditAnywhere,Category="Borders") UOmegaSlateStyle_Border* Border_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="Borders",meta=(ForceInlineRow,Categories="UiStyle.Border")) TMap<FGameplayTag,UOmegaSlateStyle_Border*> Border_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_Border* GetStyle_Border(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="Text") UOmegaSlateStyle_Text* Text_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="Text",meta=(ForceInlineRow,Categories="UiStyle.Text")) TMap<FGameplayTag,UOmegaSlateStyle_Text*> Text_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_Text* GetStyle_Text(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="Text") UOmegaSlateStyle_RichText* RichText_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="Text",meta=(ForceInlineRow,Categories="UiStyle.Text")) TMap<FGameplayTag,UOmegaSlateStyle_RichText*> RichText_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_RichText* GetStyle_RichText(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="Buttons") UOmegaSlateStyle_Button* Button_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="Buttons",meta=(ForceInlineRow,Categories="UiStyle.Button")) TMap<FGameplayTag,UOmegaSlateStyle_Button*> Button_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_Button* GetStyle_Button(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="Sliders") UOmegaSlateStyle_Slider* Slider_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="Sliders",meta=(ForceInlineRow,Categories="UiStyle.Slider")) TMap<FGameplayTag,UOmegaSlateStyle_Slider*> Slider_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_Slider* GetStyle_Slider(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="ProgressBars") UOmegaSlateStyle_ProgressBar* ProgressBar_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="ProgressBars",meta=(ForceInlineRow,Categories="UiStyle.ProgressBar")) TMap<FGameplayTag,UOmegaSlateStyle_ProgressBar*> ProgressBar_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_ProgressBar* GetStyle_ProgressBar(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="CheckBoxes") UOmegaSlateStyle_CheckBox* CheckBox_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="CheckBoxes",meta=(ForceInlineRow,Categories="UiStyle.CheckBox")) TMap<FGameplayTag,UOmegaSlateStyle_CheckBox*> CheckBox_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_CheckBox* GetStyle_CheckBox(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="ComboBoxes") UOmegaSlateStyle_ComboBox* ComboBox_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="ComboBoxes",meta=(ForceInlineRow,Categories="UiStyle.ComboBox")) TMap<FGameplayTag,UOmegaSlateStyle_ComboBox*> ComboBox_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_ComboBox* GetStyle_ComboBox(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="ExpandableAreas") UOmegaSlateStyle_ExpandableArea* ExpandableArea_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="ExpandableAreas",meta=(ForceInlineRow,Categories="UiStyle.ExpandableArea")) TMap<FGameplayTag,UOmegaSlateStyle_ExpandableArea*> ExpandableArea_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_ExpandableArea* GetStyle_ExpandableArea(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="ScrollBoxes") UOmegaSlateStyle_ScrollBox* ScrollBox_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="ScrollBoxes",meta=(ForceInlineRow,Categories="UiStyle.ScrollBox")) TMap<FGameplayTag,UOmegaSlateStyle_ScrollBox*> ScrollBox_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_ScrollBox* GetStyle_ScrollBox(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="Backgrounds") UOmegaUIStyle_Background* Background_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="Backgrounds",meta=(ForceInlineRow,Categories="UiStyle.Background")) TMap<FGameplayTag,UOmegaUIStyle_Background*> Background_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaUIStyle_Background* GetStyle_Background(FGameplayTag Tag);

	UPROPERTY(EditAnywhere,Category="Panels") UOmegaSlateStyle_Panel* Panel_Default=nullptr;
	UPROPERTY(EditAnywhere,Category="Panels",meta=(ForceInlineRow,Categories="UiStyle.Panel")) TMap<FGameplayTag,UOmegaSlateStyle_Panel*> Panel_Tagged;
	UFUNCTION(BlueprintPure,Category="Omega Slate Theme") UOmegaSlateStyle_Panel* GetStyle_Panel(FGameplayTag Tag);
	
	UPROPERTY(EditAnywhere,Category="PostProcess",meta=(ShowOnlyInnerProperties)) FOmegaWidgetPostProcess PostProcess;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound") TObjectPtr<USoundBase> Sound_Hover=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound") TObjectPtr<USoundBase> Sound_Select=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound") TObjectPtr<USoundBase> Sound_Cycle=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound") TObjectPtr<USoundBase> Sound_Error=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound") TObjectPtr<USoundBase> Sound_Menu_Open=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Sound") TObjectPtr<USoundBase> Sound_Menu_Close=nullptr;
};

// ---------------------------------------------------------------------------------------------------------------------
// Widget Interface
// ---------------------------------------------------------------------------------------------------------------------

UINTERFACE(MinimalAPI, BlueprintType)
class UOmegaWidgetInterface : public UInterface
{
	GENERATED_BODY()
public:
	
	static UOmegaSlateTheme* GetTheme(UWidget* Widget);
};

class OMEGAGAMEFRAMEWORK_API IOmegaWidgetInterface
{
	GENERATED_BODY()
public:
	// Returns this widget's own SlateTheme asset, or null if none is set.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Omega Slate Theme")
	UOmegaSlateTheme* GetSlateTheme() const;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const { return nullptr; }
};

// ---------------------------------------------------------------------------------------------------------------------
// Widgets
// ---------------------------------------------------------------------------------------------------------------------


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaButton : public UButton, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_Button* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.Button")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_Button* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Button* Style);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSlider : public USlider, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_Slider* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.Slider")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_Slider* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Slider* Style);
};

class UOmegaAttribute;
class UOmegaWidget;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaProgressBar : public UProgressBar, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_ProgressBar* L_GetStyle() const;
	UPROPERTY() UOmegaAttribute* BoundAttribute = nullptr;
	UPROPERTY() UCombatantComponent* BoundCombatant = nullptr;
	UFUNCTION() void L_OnCombUpdat(UCombatantComponent* Combatant);
	
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.ProgressBar")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_ProgressBar* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;


	/** Store a reference to the attribute this bar represents (for external logic). */
	UFUNCTION(BlueprintCallable, Category="ProgressBar")
	void BindAttribute(UCombatantComponent* Combatant, UOmegaAttribute* Attribute);

	UFUNCTION(BlueprintCallable, Category="ProgressBar")
	void UnbindAttribute();
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_ProgressBar* Style);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCheckBox : public UCheckBox, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_CheckBox* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.CheckBox")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_CheckBox* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_CheckBox* Style);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaComboBox : public UComboBoxString, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_ComboBox* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.ComboBox")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_ComboBox* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_ComboBox* Style);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBorder : public UBorder, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_Border* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.Border")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_Border* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Border* Style);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaTextBlock : public UTextBlock, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_Text* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.Text")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_Text* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Text* Style);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaRichTextBlock : public URichTextBlock, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_RichText* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.Text")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_RichText* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_RichText* NewStyle);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaExpandableArea : public UExpandableArea, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_ExpandableArea* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.ExpandableArea")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_ExpandableArea* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_ExpandableArea* NewStyle);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaScrollBox : public UScrollBox, public IOmegaWidgetInterface
{
	UOmegaSlateStyle_ScrollBox* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") bool UseStyle = false;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.ScrollBox")) FGameplayTag StyleTag;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle")) UOmegaSlateStyle_ScrollBox* OverrideStyle = nullptr;
	UPROPERTY(EditAnywhere,Category="Style") UOmegaSlateTheme* OverrideTheme = nullptr;
	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }
	virtual void OnWidgetRebuilt() override;

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_ScrollBox* Style);
};
