// OmegaSpawnableConfigCustomization.cpp

#include "OmegaSpawnableConfigCustomization.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "PropertyHandle.h"

TSharedRef<IPropertyTypeCustomization> FOmegaSpawnableConfigCustomization::MakeInstance()
{
    return MakeShareable(new FOmegaSpawnableConfigCustomization());
}

void FOmegaSpawnableConfigCustomization::CustomizeHeader(
    TSharedRef<IPropertyHandle>       StructPropertyHandle,
    FDetailWidgetRow&                 HeaderRow,
    IPropertyTypeCustomizationUtils&  CustomizationUtils)
{
    HeaderRow
        .NameContent()  [ StructPropertyHandle->CreatePropertyNameWidget()  ]
        .ValueContent() [ StructPropertyHandle->CreatePropertyValueWidget() ];
}

void FOmegaSpawnableConfigCustomization::CustomizeChildren(
    TSharedRef<IPropertyHandle>       StructPropertyHandle,
    IDetailChildrenBuilder&           ChildBuilder,
    IPropertyTypeCustomizationUtils&  CustomizationUtils)
{
    uint32 NumChildren = 0;
    StructPropertyHandle->GetNumChildren(NumChildren);
    for (uint32 i = 0; i < NumChildren; ++i)
    {
        ChildBuilder.AddProperty(StructPropertyHandle->GetChildHandle(i).ToSharedRef());
    }
}
