// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "UObject/Interface.h"
#include "I_Json.generated.h"


// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_Json : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Json
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Json",DisplayName="JSON - Get")
	FJsonObjectWrapper GetJsonData();

	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Json",DisplayName="JSON - Set")
    void SetJsonData(FJsonObjectWrapper data);
};


