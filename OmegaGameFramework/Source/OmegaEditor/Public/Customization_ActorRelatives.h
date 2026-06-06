// Customization_ActorRelatives.h

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class AActor;
class UPrimaryDataAsset;

/**
 * Property customization for FStruct_ActorRelatives
 * Displays all available relationship keys with actor pickers
 * Uses OGF_GAME_CORE() to get the available keys
 */
class FCustomization_ActorRelatives : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	// IPropertyTypeCustomization interface
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	// End of IPropertyTypeCustomization interface

private:
	// Property handles
	TSharedPtr<IPropertyHandle> StructPropertyHandle;
	TSharedPtr<IPropertyHandle> MapPropertyHandle;
	TSharedPtr<IPropertyHandle> AssetMapPropertyHandle;

	// Get the owner actor
	AActor* GetOwnerActor() const;

	// Get available keys from OmegaGameCore
	TArray<FName> GetAvailableKeys(AActor* OwnerActor) const;
	TArray<FName> GetAvailableAssetKeys(AActor* OwnerActor) const;

	// Get actor for a specific key from the RelativeActors map
	AActor* GetActorForKey(FName Key) const;

	// Set actor for a specific key in the RelativeActors map
	void SetActorForKey(FName Key, AActor* Actor);

	// Get asset for a specific key from the RelativeAssets map
	UPrimaryDataAsset* GetAssetForKey(FName Key) const;

	// Set asset for a specific key in the RelativeAssets map
	void SetAssetForKey(FName Key, UPrimaryDataAsset* Asset);

	// Clean up null entries from the map
	void CleanupNullEntries();

	// Generate a row for a relationship key
	void GenerateKeyRow(IDetailChildrenBuilder& ChildBuilder, FName Key);
	void GenerateAssetKeyRow(IDetailChildrenBuilder& ChildBuilder, FName Key);

	// Get object path for actor key
	FString GetObjectPathForKey(FName Key) const;

	// Get object path for asset key
	FString GetAssetObjectPathForKey(FName Key) const;

	// Handle object changed for a key (RelativeActors)
	void OnObjectChangedForKey(const FAssetData& AssetData, FName Key);

	// Handle asset changed for a key (RelativeAssets)
	void OnAssetChangedForKey(const FAssetData& AssetData, FName Key);
};