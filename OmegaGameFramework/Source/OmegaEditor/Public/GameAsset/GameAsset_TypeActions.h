#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class FGameplayAssetTypeActions : public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions interface
	virtual FText     GetName()           const override;
	virtual FColor    GetTypeColor()      const override { return FColor(100, 80, 200); }
	virtual UClass*   GetSupportedClass() const override;
	virtual uint32    GetCategories()     override;
	virtual void      OpenAssetEditor(const TArray<UObject*>& InObjects,
									  TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
};