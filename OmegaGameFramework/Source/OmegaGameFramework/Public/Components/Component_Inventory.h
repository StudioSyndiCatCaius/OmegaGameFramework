// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Misc/GeneralDataObject.h"
#include "Component_Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetAdded, UDataAsset*, Asset, int32, Amount, bool, IsFull);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetRemoved, UDataAsset*, Asset, int32, Amount, bool, IsEmpty);


UCLASS( ClassGroup=("Omega Game Framework"), DisplayName="Inventory (Data Asset Collection)", meta=(BlueprintSpawnableComponent) )
class OMEGAGAMEFRAMEWORK_API UDataAssetCollectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDataAssetCollectionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere,Category="Omega|Inventory")
	TMap<UPrimaryDataAsset*, int32> InventoryAssets;
	
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

	UFUNCTION(BlueprintPure, meta = (DeterminesOutputType="Asset"), Category = "Omega|Inventory")
	TArray<UPrimaryDataAsset*> GetCollectionAsArray(UPrimaryDataAsset* Asset);

	UFUNCTION(BlueprintCallable, Category = "Omega|Inventory")
	void SetCollectionMap(TMap<UPrimaryDataAsset*, int32> Map);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Inventory", DisplayName="Get Asset Collection Map")
	TMap<UPrimaryDataAsset*, int32> GetCollectionMap(int32 Min=1);

	UPROPERTY(BlueprintAssignable) FOnAssetAdded OnAssetAdded;
	//UPROPERTY(BlueprintAssignable) FOnAssetRemoved OnAssetRemoved;

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
	
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Inventory")
	int32 GetMaxCollectionNumber();

	UFUNCTION(BlueprintNativeEvent,Category="Omega|Inventory")
	TMap<UPrimaryDataAsset*, int32> GetTradeAssetRequirements(FGameplayTag TradeTag);
};


UINTERFACE(MinimalAPI)class UDataInterface_InventorySource : public UInterface { GENERATED_BODY()};
class OMEGAGAMEFRAMEWORK_API IDataInterface_InventorySource
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Omega|Inventory")
	TMap<UPrimaryDataAsset*,int32> GetInventory();
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataAssetCollectionFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|Inventory")
	static void SetInventory_FromSource(UDataAssetCollectionComponent* Component, UObject* Source);
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Cost (Total List)")
	static TMap<UPrimaryDataAsset*, int32> GetTotalAssetListTradeCost(TMap<UPrimaryDataAsset*, int32> Assets, FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Cost (One)")
	static int32 GetTotalAssetListTradeCost_One(TMap<UPrimaryDataAsset*, int32> Assets, UPrimaryDataAsset* TradeAsset, FGameplayTag TradeTag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Value (One)")
    static int32 GetDataAssetTradeValue_One(UPrimaryDataAsset* Asset, UPrimaryDataAsset* TradeAsset, FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Value (All)")
	static TMap<UPrimaryDataAsset*, int32> GetDataAssetTradeValue_All(UPrimaryDataAsset* Asset, FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Can Perform Trade?")
	static bool CanInventoryPerformTrade_ForAsset(UDataAssetCollectionComponent* Component, UPrimaryDataAsset* Asset, FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Perform Trade")
	static bool PerformTrade_Single(UDataAssetCollectionComponent* Component, UPrimaryDataAsset* Asset, FGameplayTag TradeTag, bool bForce=false,bool bWithholdAsset=false);
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