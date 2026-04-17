// OmegaTabWidget.cpp

#include "Widget/OmegaTabWidget.h"
#include "Components/WidgetSwitcherSlot.h"

#define LOCTEXT_NAMESPACE "OmegaTabWidget"

UOmegaTabWidget::UOmegaTabWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, LinkedWidgetSwitcher(nullptr)
	, Orientation(EOrientation::Orient_Horizontal)
	, IconSize(16.0f, 16.0f)
	, TabSpacing(4.0f)
	, TabPadding(8.0f, 4.0f, 8.0f, 4.0f)
	, CachedActiveIndex(0)
{
	// Initialize with default styles
	const FOmegaTabWidgetStyle& DefaultStyle = FOmegaTabWidgetStyle::GetDefault();
	TabButtonStyle = DefaultStyle.TabButtonStyle;
	ActiveTabButtonStyle = DefaultStyle.ActiveTabButtonStyle;
	TabTextStyle = DefaultStyle.TabTextStyle;
	ActiveTabTextStyle = DefaultStyle.ActiveTabTextStyle;
}

TSharedRef<SWidget> UOmegaTabWidget::RebuildWidget()
{
	UpdateStyle();
	SyncTabsWithSwitcher();

	// Get the slate widget switcher if we have a UMG one linked
	TSharedPtr<SWidgetSwitcher> SlateSwitcher;
	if (LinkedWidgetSwitcher)
	{
		SlateSwitcher = StaticCastSharedPtr<SWidgetSwitcher>(LinkedWidgetSwitcher->GetCachedWidget());
	}

	SlateTabWidget = SNew(SOmegaTabWidget)
		.Style(&CachedStyle)
		.WidgetSwitcher(SlateSwitcher)
		.TabConfigs(Tabs)
		.Orientation(Orientation)
		.OnTabSelected(FOnOmegaTabSelected::CreateUObject(this, &UOmegaTabWidget::HandleTabSelected));

	// Restore cached active index
	if (SlateTabWidget.IsValid() && CachedActiveIndex > 0)
	{
		SlateTabWidget->SetActiveTab(CachedActiveIndex);
	}

	return SlateTabWidget.ToSharedRef();
}

void UOmegaTabWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (!SlateTabWidget.IsValid())
	{
		return;
	}

	UpdateStyle();
	SlateTabWidget->SetStyle(&CachedStyle);

	// Only get slate switcher if UMG widget is fully constructed
	TSharedPtr<SWidgetSwitcher> SlateSwitcher;
	if (LinkedWidgetSwitcher && LinkedWidgetSwitcher->GetCachedWidget().IsValid())
	{
		TSharedPtr<SWidget> CachedWidget = LinkedWidgetSwitcher->GetCachedWidget();
		if (CachedWidget.IsValid())
		{
			SlateSwitcher = StaticCastSharedPtr<SWidgetSwitcher>(CachedWidget);
		}
	}
	SlateTabWidget->SetWidgetSwitcher(SlateSwitcher);

	SyncTabsWithSwitcher();
	SlateTabWidget->SetTabConfigs(Tabs);
}

void UOmegaTabWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	// Cache active index before releasing
	if (SlateTabWidget.IsValid())
	{
		CachedActiveIndex = SlateTabWidget->GetActiveTabIndex();
	}

	SlateTabWidget.Reset();
}

void UOmegaTabWidget::SyncTabsWithSwitcher()
{
	if (!LinkedWidgetSwitcher)
	{
		return;
	}

	const int32 NumChildren = LinkedWidgetSwitcher->GetChildrenCount();

	if (Tabs.Num() < NumChildren)
	{
		const int32 StartIndex = Tabs.Num();
		Tabs.SetNum(NumChildren);

		for (int32 i = StartIndex; i < NumChildren; ++i)
		{
			Tabs[i].TabName = FText::Format(LOCTEXT("DefaultTabName", "Tab {0}"), FText::AsNumber(i + 1));
		}
	}
	else if (Tabs.Num() > NumChildren)
	{
		Tabs.SetNum(NumChildren);
	}
}

void UOmegaTabWidget::UpdateStyle()
{
	CachedStyle.TabButtonStyle = TabButtonStyle;
	CachedStyle.ActiveTabButtonStyle = ActiveTabButtonStyle;
	CachedStyle.TabTextStyle = TabTextStyle;
	CachedStyle.ActiveTabTextStyle = ActiveTabTextStyle;
	CachedStyle.IconSize = IconSize;
	CachedStyle.TabSpacing = TabSpacing;
	CachedStyle.TabPadding = TabPadding;
	CachedStyle.TabBarBackground = TabBarBackground;
}

void UOmegaTabWidget::HandleTabSelected(int32 TabIndex)
{
	CachedActiveIndex = TabIndex;
	OnTabSelected.Broadcast(TabIndex);
}

int32 UOmegaTabWidget::GetActiveTabIndex() const
{
	if (SlateTabWidget.IsValid())
	{
		return SlateTabWidget->GetActiveTabIndex();
	}
	return CachedActiveIndex;
}

void UOmegaTabWidget::SetActiveTab(int32 Index)
{
	CachedActiveIndex = Index;

	if (SlateTabWidget.IsValid())
	{
		SlateTabWidget->SetActiveTab(Index);
	}

	// Also update the linked switcher
	if (LinkedWidgetSwitcher)
	{
		LinkedWidgetSwitcher->SetActiveWidgetIndex(Index);
	}
}

void UOmegaTabWidget::RebuildTabs()
{
	SyncTabsWithSwitcher();

	if (SlateTabWidget.IsValid())
	{
		SlateTabWidget->SetTabConfigs(Tabs);
	}
}

void UOmegaTabWidget::SetWidgetSwitcher(UWidgetSwitcher* InWidgetSwitcher)
{
	LinkedWidgetSwitcher = InWidgetSwitcher;

	if (SlateTabWidget.IsValid())
	{
		TSharedPtr<SWidgetSwitcher> SlateSwitcher;
		if (LinkedWidgetSwitcher)
		{
			SlateSwitcher = StaticCastSharedPtr<SWidgetSwitcher>(LinkedWidgetSwitcher->GetCachedWidget());
		}
		SlateTabWidget->SetWidgetSwitcher(SlateSwitcher);
		RebuildTabs();
	}
}

int32 UOmegaTabWidget::GetTabCount() const
{
	return Tabs.Num();
}

void UOmegaTabWidget::SetTabConfig(int32 Index, const FOmegaTabConfig& TabConfig)
{
	if (Index >= 0 && Index < Tabs.Num())
	{
		Tabs[Index] = TabConfig;

		if (SlateTabWidget.IsValid())
		{
			SlateTabWidget->SetTabConfig(Index, TabConfig);
		}
	}
}

FOmegaTabConfig UOmegaTabWidget::GetTabConfig(int32 Index) const
{
	if (Index >= 0 && Index < Tabs.Num())
	{
		return Tabs[Index];
	}
	return FOmegaTabConfig();
}

void UOmegaTabWidget::AddTab(const FOmegaTabConfig& TabConfig)
{
	Tabs.Add(TabConfig);
	RebuildTabs();
}

void UOmegaTabWidget::RemoveTab(int32 Index)
{
	if (Index >= 0 && Index < Tabs.Num())
	{
		Tabs.RemoveAt(Index);
		RebuildTabs();
	}
}

#if WITH_EDITOR
const FText UOmegaTabWidget::GetPaletteCategory()
{
	return LOCTEXT("PaletteCategory", "Common");
}
#endif

#undef LOCTEXT_NAMESPACE