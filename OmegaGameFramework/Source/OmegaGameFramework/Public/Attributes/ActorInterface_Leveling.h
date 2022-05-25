// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActorInterface_Leveling.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UActorInterface_Leveling : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IActorInterface_Leveling
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	//Adds to the base XpRate value.
	UFUNCTION(BlueprintNativeEvent, Category="Leveling")
	float GetXPRateOffset();

};
