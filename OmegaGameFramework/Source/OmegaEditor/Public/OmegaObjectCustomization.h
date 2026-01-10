// OmegaObjectCustomization.h
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FOmegaObjectCustomization : public IDetailCustomization
{
public:
    static TSharedRef<IDetailCustomization> MakeInstance();
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
    TArray<TWeakObjectPtr<UObject>> SelectedObjects;
};