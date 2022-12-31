// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OmegaVirtualInputPlayerSubsystem.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Omega Subsystem: Virtual Input")
class OMEGAINPUT_API UOmegaVirtualInputPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category="Omega|Virtual Input|Cursor")
	void SetVirtualCursorEnabled(bool bEnabled);
	
};
