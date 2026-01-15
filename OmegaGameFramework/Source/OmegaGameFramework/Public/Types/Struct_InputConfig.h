
#pragma once

#include "CoreMinimal.h"
#include "Struct_InputConfig.generated.h"

USTRUCT(BlueprintType)
struct FOmegaInputConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	FText DisplayName;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	TMap<FKey,FVector> KeyInputs;
	
};