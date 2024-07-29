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
	if(!DataAssetCollectionScript)
	{
		DataAssetCollectionScript=NewObject<UDataAssetCollectionScript>(this,UDataAssetCollectionScript::StaticClass());
	}
	if(DataAssetCollectionScript)
	{
		DataAssetCollectionScript->Ref_Comp=this;
		DataAssetCollectionScript->WorldPrivate=GetWorld();
	}
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
	DataAssetCollectionScript->AddAsset(Asset,Amount);
	OnAssetAdded.Broadcast(Asset, AmountAdded, bIsFull);
}

void UDataAssetCollectionComponent::RemoveAsset(UPrimaryDataAsset* Asset, int32 Amount)
{
	AddAsset(Asset,Amount*-1);
}

int32 UDataAssetCollectionComponent::GetAssetNumberOfType(UPrimaryDataAsset* Asset)
{
	return DataAssetCollectionScript->GetAmountOfAsset(Asset);
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
	DataAssetCollectionScript->REF_collectedAssets=Map;
}

TMap<UPrimaryDataAsset*, int32> UDataAssetCollectionComponent::GetCollectionMap(bool IncludeZero)
{
	TMap<UPrimaryDataAsset*, int32> OutMap;
	for (auto* tempAsset : DataAssetCollectionScript->GetAssetList())
	{
		if(IncludeZero || DataAssetCollectionScript->GetAmountOfAsset(tempAsset)>0)
		{
			OutMap.Add(tempAsset,DataAssetCollectionScript->GetAmountOfAsset(tempAsset));
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


UWorld* UDataAssetCollectionScript::GetWorld() const
{
	if(GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}
	return nullptr;
}

UGameInstance* UDataAssetCollectionScript::GetGameInstance() const
{
	if(WorldPrivate)
	{
		return WorldPrivate->GetGameInstance();
	}
	return Cast<UGameInstance>(GetOuter());
}

UDataAssetCollectionScript::UDataAssetCollectionScript(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

void UDataAssetCollectionScript::AddAsset_Implementation(UPrimaryDataAsset* Asset, int32 amount)
{
	if(Asset)
	{
		int32 curval = GetAmountOfAsset(Asset)+amount;
		UKismetMathLibrary::Clamp(curval,0,9999999);
		REF_collectedAssets.Add(Asset,curval);
	}
}

TArray<UPrimaryDataAsset*> UDataAssetCollectionScript::GetAssetList_Implementation() const
{
	TArray<UPrimaryDataAsset*> out;
	REF_collectedAssets.GetKeys(out);
	return out;
}

int32 UDataAssetCollectionScript::GetAmountOfAsset_Implementation(UPrimaryDataAsset* Asset) const
{
	if(REF_collectedAssets.Contains(Asset))
	{
		return REF_collectedAssets[Asset];
	}
	return 0;
}
