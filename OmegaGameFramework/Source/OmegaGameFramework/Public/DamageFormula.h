// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "DamageFormula.generated.h"

class UCombatantComponent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UDamageFormula : public UObject
{
	GENERATED_BODY()


public:
		UFUNCTION(BlueprintImplementableEvent)
		void GetDamageAmount(UCombatantComponent* Instigator, UCombatantComponent* Target, float& DamageOut);
};
