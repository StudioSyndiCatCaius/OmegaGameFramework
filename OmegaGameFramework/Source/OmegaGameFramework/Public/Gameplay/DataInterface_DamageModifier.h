// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CombatantComponent.h"
#include "UObject/Interface.h"
#include "DataInterface_DamageModifier.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UDataInterface_DamageModifier : public UInterface
{
	GENERATED_BODY()
};


class OMEGAGAMEFRAMEWORK_API IDataInterface_DamageModifier
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, Category="Attributes")
	float ModifyDamage(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context);
};
