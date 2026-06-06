// SOmegaTabWidget.cpp

#include "Widget/SOmegaTabWidget.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Text/STextBlock.h"

// ============================================================================
// Widget Implementation
// ============================================================================

SOmegaTabWidget::SOmegaTabWidget()
	: Style(&FOmegaTabWidgetStyle::GetDefault())
	, ActiveTabIndex(0)
	, Orientation(EOrientation::Orient_Horizontal)
	, LastKnownChildCount(0)
{
}

void SOmegaTabWidget::Construct(const FArguments& InArgs)
{
	Style = InArgs._Style;
	WidgetSwitcher = InArgs._WidgetSwitcher;
	TabConfigs = InArgs._TabConfigs;
	Orientation = InArgs._Orientation;
	OnTabSelected = InArgs._OnTabSelected;

	// Sync configs with switcher if we have one
	if (WidgetSwitcher.IsValid())
	{
		SyncTabConfigsWithSwitcher();
		ActiveTabIndex = WidgetSwitcher->GetActiveWidgetIndex();
	}

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(&Style->TabBarBackground)
		.Padding(0)
		[
			SAssignNew(TabBarContainer, SBox)
		]
	];

	RebuildTabs();
}

void SOmegaTabWidget::SyncTabConfigsWithSwitcher()
{
	// Safety check - ensure switcher is valid and has been constructed
	if (!WidgetSwitcher.IsValid() || !WidgetSwitcher->GetAllChildren())
	{
		return;
	}

	const int32 NumChildren = WidgetSwitcher->GetNumWidgets();
	
	// Sanity check for invalid values
	if (NumChildren < 0 || NumChildren > 1000)
	{
		return;
	}
	
	// Resize the array to match
	if (TabConfigs.Num() < NumChildren)
	{
		// Add default entries for new children
		const int32 StartIndex = TabConfigs.Num();
		TabConfigs.SetNum(NumChildren);
		
		for (int32 i = StartIndex; i < NumChildren; ++i)
		{
			TabConfigs[i].TabName = FText::Format(NSLOCTEXT("OmegaTab", "DefaultTabName", "Tab {0}"), FText::AsNumber(i + 1));
		}
	}
	else if (TabConfigs.Num() > NumChildren)
	{
		// Trim excess entries
		TabConfigs.SetNum(NumChildren);
	}

	LastKnownChildCount = NumChildren;
}

void SOmegaTabWidget::RebuildTabs()
{
	if (!TabBarContainer.IsValid())
	{
		return;
	}

	// Sync with switcher first
	SyncTabConfigsWithSwitcher();

	// Build the tab buttons based on orientation
	if (Orientation == EOrientation::Orient_Horizontal)
	{
		TSharedPtr<SHorizontalBox> HBox;
		
		TabBarContainer->SetContent(
			SNew(SScrollBox)
			.Orientation(EOrientation::Orient_Horizontal)
			.ScrollBarVisibility(EVisibility::Collapsed)
			+SScrollBox::Slot()
			[
				SAssignNew(HBox, SHorizontalBox)
			]
		);

		for (int32 i = 0; i < TabConfigs.Num(); ++i)
		{
			HBox->AddSlot()
			.AutoWidth()
			.Padding(i > 0 ? FMargin(Style->TabSpacing, 0, 0, 0) : FMargin(0))
			[
				BuildTabButton(i)
			];
		}
	}
	else
	{
		TSharedPtr<SVerticalBox> VBox;
		
		TabBarContainer->SetContent(
			SNew(SScrollBox)
			.Orientation(EOrientation::Orient_Vertical)
			.ScrollBarVisibility(EVisibility::Collapsed)
			+SScrollBox::Slot()
			[
				SAssignNew(VBox, SVerticalBox)
			]
		);

		for (int32 i = 0; i < TabConfigs.Num(); ++i)
		{
			VBox->AddSlot()
			.AutoHeight()
			.Padding(i > 0 ? FMargin(0, Style->TabSpacing, 0, 0) : FMargin(0))
			[
				BuildTabButton(i)
			];
		}
	}
}

TSharedRef<SWidget> SOmegaTabWidget::BuildTabButton(int32 TabIndex)
{
	const bool bIsActive = (TabIndex == ActiveTabIndex);
	const FOmegaTabConfig& Config = TabConfigs[TabIndex];
	const FButtonStyle& ButtonStyle = bIsActive ? Style->ActiveTabButtonStyle : Style->TabButtonStyle;
	const FTextBlockStyle& TextStyle = bIsActive ? Style->ActiveTabTextStyle : Style->TabTextStyle;

	// Determine if we have an icon
	const bool bHasIcon = Config.TabIcon.GetResourceObject() != nullptr || 
						  Config.TabIcon.GetResourceName() != NAME_None;

	TSharedPtr<SHorizontalBox> ButtonContent;

	TSharedRef<SButton> Button = SNew(SButton)
		.ButtonStyle(&ButtonStyle)
		.ContentPadding(Style->TabPadding)
		.OnClicked(this, &SOmegaTabWidget::OnTabClicked, TabIndex)
		[
			SAssignNew(ButtonContent, SHorizontalBox)
		];

	// Add icon if present
	if (bHasIcon)
	{
		ButtonContent->AddSlot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(0, 0, Config.TabName.IsEmpty() ? 0 : 4.0f, 0)
		[
			SNew(SImage)
			.Image(&Config.TabIcon)
			.DesiredSizeOverride(Style->IconSize)
		];
	}

	// Add text if present
	if (!Config.TabName.IsEmpty())
	{
		ButtonContent->AddSlot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.TextStyle(&TextStyle)
			.Text(Config.TabName)
		];
	}

	return Button;
}

FReply SOmegaTabWidget::OnTabClicked(int32 TabIndex)
{
	SetActiveTab(TabIndex);
	return FReply::Handled();
}

void SOmegaTabWidget::SetActiveTab(int32 Index)
{
	if (Index < 0 || Index >= TabConfigs.Num())
	{
		return;
	}

	if (ActiveTabIndex != Index)
	{
		ActiveTabIndex = Index;

		// Update the widget switcher
		if (WidgetSwitcher.IsValid())
		{
			WidgetSwitcher->SetActiveWidgetIndex(Index);
		}

		// Rebuild to update visual state
		RebuildTabs();

		// Fire delegate
		OnTabSelected.ExecuteIfBound(Index);
	}
}

void SOmegaTabWidget::SetWidgetSwitcher(TSharedPtr<SWidgetSwitcher> InWidgetSwitcher)
{
	WidgetSwitcher = InWidgetSwitcher;
	
	if (WidgetSwitcher.IsValid())
	{
		ActiveTabIndex = FMath::Clamp(ActiveTabIndex, 0, FMath::Max(0, WidgetSwitcher->GetNumWidgets() - 1));
	}
	
	RebuildTabs();
}

void SOmegaTabWidget::SetTabConfigs(const TArray<FOmegaTabConfig>& InConfigs)
{
	TabConfigs = InConfigs;
	RebuildTabs();
}

void SOmegaTabWidget::SetTabConfig(int32 Index, const FOmegaTabConfig& Config)
{
	if (Index >= 0 && Index < TabConfigs.Num())
	{
		TabConfigs[Index] = Config;
		RebuildTabs();
	}
}

void SOmegaTabWidget::SetStyle(const FOmegaTabWidgetStyle* InStyle)
{
	if (InStyle)
	{
		Style = InStyle;
		RebuildTabs();
	}
}