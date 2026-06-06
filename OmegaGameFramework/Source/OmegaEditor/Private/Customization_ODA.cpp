
#include "Customization_ODA.h"
#include "Misc/GeneralDataObject.h"


#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailPropertyRow.h"
#include "PropertyHandle.h"

#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/Text/STextBlock.h"
#include "Styling/AppStyle.h"

#define LOCTEXT_NAMESPACE "OmegaDataAssetCustomization"

namespace OmegaCustomization
{
    static const FString GeneralCategory   = TEXT("General");
    static const FString ColumnsCategory   = TEXT("OmegaTwoColumnLayout");
    static const float   ColumnPadding     = 8.f;
    static const float   CategoryHeaderPad = 4.f;
    static const float   PropertyNameWidth = 160.f;
}

TSharedRef<IDetailCustomization> FOmegaDataAssetCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaDataAssetCustomization());
}

void FOmegaDataAssetCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
    using namespace OmegaCustomization;

    // ── FIX 1: Use the ACTUAL runtime class of the object being inspected,
    //           not the base UOmegaDataAsset class. This is what makes child
    //           classes (OAsset_CommonItem etc.) work correctly.
    TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
    DetailBuilder.GetObjectsBeingCustomized(ObjectsBeingCustomized);

    if (ObjectsBeingCustomized.IsEmpty()) return;

    UObject* FirstObject = ObjectsBeingCustomized[0].Get();
    if (!FirstObject) return;

    UClass* ActualClass = FirstObject->GetClass();

    // ── Collect every editable property, grouped by leaf category name ───────

    TMap<FString, TArray<TSharedRef<IPropertyHandle>>> CategoryMap;
    TArray<FString> CategoryOrder;

    for (TFieldIterator<FProperty> It(ActualClass, EFieldIterationFlags::IncludeSuper); It; ++It)
    {
        FProperty* Prop = *It;

        if (!Prop->HasAnyPropertyFlags(CPF_Edit))                        continue;
        if (Prop->HasAnyPropertyFlags(CPF_Deprecated))                   continue;

        // ── FIX 2: GetProperty needs the correct outer class.
        //           Pass nullptr so it searches the full class hierarchy.
        TSharedRef<IPropertyHandle> Handle =
            DetailBuilder.GetProperty(Prop->GetFName(), nullptr);

        if (!Handle->IsValidHandle()) continue;

        FString Category = NormaliseCategory(Prop->GetMetaData(TEXT("Category")));

        if (!CategoryMap.Contains(Category))
        {
            CategoryOrder.Add(Category);
        }
        CategoryMap.FindOrAdd(Category).Add(Handle);
    }

    // ── Pin "General" to the top in its native UE form ───────────────────────

    if (CategoryMap.Contains(GeneralCategory))
    {
        DetailBuilder.EditCategory(*GeneralCategory).SetSortOrder(0);
    }

    // ── Gather all non-General categories and sort them ──────────────────────

    TArray<FString> OtherCategories;
    for (const FString& Cat : CategoryOrder)
    {
        if (!Cat.Equals(GeneralCategory, ESearchCase::IgnoreCase))
        {
            OtherCategories.Add(Cat);
        }
    }
    OtherCategories.Sort();

    if (OtherCategories.IsEmpty()) return;

    // ── FIX 3: Hide non-General categories BEFORE building the replacement
    //           widget. HideCategory must be called with the EXACT category
    //           string that UE registered — use EditCategory first to ensure
    //           it exists, then hide it. ────────────────────────────────────

    for (const FString& Cat : OtherCategories)
    {
        DetailBuilder.HideCategory(*Cat);
    }

    // ── Distribute categories alternately into left / right columns ───────────

    TArray<FString> LeftCats, RightCats;
    for (int32 i = 0; i < OtherCategories.Num(); ++i)
    {
        (i % 2 == 0 ? LeftCats : RightCats).Add(OtherCategories[i]);
    }

    // ── Inject the two-column Slate widget beneath General ───────────────────

    IDetailCategoryBuilder& ColumnsCat = DetailBuilder.EditCategory(
        *ColumnsCategory,
        FText::GetEmpty(),
        ECategoryPriority::Default);

    ColumnsCat.SetSortOrder(1);

    ColumnsCat.AddCustomRow(FText::GetEmpty())
    .WholeRowContent()
    .VAlign(VAlign_Fill)
    [
        BuildTwoColumnWidget(CategoryMap, LeftCats, RightCats)
    ];
}

// ─── helpers (unchanged from before) ─────────────────────────────────────────

FString FOmegaDataAssetCustomization::NormaliseCategory(const FString& RawCategory)
{
    if (RawCategory.IsEmpty()) return TEXT("Uncategorized");

    int32 LastPipe = INDEX_NONE;
    if (RawCategory.FindLastChar(TEXT('|'), LastPipe))
    {
        return RawCategory.Mid(LastPipe + 1).TrimStartAndEnd();
    }
    return RawCategory.TrimStartAndEnd();
}

TSharedRef<SWidget> FOmegaDataAssetCustomization::BuildTwoColumnWidget(
    const TMap<FString, TArray<TSharedRef<IPropertyHandle>>>& CategoryMap,
    const TArray<FString>& LeftCategories,
    const TArray<FString>& RightCategories)
{
    using namespace OmegaCustomization;

    return SNew(SSplitter)
        .Orientation(Orient_Horizontal)
        .PhysicalSplitterHandleSize(2.f)

        + SSplitter::Slot().Value(0.5f)
        [
            SNew(SBox).Padding(FMargin(0.f, 0.f, ColumnPadding * 0.5f, 0.f))
            [ BuildColumn(LeftCategories, CategoryMap) ]
        ]

        + SSplitter::Slot().Value(0.5f)
        [
            SNew(SBox).Padding(FMargin(ColumnPadding * 0.5f, 0.f, 0.f, 0.f))
            [ BuildColumn(RightCategories, CategoryMap) ]
        ];
}

TSharedRef<SWidget> FOmegaDataAssetCustomization::BuildColumn(
    const TArray<FString>& Categories,
    const TMap<FString, TArray<TSharedRef<IPropertyHandle>>>& CategoryMap)
{
    TSharedRef<SVerticalBox> ColumnBox = SNew(SVerticalBox);

    for (const FString& Cat : Categories)
    {
        const TArray<TSharedRef<IPropertyHandle>>* Handles = CategoryMap.Find(Cat);
        if (!Handles || Handles->IsEmpty()) continue;

        ColumnBox->AddSlot()
        .AutoHeight()
        .Padding(0.f, 4.f, 0.f, 8.f)
        [ BuildCategoryBlock(Cat, *Handles) ];
    }

    return ColumnBox;
}

TSharedRef<SWidget> FOmegaDataAssetCustomization::BuildCategoryBlock(
    const FString& CategoryName,
    const TArray<TSharedRef<IPropertyHandle>>& Handles)
{
    using namespace OmegaCustomization;

    TSharedRef<SVerticalBox> PropertiesBox = SNew(SVerticalBox);

    for (const TSharedRef<IPropertyHandle>& Handle : Handles)
    {
        if (Handle->GetProperty() &&
            Handle->GetProperty()->HasMetaData(TEXT("HideInDetailPanel")))
        {
            continue;
        }

        PropertiesBox->AddSlot()
        .AutoHeight()
        .Padding(0.f, 1.f)
        [ BuildPropertyRow(Handle) ];
    }

    return SNew(SVerticalBox)

        + SVerticalBox::Slot().AutoHeight()
        [
            SNew(SBorder)
            .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryTop"))
            .Padding(FMargin(CategoryHeaderPad, 3.f))
            .VAlign(VAlign_Center)
            [
                SNew(STextBlock)
                .Text(FText::FromString(CategoryName))
                .TextStyle(FAppStyle::Get(), "DetailsView.CategoryTextStyle")
            ]
        ]

        + SVerticalBox::Slot().AutoHeight()
        [
            SNew(SSeparator).Thickness(1.f)
            .SeparatorImage(FAppStyle::GetBrush("DetailsView.CategoryMiddle"))
        ]

        + SVerticalBox::Slot().AutoHeight()
        [
            SNew(SBorder)
            .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryMiddle"))
            .Padding(FMargin(0.f, 1.f))
            [ PropertiesBox ]
        ]

        + SVerticalBox::Slot().AutoHeight()
        [
            SNew(SBorder)
            .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryBottom"))
            .Padding(FMargin(0.f, 1.f))
        ];
}

TSharedRef<SWidget> FOmegaDataAssetCustomization::BuildPropertyRow(
    const TSharedRef<IPropertyHandle>& Handle)
{
    using namespace OmegaCustomization;

    return SNew(SHorizontalBox)

        + SHorizontalBox::Slot()
        .AutoWidth()
        .VAlign(VAlign_Center)
        .Padding(2.f, 1.f)
        [
            SNew(SBox).WidthOverride(PropertyNameWidth)
            [ Handle->CreatePropertyNameWidget() ]
        ]

        + SHorizontalBox::Slot()
        .FillWidth(1.f)
        .VAlign(VAlign_Center)
        .Padding(2.f, 1.f)
        [ Handle->CreatePropertyValueWidget() ];
}

#undef LOCTEXT_NAMESPACE