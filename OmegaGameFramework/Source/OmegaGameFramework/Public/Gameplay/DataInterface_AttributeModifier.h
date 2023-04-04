// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DataInterface_AttributeModifier.generated.h"

class UOmegaAttribute;

USTRUCT(BlueprintType)
struct FOmegaAttributeModifier
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	UOmegaAttribute* Attribute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float Incrementer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float Multiplier;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_AttributeModifier : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IDataInterface_AttributeModifier
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Attributes|Modifiers")
	TArray<FOmegaAttributeModifier> GetModifierValues();
};
