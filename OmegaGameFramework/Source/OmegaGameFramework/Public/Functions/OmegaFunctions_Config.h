// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Dom/JsonObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_Config.generated.h"

/**
 * 
 */

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaConfigFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static FJsonObject GetOmegaConfigJsonObject();
	
	UFUNCTION()
	static FJsonObjectWrapper GetOmegaConfigJson();

	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="Get Ω Config Property (String)", meta=(CompactNodeTitle="Config (String)"))
	static FString GetOmegaConfigProperty_String(const FString Property);

	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="Get Ω Config Property (Bool)", meta=(CompactNodeTitle="Config (bool)"))
	static bool GetOmegaConfigProperty_Bool(const FString Property);

	UFUNCTION(BlueprintPure, Category="Omega|Config", DisplayName="Get Ω Config Property (Int32)", meta=(CompactNodeTitle="Config (Int32)"))
	static int32 GetOmegaConfigProperty_Int(const FString Property);


	
};
