// Customization_CustomNamedList.h
#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FCustomization_CustomNamedList : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	// IPropertyTypeCustomization interface
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, 
								 FDetailWidgetRow& HeaderRow, 
								 IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
    
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, 
								   IDetailChildrenBuilder& StructBuilder, 
								   IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	// End of IPropertyTypeCustomization interface

private:
	TSharedPtr<IPropertyHandle> ListIDPropertyHandle;
	TSharedPtr<IPropertyHandle> OptionPropertyHandle;
};