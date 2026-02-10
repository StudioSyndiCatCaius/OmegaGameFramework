// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_DataAssetList.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDataAssetListEdited, UDataAssetListComponent*, Component, UPrimaryDataAsset*, Asset, bool, bAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataAssetListUpdated, UDataAssetListComponent*, Component);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UDataAssetListComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable)
	FOnDataAssetListEdited OnDataAssetListEdited;
	UPROPERTY(BlueprintAssignable)
	FOnDataAssetListUpdated OnDataAssetListUpdated;

	UPROPERTY(EditAnywhere,Category="DataAssetList")
	TArray<UPrimaryDataAsset*> AssetList;

	UFUNCTION(BlueprintCallable,Category="DataAssetList",meta=(ExpandBoolAsExecs="Result"))
	UPrimaryDataAsset* GetAssetAtIndex(int32 index, bool& Result);
	
	UFUNCTION(BlueprintCallable,Category="DataAssetList")
	void SetAssetInList(UPrimaryDataAsset* Asset, bool bAdded);

	UFUNCTION(BlueprintCallable,Category="DataAssetList")
	void ClearList();
	
	UFUNCTION(BlueprintCallable,Category="DataAssetList")
	void SetAssetsInList(TArray<UPrimaryDataAsset*> Assets, bool bAdded);
	
	UFUNCTION(BlueprintCallable,Category="DataAssetList")
	TArray<UPrimaryDataAsset*> GetAssetList();
	
	UFUNCTION(BlueprintCallable,Category="DataAssetList")
	void SwapAssetOrder(int32 A, int32 B);
};
