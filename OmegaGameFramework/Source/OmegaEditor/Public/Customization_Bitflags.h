// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "Interfaces/I_BitFlag.h"
//#include "OmegaPropertyCustomization.generated.h"


// ==================================================================================================================
// BIT FLAGS
// ==================================================================================================================


class FOmegaBitflagsCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	TSharedPtr<IPropertyHandle> BitmaskPropertyHandle;
	TSharedPtr<IPropertyHandle> BitEnumsPropertyHandle;
	TSharedPtr<IPropertyHandle> StructPropertyHandle;
	UClass* CachedOwnerClass;

	FText GetHeaderValueText() const;
	ECheckBoxState IsChecked(int32 BitIndex) const;
	void OnCheckStateChanged(ECheckBoxState NewState, int32 BitIndex);
    
	// BitEnums helpers
	int32 GetBitEnumValue(int32 BitIndex) const;
	void SetBitEnumValue(int32 BitIndex, int32 NewValue);
	FText GetBitEnumDisplayText(int32 BitIndex) const;
	TSharedRef<SWidget> GenerateEnumComboContent(int32 BitIndex);
    
	// Helper to get the owner class
	UClass* GetOwnerClass(TSharedRef<IPropertyHandle> PropertyHandle) const;
};

