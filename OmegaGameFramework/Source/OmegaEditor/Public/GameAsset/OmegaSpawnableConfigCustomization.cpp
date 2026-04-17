// OmegaSpawnableConfigCustomization.cpp

#include "OmegaSpawnableConfigCustomization.h"

// Property editor
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "PropertyHandle.h"
#include "PropertyCustomizationHelpers.h"

// Map helper

// Slate
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Styling/AppStyle.h"

// Game module – adjust to your actual include path
#include "IPropertyUtilities.h"
#include "Actors/Actor_Spawnable.h"

// =============================================================================
//  Factory
// =============================================================================

TSharedRef<IPropertyTypeCustomization> FOmegaSpawnableConfigCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaSpawnableConfigCustomization());
}

// =============================================================================
//  CustomizeHeader
// =============================================================================

void FOmegaSpawnableConfigCustomization::CustomizeHeader(
    TSharedRef<IPropertyHandle>       StructPropertyHandle,
    FDetailWidgetRow&                 HeaderRow,
    IPropertyTypeCustomizationUtils&  CustomizationUtils)
{
    StructHandle  = StructPropertyHandle;
    CachedUtils   = &CustomizationUtils;

    SpawnableClassHandle   = StructHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaSpawnableConfig, SpawnableClass));
    IdentityHandle         = StructHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FOmegaSpawnableConfig, Identity));

    if (SpawnableClassHandle.IsValid())
    {
        SpawnableClassHandle->SetOnPropertyValueChanged(
            FSimpleDelegate::CreateSP(this, &FOmegaSpawnableConfigCustomization::OnSpawnableClassChanged));
    }

    HeaderRow
        .NameContent()  [ StructHandle->CreatePropertyNameWidget()  ]
        .ValueContent() [ StructHandle->CreatePropertyValueWidget() ];
}

// =============================================================================
//  CustomizeChildren
// =============================================================================

void FOmegaSpawnableConfigCustomization::CustomizeChildren(
    TSharedRef<IPropertyHandle>       StructPropertyHandle,
    IDetailChildrenBuilder&           ChildBuilder,
    IPropertyTypeCustomizationUtils&  CustomizationUtils)
{
    UClass* CurrentClass = GetCurrentSpawnableClass();
    QueryCDO(CurrentClass);
    const bool bHasInterface = DoesClassImplementInterface(CurrentClass);

    // ── 1. SpawnableClass ────────────────────────────────────────────────────
    if (SpawnableClassHandle.IsValid())
    {
        ChildBuilder.AddProperty(SpawnableClassHandle.ToSharedRef());
    }

    // ── 2. Identity (filtered by GetSpawnableIdentities) ─────────────────────
    if (IdentityHandle.IsValid())
    {
        TArray<TSubclassOf<UPrimaryDataAsset>> IdentityClasses = CachedIdentityClasses;

        ChildBuilder.AddCustomRow(FText::FromString("Identity"))
        .NameContent()
        [
            IdentityHandle->CreatePropertyNameWidget()
        ]
        .ValueContent()
        [
            SNew(SObjectPropertyEntryBox)
            .PropertyHandle(IdentityHandle)
            .AllowedClass(UPrimaryDataAsset::StaticClass())
            .AllowClear(true)
            .OnShouldFilterAsset_Lambda(
                [IdentityClasses](const FAssetData& AssetData) -> bool
                {
                    // Return true = hide. Empty list = show all.
                    if (IdentityClasses.IsEmpty()) return false;
                    const UClass* AssetClass = AssetData.GetClass();
                    if (!AssetClass) return true;
                    for (const TSubclassOf<UPrimaryDataAsset>& AccClass : IdentityClasses)
                    {
                        if (AccClass && AssetClass->IsChildOf(AccClass))
                            return false;
                    }
                    return true;
                })
        ];
    }

    // ── 3. No-interface warning ───────────────────────────────────────────────
    if (!bHasInterface)
    {
        if (CurrentClass)
        {
            ChildBuilder.AddCustomRow(FText::FromString("InterfaceWarning"))
            .WholeRowContent()
            [
                SNew(SBorder)
                .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
                .BorderBackgroundColor(FLinearColor(0.5f, 0.25f, 0.0f, 0.6f))
                .Padding(FMargin(6.f, 4.f))
                [
                    SNew(STextBlock)
                    .Text(FText::FromString(
                        "Selected class does not implement IActorInterface_Spawnable. "
                        "No param rows will be shown."))
                    .Font(IDetailLayoutBuilder::GetDetailFont())
                    .ColorAndOpacity(FLinearColor::White)
                    .AutoWrapText(true)
                ]
            ];
        }
        return;
    }

    // ── 4. Per-key param rows ─────────────────────────────────────────────────
    auto BuildSection = [&](const FText& Title,
                            const TArray<FName>& Keys,
                            TSharedPtr<IPropertyHandle> MapHandle)
    {
        if (Keys.IsEmpty()) return;
        AddSectionHeader(ChildBuilder, Title);
        for (const FName& Key : Keys)
            AddParamRow(ChildBuilder, Key, MapHandle);
    };

    BuildSection(FText::FromString("Bool Params"),        CachedBools,      ParamsBoolHandle);
    BuildSection(FText::FromString("Int Params"),         CachedInts,       ParamsIntHandle);
    BuildSection(FText::FromString("Float Params"),       CachedFloats,     ParamsFloatHandle);
    BuildSection(FText::FromString("Actor Params"),       CachedActors,     ParamsActorHandle);
    BuildSection(FText::FromString("Data Asset Params"),  CachedDataAssets, ParamsDataAssetsHandle);
}

// =============================================================================
//  Helpers
// =============================================================================

UClass* FOmegaSpawnableConfigCustomization::GetCurrentSpawnableClass() const
{
    if (!SpawnableClassHandle.IsValid()) return nullptr;
    UObject* Raw = nullptr;
    return (SpawnableClassHandle->GetValue(Raw) == FPropertyAccess::Success)
        ? Cast<UClass>(Raw) : nullptr;
}

bool FOmegaSpawnableConfigCustomization::DoesClassImplementInterface(UClass* InClass) const
{
    return InClass && InClass->ImplementsInterface(UActorInterface_Spawnable::StaticClass());
}

void FOmegaSpawnableConfigCustomization::QueryCDO(UClass* InClass)
{
    CachedIdentityClasses.Reset();
    CachedBools.Reset();
    CachedInts.Reset();
    CachedFloats.Reset();
    CachedActors.Reset();
    CachedDataAssets.Reset();

    if (!DoesClassImplementInterface(InClass)) return;

    AActor* CDO = Cast<AActor>(InClass->GetDefaultObject(/*bCreateIfNeeded=*/false));
    if (!IsValid(CDO)) return;
    
}

void FOmegaSpawnableConfigCustomization::SyncMapToKeys(
    TSharedRef<IPropertyHandle> MapHandle,
    const TArray<FName>&        Keys) const
{
    FMapProperty* MapProp = CastField<FMapProperty>(MapHandle->GetProperty());
    if (!MapProp || !CastField<FNameProperty>(MapProp->KeyProp)) return;

    TArray<void*> RawData;
    MapHandle->AccessRawData(RawData);
    if (RawData.IsEmpty()) return;

    MapHandle->NotifyPreChange();

    const TSet<FName> DesiredSet(Keys);

    for (void* Data : RawData)
    {
        if (!Data) continue;
        FScriptMapHelper Helper(MapProp, Data);

        // Remove keys no longer in the interface
        for (int32 i = Helper.GetMaxIndex() - 1; i >= 0; --i)
        {
            if (!Helper.IsValidIndex(i)) continue;
            const FName* K = reinterpret_cast<const FName*>(Helper.GetKeyPtr(i));
            if (K && !DesiredSet.Contains(*K))
                Helper.RemoveAt(i);
        }
        Helper.Rehash();

        // Add keys missing from the map
        TSet<FName> Existing;
        for (int32 i = 0; i < Helper.GetMaxIndex(); ++i)
        {
            if (!Helper.IsValidIndex(i)) continue;
            if (const FName* K = reinterpret_cast<const FName*>(Helper.GetKeyPtr(i)))
                Existing.Add(*K);
        }

        bool bAdded = false;
        for (const FName& Key : Keys)
        {
            if (!Existing.Contains(Key))
            {
                const int32 Idx = Helper.AddDefaultValue_Invalid_NeedsRehash();
                if (FName* NewKey = reinterpret_cast<FName*>(Helper.GetKeyPtr(Idx)))
                    *NewKey = Key;
                bAdded = true;
            }
        }
        if (bAdded) Helper.Rehash();
    }

    MapHandle->NotifyPostChange(EPropertyChangeType::ArrayAdd);
}

TSharedPtr<IPropertyHandle> FOmegaSpawnableConfigCustomization::FindMapValueHandle(
    TSharedPtr<IPropertyHandle> MapHandle, const FName& Key) const
{
    if (!MapHandle.IsValid()) return nullptr;

    uint32 NumChildren = 0;
    if (MapHandle->GetNumChildren(NumChildren) != FPropertyAccess::Success) return nullptr;

    for (uint32 i = 0; i < NumChildren; ++i)
    {
        // Each child of a map handle is a key-value pair.
        // GetChildHandle(0) = key,  GetChildHandle(1) = value.
        TSharedPtr<IPropertyHandle> PairHandle = MapHandle->GetChildHandle(i);
        if (!PairHandle.IsValid()) continue;

        TSharedPtr<IPropertyHandle> KeyHandle = PairHandle->GetChildHandle(0);
        if (!KeyHandle.IsValid()) continue;

        FName ExistingKey;
        if (KeyHandle->GetValue(ExistingKey) == FPropertyAccess::Success
            && ExistingKey == Key)
        {
            return PairHandle->GetChildHandle(1);
        }
    }
    return nullptr;
}

// =============================================================================
//  Section header
// =============================================================================

void FOmegaSpawnableConfigCustomization::AddSectionHeader(
    IDetailChildrenBuilder& Builder, const FText& Title) const
{
    Builder.AddCustomRow(Title)
    .WholeRowContent()
    [
        SNew(SBorder)
        .BorderImage(FAppStyle::GetBrush("DetailsView.CategoryTop"))
        .BorderBackgroundColor(FLinearColor(0.1f, 0.1f, 0.1f, 0.8f))
        .Padding(FMargin(6.f, 3.f))
        [
            SNew(STextBlock)
            .Text(Title)
            .Font(IDetailLayoutBuilder::GetDetailFont())
            .ColorAndOpacity(FLinearColor(0.7f, 0.85f, 1.f))
        ]
    ];
}

// =============================================================================
//  Generic param row
// =============================================================================

void FOmegaSpawnableConfigCustomization::AddParamRow(
    IDetailChildrenBuilder&     Builder,
    const FName&                Key,
    TSharedPtr<IPropertyHandle> MapHandle) const
{
    TSharedPtr<IPropertyHandle> ValueHandle = FindMapValueHandle(MapHandle, Key);
    if (!ValueHandle.IsValid()) return;

    Builder.AddCustomRow(FText::FromName(Key))
    .NameContent()
    [
        SNew(STextBlock)
        .Text(FText::FromName(Key))
        .Font(IDetailLayoutBuilder::GetDetailFont())
    ]
    .ValueContent()
    .MaxDesiredWidth(TOptional<float>())
    [
        ValueHandle->CreatePropertyValueWidget()
    ];
}

// =============================================================================
//  Callback
// =============================================================================

void FOmegaSpawnableConfigCustomization::OnSpawnableClassChanged()
{
    UClass* NewClass = GetCurrentSpawnableClass();
    QueryCDO(NewClass);

    const bool bHasInterface = DoesClassImplementInterface(NewClass);
    const TArray<FName> Empty;

    auto Sync = [&](TSharedPtr<IPropertyHandle>& H, const TArray<FName>& Keys)
    {
        if (H.IsValid())
            SyncMapToKeys(H.ToSharedRef(), bHasInterface ? Keys : Empty);
    };

    Sync(ParamsBoolHandle,       CachedBools);
    Sync(ParamsIntHandle,        CachedInts);
    Sync(ParamsFloatHandle,      CachedFloats);
    Sync(ParamsActorHandle,      CachedActors);
    Sync(ParamsDataAssetsHandle, CachedDataAssets);

    if (CachedUtils)
        CachedUtils->GetPropertyUtilities()->RequestRefresh();
}