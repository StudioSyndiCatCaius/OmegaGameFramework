// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class FActorPresetTypeActions : public FAssetTypeActions_Base
{
public:
	explicit FActorPresetTypeActions(EAssetTypeCategories::Type InCategory)
		: Category(InCategory) {}

	// IAssetTypeActions interface
	virtual FText   GetName()           const override;
	virtual FColor  GetTypeColor()      const override { return FColor(255, 20, 100); }
	virtual UClass* GetSupportedClass() const override;
	virtual uint32  GetCategories()     override { return Category; }

	/** Opens the custom Actor Preset editor if the asset implements IDataInterface_ActorPreset;
	 *  falls back to the default details editor otherwise. */
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects,
	                             TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;

private:
	EAssetTypeCategories::Type Category;
};
