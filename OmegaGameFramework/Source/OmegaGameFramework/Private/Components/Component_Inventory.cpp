// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_Inventory.h"

#include "OmegaSettings.h"
#include "OmegaGameManager.h"
#include "Components/Component_Combatant.h"
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

/*
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
*/
TMap<UPrimaryDataAsset*, int32> UOmegaCommonInventory::GetInventory_Implementation()
{
	return Inventory;
}

