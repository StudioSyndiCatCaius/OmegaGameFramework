// Copyright 2018-2023 - Roberto De Ioris

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Editor/PropertyEditor/Public/IPropertyTypeCustomization.h"
#include "Runtime/SlateCore/Public/Layout/Visibility.h"
#include "LuaMachine/Public/LuaValue.h"

class FLuaValueCustomization : public IPropertyTypeCustomization
{
public:
	// IPropertyTypeCustomization interface
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& Builder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	static TSharedRef<IPropertyTypeCustomization> MakeInstance()
	{
		return MakeShareable(new FLuaValueCustomization());
	}

	EVisibility IsPropertyVisible(TSharedRef<IPropertyHandle> PropertyHandle, ELuaValueType WantedValueType);

	void LuaFunctionChanged(TSharedPtr<FString> Value, ESelectInfo::Type SelectionType, TSharedRef<IPropertyHandle> PropertyHandle);
protected:
	TArray<TSharedPtr<FString>> ValidLuaFunctions;
};


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
    
	FText GetLuaCodeText() const;
	void OnLuaCodeTextChanged(const FText& NewText);
	void OnLuaCodeTextCommitted(const FText& NewText, ETextCommit::Type CommitType);
};