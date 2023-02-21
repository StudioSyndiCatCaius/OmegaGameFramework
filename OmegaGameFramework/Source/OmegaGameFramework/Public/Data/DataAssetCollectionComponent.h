// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "DataAssetCollectionComponent.generated.h"

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

	UFUNCTION()
	bool NativeAddAsset(UPrimaryDataAsset* Asset);

	UFUNCTION()
	bool NativeRemoveAsset(UPrimaryDataAsset* Asset);

	UPROPERTY(EditAnywhere, Category="Equipment", DisplayName="Collected Assets")
	TMap<UPrimaryDataAsset*, int32> CollectionMap;

public:	
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
	
	UFUNCTION(BlueprintPure, Category = "Ω|Data")
	TMap<UPrimaryDataAsset*, int32> GetCollectionMap();

	UPROPERTY(BlueprintAssignable)
	FOnAssetAdded OnAssetAdded;
	UPROPERTY(BlueprintAssignable)
	FOnAssetRemoved OnAssetRemoved;

	//TRANSFEr
	UFUNCTION(BlueprintCallable, Category="Data Asset Collection")
	void TransferAssetToCollection(UDataAssetCollectionComponent* To, UPrimaryDataAsset* Asset, int32 Amount, bool bTransferAll);

	UFUNCTION(BlueprintCallable, Category="Data Asset Collection")
	void TransferAllAssetsToCollection(UDataAssetCollectionComponent* To);
		
};
