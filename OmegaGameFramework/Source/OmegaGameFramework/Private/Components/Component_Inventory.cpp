// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_Inventory.h"
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
	if(Asset)
	{
		int32 curval = GetAssetNumberOfType(Asset)+Amount;
		UKismetMathLibrary::Clamp(curval,0,9999999);
		InventoryAssets.Add(Asset,curval);
	}
	OnAssetAdded.Broadcast(Asset, AmountAdded, bIsFull);
}

void UDataAssetCollectionComponent::RemoveAsset(UPrimaryDataAsset* Asset, int32 Amount)
{
	AddAsset(Asset,Amount*-1);
}


int32 UDataAssetCollectionComponent::GetAssetNumberOfType(UPrimaryDataAsset* Asset)
{
	if(InventoryAssets.Contains(Asset))
	{
		return InventoryAssets[Asset];
	}
	return 0;
}

int32 UDataAssetCollectionComponent::GetAssetNumberTotal()
{
	int32 TotalNumber = 0;
	for (auto& Elem : GetCollectionMap())
	{
		TotalNumber = TotalNumber+Elem.Value;
	}
	return TotalNumber;
}

TArray<UPrimaryDataAsset*> UDataAssetCollectionComponent::GetCollectionAsArray(UPrimaryDataAsset* Asset)
{
	TArray<UPrimaryDataAsset*> OutList;
	for (int i = 0; i < GetCollectionMap().FindOrAdd(Asset); ++i)
	{
		OutList.Add(Asset);
	}
	return OutList;
}

void UDataAssetCollectionComponent::SetCollectionMap(TMap<UPrimaryDataAsset*, int32> Map)
{
	InventoryAssets=Map;
}

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionComponent::GetCollectionMap(int32 Min)
{
	TMap<UPrimaryDataAsset*, int32> OutMap;
	TArray<UPrimaryDataAsset*> asset_list;
	InventoryAssets.GetKeys(asset_list);
	for (auto* tempAsset : asset_list)
	{
		if(tempAsset && GetAssetNumberOfType(tempAsset)>=Min)
		{
			OutMap.Add(tempAsset,GetAssetNumberOfType(tempAsset));
		}
	}
	return OutMap;
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
	GetCollectionMap().GetKeys(AssetListLocal);

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
		if (GetCollectionMap().Contains(Asset))
		{
			int32 CollectionValue = GetCollectionMap()[Asset];

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



TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionFunctions::GetTotalAssetListTradeCost(
	TMap<UPrimaryDataAsset*, int32> Assets, FGameplayTag TradeTag)
{
	TMap<UPrimaryDataAsset*, int32> out;
	
	TArray<UPrimaryDataAsset*> item_list;
	Assets.GetKeys(item_list);
	for (auto* item_target : item_list)
	{
		int32 num_of_itemsIn=Assets[item_target];
		if(item_target && item_target->GetClass()->ImplementsInterface(UDataAssetCollectionInterface::StaticClass()))
		{
			TMap<UPrimaryDataAsset*, int32> item_trades=IDataAssetCollectionInterface::Execute_GetTradeAssetRequirements(item_target, TradeTag);
			TArray<UPrimaryDataAsset*> Tradeitem_list;
			item_trades.GetKeys(Tradeitem_list);
			for (auto* item_trade : Tradeitem_list)
			{
				if(item_trade)
				{
					int32 current_val=out.FindOrAdd(item_trade);
					out.Add(item_trade,num_of_itemsIn*item_trades[item_trade]+current_val);
				}
			}
		}
	}
	
	return out;
}

int32 UDataAssetCollectionFunctions::GetTotalAssetListTradeCost_One(TMap<UPrimaryDataAsset*, int32> Assets, UPrimaryDataAsset* TradeAsset,
	FGameplayTag TradeTag)
{
	return GetTotalAssetListTradeCost(Assets,TradeTag).FindOrAdd(TradeAsset);
}

int32 UDataAssetCollectionFunctions::GetDataAssetTradeValue_One(UPrimaryDataAsset* Asset, UPrimaryDataAsset* TradeAsset, FGameplayTag TradeTag)
{
	return GetDataAssetTradeValue_All(Asset,TradeTag).FindOrAdd(TradeAsset);
}

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionFunctions::GetDataAssetTradeValue_All(UPrimaryDataAsset* Asset,
	FGameplayTag TradeTag)
{
	TMap<UPrimaryDataAsset*, int32> out;
	if(Asset && Asset->GetClass()->ImplementsInterface(UDataAssetCollectionInterface::StaticClass()))
	{
		return IDataAssetCollectionInterface::Execute_GetTradeAssetRequirements(Asset,TradeTag);
	}
	return out;
}

