// OmegaSpawnableConfigCustomization.h
#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "Engine/DataAsset.h"

class IDetailChildrenBuilder;
class FDetailWidgetRow;
class IPropertyTypeCustomizationUtils;
class IPropertyHandle;

/**
 * Property customization for FOmegaSpawnableConfig.
 *
 * Behaviour:
 *  - SpawnableClass is always shown first.
 *  - Identity is shown second, filtered to subclasses returned by
 *    IActorInterface_Spawnable::Execute_GetSpawnableIdentities on the CDO.
 *    If the CDO returns an empty list the picker is unfiltered.
 *  - Param maps are NOT shown as raw maps. Instead, per-key rows are built
 *    dynamically from IActorInterface_Spawnable::Execute_GetSpawnableParams.
 *    Keys are added/removed automatically whenever SpawnableClass changes so
 *    the stored data always matches exactly what the interface declares.
 *  - If the selected class does not implement the interface, only SpawnableClass
 *    and Identity are shown with a warning banner.
 *
 * Register in your Editor module's StartupModule():
 *   FPropertyEditorModule& PropModule =
 *       FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
 *   PropModule.RegisterCustomPropertyTypeLayout(
 *       FOmegaSpawnableConfig::StaticStruct()->GetFName(),
 *       FOnGetPropertyTypeCustomizationInstance::CreateStatic(
 *           &FOmegaSpawnableConfigCustomization::MakeInstance));
 *   PropModule.NotifyCustomizationModuleChanged();
 *
 * Requires in your editor module's PrivateDependencyModuleNames:
 *   "PropertyEditor", "CoreUObject", "Engine", "Slate", "SlateCore"
 *   + your game module name.
 */
class FOmegaSpawnableConfigCustomization final : public IPropertyTypeCustomization
{
public:
    static TSharedRef<IPropertyTypeCustomization> MakeInstance();

    //~ IPropertyTypeCustomization
    virtual void CustomizeHeader(
        TSharedRef<IPropertyHandle>       StructPropertyHandle,
        FDetailWidgetRow&                 HeaderRow,
        IPropertyTypeCustomizationUtils&  CustomizationUtils) override;

    virtual void CustomizeChildren(
        TSharedRef<IPropertyHandle>       StructPropertyHandle,
        IDetailChildrenBuilder&           ChildBuilder,
        IPropertyTypeCustomizationUtils&  CustomizationUtils) override;
    //~ End IPropertyTypeCustomization

private:
    // ── Property handles ─────────────────────────────────────────────────────
    TSharedPtr<IPropertyHandle> StructHandle;
    TSharedPtr<IPropertyHandle> SpawnableClassHandle;
    TSharedPtr<IPropertyHandle> IdentityHandle;
    TSharedPtr<IPropertyHandle> ParamsBoolHandle;
    TSharedPtr<IPropertyHandle> ParamsIntHandle;
    TSharedPtr<IPropertyHandle> ParamsFloatHandle;
    TSharedPtr<IPropertyHandle> ParamsActorHandle;
    TSharedPtr<IPropertyHandle> ParamsDataAssetsHandle;

    IPropertyTypeCustomizationUtils* CachedUtils = nullptr;

    // ── CDO query cache (refreshed at the start of every CustomizeChildren) ──
    TArray<TSubclassOf<UPrimaryDataAsset>> CachedIdentityClasses;
    TArray<FName> CachedBools;
    TArray<FName> CachedInts;
    TArray<FName> CachedFloats;
    TArray<FName> CachedActors;
    TArray<FName> CachedDataAssets;

    // ── Helpers ───────────────────────────────────────────────────────────────

    /** Returns the UClass* currently selected in SpawnableClassHandle, or nullptr. */
    UClass* GetCurrentSpawnableClass() const;

    /** Returns true if InClass is non-null and implements UActorInterface_Spawnable. */
    bool DoesClassImplementInterface(UClass* InClass) const;

    /**
     * Calls Execute_GetSpawnableIdentities and Execute_GetSpawnableParams on the
     * class CDO and stores the results in the Cached* arrays. Clears them first.
     * Safe to call with a null or non-interface class (just clears the arrays).
     */
    void QueryCDO(UClass* InClass);

    /**
     * Makes the map contain EXACTLY the keys in Keys with default values.
     * - Keys missing from the map are added with a default value.
     * - Keys present in the map but absent from Keys are removed.
     * Undo-safe: wraps all mutations in NotifyPreChange / NotifyPostChange.
     * Uses FScriptMapHelper directly for structural add/remove (correct approach
     * since IPropertyHandle has no map-insertion API).
     */
    void SyncMapToKeys(TSharedRef<IPropertyHandle> MapHandle,
                       const TArray<FName>&        Keys) const;

    /**
     * Walks the map handle's child pair handles to find the value IPropertyHandle
     * whose key matches Key. Returns nullptr if not found.
     * This is the correct way to obtain an editable handle into a map value —
     * avoids any raw memory access for read/write operations.
     */
    TSharedPtr<IPropertyHandle> FindMapValueHandle(
        TSharedPtr<IPropertyHandle> MapHandle, const FName& Key) const;

    // ── Row builders ──────────────────────────────────────────────────────────

    /** Adds a tinted section separator row with the given title. */
    void AddSectionHeader(IDetailChildrenBuilder& Builder, const FText& Title) const;

    /**
     * Adds a single labelled row for Key inside MapHandle.
     * Resolves the value IPropertyHandle via FindMapValueHandle and calls
     * CreatePropertyValueWidget() so the engine generates the correct widget
     * (checkbox, numeric field, object picker, etc.) with full undo/serialization.
     */
    void AddParamRow(IDetailChildrenBuilder&     Builder,
                     const FName&                Key,
                     TSharedPtr<IPropertyHandle> MapHandle) const;

    // ── Callbacks ─────────────────────────────────────────────────────────────

    /**
     * Called whenever SpawnableClass changes.
     * Re-queries the CDO, syncs all five maps to the new key sets, then
     * requests a full detail layout refresh so param rows update immediately.
     */
    void OnSpawnableClassChanged();
};