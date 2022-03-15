// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActorInterface_Combatant.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UActorInterface_Combatant : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IActorInterface_Combatant
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintNativeEvent, Category="Combatant")
	TArray<UObject*> GetAttributeModifiers();
};
