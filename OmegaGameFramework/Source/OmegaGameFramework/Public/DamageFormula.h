// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "DamageFormula.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UDamageFormula : public UObject
{
	GENERATED_BODY()


public:
		UFUNCTION(BlueprintImplementableEvent)
		void GetDamageAmount(class UObject* Instigator, class UObject* Target, float& DamageOut);
};
