// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_Json.generated.h"

UCLASS()
class UOmegaJsonFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// JSON PARSER
	UFUNCTION(BlueprintCallable,Category="Omega|Json",DisplayName="Parse String to JSON (CSV)")
	FJsonObjectWrapper ParseStringToJson_CSV(const FString StringToParse);

	UFUNCTION(BlueprintCallable,Category="Omega|Json",DisplayName="Parse String to JSON (Lua)")
	FJsonObjectWrapper ParseStringToJson_Lua(const FString StringToParse);

	UFUNCTION(BlueprintCallable,Category="Omega|Json",DisplayName="Parse String to JSON (INI)")
	FJsonObjectWrapper ParseStringToJson_INI(const FString StringToParse);

	UFUNCTION(BlueprintCallable,Category="Omega|Json",DisplayName="Parse String to JSON (YAML)")
	FJsonObjectWrapper ParseStringToJson_YAML(const FString StringToParse);
	
	//JSON VALUE
	UFUNCTION(BlueprintPure,Category="Omega|Json",DisplayName="Get Json Value (bool)")
	bool GetJsonValue_Bool(FJsonObjectWrapper json, const FString& field);
	
	UFUNCTION(BlueprintPure,Category="Omega|Json",DisplayName="Get Json Value (bool)")
	int32 GetJsonValue_Int(FJsonObjectWrapper json, const FString& field);
	
	UFUNCTION(BlueprintPure,Category="Omega|Json",DisplayName="Get Json Value (bool)")
	float GetJsonValue_Float(FJsonObjectWrapper json, const FString& field);
	
	UFUNCTION(BlueprintPure,Category="Omega|Json",DisplayName="Get Json Value (bool)")
	FString GetJsonValue_String(FJsonObjectWrapper json, const FString& field);
	
};
