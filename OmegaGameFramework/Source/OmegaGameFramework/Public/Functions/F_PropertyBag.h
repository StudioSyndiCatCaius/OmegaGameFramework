// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/PropertyBag.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StructUtils/PropertyBag.h"
#include "F_PropertyBag.generated.h"

class UPCGComponent;
/**
 * Blueprint-accessible wrapper around FInstancedPropertyBag.
 * Stores a dynamic set of named, typed properties that can be get/set at runtime.
 */
USTRUCT(BlueprintType, DisplayName="Property Bag")
struct OMEGAGAMEFRAMEWORK_API FOmegaPropertyBagWrapper
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="PropertyBag")
	FInstancedPropertyBag Bag;
};

USTRUCT(BlueprintType, DisplayName="Property Bag Config")
struct OMEGAGAMEFRAMEWORK_API FOmegaPropertyBagConfig
{
	GENERATED_BODY()

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_PropertyBag : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Set a value in the property bag by name.
	 * Accepts any property type. If the property doesn't exist it will be created;
	 * if it exists with a different type it will be replaced.
	 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Omega|PropertyBag",
		meta=(CustomStructureParam="Value", DisplayName="Set Property Bag Value", AutoCreateRefTerm="Value"))
	static void SetPropertyBagValue(UPARAM(ref) FOmegaPropertyBagWrapper& Bag, FName PropertyName, const int32& Value);
	DECLARE_FUNCTION(execSetPropertyBagValue);

	/**
	 * Get a value from the property bag by name.
	 * Accepts any property type. Executes the "Valid" pin if the property exists and
	 * the stored type is compatible with the output pin, otherwise executes "Invalid".
	 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Omega|PropertyBag",
		meta=(CustomStructureParam="Value", DisplayName="Get Property Bag Value",
		      ExpandBoolAsExecs="bValid", AutoCreateRefTerm="Value"))
	static void GetPropertyBagValue(const FOmegaPropertyBagWrapper& Bag, FName PropertyName, bool& bValid, int32& Value);
	DECLARE_FUNCTION(execGetPropertyBagValue);
};
