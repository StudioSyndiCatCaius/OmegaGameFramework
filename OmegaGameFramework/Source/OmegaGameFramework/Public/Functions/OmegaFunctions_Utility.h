// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_Utility.generated.h"

UCLASS()
class UOmegaUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static bool AreShadersCompiling();

	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static int32 GetShaderCompilationRemaining();

	//###############################################################################
	// Text
	//###############################################################################
	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Text")
	static void SetTextLocalized(FText& TextToLocalize);

	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Text")
	static TArray<FString> GetBlueprintCallableAndPureFunctions(UObject* Object);

	// INCOMPLETE: these functions still need to be made
	UFUNCTION()
	static bool IsLoading_Foliage()
	{
		return false;
	}

	UFUNCTION()
	static bool IsLoading_Textures()
	{
		return false;
	}
};

UCLASS()
class UOmegaAssetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure,Category="Omega|Asset")
	UClass* GetBlueprintClassFromPath(const FString Path);
	
};