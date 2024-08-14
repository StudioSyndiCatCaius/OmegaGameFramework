// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Component_Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetAdded, UDataAsset*, Asset, int32, Amount, bool, IsFull);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetRemoved, UDataAsset*, Asset, int32, Amount, bool, IsEmpty);


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

	UFUNCTION(BlueprintCallable, Category = "Omega|Inventory")
	void AddAsset(UPrimaryDataAsset* Asset, int32 Amount=1);

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

	UPROPERTY(BlueprintAssignable)
	FOnAssetAdded OnAssetAdded;
	UPROPERTY(BlueprintAssignable)
	FOnAssetRemoved OnAssetRemoved;

	//TRANSFEr
	UFUNCTION(BlueprintCallable, Category="Data Asset Collection")
	void TransferAssetToCollection(UDataAssetCollectionComponent* To, UPrimaryDataAsset* Asset, int32 Amount, bool bTransferAll);

	UFUNCTION(BlueprintCallable, Category="Data Asset Collection")
	void TransferAllAssetsToCollection(UDataAssetCollectionComponent* To);

	//Checks if the collection has enough of each given type of asset;
	UFUNCTION(BlueprintPure, Category="Data Asset Collection")
	bool HasMinimumAssets(TMap<UPrimaryDataAsset*, int32> Assets);
		
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataAssetCollectionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IDataAssetCollectionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	UFUNCTION(BlueprintNativeEvent)
	int32 GetMaxCollectionNumber();
};



