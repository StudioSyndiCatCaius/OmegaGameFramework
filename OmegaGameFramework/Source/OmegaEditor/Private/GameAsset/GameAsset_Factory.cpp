#include "GameAsset/GameAsset_Factory.h"
#include "OmegaGameAsset.h"
#include "AssetTypeCategories.h"
#include "ClassViewerModule.h"
#include "ClassViewerFilter.h"
#include "Kismet2/SClassPickerDialog.h"
#include "Modules/ModuleManager.h"

// ── Class picker filter — only shows UGameplayAsset subclasses ────────────────

class FGameplayAssetClassFilter : public IClassViewerFilter
{
public:
    virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions,
                                const UClass* InClass,
                                TSharedRef<FClassViewerFilterFuncs> InFilterFuncs) override
    {
        if (!InClass) return false;
        return InClass->IsChildOf(UOmegaGameAsset::StaticClass())
            && !InClass->HasAnyClassFlags(CLASS_Abstract | CLASS_Deprecated | CLASS_HideDropDown);
    }

    virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions,
                                        const TSharedRef<const IUnloadedBlueprintData> InUnloadedClassData,
                                        TSharedRef<FClassViewerFilterFuncs> InFilterFuncs) override
    {
        return InUnloadedClassData->IsChildOf(UOmegaGameAsset::StaticClass());
    }
};


// ── UGameplayAssetFactory ─────────────────────────────────────────────────────

UGameplayAssetFactory::UGameplayAssetFactory()
{
    bCreateNew         = true;
    bEditAfterNew      = true;
    SupportedClass     = UOmegaGameAsset::StaticClass();
    ChosenClass        = UOmegaGameAsset::StaticClass();
}

FText UGameplayAssetFactory::GetDisplayName() const
{
    return NSLOCTEXT("GameplayAsset", "FactoryDisplayName", "Gameplay Asset");
}

FText UGameplayAssetFactory::GetToolTip() const
{
    return NSLOCTEXT("GameplayAsset", "FactoryToolTip",
        "Create a new Gameplay Asset. You will be prompted to choose a specific type.");
}

uint32 UGameplayAssetFactory::GetMenuCategories() const
{
    return EAssetTypeCategories::Gameplay;
}

bool UGameplayAssetFactory::ConfigureProperties()
{
    ChosenClass = nullptr;

    FClassViewerInitializationOptions Options;
    Options.Mode                    = EClassViewerMode::ClassPicker;
    Options.DisplayMode             = EClassViewerDisplayMode::ListView;
    Options.bShowUnloadedBlueprints = true;
    Options.bShowNoneOption         = false;
    Options.bExpandRootNodes        = false;
    Options.NameTypeToDisplay       = EClassViewerNameTypeToDisplay::DisplayName;
    Options.ClassFilters.Add(MakeShared<FGameplayAssetClassFilter>());
    Options.bShowObjectRootClass    = false;

    UClass* PickedClass = nullptr;
    const bool bPicked  = SClassPickerDialog::PickClass(
        NSLOCTEXT("GameplayAsset", "PickClassTitle", "Pick Gameplay Asset Type"),
        Options,
        PickedClass,
        UOmegaGameAsset::StaticClass());

    if (bPicked && PickedClass)
    {
        ChosenClass    = PickedClass;
        SupportedClass = PickedClass;
        return true;
    }
    return false;
}

UObject* UGameplayAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent,
                                                   FName InName, EObjectFlags Flags,
                                                   UObject* Context, FFeedbackContext* Warn)
{
    TSubclassOf<UOmegaGameAsset> ClassToUse;
    if (ChosenClass)
    {
        ClassToUse = ChosenClass;
    }
    else
    {
        ClassToUse = UOmegaGameAsset::StaticClass();
    }
    return NewObject<UOmegaGameAsset>(InParent, ClassToUse, InName, Flags);
}
