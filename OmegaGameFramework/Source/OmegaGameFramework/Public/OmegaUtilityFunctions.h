// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaUtilityFunctions.generated.h"

UCLASS()
class UOmegaUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static bool AreShadersCompiling();

	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static int32 GetShaderCompilationRemaining();
/*
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Math")
	static bool CompareFloatValues(float Value1, float Value2, EComparisonMethod ComparisonMethod);
	*/

	//###############################################################################
	// Text
	//###############################################################################
	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Text")
	static void SetTextLocalized(FText& TextToLocalize);

	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Text")
	static TArray<FString> GetBlueprintCallableAndPureFunctions(UObject* Object);
};

UCLASS()
class UOmegaAssetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure,Category="Omega|Asset")
	UClass* GetBlueprintClassFromPath(const FString Path);
	
};