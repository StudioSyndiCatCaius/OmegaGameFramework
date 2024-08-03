// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "DataAssetCollectionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetAdded, UDataAsset*, Asset, int32, Amount, bool, IsFull);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAssetRemoved, UDataAsset*, Asset, int32, Amount, bool, IsEmpty);

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Abstract, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UDataAssetCollectionScript : public UObject
{
	GENERATED_BODY()
private:
	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	

	UDataAssetCollectionScript(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;
	UPROPERTY()
	UDataAssetCollectionComponent* Ref_Comp;
	
	UFUNCTION(BlueprintPure,Category="Equipment")
	UDataAssetCollectionComponent* GetOwningComponent() const { return  Ref_Comp; }

	UPROPERTY()
	TMap<UPrimaryDataAsset*, int32> REF_collectedAssets;
	
	UFUNCTION(BlueprintNativeEvent, Category="Equipment")
	int32 GetAmountOfAsset(UPrimaryDataAsset* Asset) const;

	UFUNCTION(BlueprintNativeEvent,Category="Equipment")
	void AddAsset(UPrimaryDataAsset* Asset, int32 amount);
	
	UFUNCTION(BlueprintNativeEvent, Category="Equipment")
	TArray<UPrimaryDataAsset*> GetAssetList() const;
	
};

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

	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadWrite,Category="DataAssetCollection", DisplayName="Script")
	UDataAssetCollectionScript* DataAssetCollectionScript=nullptr;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Ω|Data")
	void AddAsset(UPrimaryDataAsset* Asset, int32 Amount=1);

	UFUNCTION(BlueprintCallable, Category = "Ω|Data")
	void RemoveAsset(UPrimaryDataAsset* Asset, int32 Amount=1);

	UFUNCTION(BlueprintPure, Category = "Ω|Data")
	int32 GetAssetNumberOfType(UPrimaryDataAsset* Asset);

	UFUNCTION(BlueprintPure, Category = "Ω|Data")
	int32 GetAssetNumberTotal();

	UFUNCTION(BlueprintPure, meta = (DeterminesOutputType="Asset"), Category = "Ω|Data")
	TArray<UPrimaryDataAsset*> GetCollectionAsArray(UPrimaryDataAsset* Asset);

	UFUNCTION(BlueprintCallable, Category = "Ω|Data")
	void SetCollectionMap(TMap<UPrimaryDataAsset*, int32> Map);
	
	UFUNCTION(BlueprintPure, Category = "Ω|Data", DisplayName="Get Asset Collection Map")
	TMap<UPrimaryDataAsset*, int32> GetCollectionMap(bool IncludeZero=true);

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



