// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "InputCoreTypes.h"
#include "InputMappingContext.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "UObject/Interface.h"

#include "OmegaFunctions_Input.generated.h"

// This class does not need to be modified.
UINTERFACE() class UDataInterface_Input : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Input
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="Omega|Input")
	FKey GetContext_InputKey(FGameplayTag ContextTag=FGameplayTag());
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Input")
	UInputAction* GetContext_InputAction(FGameplayTag ContextTag=FGameplayTag());
	UFUNCTION(BlueprintNativeEvent,Category="Omega|Input")
	UInputMappingContext* GetContext_InputMappingContext(FGameplayTag ContextTag=FGameplayTag());
};



UCLASS()
class UOmegaInputFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Input", meta=(ExpandBoolAsExecs = "Outcome"))
	static UObject* GetFirstObjectWithContextInputKey(TArray<UObject*> Objects,FKey Key, bool& Outcome, FGameplayTag ContextTag=FGameplayTag());
	
};
