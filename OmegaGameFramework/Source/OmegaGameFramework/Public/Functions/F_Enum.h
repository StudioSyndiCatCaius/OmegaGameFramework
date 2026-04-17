// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Enum.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Enum : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, CustomThunk, Category = "Utilities|Enum", meta = (
		CustomStructureParam = "EnumValue",
		CompactNodeTitle = "Description",
		Keywords = "enum description tooltip"))
	static FText GetEnumValueDescription(uint8 EnumValue);

	DECLARE_FUNCTION(execGetEnumValueDescription);
	
};


