// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "DamageFormula.generated.h"

class UCombatantComponent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, editinlinenew)
class OMEGAGAMEFRAMEWORK_API UDamageFormula : public UObject
{
	GENERATED_BODY()


public:
		UFUNCTION(BlueprintNativeEvent, Category="Damage")
		void GetDamageAmount(UCombatantComponent* Instigator, UCombatantComponent* Target, float& DamageOut);
	
};
