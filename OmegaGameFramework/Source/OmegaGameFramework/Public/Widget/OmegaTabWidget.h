// OmegaTabWidget.h
// UMG Widget wrapper for SOmegaTabWidget - usable in Blueprint Widget Editor

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Components/WidgetSwitcher.h"
#include "OmegaTabWidgetTypes.h"
#include "SOmegaTabWidget.h"
#include "OmegaTabWidget.generated.h"

// ============================================================================
// Tab Selected Delegate
// ============================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTabSelectedEvent, int32, TabIndex);

// ============================================================================
// UMG Widget
// ============================================================================

UCLASS(meta = (DisplayName = "Omega Tab Widget"))
class OMEGAGAMEFRAMEWORK_API UOmegaTabWidget : public UWidget
{
	GENERATED_BODY()

public:
	UOmegaTabWidget(const FObjectInitializer& ObjectInitializer);

	// ========================================================================
	// Properties
	// ========================================================================

	/** The Widget Switcher this tab widget controls */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega Tab Widget", meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> LinkedWidgetSwitcher;

	/** Tab configurations - array auto-syncs with WidgetSwitcher children count */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega Tab Widget")
	TArray<FOmegaTabConfig> Tabs;

	/** Orientation of the tab bar */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega Tab Widget")
	TEnumAsByte<EOrientation> Orientation;

	/** Style for inactive tab buttons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FButtonStyle TabButtonStyle;

	/** Style for the active tab button */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FButtonStyle ActiveTabButtonStyle;

	/** Text style for inactive tabs */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FTextBlockStyle TabTextStyle;

	/** Text style for active tab */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FTextBlockStyle ActiveTabTextStyle;

	/** Size of tab icons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FVector2D IconSize;

	/** Spacing between tab buttons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	float TabSpacing;

	/** Padding inside each tab button */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FMargin TabPadding;

	/** Background brush for the tab bar */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FSlateBrush TabBarBackground;

	// ========================================================================
	// Events
	// ========================================================================

	/** Called when a tab is selected */
	UPROPERTY(BlueprintAssignable, Category = "Omega Tab Widget|Events")
	FOnTabSelectedEvent OnTabSelected;

	// ========================================================================
	// Blueprint Functions
	// ========================================================================

	/** Get the currently active tab index */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	int32 GetActiveTabIndex() const;

	/** Set the active tab by index */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	void SetActiveTab(int32 Index);

	/** Rebuild the tab buttons (call after modifying Tabs array or WidgetSwitcher children) */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	void RebuildTabs();

	/** Set the linked Widget Switcher at runtime */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	void SetWidgetSwitcher(UWidgetSwitcher* InWidgetSwitcher);

	/** Get the number of tabs */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	int32 GetTabCount() const;

	/** Set a tab's configuration */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	void SetTabConfig(int32 Index, const FOmegaTabConfig& TabConfig);

	/** Get a tab's configuration */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	FOmegaTabConfig GetTabConfig(int32 Index) const;

	/** Add a new tab (also adds a slot to the WidgetSwitcher if linked) */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	void AddTab(const FOmegaTabConfig& TabConfig);

	/** Remove a tab by index */
	UFUNCTION(BlueprintCallable, Category = "Omega Tab Widget")
	void RemoveTab(int32 Index);

	// ========================================================================
	// UWidget Interface
	// ========================================================================

	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	/** Sync Tabs array with WidgetSwitcher children */
	void SyncTabsWithSwitcher();

	/** Build the style struct from exposed properties */
	void UpdateStyle();

	/** Handle tab selection from Slate widget */
	void HandleTabSelected(int32 TabIndex);

protected:
	/** The underlying Slate widget */
	TSharedPtr<SOmegaTabWidget> SlateTabWidget;

	/** Cached style */
	FOmegaTabWidgetStyle CachedStyle;

	/** Cached active index for pre-construct state */
	int32 CachedActiveIndex;
};