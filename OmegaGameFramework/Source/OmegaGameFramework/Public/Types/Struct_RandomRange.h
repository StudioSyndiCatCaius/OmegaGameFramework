
#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "Struct_RandomRange.generated.h"

USTRUCT(BlueprintType)
struct FOmegaRandomRangeFloat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Range") float Base = 0.0f;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Range") float Variation = 0.0f;

	float GetValue() const
	{
		return FMath::RandRange(Variation*-1,Variation)+Base;
	}
};