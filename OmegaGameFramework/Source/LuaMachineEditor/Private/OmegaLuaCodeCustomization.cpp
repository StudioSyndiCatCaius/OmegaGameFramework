#include "OmegaLuaCodeCustomization.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "FLuaSyntaxHighlighter.h"
#include "LuaCode.h"

TSharedRef<IPropertyTypeCustomization> FOmegaLuaCodeCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaLuaCodeCustomization());
}

void FOmegaLuaCodeCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, 
    FDetailWidgetRow& HeaderRow, 
    IPropertyTypeCustomizationUtils& CustomizationUtils)
{
    
}


void FOmegaLuaCodeCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, 
    IDetailChildrenBuilder& ChildBuilder, 
    IPropertyTypeCustomizationUtils& CustomizationUtils)
{
    LuaCodePropertyHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaLuaCode, LuaCode));

    if (LuaCodePropertyHandle.IsValid())
    {
        // Create syntax highlighter
        TSharedRef<FLuaSyntaxHighlighter> SyntaxHighlighter = FLuaSyntaxHighlighter::Create();

        ChildBuilder.AddCustomRow(NSLOCTEXT("OmegaLua", "LuaCode", "Lua Code"))
            .NameContent()
            [
                PropertyHandle->CreatePropertyNameWidget()
            ]
            .ValueContent()
            .MinDesiredWidth(300.0f)
            .MaxDesiredWidth(800.0f)
            [
                SAssignNew(TextBox, SMultiLineEditableTextBox)
                    .Text(this, &FOmegaLuaCodeCustomization::GetLuaCodeText)
                    .OnTextChanged(this, &FOmegaLuaCodeCustomization::OnLuaCodeTextChanged)
                    .OnTextCommitted(this, &FOmegaLuaCodeCustomization::OnLuaCodeTextCommitted)
                    .Marshaller(SyntaxHighlighter)
                    .Font(FCoreStyle::GetDefaultFontStyle("Mono", 9))
                    .BackgroundColor(FLinearColor(0.02f, 0.02f, 0.02f, 1.0f))
                    .ForegroundColor(FLinearColor(0.9f, 0.9f, 0.9f, 1.0f))
                    .Margin(FMargin(0.0f, 4.0f))
                    .AutoWrapText(false)
                    .AllowMultiLine(true)
            ];
    }
}

FText FOmegaLuaCodeCustomization::GetLuaCodeText() const
{
    if (LuaCodePropertyHandle.IsValid())
    {
        FString ValueStr;
        LuaCodePropertyHandle->GetValue(ValueStr);
        return FText::FromString(ValueStr);
    }
    return FText::GetEmpty();
}

void FOmegaLuaCodeCustomization::OnLuaCodeTextChanged(const FText& NewText)
{
    // Optional: Handle real-time changes
}

void FOmegaLuaCodeCustomization::OnLuaCodeTextCommitted(const FText& NewText, ETextCommit::Type CommitType)
{
    if (LuaCodePropertyHandle.IsValid())
    {
        LuaCodePropertyHandle->SetValue(NewText.ToString());
    }
}