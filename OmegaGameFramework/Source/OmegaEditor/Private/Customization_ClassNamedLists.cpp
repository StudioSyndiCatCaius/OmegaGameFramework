// Customization_ClassNamedLists.cpp
#include "Customization_ClassNamedLists.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "IPropertyUtilities.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Styling/AppStyle.h"
#include "OmegaSettings.h"
#include "OmegaGameCore.h"
#include "Interfaces/I_NamedLists.h"
#include "Types/Struct_CustomNamedList.h"


TSharedRef<IPropertyTypeCustomization> FCustomization_ClassNamedLists::MakeInstance()
{
    return MakeShareable(new FCustomization_ClassNamedLists);
}

void FCustomization_ClassNamedLists::CustomizeHeader(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    FDetailWidgetRow& HeaderRow,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    // Custom styled header
    HeaderRow
    .NameContent()
    [
        SNew(SBox)
        .Padding(FMargin(0, 4, 0, 4))
        [
            SNew(STextBlock)
            .Text(StructPropertyHandle->GetPropertyDisplayName().ToUpper())
            .Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
            .ColorAndOpacity(FLinearColor(0.8f, 0.9f, 1.0f, 1.0f)) // Light blue tint
            
        ]
    ]
    .ValueContent()
    [
        SNullWidget::NullWidget // Empty value content
    ];
}

void FCustomization_ClassNamedLists::CustomizeChildren(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    IDetailChildrenBuilder& StructBuilder,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    // Get the map property handle
    MapPropertyHandle = StructPropertyHandle->GetChildHandle(TEXT("CustomNamedList"));
    
    if (!MapPropertyHandle.IsValid())
    {
        return;
    }

    // Get the outer object
    TArray<UObject*> OuterObjects;
    StructPropertyHandle->GetOuterObjects(OuterObjects);
    
    if (OuterObjects.Num() == 0 || !OuterObjects[0])
    {
        return;
    }

    UObject* OuterObject = OuterObjects[0];

    // Get the list of ListIDs from settings
    TArray<FName> Lists;
    if (OuterObject->GetClass()->ImplementsInterface(UDataInterface_NamedLists::StaticClass()))
    {
        Lists=IDataInterface_NamedLists::Execute_Override_ObjectLists(OuterObject);
    }
    if (Lists.Num() == 0)
    {
        Lists=GetMutableDefault<UOmegaSettings>()->GetGameCore()->CustomList_GetListFromObject(OuterObject);
    }

    // Create a darker background container for all dropdowns
    StructBuilder.AddCustomRow(FText::GetEmpty())
    .WholeRowContent()
    [
        SNew(SBorder)
        .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryMiddle"))
        .BorderBackgroundColor(FLinearColor(0.03f, 0.03f, 0.03f, 1.0f)) // Dark background
        .Padding(FMargin(8.0f, 6.0f, 8.0f, 6.0f))
        [
            SNew(SVerticalBox)
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                CreateDropdownList(Lists, StructPropertyHandle)
            ]
        ]
    ];
}

TSharedRef<SWidget> FCustomization_ClassNamedLists::CreateDropdownList(
    const TArray<FName>& Lists,
    TSharedRef<IPropertyHandle> StructPropertyHandle)
{
    TSharedRef<SVerticalBox> VerticalBox = SNew(SVerticalBox);

    // Create a dropdown for each ListID
    for (int32 i = 0; i < Lists.Num(); ++i)
    {
        const FName& ListID = Lists[i];
        
        VerticalBox->AddSlot()
        .AutoHeight()
        .Padding(FMargin(0.0f, i > 0 ? 4.0f : 0.0f, 0.0f, 0.0f)) // Add spacing between rows
        [
            SNew(SHorizontalBox)
            
            // Label
            + SHorizontalBox::Slot()
            .AutoWidth()
            .VAlign(VAlign_Center)
            .Padding(FMargin(0.0f, 0.0f, 5.0f, 0.0f))
            [
                SNew(SBox)
                .MinDesiredWidth(120.0f)
                [
                    SNew(STextBlock)
                    .Text(FText::FromName(ListID))
                    .Font(IDetailLayoutBuilder::GetDetailFont())
                ]
            ]
            
            // Dropdown
            + SHorizontalBox::Slot()
            .FillWidth(1.0f)
            .VAlign(VAlign_Center)
            [
                CreateDropdownForList(ListID, StructPropertyHandle)
            ]
        ];
    }

    // If no lists, show a message
    if (Lists.Num() == 0)
    {
        float dropdown_value=0.2f;
        VerticalBox->AddSlot()
        .AutoHeight()
        .Padding(4.0f)
        [
            SNew(STextBlock)
            .Text(NSLOCTEXT("ClassNamedLists", "NoLists", "No lists available for this object"))
            .Font(IDetailLayoutBuilder::GetDetailFont())
            .ColorAndOpacity(FLinearColor(dropdown_value, dropdown_value, dropdown_value, 1.0f))
        ];
    }

    return VerticalBox;
}

TSharedRef<SWidget> FCustomization_ClassNamedLists::CreateDropdownForList(
    FName ListID, 
    TSharedRef<IPropertyHandle> StructPropertyHandle)
{
    return SNew(SComboButton)
        .OnGetMenuContent_Lambda([this, ListID, StructPropertyHandle]() -> TSharedRef<SWidget>
        {
            // Get options for this specific ListID
            TArray<FName> Options=GetMutableDefault<UOmegaSettings>()->GetGameCore()->CustomList_GetOptions(ListID);

            // Build menu
            FMenuBuilder MenuBuilder(true, nullptr);

            if (Options.Num() == 0)
            {
                MenuBuilder.AddMenuEntry(
                    NSLOCTEXT("ClassNamedLists", "None", "(None)"),
                    FText::GetEmpty(),
                    FSlateIcon(),
                    FUIAction()
                );
            }
            else
            {
                for (const FName& OptionName : Options)
                {
                    MenuBuilder.AddMenuEntry(
                        FText::FromName(OptionName),
                        FText::GetEmpty(),
                        FSlateIcon(),
                        FUIAction(
                            FExecuteAction::CreateLambda([this, ListID, OptionName, StructPropertyHandle]()
                            {
                                SetOptionForList(ListID, OptionName, StructPropertyHandle);
                            })
                        )
                    );
                }
            }

            return MenuBuilder.MakeWidget();
        })
        .ButtonContent()
        [
            SNew(STextBlock)
            .Text_Lambda([this, ListID, StructPropertyHandle]() -> FText
            {
                FName CurrentValue = GetOptionForList(ListID, StructPropertyHandle);
                return FText::FromName(CurrentValue);
            })
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ];
}

void FCustomization_ClassNamedLists::SetOptionForList(
    FName ListID, 
    FName OptionValue, 
    TSharedRef<IPropertyHandle> StructPropertyHandle)
{
    if (!MapPropertyHandle.IsValid())
    {
        return;
    }

    // Access the raw data
    TArray<void*> RawData;
    MapPropertyHandle->AccessRawData(RawData);
    
    if (RawData.Num() == 0)
    {
        return;
    }

    TMap<FName, FOmegaCustomNamedList>* MapPtr = static_cast<TMap<FName, FOmegaCustomNamedList>*>(RawData[0]);
    
    if (MapPtr)
    {
        // Find or create the entry for this ListID
        FOmegaCustomNamedList& Entry = MapPtr->FindOrAdd(ListID);
        Entry.ListID = ListID;
        Entry.Option = OptionValue;
        
        // Notify that the property has changed
        MapPropertyHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
    }
}

FName FCustomization_ClassNamedLists::GetOptionForList(
    FName ListID, 
    TSharedRef<IPropertyHandle> StructPropertyHandle) const
{
    if (!MapPropertyHandle.IsValid())
    {
        return NAME_None;
    }

    // Access the raw data
    TArray<const void*> RawData;
    MapPropertyHandle->AccessRawData(RawData);
    
    if (RawData.Num() == 0)
    {
        return NAME_None;
    }

    const TMap<FName, FOmegaCustomNamedList>* MapPtr = static_cast<const TMap<FName, FOmegaCustomNamedList>*>(RawData[0]);
    
    if (MapPtr)
    {
        const FOmegaCustomNamedList* Entry = MapPtr->Find(ListID);
        if (Entry)
        {
            return Entry->Option;
        }
    }

    return NAME_None;
}