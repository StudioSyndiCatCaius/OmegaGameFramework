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


UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Button : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FButtonStyle ButtonStyle;
	UPROPERTY(EditAnywhere,Category="Style") FLinearColor ButtonColor;
	UPROPERTY(EditAnywhere,Category="Style") FLinearColor BackgroundColor;

	UFUNCTION() void Apply(UButton* button);
};
UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Slider : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FSliderStyle Brush_Slider;
};
UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_ProgressBar : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FProgressBarStyle Brush_ProgressBar;
};
UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_CheckBox : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FCheckBoxStyle CheckBox;
	
	UFUNCTION() void Apply(UCheckBox* widget);
};
UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_ComboBox : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FComboBoxStyle ComboBox;
	UPROPERTY(EditAnywhere,Category="Style") FTableRowStyle Item;
	UPROPERTY(EditAnywhere,Category="Style") FScrollBarStyle ScrollBar;
	UPROPERTY(EditAnywhere,Category="Style") FSlateFontInfo Font;
	UPROPERTY(EditAnywhere,Category="Style") FMargin ContentPadding;

	UFUNCTION() void Apply(UComboBoxString* box);
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Border : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FSlateBrush Brush;
	UPROPERTY(EditAnywhere,Category="Style") FMargin Padding;
	
	UFUNCTION() void Apply(UBorder* widget);
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_Text : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FSlateFontInfo Font;
	UPROPERTY(EditAnywhere,Category="Style") FSlateColor Color;
	UPROPERTY(EditAnywhere,Category="Style") FSlateBrush StrikeBrush;
	UPROPERTY(EditAnywhere,Category="Style") FVector2D ShadowOffset;
	UPROPERTY(EditAnywhere,Category="Style") FLinearColor ShadowColor;
	UPROPERTY(EditAnywhere,Category="Style") FMargin Margins;
	UPROPERTY(EditAnywhere,Category="Style") float LineHeightPercentage;

	UFUNCTION() void Apply(UTextBlock* widget);
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_RichText : public UPrimaryDataAsset {
	GENERATED_BODY() public:
};

UCLASS() class OMEGAGAMEFRAMEWORK_API UOmegaSlateStyle_ExpandableArea : public UPrimaryDataAsset {
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style") FExpandableAreaStyle Style;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaButton : public UButton
{
	UOmegaSlateStyle_Button* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_Button* StyleAsset;
	virtual void OnWidgetRebuilt() override;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSlider : public USlider
{
	UOmegaSlateStyle_Slider* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_Slider* StyleAsset;
	virtual void OnWidgetRebuilt() override;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaProgressBar : public UProgressBar
{
	UOmegaSlateStyle_ProgressBar* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_ProgressBar* StyleAsset;
	virtual void OnWidgetRebuilt() override;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCheckBox : public UCheckBox
{
	UOmegaSlateStyle_CheckBox* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_CheckBox* StyleAsset;
	virtual void OnWidgetRebuilt() override;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaComboBox : public UComboBoxString
{
	UOmegaSlateStyle_ComboBox* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_ComboBox* StyleAsset;
	virtual void OnWidgetRebuilt() override;
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
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaRichTextBlock : public URichTextBlock
{
	UOmegaSlateStyle_RichText* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_RichText* StyleAsset;
	virtual void OnWidgetRebuilt() override;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaExpandableArea : public UExpandableArea
{
	UOmegaSlateStyle_ExpandableArea* L_GetStyle() const;
	GENERATED_BODY() public:
	UPROPERTY(EditAnywhere,Category="Style")  UOmegaSlateStyle_ExpandableArea* StyleAsset;
	virtual void OnWidgetRebuilt() override;
};
