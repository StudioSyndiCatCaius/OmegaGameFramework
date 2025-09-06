// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaGameplayComponent.h"
#include "Components/ActorComponent.h"
#include "Misc/GeneralDataObject.h"
#include "Component_Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetAdded, UDataAsset*, Asset, int32, Amount, bool, IsFull);
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

	UPROPERTY(BlueprintAssignable) FOnAssetAdded OnAssetAdded;

	//TRANSFEr
	UFUNCTION(BlueprintCallable, Category="Omega|Inventory|Transfer")
	void TransferAssetToCollection(UDataAssetCollectionComponent* To, UPrimaryDataAsset* Asset, int32 Amount, bool bTransferAll);

	UFUNCTION(BlueprintCallable, Category="Omega|Inventory|Transfer")
	void TransferAllAssetsToCollection(UDataAssetCollectionComponent* To);

	//Checks if the collection has enough of each given type of asset;
	UFUNCTION(BlueprintPure, Category="Omega|Inventory|Transfer")
	bool HasMinimumAssets(TMap<UPrimaryDataAsset*, int32> Assets);
};



UINTERFACE(MinimalAPI)class UDataAssetCollectionInterface : public UInterface { GENERATED_BODY()};
class OMEGAGAMEFRAMEWORK_API IDataAssetCollectionInterface
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Inventory",DisplayName="Inventory Item - Get Max Amount")
	int32 GetMaxCollectionNumber();

	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Inventory",DisplayName="Inventory Item - Get Size Per Max")
	int32 GetSizePerAmount();
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Inventory",DisplayName="Inventory Item - Get Trade Requirements")
	TMap<UPrimaryDataAsset*, int32> GetTradeAssetRequirements(FGameplayTag TradeTag);
};


UINTERFACE(MinimalAPI)class UDataInterface_InventorySource : public UInterface { GENERATED_BODY()};
class OMEGAGAMEFRAMEWORK_API IDataInterface_InventorySource
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="ΩI|Inventory",DisplayName="Inventory Source - Get Items")
	TMap<UPrimaryDataAsset*,int32> GetInventory();
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataAssetCollectionFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Cost (Total List)")
	static TMap<UPrimaryDataAsset*, int32> GetListTradeCost_Total(TMap<UPrimaryDataAsset*, int32> Assets, FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Cost (One)")
	static int32 GetListTradeCost_One(TMap<UPrimaryDataAsset*, int32> Assets, UPrimaryDataAsset* TradeAsset, FGameplayTag TradeTag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Value (One)")
    static int32 GetDataAssetTradeValue_One(UPrimaryDataAsset* Asset, int32 AssetAmount, UPrimaryDataAsset* TradeAsset, FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Value (All)")
	static TMap<UPrimaryDataAsset*, int32> GetDataAssetTradeValue_All(UPrimaryDataAsset* Asset, int32 AssetAmount, FGameplayTag TradeTag);

	UFUNCTION(BlueprintPure, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Can Perform Trade (One)?")
	static bool CanInventoryPerformTrade_ForAsset(UDataAssetCollectionComponent* Component, UPrimaryDataAsset* Asset, int32 Amount, FGameplayTag TradeTag);

	UFUNCTION(BlueprintPure, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Can Perform Trade (All)?")
	static bool CanInventoryPerformTrade_ForList(UDataAssetCollectionComponent* Component, TMap<UPrimaryDataAsset*, int32> Assets, bool bInvert, FGameplayTag TradeTag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Perform Trade (One)",meta=(AdvancedDisplay="bForce,bWithholdAsset,bInvert",ExpandBoolAsExecs="Outcome"))
	static FString PerformTrade_Single(UDataAssetCollectionComponent* Component, UPrimaryDataAsset* Asset, int32 Amount, FGameplayTag TradeTag, bool& Outcome, bool bInvert=false, bool bForce=false,bool bWithholdAsset=false);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Perform Trade (List)",meta=(AdvancedDisplay="bForce,bWithholdAsset",ExpandBoolAsExecs="Outcome"))
	static FString PerformTrade_List(UDataAssetCollectionComponent* Component, TMap<UPrimaryDataAsset*, int32> Assets, FGameplayTag TradeTag, bool& Outcome, bool bInvert=false,bool bForce=false,bool bWithholdAsset=false);
};




UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCommonInventory : public UOmegaDataAsset, public IDataInterface_InventorySource
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Inventory")
	TMap<UPrimaryDataAsset*, int32> Inventory;

	virtual TMap<UPrimaryDataAsset*, int32> GetInventory_Implementation() override;
};