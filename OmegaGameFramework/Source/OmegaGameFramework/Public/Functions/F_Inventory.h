// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subsystems/WorldSubsystem.h"
#include "F_Inventory.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataAssetCollectionFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Cost (Total List)")
	static TMap<UPrimaryDataAsset*, int32> GetListTradeCost_Total(TMap<UPrimaryDataAsset*, int32> Assets,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Cost (One)")
	static int32 GetListTradeCost_One(TMap<UPrimaryDataAsset*, int32> Assets, UPrimaryDataAsset* TradeAsset,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Value (One)")
    static int32 GetDataAssetTradeValue_One(UPrimaryDataAsset* Asset, int32 AssetAmount, UPrimaryDataAsset* TradeAsset,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Get Trade Value (All)")
	static TMap<UPrimaryDataAsset*, int32> GetDataAssetTradeValue_All(UPrimaryDataAsset* Asset, int32 AssetAmount,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag);

	UFUNCTION(BlueprintPure, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Can Perform Trade (One)?")
	static bool CanInventoryPerformTrade_ForAsset(UCombatantComponent* Component, UPrimaryDataAsset* Asset, int32 Amount,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag);

	UFUNCTION(BlueprintPure, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Can Perform Trade (All)?")
	static bool CanInventoryPerformTrade_ForList(UCombatantComponent* Component, TMap<UPrimaryDataAsset*, int32> Assets, bool bInvert,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag);
	
	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Perform Trade (One)",meta=(AdvancedDisplay="bForce,bWithholdAsset,bInvert",ExpandBoolAsExecs="Outcome"))
	static FString PerformTrade_Single(UCombatantComponent* Component, UPrimaryDataAsset* Asset, int32 Amount,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag, bool& Outcome, bool bInvert=false, bool bForce=false,bool bWithholdAsset=false);

	UFUNCTION(BlueprintCallable, Category="Omega|DataAsset|Trading", DisplayName="Ω Inventory - Perform Trade (List)",meta=(AdvancedDisplay="bForce,bWithholdAsset",ExpandBoolAsExecs="Outcome"))
	static FString PerformTrade_List(UCombatantComponent* Component, TMap<UPrimaryDataAsset*, int32> Assets,UPARAM(meta=(Categories="Trade")) FGameplayTag TradeTag, bool& Outcome, bool bInvert=false,bool bForce=false,bool bWithholdAsset=false);
};

