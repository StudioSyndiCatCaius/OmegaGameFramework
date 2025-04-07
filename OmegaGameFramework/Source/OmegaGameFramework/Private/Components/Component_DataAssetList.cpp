// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_DataAssetList.h"

UPrimaryDataAsset* UDataAssetListComponent::GetAssetAtIndex(int32 index, bool& Result)
{
	TArray<UPrimaryDataAsset*> L = GetAssetList();
	if(L.IsValidIndex(index))
	{
		Result=true;
		return L[index];
	}
	Result=false;
	return nullptr;
}

void UDataAssetListComponent::SetAssetInList(UPrimaryDataAsset* Asset, bool bAdded)
{
	if(Asset)
	{
		if(bAdded && !AssetList.Contains(Asset))
		{
			AssetList.Add(Asset);
			OnDataAssetListEdited.Broadcast(this,Asset,true);
		}
		else if(!bAdded && AssetList.Contains(Asset))
		{
			AssetList.Remove(Asset);
			OnDataAssetListEdited.Broadcast(this,Asset,false);
		}
	}
	OnDataAssetListUpdated.Broadcast(this);
}

void UDataAssetListComponent::ClearList()
{
	TArray<UPrimaryDataAsset*> L = GetAssetList();
	for(auto* a : L)
	{
		if(a)
		{
			SetAssetInList(a,false);
		}
	}
}

void UDataAssetListComponent::SetAssetsInList(TArray<UPrimaryDataAsset*> Assets, bool bAdded)
{
	for(auto* a : Assets)
	{
		if(a)
		{
			SetAssetInList(a,bAdded);
		}
	}
}

TArray<UPrimaryDataAsset*> UDataAssetListComponent::GetAssetList()
{
	TArray<UPrimaryDataAsset*> out;
	for(auto* a : AssetList)
	{
		if(a) {out.Add(a);}
	}
	return out;
}

void UDataAssetListComponent::SwapAssetOrder(int32 A, int32 B)
{
	TArray<UPrimaryDataAsset*> L = GetAssetList();
	if(L.IsValidIndex(A) && L.IsValidIndex(B))
	{
		L.Swap(A,B);
	}
	OnDataAssetListUpdated.Broadcast(this);
}
