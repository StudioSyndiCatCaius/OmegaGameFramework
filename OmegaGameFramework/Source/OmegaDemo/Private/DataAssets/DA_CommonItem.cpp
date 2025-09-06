// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonItem.h"

void UOAsset_CommonItem::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Super::GetGeneralDataText_Implementation(Label, Context, Name, Description);
	if(bAppendEffectsDescription)
	{
		FString str=Description.ToString()+
			UOmegaScriptedEffectFunctions::GetEffects_Description(GetScriptedEffects("")).ToString();
		Description=FText::FromString(str);
	}
}

TMap<UPrimaryDataAsset*, int32> UOAsset_CommonItem::GetTradeAssetRequirements_Implementation(FGameplayTag TradeTag)
{
	TMap<UPrimaryDataAsset*, int32> out;
	if(TradeTag.IsValid())
	{
		if(TradeCosts_Tagged.Contains(TradeTag))
		{
			return TradeCosts_Tagged.FindOrAdd(TradeTag).map;
		}
		return out;
	}
	return TradeCosts;
}

int32 UOAsset_CommonItem::GetMaxCollectionNumber_Implementation()
{
	return CollectionMax;
}

