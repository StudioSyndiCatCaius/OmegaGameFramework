// OmegaTabWidgetTypes.cpp

#include "Widget/OmegaTabWidgetTypes.h"
#include "Styling/CoreStyle.h"

// ============================================================================
// Style Implementation
// ============================================================================

const FName FOmegaTabWidgetStyle::TypeName(TEXT("FOmegaTabWidgetStyle"));

FOmegaTabWidgetStyle::FOmegaTabWidgetStyle()
	: IconSize(16.0f, 16.0f)
	, TabSpacing(4.0f)
	, TabPadding(8.0f, 4.0f, 8.0f, 4.0f)
{
	// Initialize with core style defaults
	TabButtonStyle = FCoreStyle::Get().GetWidgetStyle<FButtonStyle>("Button");
	ActiveTabButtonStyle = FCoreStyle::Get().GetWidgetStyle<FButtonStyle>("Button");
	TabTextStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalText");
	ActiveTabTextStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalText");
}

void FOmegaTabWidgetStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	TabButtonStyle.GetResources(OutBrushes);
	ActiveTabButtonStyle.GetResources(OutBrushes);
	OutBrushes.Add(&TabBarBackground);
}

const FOmegaTabWidgetStyle& FOmegaTabWidgetStyle::GetDefault()
{
	static FOmegaTabWidgetStyle Default;
	return Default;
}
