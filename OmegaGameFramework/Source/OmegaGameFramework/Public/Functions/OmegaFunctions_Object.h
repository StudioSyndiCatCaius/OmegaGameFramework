// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Selectors/Selector_DataAsset.h"
#include "Selectors/Selector_Object.h"

#include "OmegaFunctions_Object.generated.h"

UCLASS()
class UOmegaObjectFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(DeterminesOutputType="Class"))
	static UObject* Duplicate_Object(UObject* object,UObject* NewOuter, UClass* Class);

	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(WorldContext="WorldContextObject"))
	static UObject* RunSelector_Object(UObject* WorldContextObject, FOmegaSelect_Object Selector);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(WorldContext="WorldContextObject"))
	static UPrimaryDataAsset* RunSelector_DataAsset(UObject* WorldContextObject, FOmegaSelect_DataAsset Selector);
};
