// Customization_CustomNamedList.cpp
#include "Customization_CustomNamedList.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "IPropertyUtilities.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "OmegaSettings.h"
#include "OmegaGameCore.h"
#include "Types/Struct_CustomNamedList.h"

TSharedRef<IPropertyTypeCustomization> FCustomization_CustomNamedList::MakeInstance()
{
    return MakeShareable(new FCustomization_CustomNamedList);
}

void FCustomization_CustomNamedList::CustomizeHeader(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    FDetailWidgetRow& HeaderRow,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    // Get property handles
    ListIDPropertyHandle = StructPropertyHandle->GetChildHandle(TEXT("ListID"));
    OptionPropertyHandle = StructPropertyHandle->GetChildHandle(TEXT("Option"));

    if (!ListIDPropertyHandle.IsValid() || !OptionPropertyHandle.IsValid())
    {
        return;
    }

    // Show only the Option dropdown in the header
    HeaderRow
    .NameContent()
    [
        StructPropertyHandle->CreatePropertyNameWidget()
    ]
    .ValueContent()
    .MinDesiredWidth(125.0f)
    .MaxDesiredWidth(400.0f)
    [
        SNew(SComboButton)
        .OnGetMenuContent_Lambda([this]() -> TSharedRef<SWidget>
        {
            // Get the current ListID value
            FName CurrentListID = NAME_None;
            if (ListIDPropertyHandle.IsValid())
            {
                ListIDPropertyHandle->GetValue(CurrentListID);
            }

            // Get options from settings
            TArray<FName> Options=GetMutableDefault<UOmegaSettings>()->GetGameCore()->CustomList_GetOptions(CurrentListID);

            // Build menu
            FMenuBuilder MenuBuilder(true, nullptr);

            if (Options.Num() == 0)
            {
                MenuBuilder.AddMenuEntry(
                    NSLOCTEXT("CustomNamedList", "None", "(None)"),
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
                            FExecuteAction::CreateLambda([this, OptionName]()
                            {
                                if (OptionPropertyHandle.IsValid())
                                {
                                    OptionPropertyHandle->SetValue(OptionName);
                                }
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
            .Text_Lambda([this]() -> FText
            {
                if (OptionPropertyHandle.IsValid())
                {
                    FName CurrentValue = NAME_None;
                    OptionPropertyHandle->GetValue(CurrentValue);
                    return FText::FromName(CurrentValue);
                }
                return NSLOCTEXT("CustomNamedList", "None", "None");
            })
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ]
    ];
}

void FCustomization_CustomNamedList::CustomizeChildren(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    IDetailChildrenBuilder& StructBuilder,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    // Don't add any children - everything is in the header
    // This prevents the struct from being expandable
}