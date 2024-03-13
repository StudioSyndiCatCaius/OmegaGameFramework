// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/DataAssetCollectionComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UDataAssetCollectionComponent::UDataAssetCollectionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDataAssetCollectionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UDataAssetCollectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDataAssetCollectionComponent::AddAsset(UPrimaryDataAsset* Asset, int32 Amount)
{
	bool bIsFull = false;
	int32 AmountAdded = 0;
	for (int i = 0; i < Amount; ++i)
	{
		bIsFull = NativeAddAsset(Asset);
		if(!bIsFull)
		{
			AmountAdded = AmountAdded+1;
		}
	}
	OnAssetAdded.Broadcast(Asset, AmountAdded, bIsFull);
}

void UDataAssetCollectionComponent::RemoveAsset(UPrimaryDataAsset* Asset, int32 Amount)
{
	bool bIsEmpty = false;
	int32 AmountRemoved = 0;
	for (int i = 0; i < Amount; ++i)
	{
		bIsEmpty = NativeRemoveAsset(Asset);
		if(!bIsEmpty)
		{
			AmountRemoved = AmountRemoved+1;
		}
	}
	OnAssetRemoved.Broadcast(Asset, AmountRemoved, bIsEmpty);
}

int32 UDataAssetCollectionComponent::GetAssetNumberOfType(UPrimaryDataAsset* Asset)
{
	return CollectionMap.FindOrAdd(Asset);
}

int32 UDataAssetCollectionComponent::GetAssetNumberTotal()
{
	int32 TotalNumber = 0;
	for (auto& Elem : CollectionMap)
	{
		TotalNumber = TotalNumber+Elem.Value;
	}
	return TotalNumber;
}

TArray<UPrimaryDataAsset*> UDataAssetCollectionComponent::GetCollectionAsArray(UPrimaryDataAsset* Asset)
{
	TArray<UPrimaryDataAsset*> OutList;
	for (int i = 0; i < CollectionMap.FindOrAdd(Asset); ++i)
	{
		OutList.Add(Asset);
	}
	return OutList;
}

void UDataAssetCollectionComponent::SetCollectionMap(TMap<UPrimaryDataAsset*, int32> Map)
{
	CollectionMap=Map;
}

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionComponent::GetCollectionMap(bool IncludeZero)
{
	if(IncludeZero)
	{
		return CollectionMap;
	}
	
	TArray<UPrimaryDataAsset*> AssetList;
	CollectionMap.GetKeys(AssetList);
	TMap<UPrimaryDataAsset*, int32> OutMap;
		
	for(auto* TempAsset : AssetList)
	{
		if(TempAsset && GetAssetNumberOfType(TempAsset)>0)
		{
			OutMap.Add(TempAsset, GetAssetNumberOfType(TempAsset));
		}
	}
	return OutMap;
}


bool UDataAssetCollectionComponent::NativeAddAsset(UPrimaryDataAsset* Asset)
{
	if(Asset)
	{
		const int32 CurrentValue = CollectionMap.FindOrAdd(Asset);
		const int32 MaxValue = IDataAssetCollectionInterface::Execute_GetMaxCollectionNumber(Asset);
		if(CurrentValue<MaxValue || MaxValue<=0)
		{
			CollectionMap.Add(Asset, CurrentValue+1);
			return false;
		}
		return true;
	}
	return false;
}

bool UDataAssetCollectionComponent::NativeRemoveAsset(UPrimaryDataAsset* Asset)
{
	const int32 CurrentValue = CollectionMap.FindOrAdd(Asset);
	if(CurrentValue>0)
	{
		CollectionMap.Add(Asset, CurrentValue-1);
		return false;
	}
	return true;
}

//TRANSFER

void UDataAssetCollectionComponent::TransferAssetToCollection(UDataAssetCollectionComponent* To,
	UPrimaryDataAsset* Asset, int32 Amount, bool bTransferAll)
{
	if(!Asset || !To)
	{
		return;
	}
	int32 AmountToRemove = Amount;
	if(bTransferAll)
	{
		AmountToRemove = GetAssetNumberOfType(Asset);
	}
	else
	{
		AmountToRemove = UKismetMathLibrary::Clamp(AmountToRemove, 0, GetAssetNumberOfType(Asset));
	}

	//Transfer
	RemoveAsset(Asset, AmountToRemove);

	To->AddAsset(Asset, AmountToRemove);
	
}

void UDataAssetCollectionComponent::TransferAllAssetsToCollection(UDataAssetCollectionComponent* To)
{
	TArray<UPrimaryDataAsset*> AssetListLocal;
	CollectionMap.GetKeys(AssetListLocal);

	for(auto* TempAsset : AssetListLocal)
	{
		TransferAssetToCollection(To, TempAsset, 0, true);
	}
}

bool UDataAssetCollectionComponent::HasMinimumAssets(TMap<UPrimaryDataAsset*, int32> Assets)
{
	for (const auto& Pair : Assets)
	{
		UPrimaryDataAsset* Asset = Pair.Key;
		int32 InputValue = Pair.Value;

		// Check if the asset is present in the 'CollectionMap'
		if (CollectionMap.Contains(Asset))
		{
			int32 CollectionValue = CollectionMap[Asset];

			// Check if the CollectionValue is greater than or equal to InputValue
			if (CollectionValue < InputValue)
			{
				// The CollectionMap does not have the minimum required value for this asset
				return false;
			}
		}
		else
		{
			// The asset is not in the 'CollectionMap', so it can't meet the minimum requirement
			return false;
		}
	}

	// All assets in 'Assets' meet the minimum requirements
	return true;
}
