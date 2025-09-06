// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_AI.generated.h"

UCLASS()
class UOmegaAIFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|AI")
	static void SetStateTreeActive();

};


