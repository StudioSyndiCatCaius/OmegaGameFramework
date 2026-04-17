#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "OmegaGameAsset.h"
#include "GameAsset_Factory.generated.h"

UCLASS()
class UGameplayAssetFactory : public UFactory
{
    GENERATED_BODY()

public:
    UGameplayAssetFactory();

    // The specific subclass chosen by the user in the picker dialog
    UPROPERTY()
    TSubclassOf<UOmegaGameAsset> ChosenClass;

    // UFactory interface
    virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent,
                                       FName InName, EObjectFlags Flags,
                                       UObject* Context,
                                       FFeedbackContext* Warn) override;
    virtual bool ConfigureProperties() override;
    virtual bool ShouldShowInNewMenu() const override { return true; }
    virtual FText GetDisplayName() const override;
    virtual FText GetToolTip() const override;
    virtual uint32 GetMenuCategories() const override;
};
