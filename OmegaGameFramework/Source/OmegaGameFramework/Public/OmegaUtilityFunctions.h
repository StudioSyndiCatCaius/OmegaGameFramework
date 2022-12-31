// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "OmegaUtilityFunctions.generated.h"

UCLASS()
class UOmegaUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	//UFUNCTION(BlueprintPure, Category="Omega|Utilities|PropertyAccess")
	static float GetHardVariable_Float(UObject* Object, const FString& VariableName, bool bValid);
	
};
