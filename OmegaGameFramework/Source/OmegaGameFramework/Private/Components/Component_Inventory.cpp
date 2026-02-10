// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_Inventory.h"

#include "OmegaSettings.h"
#include "OmegaGameCore.h"
#include "Kismet/KismetMathLibrary.h"


bool L_AssetUsesInterface(const UPrimaryDataAsset* asset)
{
	if (asset && asset->GetClass()->ImplementsInterface(UDataAssetCollectionInterface::StaticClass()))
	{
		return true;
	}
	return false;
}

int32 L_GetAssetSize(UPrimaryDataAsset* asset, int32 amount)
{
	if(L_AssetUsesInterface(asset))
	{
		return IDataAssetCollectionInterface::Execute_GetSizePerAmount(asset)*amount;
	}
	return 0;
}

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
	if(Asset && (L_GetAssetSize(Asset,Amount)+GetCurrentSize()<MaxSize || MaxSize<1))
	{
		int32 curval = GetAssetNumberOfType(Asset)+Amount;
		UKismetMathLibrary::Clamp(curval,0,9999999);
		InventoryAssets.Add(Asset,curval);
	}
	OnAssetAdded.Broadcast(Asset, AmountAdded, bIsFull);
}

void UDataAssetCollectionComponent::AddAssets(TMap<UPrimaryDataAsset*, int32> Assets, bool bInvertAmount)
{
	TArray<UPrimaryDataAsset*> asset_keys;
	Assets.GetKeys(asset_keys);
	for(auto* i : asset_keys)
	{
		int32 multiplier=1;
		if(bInvertAmount) {multiplier=-1;}
		AddAsset(i,Assets[i]*multiplier);
	}
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


int32 UDataAssetCollectionComponent::GetCurrentSize()
{
	int32 out=0;
	TArray<UPrimaryDataAsset*> OutList;
	InventoryAssets.GetKeys(OutList);
	for (auto* a : OutList)
	{
		if(a)
		{
			int32 a_size=0;
			if(a->GetClass()->ImplementsInterface(UDataAssetCollectionInterface::StaticClass()))
			{
				a_size=IDataAssetCollectionInterface::Execute_GetSizePerAmount(a);
			}
			out+=GetAssetNumberOfType(a)*a_size;
		}
	}
	return out;
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

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionComponent::GetCollectionMap(int32 Min,bool IncludeSources)
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
	if(IncludeSources)
	{
		for(auto* a : InventorySources)
		{
			if(a && a->GetClass()->ImplementsInterface(UDataInterface_InventorySource::StaticClass()))
			{
				for(const auto& p : IDataInterface_InventorySource::Execute_GetInventory(a))
				{
					int32 b=OutMap.FindOrAdd(p.Key);
					OutMap.Add(p.Key,b+p.Value);
				}
			}
		}
	}
	OutMap.Append(GetMutableDefault<UOmegaSettings>()->GetGameCore()->Append_Inventory(this));
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

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionFunctions::GetListTradeCost_Total(
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

int32 UDataAssetCollectionFunctions::GetListTradeCost_One(TMap<UPrimaryDataAsset*, int32> Assets, UPrimaryDataAsset* TradeAsset,
	FGameplayTag TradeTag)
{
	return GetListTradeCost_Total(Assets,TradeTag).FindOrAdd(TradeAsset);
}

int32 UDataAssetCollectionFunctions::GetDataAssetTradeValue_One(UPrimaryDataAsset* Asset, int32 AssetAmount, UPrimaryDataAsset* TradeAsset, FGameplayTag TradeTag)
{
	return GetDataAssetTradeValue_All(Asset,AssetAmount,TradeTag).FindOrAdd(TradeAsset);
}

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionFunctions::GetDataAssetTradeValue_All(UPrimaryDataAsset* Asset, int32 AssetAmount,
	FGameplayTag TradeTag)
{
	TMap<UPrimaryDataAsset*, int32> out;
	//if uses interface
	if(Asset && Asset->GetClass()->ImplementsInterface(UDataAssetCollectionInterface::StaticClass()))
	{
		for (const auto& p : IDataAssetCollectionInterface::Execute_GetTradeAssetRequirements(Asset,TradeTag))
		{
			if(p.Key)
			{
				//add asset base cost * AssetAmount to output
				out.Add(p.Key,p.Value*AssetAmount);
			}
		}
	}
	return out;
}

bool UDataAssetCollectionFunctions::CanInventoryPerformTrade_ForAsset(UDataAssetCollectionComponent* Component,
	UPrimaryDataAsset* Asset, int32 Amount, FGameplayTag TradeTag)
{
	if(Asset && Component)
	{
		TMap<UPrimaryDataAsset*,int32> cost=GetDataAssetTradeValue_All(Asset,Amount,TradeTag);
		return Component->HasMinimumAssets(cost);
	}
	return false;
}

bool UDataAssetCollectionFunctions::CanInventoryPerformTrade_ForList(UDataAssetCollectionComponent* Component,
	TMap<UPrimaryDataAsset*, int32> Assets, bool bInvert, FGameplayTag TradeTag)
{
	if(Component)
	{
		if(bInvert)
		{
			return Component->HasMinimumAssets(Assets);
		}
		else
		{
			return Component->HasMinimumAssets(GetListTradeCost_Total(Assets,TradeTag));
		}
	}
	return false;
}

FString UDataAssetCollectionFunctions::PerformTrade_Single(UDataAssetCollectionComponent* Component,
                                                           UPrimaryDataAsset* Asset, int32 Amount,  FGameplayTag TradeTag, bool& Outcome, bool bInvert, bool bForce, bool bWithholdAsset)
{
	int32 m=Amount;
	if(bInvert) {m=m*-1;}
	if(Asset && Component && (bForce || CanInventoryPerformTrade_ForAsset(Component,Asset,m,TradeTag)))
	{
		Component->AddAssets(GetDataAssetTradeValue_All(Asset,m,TradeTag),!bInvert);
		if(!bWithholdAsset)
		{
			Component->AddAsset(Asset,m);
		}
		Outcome=true;
		return "";
	}
	Outcome=false;
	return "";
}

FString UDataAssetCollectionFunctions::PerformTrade_List(UDataAssetCollectionComponent* Component,
	TMap<UPrimaryDataAsset*, int32> Assets, FGameplayTag TradeTag, bool& Outcome, bool bInvert, bool bForce, bool bWithholdAsset)
{
	Outcome=false;
	TMap<UPrimaryDataAsset*, int32> _price=GetListTradeCost_Total(Assets,TradeTag);
	TMap<UPrimaryDataAsset*, int32> _goods=Assets;
	if(bInvert)
	{
		_price=Assets;
		_goods=GetListTradeCost_Total(Assets,TradeTag);
	}
	if(Component)
	{
		//check if price is owned
		if(bForce || Component->HasMinimumAssets(_price))
		{
			Component->AddAssets(_price,true);
			//deduct cost
			if(!bWithholdAsset)
			{
				Component->AddAssets(_goods);
			}
			Outcome=true;
			return "";
		}
	}
	return "Invalid Component";
}



TMap<UPrimaryDataAsset*, int32> UOmegaCommonInventory::GetInventory_Implementation()
{
	return Inventory;
}

