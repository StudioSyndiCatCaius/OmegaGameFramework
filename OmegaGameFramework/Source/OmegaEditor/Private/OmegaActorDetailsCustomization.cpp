// OmegaActorDetailsCustomization.cpp
#include "OmegaActorDetailsCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailsView.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SSeparator.h"
#include "PropertyCustomizationHelpers.h"
#include "OmegaGameCore.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_Actors.h"

TSharedRef<IDetailCustomization> FOmegaActorDetailsCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaActorDetailsCustomization);
}

void FOmegaActorDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
    // CRITICAL: This function must NEVER crash or throw exceptions
    // If anything fails, we simply return and let default properties show
    
    UE_LOG(LogTemp, Log, TEXT("OmegaActorDetailsCustomization::CustomizeDetails - Starting"));

    // Get objects being customized
    TArray<TWeakObjectPtr<UObject>> Objects;
    DetailBuilder.GetObjectsBeingCustomized(Objects);

    // Only work with single selection
    if (Objects.Num() != 1)
    {
        UE_LOG(LogTemp, Log, TEXT("OmegaActorDetailsCustomization - Multi-selection, skipping"));
        return; // Exit gracefully - default properties will still show
    }

    // Cast to actor
    SelectedActor = Cast<AActor>(Objects[0].Get());
    if (!SelectedActor.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("OmegaActorDetailsCustomization - Not an actor, skipping"));
        return; // Exit gracefully - default properties will still show
    }

    UE_LOG(LogTemp, Log, TEXT("OmegaActorDetailsCustomization - Actor: %s"), *SelectedActor->GetName());

    // Try to setup metadata UI - if this fails, default properties still show
    SetupMetadataCategory(DetailBuilder);
    
    UE_LOG(LogTemp, Log, TEXT("OmegaActorDetailsCustomization::CustomizeDetails - Complete"));
    
    // NOTE: We do NOT touch any existing categories
    // We do NOT hide any properties
    // We ONLY add our metadata category
    // Transform and all other properties remain untouched
}

void FOmegaActorDetailsCustomization::SetupMetadataCategory(IDetailLayoutBuilder& DetailBuilder)
{
    // Wrapped in its own function so if this fails, it doesn't break the entire details panel
    
    UE_LOG(LogTemp, Log, TEXT("SetupMetadataCategory - Starting"));

    // Get the game core - safely
    UOmegaGameCore* GameCore = nullptr;
    
    try
    {
        GameCore = OGF_GAME_CORE();
    }
    catch (...)
    {
        UE_LOG(LogTemp, Error, TEXT("OGF_GAME_CORE() threw an exception!"));
        return; // Exit gracefully
    }

    if (!GameCore)
    {
        UE_LOG(LogTemp, Warning, TEXT("SetupMetadataCategory - No GameCore, skipping metadata UI"));
        return; // Exit gracefully - no metadata UI, but default properties still show
    }

    UE_LOG(LogTemp, Log, TEXT("SetupMetadataCategory - GameCore found"));

    // Get available parameters for this actor
    TArray<FName> BoolParams, IntParams, FloatParams, StringParams, DataAssetParams, ActorParams;
    
    try
    {
        GameCore->GetActorInstanceMetaParams(
            SelectedActor.Get(),
            BoolParams,
            IntParams,
            FloatParams,
            StringParams,
            DataAssetParams,
            ActorParams
        );
    }
    catch (...)
    {
        UE_LOG(LogTemp, Error, TEXT("GetActorInstanceMetaParams threw an exception!"));
        return; // Exit gracefully
    }

    UE_LOG(LogTemp, Log, TEXT("SetupMetadataCategory - Params: Bool=%d, Int=%d, Float=%d, String=%d, DataAsset=%d, Actor=%d"),
        BoolParams.Num(), IntParams.Num(), FloatParams.Num(), StringParams.Num(), DataAssetParams.Num(), ActorParams.Num());

    // Only create the category if there are any parameters
    if (BoolParams.Num() == 0 && IntParams.Num() == 0 && FloatParams.Num() == 0 && 
        StringParams.Num() == 0 && DataAssetParams.Num() == 0 && ActorParams.Num() == 0)
    {
        UE_LOG(LogTemp, Log, TEXT("SetupMetadataCategory - No parameters, skipping"));
        return; // No parameters - exit gracefully
    }

    // Add our metadata category
    // IMPORTANT: We use EditCategory which creates OR gets existing category
    // This does NOT hide or remove any existing categories
    IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
        TEXT("Omega Instance Metadata"),
        FText::FromString(TEXT("Omega Instance Metadata")),
        ECategoryPriority::Important
    );

    UE_LOG(LogTemp, Log, TEXT("SetupMetadataCategory - Category created"));

    try
    {
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
                CreateBoolProperty(Category, ParamName);
            }
        }

        // Int Parameters
        if (IntParams.Num() > 0)
        {
            AddTypeSeparator(Category, TEXT("Integers"));
            for (const FName& ParamName : IntParams)
            {
                CreateIntProperty(Category, ParamName);
            }
        }

        // Float Parameters
        if (FloatParams.Num() > 0)
        {
            AddTypeSeparator(Category, TEXT("Floats"));
            for (const FName& ParamName : FloatParams)
            {
                CreateFloatProperty(Category, ParamName);
            }
        }

        // String Parameters
        if (StringParams.Num() > 0)
        {
            AddTypeSeparator(Category, TEXT("Strings"));
            for (const FName& ParamName : StringParams)
            {
                CreateStringProperty(Category, ParamName);
            }
        }

        // DataAsset Parameters
        if (DataAssetParams.Num() > 0)
        {
            AddTypeSeparator(Category, TEXT("Data Assets"));
            for (const FName& ParamName : DataAssetParams)
            {
                CreateDataAssetProperty(Category, ParamName);
            }
        }

        // Actor Parameters
        if (ActorParams.Num() > 0)
        {
            AddTypeSeparator(Category, TEXT("Actors"));
            for (const FName& ParamName : ActorParams)
            {
                CreateActorProperty(Category, ParamName);
            }
        }

        UE_LOG(LogTemp, Log, TEXT("SetupMetadataCategory - UI created successfully"));
    }
    catch (...)
    {
        UE_LOG(LogTemp, Error, TEXT("SetupMetadataCategory - Exception while creating UI!"));
        // Even if UI creation fails, default properties should still be visible
    }
}

void FOmegaActorDetailsCustomization::AddTypeSeparator(IDetailCategoryBuilder& Category, const FString& TypeName)
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

FOmegaActorInstanceMetadata FOmegaActorDetailsCustomization::GetMetadata() const
{
    if (!SelectedActor.IsValid())
    {
        return FOmegaActorInstanceMetadata();
    }

    UWorld* World = SelectedActor->GetWorld();
    if (!World)
    {
        return FOmegaActorInstanceMetadata();
    }

    UOmegaActorSubsystem* Subsystem = World->GetSubsystem<UOmegaActorSubsystem>();
    if (!Subsystem)
    {
        return FOmegaActorInstanceMetadata();
    }

    AOmegaWorldManager* WorldManager = Subsystem->GetWorldManager();
    if (!WorldManager)
    {
        return FOmegaActorInstanceMetadata();
    }

    return WorldManager->GetActorMetadata(SelectedActor.Get());
}

void FOmegaActorDetailsCustomization::SetMetadata(const FOmegaActorInstanceMetadata& NewMetadata)
{
    if (!SelectedActor.IsValid())
    {
        return;
    }

    UWorld* World = SelectedActor->GetWorld();
    if (!World)
    {
        return;
    }

    UOmegaActorSubsystem* Subsystem = World->GetSubsystem<UOmegaActorSubsystem>();
    if (!Subsystem)
    {
        return;
    }

    AOmegaWorldManager* WorldManager = Subsystem->GetWorldManager();
    if (!WorldManager)
    {
        return;
    }

    WorldManager->SetActorMetadata(SelectedActor.Get(), NewMetadata);
}

// ===== Bool Properties =====

void FOmegaActorDetailsCustomization::CreateBoolProperty(IDetailCategoryBuilder& Category, FName ParamName)
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
            .IsChecked_Lambda([this, ParamName]()
            {
                TOptional<bool> Value = GetBoolValue(ParamName);
                return Value.IsSet() && Value.GetValue() ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
            })
            .OnCheckStateChanged_Lambda([this, ParamName](ECheckBoxState NewState)
            {
                SetBoolValue(NewState == ECheckBoxState::Checked, ParamName);
            })
        ];
}

TOptional<bool> FOmegaActorDetailsCustomization::GetBoolValue(FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    if (const bool* Value = Metadata.BoolParams.Find(ParamName))
    {
        return *Value;
    }
    return false;
}

void FOmegaActorDetailsCustomization::SetBoolValue(bool NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    Metadata.BoolParams.Add(ParamName, NewValue);
    SetMetadata(Metadata);
}

// ===== Int Properties =====

void FOmegaActorDetailsCustomization::CreateIntProperty(IDetailCategoryBuilder& Category, FName ParamName)
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
            .Value_Lambda([this, ParamName]()
            {
                return GetIntValue(ParamName);
            })
            .OnValueChanged_Lambda([this, ParamName](int32 NewValue)
            {
                SetIntValue(NewValue, ParamName);
            })
            .AllowSpin(true)
        ];
}

TOptional<int32> FOmegaActorDetailsCustomization::GetIntValue(FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    if (const int32* Value = Metadata.IntParams.Find(ParamName))
    {
        return *Value;
    }
    return 0;
}

void FOmegaActorDetailsCustomization::SetIntValue(int32 NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    Metadata.IntParams.Add(ParamName, NewValue);
    SetMetadata(Metadata);
}

// ===== Float Properties =====

void FOmegaActorDetailsCustomization::CreateFloatProperty(IDetailCategoryBuilder& Category, FName ParamName)
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
            .Value_Lambda([this, ParamName]()
            {
                return GetFloatValue(ParamName);
            })
            .OnValueChanged_Lambda([this, ParamName](float NewValue)
            {
                SetFloatValue(NewValue, ParamName);
            })
            .AllowSpin(true)
        ];
}

TOptional<float> FOmegaActorDetailsCustomization::GetFloatValue(FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    if (const float* Value = Metadata.FloatParams.Find(ParamName))
    {
        return *Value;
    }
    return 0.0f;
}

void FOmegaActorDetailsCustomization::SetFloatValue(float NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    Metadata.FloatParams.Add(ParamName, NewValue);
    SetMetadata(Metadata);
}

// ===== String Properties =====

void FOmegaActorDetailsCustomization::CreateStringProperty(IDetailCategoryBuilder& Category, FName ParamName)
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
            .Text_Lambda([this, ParamName]()
            {
                return GetStringValue(ParamName);
            })
            .OnTextCommitted_Lambda([this, ParamName](const FText& NewText, ETextCommit::Type CommitType)
            {
                SetStringValue(NewText, ParamName);
            })
        ];
}

FText FOmegaActorDetailsCustomization::GetStringValue(FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    if (const FString* Value = Metadata.StringParams.Find(ParamName))
    {
        return FText::FromString(*Value);
    }
    return FText::GetEmpty();
}

void FOmegaActorDetailsCustomization::SetStringValue(const FText& NewValue, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    Metadata.StringParams.Add(ParamName, NewValue.ToString());
    SetMetadata(Metadata);
}

// ===== DataAsset Properties =====

void FOmegaActorDetailsCustomization::CreateDataAssetProperty(IDetailCategoryBuilder& Category, FName ParamName)
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
            .ObjectPath_Lambda([this, ParamName]()
            {
                UObject* Object = GetDataAssetValue(ParamName);
                return Object ? Object->GetPathName() : FString();
            })
            .OnObjectChanged_Lambda([this, ParamName](const FAssetData& AssetData)
            {
                SetDataAssetValue(AssetData, ParamName);
            })
        ];
}

UObject* FOmegaActorDetailsCustomization::GetDataAssetValue(FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    if (UPrimaryDataAsset* const* Value = Metadata.DataAssetParams.Find(ParamName))
    {
        return *Value;
    }
    return nullptr;
}

void FOmegaActorDetailsCustomization::SetDataAssetValue(const FAssetData& AssetData, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    Metadata.DataAssetParams.Add(ParamName, Cast<UPrimaryDataAsset>(AssetData.GetAsset()));
    SetMetadata(Metadata);
}

// ===== Actor Properties =====

void FOmegaActorDetailsCustomization::CreateActorProperty(IDetailCategoryBuilder& Category, FName ParamName)
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
            .ObjectPath_Lambda([this, ParamName]()
            {
                UObject* Object = GetActorValue(ParamName);
                return Object ? Object->GetPathName() : FString();
            })
            .OnObjectChanged_Lambda([this, ParamName](const FAssetData& AssetData)
            {
                SetActorValue(AssetData, ParamName);
            })
        ];
}

UObject* FOmegaActorDetailsCustomization::GetActorValue(FName ParamName) const
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    if (const TSoftObjectPtr<AActor>* Value = Metadata.ActorParams.Find(ParamName))
    {
        return Value->Get();
    }
    return nullptr;
}

void FOmegaActorDetailsCustomization::SetActorValue(const FAssetData& AssetData, FName ParamName)
{
    FOmegaActorInstanceMetadata Metadata = GetMetadata();
    AActor* Actor = Cast<AActor>(AssetData.GetAsset());
    Metadata.ActorParams.Add(ParamName, TSoftObjectPtr<AActor>(Actor));
    SetMetadata(Metadata);
}