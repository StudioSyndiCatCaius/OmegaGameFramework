// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Misc/OmegaUtils_Enums.h"
#include "I_DataAsset.generated.h"


// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_DataAsset : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_DataAsset
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, Category="DataAsset")
    UPrimaryDataAsset* GetDataAsset_Named(FName name);
};

