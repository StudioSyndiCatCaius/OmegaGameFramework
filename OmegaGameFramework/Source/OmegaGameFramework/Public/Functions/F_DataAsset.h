// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_DataAsset.generated.h"

UINTERFACE(MinimalAPI) class UDataInterface_SourceDataAsset : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_SourceDataAsset
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	UPrimaryDataAsset* GetSourceDataAsset();
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDataAssetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:




	
};
