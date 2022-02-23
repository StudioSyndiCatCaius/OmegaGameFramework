// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Data/DataAssetCollectionComponent.h"
#include "Data/DataAssetCollectionInterface.h"

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

void UDataAssetCollectionComponent::AddAsset(UDataAsset* Asset, int32 Amount)
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

void UDataAssetCollectionComponent::RemoveAsset(UDataAsset* Asset, int32 Amount)
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

int32 UDataAssetCollectionComponent::GetAssetNumberOfType(UDataAsset* Asset)
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

TArray<UDataAsset*> UDataAssetCollectionComponent::GetCollectionAsArray(UDataAsset* Asset)
{
	TArray<UDataAsset*> OutList;
	for (int i = 0; i < CollectionMap.FindOrAdd(Asset); ++i)
	{
		OutList.Add(Asset);
	}
	return OutList;
}

void UDataAssetCollectionComponent::SetCollectionMap(TMap<UDataAsset*, int32> Map)
{
	CollectionMap=Map;
}

TMap<UDataAsset*, int32> UDataAssetCollectionComponent::GetCollectionMap()
{
	return CollectionMap;
}

bool UDataAssetCollectionComponent::NativeAddAsset(UDataAsset* Asset)
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

bool UDataAssetCollectionComponent::NativeRemoveAsset(UDataAsset* Asset)
{
	const int32 CurrentValue = CollectionMap.FindOrAdd(Asset);
	if(CurrentValue>0)
	{
		CollectionMap.Add(Asset, CurrentValue-1);
		return false;
	}
	return true;
}

