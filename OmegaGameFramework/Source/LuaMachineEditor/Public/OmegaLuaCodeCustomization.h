#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"

class FOmegaLuaCodeCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, 
		FDetailWidgetRow& HeaderRow, 
		IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, 
		IDetailChildrenBuilder& ChildBuilder, 
		IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	TSharedPtr<IPropertyHandle> LuaCodePropertyHandle;
	TSharedPtr<SMultiLineEditableTextBox> TextBox;

	FText GetLuaCodeText() const;
	void OnLuaCodeTextChanged(const FText& NewText);
	void OnLuaCodeTextCommitted(const FText& NewText, ETextCommit::Type CommitType);
};