// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFeatureAction.h"
#include "OFunctions_GameFeatures.generated.h"

/**
 * 
 */
UCLASS()
class OMEGA5_GAMEFEATURES_API UOFunctions_GameFeatures : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Omega|GameFeatures")
	static void SetGameFeatureActive(const FString& Name, bool bNewActive);
};

UCLASS(MinimalAPI, Abstract, Blueprintable,BlueprintType)
class UOmegaGameFeatureActionBase final : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Feature")
	void FeatureActivated();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Feature")
	void FeatureDeactivated();

protected:
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;

	
};
