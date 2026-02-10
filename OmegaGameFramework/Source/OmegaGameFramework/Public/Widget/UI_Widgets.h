// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/ComboBox.h"
#include "Components/ComboBoxString.h"
#include "Components/ExpandableArea.h"
#include "Components/ProgressBar.h"
#include "Components/RichTextBlock.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "Interfaces/I_AssetThumbnail.h"

#include "UI_Widgets.generated.h"

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

// IStyleApplicator.h
#pragma once

class UWidget;

UCLASS(Abstract) class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle : public UPrimaryDataAsset, public IDataInterface_AssetThumbnail
{
	GENERATED_BODY() public:
	
	virtual void ApplyStyleAgnostic(UWidget* Widget)
	{
		
	}
	
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


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaButton : public UButton
{
	UOmegaSlateStyle_Button* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_Button* StyleAsset;
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Button* Style);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSlider : public USlider
{
	UOmegaSlateStyle_Slider* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_Slider* StyleAsset;
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Slider* Style);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaProgressBar : public UProgressBar
{
	UOmegaSlateStyle_ProgressBar* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  bool UseDefaultStyle;
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition = "!UseDefaultStyle"))  UOmegaSlateStyle_ProgressBar* StyleAsset;
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_ProgressBar* Style);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCheckBox : public UCheckBox
{
	UOmegaSlateStyle_CheckBox* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_CheckBox* StyleAsset;
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_CheckBox* Style);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaComboBox : public UComboBoxString
{
	UOmegaSlateStyle_ComboBox* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_ComboBox* StyleAsset;
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_ComboBox* Style);
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBorder : public UBorder
{
	UOmegaSlateStyle_Border* L_GetStyle() const;
	
	GENERATED_BODY() public:
	
	virtual void OnWidgetRebuilt() override;
	
	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="!bUseDefaultStyle"))
	UOmegaSlateStyle_Border* StyleAsset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Style")
	bool bUseDefaultStyle;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Style",meta=(EditCondition="bUseDefaultStyle"))
	TEnumAsByte<EOmegaSlateBorderType> DefaultStyleToUse;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Border* Style);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaTextBlock : public UTextBlock
{
	UOmegaSlateStyle_Text* L_GetStyle() const;
	GENERATED_BODY() public:
	virtual void OnWidgetRebuilt() override;

	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="!bUseDefaultStyle"))
	UOmegaSlateStyle_Text* StyleAsset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Style")
	bool bUseDefaultStyle;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Style",meta=(EditCondition="bUseDefaultStyle"))
	TEnumAsByte<EOmegaSlateTextType> DefaultStyleToUse;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Text* Style);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaRichTextBlock : public URichTextBlock
{
	UOmegaSlateStyle_RichText* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_RichText* StyleAsset;
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_RichText* NewStyle);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaExpandableArea : public UExpandableArea
{
	UOmegaSlateStyle_ExpandableArea* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_ExpandableArea* StyleAsset;
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_ExpandableArea* NewStyle);
};
