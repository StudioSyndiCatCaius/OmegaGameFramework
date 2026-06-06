// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_CommandLine.generated.h"

UCLASS()
class UOmegaFunctions_Command : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Command",DisplayName="CMD - Parse (String)")
	static FString Parse_String(const FString& source, const FString& param, const FString& Fallback,bool& bValid);
	
	UFUNCTION(BlueprintPure,Category="Omega|Command",DisplayName="CMD - Parse (Bool)")
	static bool Parse_Bool(const FString& source, const FString& param, bool Fallback,bool& bValid);
	
	UFUNCTION(BlueprintPure,Category="Omega|Command",DisplayName="CMD - Parse (Int32)")
	static int32 Parse_Int32(const FString& source, const FString& param, int32 Fallback,bool& bValid);
	
	UFUNCTION(BlueprintPure,Category="Omega|Command",DisplayName="CMD - Parse (Float)")
	static float Parse_Float(const FString& source, const FString& param, float Fallback,bool& bValid);
};