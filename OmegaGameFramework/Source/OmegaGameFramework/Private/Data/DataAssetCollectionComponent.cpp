// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Data/DataAssetCollectionComponent.h"
#include "Data/DataAssetCollectionInterface.h"
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

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionComponent::GetCollectionMap()
{
	return CollectionMap;
}


bool UDataAssetCollectionComponent::NativeAddAsset(UPrimaryDataAsset* Asset)
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
