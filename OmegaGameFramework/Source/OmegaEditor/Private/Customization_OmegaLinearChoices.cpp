#include "Customization_OmegaLinearChoices.h"
#include "DetailWidgetRow.h"
#include "DetailLayoutBuilder.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SBorder.h"
#include "PropertyCustomizationHelpers.h"
#include "ScopedTransaction.h"
#include "IDetailsView.h"
#include "IPropertyUtilities.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "Styling/SlateColor.h"
#include "Choice/OmegaLinearChoiceInstance.h"

TSharedRef<IPropertyTypeCustomization> FCustomization_OmegaLinearChoices::MakeInstance()
{
    return MakeShareable(new FCustomization_OmegaLinearChoices());
}

void FCustomization_OmegaLinearChoices::CustomizeHeader(
    TSharedRef<IPropertyHandle> PropertyHandle,
    FDetailWidgetRow& HeaderRow,
    IPropertyTypeCustomizationUtils& CustomizationUtils)
{
    CustomizationUtilsPtr = &CustomizationUtils;
    ChoicesPropertyHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaLinearChoices, Choices));

    // Simple header without dropdown - just title and buttons
    HeaderRow
    .WholeRowContent()
    [
        SNew(SHorizontalBox)
        
        // Title
        + SHorizontalBox::Slot()
        .FillWidth(1.0f)
        .VAlign(VAlign_Center)
        [
            SNew(SBorder)
            .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
            .Padding(FMargin(6.0f, 2.0f))
            [
                SNew(STextBlock)
                .Text(FText::FromString("Linear Choices"))
                .Font(IDetailLayoutBuilder::GetDetailFontBold())
            ]
        ]
        
        // Buttons
        + SHorizontalBox::Slot()
        .AutoWidth()
        .VAlign(VAlign_Center)
        .Padding(4.0f, 0.0f, 0.0f, 0.0f)
        [
            SNew(SHorizontalBox)
            
            // Delete All Button (Red)
            + SHorizontalBox::Slot()
            .AutoWidth()
            .Padding(0.0f, 0.0f, 4.0f, 0.0f)
            [
                SNew(SButton)
                .Text(FText::FromString("Delete All"))
                .ButtonColorAndOpacity(FLinearColor(0.8f, 0.1f, 0.1f, 1.0f))
                .OnClicked(this, &FCustomization_OmegaLinearChoices::OnDeleteAllClicked)
                .ToolTipText(FText::FromString("Remove all choices from the array"))
            ]
            
            // +1 Button (Green)
            + SHorizontalBox::Slot()
            .AutoWidth()
            .Padding(0.0f, 0.0f, 2.0f, 0.0f)
            [
                SNew(SButton)
                .Text(FText::FromString("+1"))
                .ButtonColorAndOpacity(FLinearColor(0.1f, 0.6f, 0.1f, 1.0f))
                .OnClicked(this, &FCustomization_OmegaLinearChoices::OnAddChoicesClicked, 1)
                .ToolTipText(FText::FromString("Add 1 choice"))
            ]
            
            // +2 Button (Green)
            + SHorizontalBox::Slot()
            .AutoWidth()
            .Padding(0.0f, 0.0f, 2.0f, 0.0f)
            [
                SNew(SButton)
                .Text(FText::FromString("+2"))
                .ButtonColorAndOpacity(FLinearColor(0.1f, 0.6f, 0.1f, 1.0f))
                .OnClicked(this, &FCustomization_OmegaLinearChoices::OnAddChoicesClicked, 2)
                .ToolTipText(FText::FromString("Add 2 choices"))
            ]
            
            // +3 Button (Green)
            + SHorizontalBox::Slot()
            .AutoWidth()
            [
                SNew(SButton)
                .Text(FText::FromString("+3"))
                .ButtonColorAndOpacity(FLinearColor(0.1f, 0.6f, 0.1f, 1.0f))
                .OnClicked(this, &FCustomization_OmegaLinearChoices::OnAddChoicesClicked, 3)
                .ToolTipText(FText::FromString("Add 3 choices"))
            ]
        ]
    ];
}

TSharedRef<SWidget> FCustomization_OmegaLinearChoices::CreateChoiceWidget(TSharedRef<IPropertyHandle> ChoiceHandle, int32 ChoiceIndex)
{
    UObject* ChoiceObject = nullptr;
    ChoiceHandle->GetValue(ChoiceObject);
    
    // Create a details view for this specific object
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    
    FDetailsViewArgs DetailsViewArgs;
    DetailsViewArgs.bAllowSearch = false;
    DetailsViewArgs.bShowOptions = false;
    DetailsViewArgs.bAllowMultipleTopLevelObjects = false;
    DetailsViewArgs.bAllowFavoriteSystem = false;
    DetailsViewArgs.bShowScrollBar = false;
    DetailsViewArgs.bShowPropertyMatrixButton = false;
    DetailsViewArgs.bHideSelectionTip = true;
    DetailsViewArgs.bShowObjectLabel = false;
    DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
    
    TSharedRef<IDetailsView> DetailsView = PropertyModule.CreateDetailView(DetailsViewArgs);
    
    if (ChoiceObject)
    {
        DetailsView->SetObject(ChoiceObject);
    }
    
    return SNew(SBorder)
        .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
        .BorderBackgroundColor(FLinearColor(0.05f, 0.05f, 0.05f, 1.0f))
        .Padding(FMargin(4.0f, 4.0f))
        [
            SNew(SVerticalBox)
            
            // Horizontal layout: Index + Delete Button | Class Selector
            + SVerticalBox::Slot()
            .AutoHeight()
            .Padding(0.0f, 0.0f, 0.0f, 2.0f)
            [
                SNew(SHorizontalBox)
                
                // Left side: Index number and delete button in black box
                + SHorizontalBox::Slot()
                .AutoWidth()
                .Padding(0.0f, 0.0f, 2.0f, 0.0f)
                [
                    SNew(SBorder)
                    .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryTop"))
                    .BorderBackgroundColor(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f))
                    .Padding(FMargin(3.0f, 2.0f))
                    [
                        SNew(SHorizontalBox)
                        
                        + SHorizontalBox::Slot()
                        .AutoWidth()
                        .VAlign(VAlign_Center)
                        .Padding(0.0f, 0.0f, 4.0f, 0.0f)
                        [
                            SNew(STextBlock)
                            .Text(FText::AsNumber(ChoiceIndex))
                            .Font(IDetailLayoutBuilder::GetDetailFont())
                        ]
                        
                        + SHorizontalBox::Slot()
                        .AutoWidth()
                        .VAlign(VAlign_Center)
                        [
                            PropertyCustomizationHelpers::MakeDeleteButton(
                                FSimpleDelegate::CreateLambda([this, ChoiceHandle]()
                                {
                                    if (ChoicesPropertyHandle.IsValid())
                                    {
                                        FScopedTransaction Transaction(FText::FromString("Remove Choice"));
                                        
                                        // Find the current index of this handle
                                        uint32 NumChildren = 0;
                                        ChoicesPropertyHandle->GetNumChildren(NumChildren);
                                        
                                        for (uint32 i = 0; i < NumChildren; ++i)
                                        {
                                            TSharedPtr<IPropertyHandle> CurrentHandle = ChoicesPropertyHandle->GetChildHandle(i);
                                            if (CurrentHandle.IsValid() && CurrentHandle.Get() == &ChoiceHandle.Get())
                                            {
                                                ChoicesPropertyHandle->AsArray()->DeleteItem(i);
                                                
                                                // Force a refresh to rebuild the UI
                                                if (CustomizationUtilsPtr)
                                                {
                                                    CustomizationUtilsPtr->GetPropertyUtilities()->ForceRefresh();
                                                }
                                                break;
                                            }
                                        }
                                    }
                                }),
                                FText::FromString("Remove this choice"),
                                true
                            )
                        ]
                    ]
                ]
                
                // Right side: Object class selector
                + SHorizontalBox::Slot()
                .FillWidth(1.0f)
                [
                    SNew(SBorder)
                    .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryTop"))
                    .BorderBackgroundColor(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f))
                    .Padding(FMargin(3.0f, 2.0f))
                    [
                        ChoiceHandle->CreatePropertyValueWidget()
                    ]
                ]
            ]
            
            // Details view for the object's properties (no categories)
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SBorder)
                .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryTop"))
                .BorderBackgroundColor(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f))
                .Padding(FMargin(3.0f, 2.0f))
                [
                    SNew(SBox)
                    .MinDesiredHeight(30.0f)
                    [
                        DetailsView
                    ]
                ]
            ]
        ];
}

void FCustomization_OmegaLinearChoices::CustomizeChildren(
    TSharedRef<IPropertyHandle> PropertyHandle,
    IDetailChildrenBuilder& ChildBuilder,
    IPropertyTypeCustomizationUtils& CustomizationUtils)
{
    if (!ChoicesPropertyHandle.IsValid())
    {
        return;
    }

    uint32 NumChildren = 0;
    ChoicesPropertyHandle->GetNumChildren(NumChildren);

    for (uint32 ChildIndex = 0; ChildIndex < NumChildren; ++ChildIndex)
    {
        TSharedRef<IPropertyHandle> ChildHandle = ChoicesPropertyHandle->GetChildHandle(ChildIndex).ToSharedRef();

        ChildBuilder.AddCustomRow(FText::GetEmpty())
        .WholeRowContent()
        [
            CreateChoiceWidget(ChildHandle, ChildIndex)
        ];
        
        // Add spacing between choices (except after the last one)
        if (ChildIndex < NumChildren - 1)
        {
            ChildBuilder.AddCustomRow(FText::GetEmpty())
            .WholeRowContent()
            [
                SNew(SBox)
                .HeightOverride(2.0f)
            ];
        }
    }
}

FReply FCustomization_OmegaLinearChoices::OnAddChoicesClicked(int32 Count)
{
    if (ChoicesPropertyHandle.IsValid())
    {
        FScopedTransaction Transaction(FText::Format(FText::FromString("Add {0} Choice(s)"), Count));
        
        for (int32 i = 0; i < Count; ++i)
        {
            ChoicesPropertyHandle->AsArray()->AddItem();
        }
        
        if (CustomizationUtilsPtr)
        {
            CustomizationUtilsPtr->GetPropertyUtilities()->ForceRefresh();
        }
    }
    
    return FReply::Handled();
}

FReply FCustomization_OmegaLinearChoices::OnDeleteAllClicked()
{
    if (ChoicesPropertyHandle.IsValid())
    {
        uint32 NumChildren = 0;
        ChoicesPropertyHandle->GetNumChildren(NumChildren);
        
        if (NumChildren > 0)
        {
            FScopedTransaction Transaction(FText::FromString("Delete All Choices"));
            
            for (int32 i = NumChildren - 1; i >= 0; --i)
            {
                ChoicesPropertyHandle->AsArray()->DeleteItem(i);
            }
            
            if (CustomizationUtilsPtr)
            {
                CustomizationUtilsPtr->GetPropertyUtilities()->ForceRefresh();
            }
        }
    }
    
    return FReply::Handled();
}

void FCustomization_OmegaLinearChoices::RefreshChildren()
{
    if (CustomizationUtilsPtr)
    {
        CustomizationUtilsPtr->GetPropertyUtilities()->ForceRefresh();
    }
}