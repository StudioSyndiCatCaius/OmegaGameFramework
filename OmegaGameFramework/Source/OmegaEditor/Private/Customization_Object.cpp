// OmegaPropertyHidingCustomization.cpp
#include "Customization_Object.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "OmegaEditorSettings.h"
#include "OmegaGameCore.h"
#include "OmegaSettings.h"
#include "Widgets/Layout/SWrapBox.h"
#include "GameFramework/Actor.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SSeparator.h"
#include "PropertyCustomizationHelpers.h"
#include "Subsystems/Subsystem_Actors.h"

TSharedRef<IDetailCustomization> FOmegaPropertyHidingCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaPropertyHidingCustomization);
}

void FOmegaPropertyHidingCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
    
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
                            GetMutableDefault<UOmegaSettings>()->GetGameCore()->Object_RunClassCommand(Obj, CommandIndex);
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
    
    // ===== NEW: Check if object is an Actor and add metadata =====
    AActor* Actor = Cast<AActor>(FirstObject);
    if (Actor && SelectedObjects.Num() == 1) // Only for actors in single selection
    {
        SetupActorMetadataCategory(DetailBuilder, Actor);
    }
    // =============================================================
    
    HidePropertiesAndCategories(DetailBuilder, FirstObject);
}

void FOmegaPropertyHidingCustomization::HidePropertiesAndCategories(IDetailLayoutBuilder& DetailBuilder, UObject* Object)
{
    UOmegaEditorSettings* Settings = UOmegaEditorSettings::Get();
    if (!Settings)
        return;

    TArray<FName> HiddenProperties;
    TArray<FName> HiddenCategories;
    
    Settings->GetHiddenVariables(Object, HiddenProperties, HiddenCategories);
    
    // Hide individual properties
    for (const FName& PropertyName : HiddenProperties)
    {
        TSharedPtr<IPropertyHandle> PropertyHandle = DetailBuilder.GetProperty(PropertyName);
        if (PropertyHandle.IsValid() && PropertyHandle->IsValidHandle())
        {
            DetailBuilder.HideProperty(PropertyHandle);
        }
    }

    // Hide entire categories
    for (const FName& CategoryName : HiddenCategories)
    {
        DetailBuilder.HideCategory(CategoryName);
    }
}

// ============================================================================
// ACTOR METADATA FUNCTIONALITY
// ============================================================================

void FOmegaPropertyHidingCustomization::SetupActorMetadataCategory(IDetailLayoutBuilder& DetailBuilder, AActor* Actor)
{
    if (!Actor)
        return;

    // Get the game core
    UOmegaGameCore* GameCore = GetMutableDefault<UOmegaSettings>()->GetGameCore();
    if (!GameCore)
        return;

    // Get available parameters for this actor
    TArray<FName> BoolParams, IntParams, FloatParams, StringParams, DataAssetParams, ActorParams;
    GameCore->GetActorInstanceMetaParams(
        Actor,
        BoolParams,
        IntParams,
        FloatParams,
        StringParams,
        DataAssetParams,
        ActorParams
    );

    // Only create the category if there are any parameters
    if (BoolParams.Num() == 0 && IntParams.Num() == 0 && FloatParams.Num() == 0 && 
        StringParams.Num() == 0 && DataAssetParams.Num() == 0 && ActorParams.Num() == 0)
    {
        return;
    }

    // Add metadata category
    IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
        TEXT("Omega Instance Metadata"),
        FText::FromString(TEXT("Omega Instance Metadata")),
        ECategoryPriority::Important
    );

    // Add styled header
    Category.AddCustomRow(FText::GetEmpty())
        .WholeRowContent()
        [
            SNew(SBorder)
            .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryMiddle"))
            .BorderBackgroundColor(FLinearColor(0.1f, 0.3f, 0.5f, 0.3f))
            .Padding(FMargin(0.0f, 4.0f))
            [
                SNew(SBorder)
                .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
                .BorderBackgroundColor(FLinearColor(0.05f, 0.15f, 0.25f, 0.5f))
                .Padding(FMargin(8.0f, 6.0f))
                [
                    SNew(STextBlock)
                    .Text(FText::FromString(TEXT("⚙ Actor Instance Metadata")))
                    .Font(FCoreStyle::GetDefaultFontStyle("Bold", 9))
                    .ColorAndOpacity(FLinearColor(0.8f, 0.9f, 1.0f, 1.0f))
                ]
            ]
        ];

    // Bool Parameters
    if (BoolParams.Num() > 0)
    {
        AddTypeSeparator(Category, TEXT("Booleans"));
        for (const FName& ParamName : BoolParams)
        {
            CreateBoolProperty(Category, ParamName, Actor);
        }
    }

    // Int Parameters
    if (IntParams.Num() > 0)
    {
        AddTypeSeparator(Category, TEXT("Integers"));
        for (const FName& ParamName : IntParams)
        {
            CreateIntProperty(Category, ParamName, Actor);
        }
    }

    // Float Parameters
    if (FloatParams.Num() > 0)
    {
        AddTypeSeparator(Category, TEXT("Floats"));
        for (const FName& ParamName : FloatParams)
        {
            CreateFloatProperty(Category, ParamName, Actor);
        }
    }

    // String Parameters
    if (StringParams.Num() > 0)
    {
        AddTypeSeparator(Category, TEXT("Strings"));
        for (const FName& ParamName : StringParams)
        {
            CreateStringProperty(Category, ParamName, Actor);
        }
    }

    // DataAsset Parameters
    if (DataAssetParams.Num() > 0)
    {
        AddTypeSeparator(Category, TEXT("Data Assets"));
        for (const FName& ParamName : DataAssetParams)
        {
            CreateDataAssetProperty(Category, ParamName, Actor);
        }
    }

    // Actor Parameters
    if (ActorParams.Num() > 0)
    {
        AddTypeSeparator(Category, TEXT("Actors"));
        for (const FName& ParamName : ActorParams)
        {
            CreateActorProperty(Category, ParamName, Actor);
        }
    }
}

void FOmegaPropertyHidingCustomization::AddTypeSeparator(IDetailCategoryBuilder& Category, const FString& TypeName)
{
    Category.AddCustomRow(FText::FromString(TypeName))
        .WholeRowContent()
        .VAlign(VAlign_Center)
        .HAlign(HAlign_Fill)
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
            .FillWidth(1.0f)
            .VAlign(VAlign_Center)
            .Padding(0.0f, 0.0f, 8.0f, 0.0f)
            [
                SNew(SSeparator)
                .Thickness(1.0f)
                .SeparatorImage(FAppStyle::GetBrush("PropertyEditor.HorizontalDottedLine"))
                .ColorAndOpacity(FLinearColor(0.3f, 0.5f, 0.7f, 0.4f))
            ]
            + SHorizontalBox::Slot()
            .AutoWidth()
            .VAlign(VAlign_Center)
            [
                SNew(STextBlock)
                .Text(FText::FromString(TypeName))
                .Font(FCoreStyle::GetDefaultFontStyle("Italic", 8))
                .ColorAndOpacity(FLinearColor(0.5f, 0.7f, 0.9f, 0.7f))
            ]
            + SHorizontalBox::Slot()
            .FillWidth(1.0f)
            .VAlign(VAlign_Center)
            .Padding(8.0f, 0.0f, 0.0f, 0.0f)
            [
                SNew(SSeparator)
                .Thickness(1.0f)
                .SeparatorImage(FAppStyle::GetBrush("PropertyEditor.HorizontalDottedLine"))
                .ColorAndOpacity(FLinearColor(0.3f, 0.5f, 0.7f, 0.4f))
            ]
        ];
}

FOmegaActorInstanceMetadata FOmegaPropertyHidingCustomization::GetMetadata(AActor* Actor) const
{
    if (!Actor || !Actor->GetWorld())
    {
        return FOmegaActorInstanceMetadata();
    }

    UOmegaActorSubsystem* Subsystem = Actor->GetWorld()->GetSubsystem<UOmegaActorSubsystem>();
    if (!Subsystem)
    {
        return FOmegaActorInstanceMetadata();
    }

    AOmegaWorldManager* WorldManager = Subsystem->GetWorldManager();
    if (!WorldManager)
    {
        return FOmegaActorInstanceMetadata();
    }

    return WorldManager->GetActorMetadata(Actor);
}

void FOmegaPropertyHidingCustomization::SetMetadata(AActor* Actor, const FOmegaActorInstanceMetadata& NewMetadata)
{
    if (!Actor || !Actor->GetWorld())
    {
        return;
    }

    UOmegaActorSubsystem* Subsystem = Actor->GetWorld()->GetSubsystem<UOmegaActorSubsystem>();
    if (!Subsystem)
    {
        return;
    }

    AOmegaWorldManager* WorldManager = Subsystem->GetWorldManager();
    if (!WorldManager)
    {
        return;
    }

    WorldManager->SetActorMetadata(Actor, NewMetadata);
}

// ===== Bool Properties =====

void FOmegaPropertyHidingCustomization::CreateBoolProperty(IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor)
{
    Category.AddCustomRow(FText::FromName(ParamName))
        .NameContent()
        [
            SNew(STextBlock)
            .Text(FText::FromName(ParamName))
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ]
        .ValueContent()
        [
            SNew(SCheckBox)
            .IsChecked_Lambda([this, ParamName, Actor]()
            {
                TOptional<bool> Value = GetBoolValue(Actor, ParamName);
                return Value.IsSet() && Value.GetValue() ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
            })
            .OnCheckStateChanged_Lambda([this, ParamName, Actor](ECheckBoxState NewState)
            {
                SetBoolValue(Actor, NewState == ECheckBoxState::Checked, ParamName);
            })
        ];
}

TOptional<bool> FOmegaPropertyHidingCustomization::GetBoolValue(AActor* Actor, FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    if (const bool* Value = Metadata.BoolParams.Find(ParamName))
    {
        return *Value;
    }
    return false;
}

void FOmegaPropertyHidingCustomization::SetBoolValue(AActor* Actor, bool NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    Metadata.BoolParams.Add(ParamName, NewValue);
    SetMetadata(Actor, Metadata);
}

// ===== Int Properties =====

void FOmegaPropertyHidingCustomization::CreateIntProperty(IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor)
{
    Category.AddCustomRow(FText::FromName(ParamName))
        .NameContent()
        [
            SNew(STextBlock)
            .Text(FText::FromName(ParamName))
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ]
        .ValueContent()
        [
            SNew(SNumericEntryBox<int32>)
            .Value_Lambda([this, ParamName, Actor]()
            {
                return GetIntValue(Actor, ParamName);
            })
            .OnValueChanged_Lambda([this, ParamName, Actor](int32 NewValue)
            {
                SetIntValue(Actor, NewValue, ParamName);
            })
            .AllowSpin(true)
        ];
}

TOptional<int32> FOmegaPropertyHidingCustomization::GetIntValue(AActor* Actor, FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    if (const int32* Value = Metadata.IntParams.Find(ParamName))
    {
        return *Value;
    }
    return 0;
}

void FOmegaPropertyHidingCustomization::SetIntValue(AActor* Actor, int32 NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    Metadata.IntParams.Add(ParamName, NewValue);
    SetMetadata(Actor, Metadata);
}

// ===== Float Properties =====

void FOmegaPropertyHidingCustomization::CreateFloatProperty(IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor)
{
    Category.AddCustomRow(FText::FromName(ParamName))
        .NameContent()
        [
            SNew(STextBlock)
            .Text(FText::FromName(ParamName))
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ]
        .ValueContent()
        [
            SNew(SNumericEntryBox<float>)
            .Value_Lambda([this, ParamName, Actor]()
            {
                return GetFloatValue(Actor, ParamName);
            })
            .OnValueChanged_Lambda([this, ParamName, Actor](float NewValue)
            {
                SetFloatValue(Actor, NewValue, ParamName);
            })
            .AllowSpin(true)
        ];
}

TOptional<float> FOmegaPropertyHidingCustomization::GetFloatValue(AActor* Actor, FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    if (const float* Value = Metadata.FloatParams.Find(ParamName))
    {
        return *Value;
    }
    return 0.0f;
}

void FOmegaPropertyHidingCustomization::SetFloatValue(AActor* Actor, float NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    Metadata.FloatParams.Add(ParamName, NewValue);
    SetMetadata(Actor, Metadata);
}

// ===== String Properties =====

void FOmegaPropertyHidingCustomization::CreateStringProperty(IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor)
{
    Category.AddCustomRow(FText::FromName(ParamName))
        .NameContent()
        [
            SNew(STextBlock)
            .Text(FText::FromName(ParamName))
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ]
        .ValueContent()
        [
            SNew(SEditableTextBox)
            .Text_Lambda([this, ParamName, Actor]()
            {
                return GetStringValue(Actor, ParamName);
            })
            .OnTextCommitted_Lambda([this, ParamName, Actor](const FText& NewText, ETextCommit::Type CommitType)
            {
                SetStringValue(Actor, NewText, ParamName);
            })
        ];
}

FText FOmegaPropertyHidingCustomization::GetStringValue(AActor* Actor, FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    if (const FString* Value = Metadata.StringParams.Find(ParamName))
    {
        return FText::FromString(*Value);
    }
    return FText::GetEmpty();
}

void FOmegaPropertyHidingCustomization::SetStringValue(AActor* Actor, const FText& NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    Metadata.StringParams.Add(ParamName, NewValue.ToString());
    SetMetadata(Actor, Metadata);
}

// ===== DataAsset Properties =====

void FOmegaPropertyHidingCustomization::CreateDataAssetProperty(IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor)
{
    Category.AddCustomRow(FText::FromName(ParamName))
        .NameContent()
        [
            SNew(STextBlock)
            .Text(FText::FromName(ParamName))
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ]
        .ValueContent()
        [
            SNew(SObjectPropertyEntryBox)
            .AllowedClass(UPrimaryDataAsset::StaticClass())
            .ObjectPath_Lambda([this, ParamName, Actor]()
            {
                UObject* Object = GetDataAssetValue(Actor, ParamName);
                return Object ? Object->GetPathName() : FString();
            })
            .OnObjectChanged_Lambda([this, ParamName, Actor](const FAssetData& AssetData)
            {
                SetDataAssetValue(Actor, AssetData, ParamName);
            })
        ];
}

UObject* FOmegaPropertyHidingCustomization::GetDataAssetValue(AActor* Actor, FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    if (UPrimaryDataAsset* const* Value = Metadata.DataAssetParams.Find(ParamName))
    {
        return *Value;
    }
    return nullptr;
}

void FOmegaPropertyHidingCustomization::SetDataAssetValue(AActor* Actor, const FAssetData& AssetData, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    Metadata.DataAssetParams.Add(ParamName, Cast<UPrimaryDataAsset>(AssetData.GetAsset()));
    SetMetadata(Actor, Metadata);
}

// ===== Actor Properties =====

void FOmegaPropertyHidingCustomization::CreateActorProperty(IDetailCategoryBuilder& Category, FName ParamName, AActor* Actor)
{
    Category.AddCustomRow(FText::FromName(ParamName))
        .NameContent()
        [
            SNew(STextBlock)
            .Text(FText::FromName(ParamName))
            .Font(IDetailLayoutBuilder::GetDetailFont())
        ]
        .ValueContent()
        [
            SNew(SObjectPropertyEntryBox)
            .AllowedClass(AActor::StaticClass())
            .ObjectPath_Lambda([this, ParamName, Actor]()
            {
                UObject* Object = GetActorValue(Actor, ParamName);
                return Object ? Object->GetPathName() : FString();
            })
            .OnObjectChanged_Lambda([this, ParamName, Actor](const FAssetData& AssetData)
            {
                SetActorValue(Actor, AssetData, ParamName);
            })
        ];
}

UObject* FOmegaPropertyHidingCustomization::GetActorValue(AActor* Actor, FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    if (const TSoftObjectPtr<AActor>* Value = Metadata.ActorParams.Find(ParamName))
    {
        return Value->Get();
    }
    return nullptr;
}

void FOmegaPropertyHidingCustomization::SetActorValue(AActor* Actor, const FAssetData& AssetData, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata(Actor);
    AActor* TargetActor = Cast<AActor>(AssetData.GetAsset());
    Metadata.ActorParams.Add(ParamName, TSoftObjectPtr<AActor>(TargetActor));
    SetMetadata(Actor, Metadata);
}