// Customization_ClassNamedLists.h
#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FCustomization_ClassNamedLists : public IPropertyTypeCustomization
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
	TSharedPtr<IPropertyHandle> MapPropertyHandle;
    
	TSharedRef<SWidget> CreateDropdownList(const TArray<FName>& Lists, TSharedRef<IPropertyHandle> StructPropertyHandle);
	TSharedRef<SWidget> CreateDropdownForList(FName ListID, TSharedRef<IPropertyHandle> StructPropertyHandle);
	void SetOptionForList(FName ListID, FName OptionValue, TSharedRef<IPropertyHandle> StructPropertyHandle);
	FName GetOptionForList(FName ListID, TSharedRef<IPropertyHandle> StructPropertyHandle) const;
};