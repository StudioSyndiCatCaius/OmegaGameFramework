// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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
