#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "PropertyHandle.h"

class IDetailsView;

class FCustomization_OmegaLinearChoices : public IPropertyTypeCustomization
{
public:
    static TSharedRef<IPropertyTypeCustomization> MakeInstance();

    virtual void CustomizeHeader(
        TSharedRef<IPropertyHandle> PropertyHandle,
        FDetailWidgetRow& HeaderRow,
        IPropertyTypeCustomizationUtils& CustomizationUtils) override;

    virtual void CustomizeChildren(
        TSharedRef<IPropertyHandle> PropertyHandle,
        IDetailChildrenBuilder& ChildBuilder,
        IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
    TSharedPtr<IPropertyHandle> ChoicesPropertyHandle;
    IPropertyTypeCustomizationUtils* CustomizationUtilsPtr;

    FReply OnAddChoicesClicked(int32 Count);  // Changed to accept count parameter
    FReply OnDeleteAllClicked();
    void RefreshChildren();
    
    TSharedRef<SWidget> CreateChoiceWidget(TSharedRef<IPropertyHandle> ChoiceHandle, int32 ChoiceIndex);
};