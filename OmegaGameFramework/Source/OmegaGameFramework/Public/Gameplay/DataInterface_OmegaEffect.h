// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OmegaGameplayEffect.h"
#include "DataInterface_OmegaEffect.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UDataInterface_OmegaEffect : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IDataInterface_OmegaEffect
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, Category="Effects")
	TArray<FOmegaEffectContainer> GetOmegaEffects();
};
