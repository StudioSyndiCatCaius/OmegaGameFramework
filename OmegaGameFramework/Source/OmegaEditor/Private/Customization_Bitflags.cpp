// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Customization_Bitflags.h"// OmegaBitflagsCustomization.cpp

#include "DetailLayoutBuilder.h"
#include "Interfaces/I_BitFlag.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Text/STextBlock.h"
#include "OmegaSettings.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Text/STextBlock.h"
#include "OmegaSettings_Global.h"
#include "Types/Struct_CustomNamedList.h"


// ==================================================================================================================
// BIT FLAGS
// ==================================================================================================================

TSharedRef<IPropertyTypeCustomization> FOmegaBitflagsCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaBitflagsCustomization());
}

UClass* FOmegaBitflagsCustomization::GetOwnerClass(TSharedRef<IPropertyHandle> PropertyHandle) const
{
    TArray<UObject*> OuterObjects;
    PropertyHandle->GetOuterObjects(OuterObjects);
    
    if (OuterObjects.Num() > 0 && OuterObjects[0])
    {
        return OuterObjects[0]->GetClass();
    }
    
    return nullptr;
}

void FOmegaBitflagsCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
    // Get property handles
    BitmaskPropertyHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaBitflagsBase, Bitmask));
    BitEnumsPropertyHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaBitflagsBase, BitEnums));
    StructPropertyHandle = PropertyHandle;

    // Get the owner class
    CachedOwnerClass = GetOwnerClass(PropertyHandle);

    HeaderRow
    .NameContent()
    [
        PropertyHandle->CreatePropertyNameWidget()
    ]
    .ValueContent()
    [
        SNew(STextBlock)
        .Text(this, &FOmegaBitflagsCustomization::GetHeaderValueText)
        .Font(IPropertyTypeCustomizationUtils::GetRegularFont())
    ];
}

void FOmegaBitflagsCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
    if (!BitmaskPropertyHandle.IsValid() || !BitEnumsPropertyHandle.IsValid())
    {
        return;
    }

    if (!CachedOwnerClass)
    {
        ChildBuilder.AddCustomRow(FText::FromString("Error"))
        .WholeRowContent()
        [
            SNew(STextBlock)
            .Text(FText::FromString("Could not determine owner class"))
        ];
        return;
    }

    // Get settings
    const UOmegaSettings* Settings = GetDefault<UOmegaSettings>();
    if (!Settings)
    {
        return;
    }

    // Get the editor data for this class
    const FOmegaBitmaskEditorData* EditorData = Settings->GetEditorDataForClass(CachedOwnerClass);
    
    if (!EditorData)
    {
        ChildBuilder.AddCustomRow(FText::FromString("No Configuration"))
        .WholeRowContent()
        [
            SNew(STextBlock)
            .Text(FText::FromString(FString::Printf(TEXT("No bitflag configuration found for class: %s\nAdd it in Project Settings -> Omega Settings"), *CachedOwnerClass->GetName())))
            .AutoWrapText(true)
        ];
        return;
    }

    // Define colors for sections
    FLinearColor BitflagsColor = FLinearColor(0.8f, 0.2f, 0.2f, 0.6f); // Red tint
    FLinearColor BitEnumsColor = FLinearColor(0.2f, 0.6f, 0.8f, 0.6f); // Blue/Cyan tint

    // === BITFLAGS SECTION ===
    if (EditorData->Bitflags.Num() > 0)
    {
        // Add section header with color
        ChildBuilder.AddCustomRow(FText::FromString("Bitflags"))
        .WholeRowContent()
        [
            SNew(SBorder)
            .BorderBackgroundColor(BitflagsColor)
            .Padding(FMargin(4, 2))
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("🔴 BIT_FLAGS")))
                .Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
                .ColorAndOpacity(FLinearColor(1,0.5,0.5,1))
            ]
            .VAlign(VAlign_Fill)
            .ColorAndOpacity(FLinearColor(1,0.5,0.5,1))
        ];

        // Add each bitflag
        for (int32 i = 0; i < EditorData->Bitflags.Num() && i < 32; ++i)
        {
            const FOmegaBitmaskEditorEntry& Entry = EditorData->Bitflags[i];
            
            // Skip if the title is empty
            if (Entry.Title.IsEmpty() || Entry.Title.ToString().TrimStartAndEnd().IsEmpty())
            {
                continue;
            }

            FText DisplayName = FText::FromString(FString::Printf(TEXT("[%d] %s"), i, *Entry.Title.ToString()));
            FText DisplayDesc = Entry.Description;

            ChildBuilder.AddCustomRow(DisplayName)
            .NameContent()
            [
                SNew(SBorder)
                .BorderBackgroundColor(FLinearColor(BitflagsColor.R, BitflagsColor.G, BitflagsColor.B, 0.15f))
                .Padding(FMargin(20, 0))
                [
                    SNew(STextBlock)
                    .Text(DisplayName)
                    .Font(IPropertyTypeCustomizationUtils::GetRegularFont())
                    .ToolTipText(DisplayDesc)
                ]
            ]
            .ValueContent()
            [
                SNew(SCheckBox)
                .IsChecked(this, &FOmegaBitflagsCustomization::IsChecked, i)
                .OnCheckStateChanged(this, &FOmegaBitflagsCustomization::OnCheckStateChanged, i)
            ];
        }
    }

    // === BITENUMS SECTION ===
    if (EditorData->BitEnums.Num() > 0)
    {
        // Add section header with color
        ChildBuilder.AddCustomRow(FText::FromString("BitEnums"))
        .WholeRowContent()
        [
            SNew(SBorder)
            .BorderBackgroundColor(BitEnumsColor)
            .Padding(FMargin(4, 2))
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("🔵 BIT_ENUMS")))
                .Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
                .ColorAndOpacity(FLinearColor(0.5,1,0.5,1))
            ]
            .VAlign(VAlign_Fill)
            .ColorAndOpacity(FLinearColor(0.5,1,0.5,1))
        ];

        // Add each bitenum
        for (int32 i = 0; i < EditorData->BitEnums.Num() && i < 16; ++i)
        {
            const FOmegaBitmaskEditorEnumData& EnumData = EditorData->BitEnums[i];
            
            // Skip if the title is empty
            if (EnumData.Title.IsEmpty() || EnumData.Title.ToString().TrimStartAndEnd().IsEmpty())
            {
                continue;
            }

            FText DisplayName = FText::FromString(FString::Printf(TEXT("[%d] %s"), i, *EnumData.Title.ToString()));
            FText DisplayDesc = EnumData.Description;

            ChildBuilder.AddCustomRow(DisplayName)
            .NameContent()
            [
                SNew(SBorder)
                .BorderBackgroundColor(FLinearColor(BitEnumsColor.R, BitEnumsColor.G, BitEnumsColor.B, 0.15f))
                .Padding(FMargin(20, 0))
                [
                    SNew(STextBlock)
                    .Text(DisplayName)
                    .Font(IPropertyTypeCustomizationUtils::GetRegularFont())
                    .ToolTipText(DisplayDesc)
                ]
            ]
            .ValueContent()
            [
                SNew(SComboButton)
                .OnGetMenuContent(this, &FOmegaBitflagsCustomization::GenerateEnumComboContent, i)
                .ButtonContent()
                [
                    SNew(STextBlock)
                    .Text(this, &FOmegaBitflagsCustomization::GetBitEnumDisplayText, i)
                    .Font(IPropertyTypeCustomizationUtils::GetRegularFont())
                ]
            ];
        }
    }
}

FText FOmegaBitflagsCustomization::GetHeaderValueText() const
{
    if (!BitmaskPropertyHandle.IsValid())
    {
        return FText::FromString("Bitflags");
    }

    int32 CurrentValue = 0;
    BitmaskPropertyHandle->GetValue(CurrentValue);

    return FText::FromString(FString::Printf(TEXT("Flags (%d)"), CurrentValue));
}

ECheckBoxState FOmegaBitflagsCustomization::IsChecked(int32 BitIndex) const
{
    if (!BitmaskPropertyHandle.IsValid())
    {
        return ECheckBoxState::Unchecked;
    }

    int32 CurrentValue = 0;
    BitmaskPropertyHandle->GetValue(CurrentValue);

    return (CurrentValue & (1 << BitIndex)) != 0 ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void FOmegaBitflagsCustomization::OnCheckStateChanged(ECheckBoxState NewState, int32 BitIndex)
{
    if (!BitmaskPropertyHandle.IsValid())
    {
        return;
    }

    int32 CurrentValue = 0;
    BitmaskPropertyHandle->GetValue(CurrentValue);

    if (NewState == ECheckBoxState::Checked)
    {
        CurrentValue |= (1 << BitIndex);
    }
    else
    {
        CurrentValue &= ~(1 << BitIndex);
    }

    BitmaskPropertyHandle->SetValue(CurrentValue);
}

int32 FOmegaBitflagsCustomization::GetBitEnumValue(int32 BitIndex) const
{
    if (!BitEnumsPropertyHandle.IsValid())
    {
        return 0;
    }

    int64 BitEnumsValue = 0;
    BitEnumsPropertyHandle->GetValue(BitEnumsValue);

    // Extract 4 bits at the correct position
    int32 Shift = BitIndex * 4;
    return (BitEnumsValue >> Shift) & 0xF;
}

void FOmegaBitflagsCustomization::SetBitEnumValue(int32 BitIndex, int32 NewValue)
{
    if (!BitEnumsPropertyHandle.IsValid())
    {
        return;
    }

    int64 BitEnumsValue = 0;
    BitEnumsPropertyHandle->GetValue(BitEnumsValue);

    // Clamp value to 0-15
    NewValue = FMath::Clamp(NewValue, 0, 15);
    
    int32 Shift = BitIndex * 4;
    // Clear the 4 bits at this position
    BitEnumsValue &= ~(0xFLL << Shift);
    // Set the new value
    BitEnumsValue |= ((int64)NewValue << Shift);

    BitEnumsPropertyHandle->SetValue(BitEnumsValue);
}

FText FOmegaBitflagsCustomization::GetBitEnumDisplayText(int32 BitIndex) const
{
    const UOmegaSettings* Settings = GetDefault<UOmegaSettings>();
    if (!Settings || !CachedOwnerClass)
    {
        return FText::FromString("0");
    }

    int32 Value = GetBitEnumValue(BitIndex);
    FText OptionName = Settings->GetBitEnumOptionName(CachedOwnerClass, BitIndex, Value);
    
    // Always show [index] name format
    if (OptionName.IsEmpty() || OptionName.ToString().TrimStartAndEnd().IsEmpty())
    {
        return FText::FromString(FString::Printf(TEXT("[%d]"), Value));
    }
    
    return FText::FromString(FString::Printf(TEXT("[%d] %s"), Value, *OptionName.ToString()));
}

TSharedRef<SWidget> FOmegaBitflagsCustomization::GenerateEnumComboContent(int32 BitIndex)
{
    FMenuBuilder MenuBuilder(true, nullptr);

    const UOmegaSettings* Settings = GetDefault<UOmegaSettings>();
    if (!Settings || !CachedOwnerClass)
    {
        return MenuBuilder.MakeWidget();
    }

    const FOmegaBitmaskEditorData* EditorData = Settings->GetEditorDataForClass(CachedOwnerClass);
    
    if (!EditorData || !EditorData->BitEnums.IsValidIndex(BitIndex))
    {
        return MenuBuilder.MakeWidget();
    }

    const FOmegaBitmaskEditorEnumData& EnumData = EditorData->BitEnums[BitIndex];
    
    // Show options from the enum data, or default to 0-15 if no options defined
    int32 NumOptions = EnumData.Options.Num() > 0 ? FMath::Min(EnumData.Options.Num(), 16) : 16;

    for (int32 i = 0; i < NumOptions; ++i)
    {
        FText Label;
        
        if (EnumData.Options.IsValidIndex(i))
        {
            const FOmegaBitmaskEditorEntry& Option = EnumData.Options[i];
            
            if (!Option.Title.IsEmpty())
            {
                Label = FText::FromString(FString::Printf(TEXT("[%d] %s"), i, *Option.Title.ToString()));
            }
            else
            {
                Label = FText::FromString(FString::Printf(TEXT("[%d]"), i));
            }
        }
        else
        {
            Label = FText::FromString(FString::Printf(TEXT("[%d]"), i));
        }
        
        MenuBuilder.AddMenuEntry(
            Label,
            FText::GetEmpty(),
            FSlateIcon(),
            FUIAction(
                FExecuteAction::CreateLambda([this, BitIndex, i]()
                {
                    SetBitEnumValue(BitIndex, i);
                }),
                FCanExecuteAction(),
                FIsActionChecked::CreateLambda([this, BitIndex, i]()
                {
                    return GetBitEnumValue(BitIndex) == i;
                })
            ),
            NAME_None,
            EUserInterfaceActionType::RadioButton
        );
    }

    return MenuBuilder.MakeWidget();
}

