// OmegaSpawnableConfigCustomization.h
#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class IDetailChildrenBuilder;
class FDetailWidgetRow;
class IPropertyTypeCustomizationUtils;
class IPropertyHandle;

class FOmegaSpawnableConfigCustomization final : public IPropertyTypeCustomization
{
public:
    static TSharedRef<IPropertyTypeCustomization> MakeInstance();

    virtual void CustomizeHeader(
        TSharedRef<IPropertyHandle>       StructPropertyHandle,
        FDetailWidgetRow&                 HeaderRow,
        IPropertyTypeCustomizationUtils&  CustomizationUtils) override;

    virtual void CustomizeChildren(
        TSharedRef<IPropertyHandle>       StructPropertyHandle,
        IDetailChildrenBuilder&           ChildBuilder,
        IPropertyTypeCustomizationUtils&  CustomizationUtils) override;
};
