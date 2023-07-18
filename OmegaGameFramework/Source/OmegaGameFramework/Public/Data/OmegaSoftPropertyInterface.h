// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaSoftPropertyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UOmegaSoftPropertyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IOmegaSoftPropertyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, Category="SoftPropertries")
	FString GetSoftProperty(const FString& Property);

	UFUNCTION(BlueprintNativeEvent, Category="SoftPropertries")
	TMap<FString, FString> GetSoftPropertyMap();
};

//#####################################################################################################
// PROPERTY FUNCTIONS
//#####################################################################################################
UCLASS()
class UOmegaSoftPropertyFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|PropertyAccess", meta=(CompactNodeTitle="Soft String"))
	static FString GetSoftProperty_String(UObject* Object, const FString& PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|PropertyAccess", meta=(CompactNodeTitle="Soft Bool"))
	static bool GetSoftProperty_bool(UObject* Object, const FString& PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|PropertyAccess", meta=(CompactNodeTitle="Soft Float"))
	static float GetSoftProperty_float(UObject* Object, const FString& PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|PropertyAccess", meta=(CompactNodeTitle="Soft Int32"))
	static int32 GetSoftProperty_int32(UObject* Object, const FString& PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|PropertyAccess", meta=(CompactNodeTitle="Soft Vector"))
	static FVector GetSoftProperty_Vector(UObject* Object, const FString& PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|PropertyAccess", meta=(CompactNodeTitle="Soft Rotator"))
	static FRotator GetSoftProperty_Rotator(UObject* Object, const FString& PropertyName);
};