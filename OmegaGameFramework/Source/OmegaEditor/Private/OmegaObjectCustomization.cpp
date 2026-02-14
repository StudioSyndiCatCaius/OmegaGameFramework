// OmegaObjectCustomization.cpp
#include "OmegaObjectCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SWrapBox.h"
#include "OmegaEditorSettings.h"
#include "OmegaSettings.h"
#include "OmegaSettings_Global.h"

TSharedRef<IDetailCustomization> FOmegaObjectCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaObjectCustomization);
}

void FOmegaObjectCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
    // Get selected objects
    DetailBuilder.GetObjectsBeingCustomized(SelectedObjects);
    
    if (SelectedObjects.Num() == 0)
        return;

    UObject* FirstObject = SelectedObjects[0].Get();
    if (!FirstObject)
        return;

    // Get settings
    UOmegaEditorSettings* Settings = UOmegaEditorSettings::Get();
    if (!Settings)
        return;

    // Find commands for this object's class
    UClass* ObjectClass = FirstObject->GetClass();
    FOmegaEditorCommandsList* CommandsList = nullptr;
    
    for (auto& Pair : Settings->ClassCommands)
    {
        if (Pair.Key.IsValid())
        {
            UClass* MappedClass = Pair.Key.Get();
            if (MappedClass && ObjectClass->IsChildOf(MappedClass))
            {
                CommandsList = &Pair.Value;
                break;
            }
        }
    }

    if (!CommandsList || CommandsList->CommandNames.Num() == 0)
        return;

    // Add custom category with buttons
    IDetailCategoryBuilder& CommandCategory = DetailBuilder.EditCategory(
        "OmegaCommands", 
        FText::FromString("Commands"), 
        ECategoryPriority::Transform
    );

    // Create buttons
    TSharedRef<SWrapBox> ButtonBox = SNew(SWrapBox)
        .UseAllottedSize(true);

    for (int32 i = 0; i < CommandsList->CommandNames.Num(); ++i)
    {
        const FString& CommandName = CommandsList->CommandNames[i];
        const int32 CommandIndex = i;

        ButtonBox->AddSlot()
            .Padding(2.0f)
            [
                SNew(SButton)
                .Text(FText::FromString("["+FString::FromInt(CommandIndex)+"] "+CommandName))
                .OnClicked_Lambda([this, CommandIndex]()
                {
                    UOmegaEditorSettings* Settings = UOmegaEditorSettings::Get();
                    for (auto& WeakObj : SelectedObjects)
                    {
                        if (UObject* Obj = WeakObj.Get())
                        {
                            GetMutableDefault<UOmegaSettings>()->GetGlobalSettings()->Object_RunClassCommand(Obj, CommandIndex);
                           // Settings->FireCommandEvent(Obj, CommandIndex);
                        }
                    }
                    return FReply::Handled();
                })
            ];
    }

    CommandCategory.AddCustomRow(FText::FromString("Commands"))
        [
            ButtonBox
        ];
}