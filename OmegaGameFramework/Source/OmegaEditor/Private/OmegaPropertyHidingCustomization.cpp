// OmegaPropertyHidingCustomization.cpp
#include "OmegaPropertyHidingCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "OmegaEditorSettings.h"

TSharedRef<IDetailCustomization> FOmegaPropertyHidingCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaPropertyHidingCustomization);
}

void FOmegaPropertyHidingCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
    TArray<TWeakObjectPtr<UObject>> SelectedObjects;
    DetailBuilder.GetObjectsBeingCustomized(SelectedObjects);
    
    if (SelectedObjects.Num() == 0)
        return;

    UObject* FirstObject = SelectedObjects[0].Get();
    if (!FirstObject)
        return;

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