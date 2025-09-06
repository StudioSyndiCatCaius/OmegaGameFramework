// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Misc/OmegaUtils_Structs.h"
#include "OmegaInterface_SoftEvent.generated.h"



// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_SoftEvent : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_SoftEvent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Soft",DisplayName="Soft Event")
	void SoftEvent(FName Event, FOmegaCommonMeta meta);
	
};

UCLASS()
class UOmegaSoftEventFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	
};

