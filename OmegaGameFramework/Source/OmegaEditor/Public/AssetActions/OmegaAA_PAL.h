// Copyright Notice Here

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class UPrimaryAssetLabel;

/**
 * Asset actions for Primary Asset Labels
 * Provides "Cook & Pak" functionality to create .pak files from PAL assets
 */
class FMyPrimaryAssetLabelActions : public FAssetTypeActions_Base
{
public:
	// FAssetTypeActions_Base interface
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual void GetActions(const TArray<UObject*>& InObjects, FToolMenuSection& Section) override;
	// End of FAssetTypeActions_Base interface

private:
	/**
	 * Execute the Cook & Pak operation
	 * @param Labels - Selected Primary Asset Labels
	 * @param bIterative - If true, only cook changed assets
	 */
	void ExecuteCookAndPak(TArray<TWeakObjectPtr<UPrimaryAssetLabel>> Labels, bool bIterative);

	/**
	 * Collect all package names from the Primary Asset Labels
	 * Scans the label's directory recursively for all assets
	 * @param Labels - Labels to collect packages from
	 * @return Set of package names to cook
	 */
	TSet<FName> CollectPackagesFromLabels(const TArray<TWeakObjectPtr<UPrimaryAssetLabel>>& Labels);

	/**
	 * Cook packages using the cook commandlet
	 * @param Packages - Package names to cook
	 * @param bIterative - If true, use iterative cooking
	 */
	void CookPackages(const TArray<FName>& Packages, bool bIterative);

	/**
	 * Create .pak file from cooked assets using UnrealPak
	 * @param Packages - Package names that were cooked
	 * @param OutputPath - Full path for output .pak file
	 */
	void CreatePakFile(const TArray<FName>& Packages, const FString& OutputPath);
};