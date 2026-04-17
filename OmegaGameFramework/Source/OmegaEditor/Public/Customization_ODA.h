#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class IDetailLayoutBuilder;
class IPropertyHandle;

/**
 * Custom Details Customization for UOmegaDataAsset.
 *
 * Layout:
 *   ┌────────────────────────────────────────────┐
 *   │  [General Category — normal detail rows]   │
 *   ├───────────────────┬────────────────────────┤
 *   │  Left Column      │  Right Column          │
 *   │  ─ CategoryA      │  ─ CategoryB           │
 *   │    prop / value   │    prop / value        │
 *   │  ─ CategoryC      │  ─ CategoryD           │
 *   │    ...            │    ...                 │
 *   └───────────────────┴────────────────────────┘
 */
class FOmegaDataAssetCustomization : public IDetailCustomization
{
public:
    static TSharedRef<IDetailCustomization> MakeInstance();

    //~ IDetailCustomization
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
    /** Normalises a raw category metadata string to its leaf name.
     *  e.g. "OmegaDataAsset|Combat|Advanced" → "Advanced" */
    static FString NormaliseCategory(const FString& RawCategory);

    /** Builds the full two-column Slate widget for all non-General categories. */
    TSharedRef<SWidget> BuildTwoColumnWidget(
        const TMap<FString, TArray<TSharedRef<IPropertyHandle>>>& CategoryMap,
        const TArray<FString>& LeftCategories,
        const TArray<FString>& RightCategories);

    /** Builds one column (a vertical list of category blocks). */
    TSharedRef<SWidget> BuildColumn(
        const TArray<FString>& Categories,
        const TMap<FString, TArray<TSharedRef<IPropertyHandle>>>& CategoryMap);

    /** Builds a single category block: a styled header + property rows. */
    TSharedRef<SWidget> BuildCategoryBlock(
        const FString& CategoryName,
        const TArray<TSharedRef<IPropertyHandle>>& Handles);

    /** Builds one name-label | value-widget row for a property. */
    TSharedRef<SWidget> BuildPropertyRow(const TSharedRef<IPropertyHandle>& Handle);
};