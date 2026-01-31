// OmegaPropertyHidingCustomization.h
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FOmegaPropertyHidingCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	void HidePropertiesAndCategories(IDetailLayoutBuilder& DetailBuilder, UObject* Object);
    TArray<TWeakObjectPtr<UObject>> SelectedObjects;
};