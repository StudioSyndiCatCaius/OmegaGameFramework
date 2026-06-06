// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "Misc/OmegaUtils_Structs.h"

class FOmegaEntityIDCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	TSharedPtr<IPropertyHandle> StructHandle;

	// entity_type / entity_string lack EditAnywhere so we bypass child handles
	// and access struct memory directly via GetStructPtr().
	FOmegaEntityID* GetStructPtr() const;

	uint8 GetCurrentType() const;
	void SetCurrentType(uint8 NewType);
	FText GetTypeLabel(uint8 Type) const;
	FText GetCurrentTypeLabel() const;

	FString GetEntityString() const;
	void SetEntityString(const FString& NewValue);

	// Asset picker helpers (type 0)
	FString GetAssetPath() const;
	void OnAssetChanged(const FAssetData& AssetData);

	TSharedRef<SWidget> MakeTypePickerMenu();
};
