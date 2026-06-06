// OmegaTabWidgetTypes.h
// Shared types for Omega Tab Widget system

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "OmegaTabWidgetTypes.generated.h"

// ============================================================================
// Tab Configuration Struct
// ============================================================================

USTRUCT(BlueprintType)
struct FOmegaTabConfig
{
	GENERATED_BODY()

	/** Display name for the tab */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tab")
	FText TabName;

	/** Icon displayed on the tab */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tab")
	FSlateBrush TabIcon;

	FOmegaTabConfig()
		: TabName(FText::GetEmpty())
		, TabIcon()
	{
	}

	FOmegaTabConfig(const FText& InName, const FSlateBrush& InIcon = FSlateBrush())
		: TabName(InName)
		, TabIcon(InIcon)
	{
	}
};

// ============================================================================
// Style Struct
// ============================================================================

USTRUCT(BlueprintType)
struct FOmegaTabWidgetStyle : public FSlateWidgetStyle
{
	GENERATED_BODY()

	FOmegaTabWidgetStyle();
	virtual ~FOmegaTabWidgetStyle() {}

	// FSlateWidgetStyle interface
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; }
	static const FOmegaTabWidgetStyle& GetDefault();

	/** Style for inactive tab buttons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FButtonStyle TabButtonStyle;

	/** Style for the currently active tab button */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FButtonStyle ActiveTabButtonStyle;

	/** Text style for inactive tabs */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FTextBlockStyle TabTextStyle;

	/** Text style for the active tab */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FTextBlockStyle ActiveTabTextStyle;

	/** Size of tab icons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FVector2D IconSize;

	/** Spacing between tab buttons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	float TabSpacing;

	/** Padding inside each tab button */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FMargin TabPadding;

	/** Background brush for the entire tab bar */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FSlateBrush TabBarBackground;
};

// ============================================================================
// Style Container (for Slate Style Sets)
// ============================================================================

UCLASS(hidecategories = Object, MinimalAPI)
class UOmegaTabWidgetStyleContainer : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Appearance", meta = (ShowOnlyInnerProperties))
	FOmegaTabWidgetStyle Style;

	virtual const FSlateWidgetStyle* const GetStyle() const override
	{
		return &Style;
	}
};
