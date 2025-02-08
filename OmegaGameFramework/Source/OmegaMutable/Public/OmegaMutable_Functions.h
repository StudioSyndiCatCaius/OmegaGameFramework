// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MuCO/CustomizableSkeletalComponent.h"
#include "OmegaMutable_Functions.generated.h"

UINTERFACE(MinimalAPI) class UDataInterface_MutableSource : public UInterface { GENERATED_BODY() };
class OMEGAMUTABLE_API IDataInterface_MutableSource
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Combatant")
	UCustomizableObjectInstance* GetCustomizableObjectInstance();
};



UCLASS()
class UOmegaMutablesFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Materials")
	static void SetMutable_FromSource(UCustomizableSkeletalComponent* Component, UObject* Source);

};


