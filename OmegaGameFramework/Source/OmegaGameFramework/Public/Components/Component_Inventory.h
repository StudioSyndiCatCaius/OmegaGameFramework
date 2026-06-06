// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Misc/GeneralDataObject.h"
#include "Component_Inventory.generated.h"

class UCombatantComponent;

/*

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetAdded, UPrimaryDataAsset*, Asset, int32, Amount, bool, IsFull);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetRemoved, UDataAsset*, Asset, int32, Amount, bool, IsEmpty);



UCLASS( ClassGroup=("Omega Game Framework"), DisplayName="Inventory (Data Asset Collection)", meta=(BlueprintSpawnableComponent),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API UDataAssetCollectionComponent : public UOmegaGameplayComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDataAssetCollectionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere,Category="Inventory",meta=(MustImplement="DataAssetCollectionInterface"))
	TMap<UPrimaryDataAsset*, int32> InventoryAssets;
	//Assets can have a per-count size. This is the max total size for all assets. If <1, you have infinite size.
	UPROPERTY(EditAnywhere,Category="Inventory") int32 MaxSize=-1;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Inventory",meta=(MustImplement="DataInterface_InventorySource"))
	TArray<UObject*> InventorySources;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Omega|Inventory",DisplayName="Add Asset (Single)")
	void AddAsset(UPrimaryDataAsset* Asset, int32 Amount=1);

	UFUNCTION(BlueprintCallable, Category = "Omega|Inventory",DisplayName="Add Asset (Map)")
	void AddAssets(TMap<UPrimaryDataAsset*, int32> Assets,bool bInvertAmount=false);

	UFUNCTION(BlueprintCallable, Category = "Omega|Inventory")
	void RemoveAsset(UPrimaryDataAsset* Asset, int32 Amount=1);

	UFUNCTION(BlueprintPure, Category = "Omega|Inventory")
	int32 GetAssetNumberOfType(UPrimaryDataAsset* Asset);

	UFUNCTION(BlueprintPure, Category = "Omega|Inventory")
	int32 GetAssetNumberTotal();

	UFUNCTION(BlueprintPure, Category = "Omega|Inventory")
	int32 GetCurrentSize();

	UFUNCTION(BlueprintPure, meta = (DeterminesOutputType="Asset"), Category = "Omega|Inventory")
	TArray<UPrimaryDataAsset*> GetCollectionAsArray(UPrimaryDataAsset* Asset);

	UFUNCTION(BlueprintCallable, Category = "Omega|Inventory")
	void SetCollectionMap(TMap<UPrimaryDataAsset*, int32> Map);

	UFUNCTION(BlueprintPure, Category = "Omega|Inventory", DisplayName="Get Asset Collection Map")
	TMap<UPrimaryDataAsset*, int32> GetCollectionMap(int32 Min=1,bool IncludeSources=true);

	UPROPERTY(BlueprintAssignable, Category="Omega") FOnAssetAdded OnAssetAdded;

	//TRANSFEr
	UFUNCTION(BlueprintCallable, Category="Omega|Inventory|Transfer")
	void TransferAssetToCollection(UDataAssetCollectionComponent* To, UPrimaryDataAsset* Asset, int32 Amount, bool bTransferAll);

	UFUNCTION(BlueprintCallable, Category="Omega|Inventory|Transfer")
	void TransferAllAssetsToCollection(UDataAssetCollectionComponent* To);

	//Checks if the collection has enough of each given type of asset;
	UFUNCTION(BlueprintPure, Category="Omega|Inventory|Transfer")
	bool HasMinimumAssets(TMap<UPrimaryDataAsset*, int32> Assets);
};

*/

// Implement on data assets to define per-item inventory rules such as stack limits and trade costs.
UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Inventory Item") class UDataInterface_InventoryItem : public UInterface { GENERATED_BODY()};
class OMEGAGAMEFRAMEWORK_API IDataInterface_InventoryItem
{
	GENERATED_BODY()
public:

	// Returns the maximum number of this item that can exist in a single stack/slot.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🧪Inventory",DisplayName="🧪Inventory Item - Get Max Amount")
	int32 GetMaxCollectionNumber();

	// Returns the inventory "size" cost of a single unit of this item.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🧪Inventory",DisplayName="🧪Inventory Item - Get Size Per Max")
	int32 GetSizePerAmount();

	// Returns the assets and quantities required to trade for this item under the given trade tag.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🧪Inventory",DisplayName="🧪Inventory Item - Get Trade Requirements")
	TMap<UPrimaryDataAsset*, int32> GetTradeAssetRequirements(FGameplayTag TradeTag);
};


// Implement on any object that can supply a pre-defined inventory map (e.g. loot tables, shop presets).
UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Inventory Source") class UDataInterface_InventorySource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_InventorySource
{
	GENERATED_BODY()
public:

	// Returns the item-to-quantity map this object provides as an inventory source.
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|Inventory",DisplayName="Inventory Source - Get Items")
	TMap<UPrimaryDataAsset*,int32> GetInventory();
};




// A data asset that defines a preset inventory (item/quantity map) for use as an inventory source.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCommonInventory : public UOmegaDataAsset, public IDataInterface_InventorySource
{
	GENERATED_BODY()

	public:

	// The items and their default quantities contained in this preset inventory.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Inventory")
	TMap<UPrimaryDataAsset*, int32> Inventory;

	virtual TMap<UPrimaryDataAsset*, int32> GetInventory_Implementation() override;
};
