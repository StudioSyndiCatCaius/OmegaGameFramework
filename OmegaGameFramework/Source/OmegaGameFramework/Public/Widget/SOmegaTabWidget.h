// SOmegaTabWidget.h
// Custom Slate tab widget that syncs with a Widget Switcher

#pragma once

#include "CoreMinimal.h"
#include "OmegaTabWidgetTypes.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SWidgetSwitcher.h"

// ============================================================================
// The Slate Widget
// ============================================================================

DECLARE_DELEGATE_OneParam(FOnOmegaTabSelected, int32 /* TabIndex */);

class SOmegaTabWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SOmegaTabWidget)
		: _Style(&FOmegaTabWidgetStyle::GetDefault())
		, _Orientation(EOrientation::Orient_Horizontal)
	{}
		// The style to use
		SLATE_STYLE_ARGUMENT(FOmegaTabWidgetStyle, Style)

		// The widget switcher to control
		SLATE_ARGUMENT(TSharedPtr<SWidgetSwitcher>, WidgetSwitcher)

		// Initial tab configurations (optional - will auto-generate if empty)
		SLATE_ARGUMENT(TArray<FOmegaTabConfig>, TabConfigs)

		// Tab bar orientation
		SLATE_ARGUMENT(EOrientation, Orientation)

		// Called when a tab is selected
		SLATE_EVENT(FOnOmegaTabSelected, OnTabSelected)

	SLATE_END_ARGS()

	SOmegaTabWidget();

	void Construct(const FArguments& InArgs);

	// Manually trigger a rebuild of the tab buttons
	void RebuildTabs();

	// Set a new widget switcher to link to
	void SetWidgetSwitcher(TSharedPtr<SWidgetSwitcher> InWidgetSwitcher);

	// Get the current widget switcher
	TSharedPtr<SWidgetSwitcher> GetWidgetSwitcher() const { return WidgetSwitcher; }

	// Set tab configurations (array will be resized to match switcher children)
	void SetTabConfigs(const TArray<FOmegaTabConfig>& InConfigs);

	// Get the current tab configurations
	const TArray<FOmegaTabConfig>& GetTabConfigs() const { return TabConfigs; }

	// Set a single tab's configuration
	void SetTabConfig(int32 Index, const FOmegaTabConfig& Config);

	// Get the currently active tab index
	int32 GetActiveTabIndex() const { return ActiveTabIndex; }

	// Set the active tab (also updates the widget switcher)
	void SetActiveTab(int32 Index);

	// Update the style
	void SetStyle(const FOmegaTabWidgetStyle* InStyle);

protected:
	// Build a single tab button widget
	TSharedRef<SWidget> BuildTabButton(int32 TabIndex);

	// Handle tab button click
	FReply OnTabClicked(int32 TabIndex);

	// Synchronize tab configs with widget switcher children count
	void SyncTabConfigsWithSwitcher();

private:
	// The linked widget switcher
	TSharedPtr<SWidgetSwitcher> WidgetSwitcher;

	// Container for tab buttons
	TSharedPtr<SBox> TabBarContainer;

	// The current style
	const FOmegaTabWidgetStyle* Style;

	// Tab configurations
	TArray<FOmegaTabConfig> TabConfigs;

	// Currently active tab
	int32 ActiveTabIndex;

	// Tab bar orientation
	EOrientation Orientation;

	// Callback for tab selection
	FOnOmegaTabSelected OnTabSelected;

	// Cache of last known child count for change detection
	int32 LastKnownChildCount;
};