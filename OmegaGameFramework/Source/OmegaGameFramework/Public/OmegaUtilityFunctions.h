// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaUtilityFunctions.generated.h"

UCLASS()
class UOmegaUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static bool AreShadersCompiling();

	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static int32 GetShaderCompilationRemaining();
	
};
