// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Inventory.h"
#include "Components/Component_Combatant.h"
#include "GameplayTagContainer.h"
#include "Components/Component_Inventory.h"
#include "Kismet/KismetMathLibrary.h"


TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionFunctions::ScaleItemMap(TMap<UPrimaryDataAsset*, int32> items,
                                                                            float scale)
{
	TMap<UPrimaryDataAsset*, int32> out;
	TArray<UPrimaryDataAsset*> item_list;
	items.GetKeys(item_list);
	for (auto* item : item_list)
	{
		if(item)
		{
			out.Add(item,UKismetMathLibrary::FTrunc(scale*items[item]));		
		}
	}
	
	return out;
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

bool UDataAssetCollectionFunctions::CanInventoryPerformTrade_ForAsset(UCombatantComponent* Component,
	UPrimaryDataAsset* Asset, int32 Amount, FGameplayTag TradeTag)
{
	if(Asset && Component)
	{
		TMap<UPrimaryDataAsset*,int32> cost=GetDataAssetTradeValue_All(Asset,Amount,TradeTag);
		return Component->Inventory_HasMinimum(cost);
	}
	return false;
}

bool UDataAssetCollectionFunctions::CanInventoryPerformTrade_ForList(UCombatantComponent* Component,
	TMap<UPrimaryDataAsset*, int32> Assets, bool bInvert, FGameplayTag TradeTag)
{
	if(Component)
	{
		if(bInvert)
		{
			return Component->Inventory_HasMinimum(Assets);
		}
		else
		{
			return Component->Inventory_HasMinimum(GetListTradeCost_Total(Assets,TradeTag));
		}
	}
	return false;
}

FString UDataAssetCollectionFunctions::PerformTrade_Single(UCombatantComponent* Component,
                                                           UPrimaryDataAsset* Asset, int32 Amount,  FGameplayTag TradeTag, bool& Outcome, bool bInvert, bool bForce, bool bWithholdAsset)
{
	int32 m=Amount;
	if(bInvert) {m=m*-1;}
	if(Asset && Component && (bForce || CanInventoryPerformTrade_ForAsset(Component,Asset,m,TradeTag)))
	{
		Component->Inventory_AddList(GetDataAssetTradeValue_All(Asset,m,TradeTag),!bInvert);
		if(!bWithholdAsset)
		{
			Component->Inventory_Add(Asset,m);
		}
		Outcome=true;
		return "";
	}
	Outcome=false;
	return "";
}

FString UDataAssetCollectionFunctions::PerformTrade_List(UCombatantComponent* Component,
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
		if(bForce || Component->Inventory_HasMinimum(_price))
		{
			Component->Inventory_AddList(_price,true);
			//deduct cost
			if(!bWithholdAsset)
			{
				Component->Inventory_AddList(_goods);
			}
			Outcome=true;
			return "";
		}
	}
	return "Invalid Component";
}



