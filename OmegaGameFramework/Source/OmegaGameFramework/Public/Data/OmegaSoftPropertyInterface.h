// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OmegaSoftPropertyInterface.generated.h"

USTRUCT()
struct FSoftPropertyCollection
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, float> SoftProp_float;
	UPROPERTY()
	TMap<FString, int32> SoftProp_int;
	UPROPERTY()
	TMap<FString, FString> SoftProp_string;
	UPROPERTY()
	TMap<FString, bool> SoftProp_bool;
	UPROPERTY()
	TMap<FString, UObject*> SoftProp_object;
	UPROPERTY()
	TMap<FString, FVector> SoftProp_Vector;
	UPROPERTY()
	TMap<FString, FRotator> SoftProp_Rotator;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
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
	
	UFUNCTION(BlueprintCallable, Category="SoftPropertries", meta=(CompactNodeTitle="bool"), DisplayName="Get Soft Property (Bool)")
	virtual bool NativeGetSoftProperty_Bool(const FString& Property);
	UFUNCTION(BlueprintCallable, Category="SoftPropertries", meta=(CompactNodeTitle="int32"), DisplayName="Get Soft Property (Int32)")
	virtual int32 NativeGetSoftProperty_Int32(const FString& Property);
	UFUNCTION(BlueprintCallable, Category="SoftPropertries", meta=(CompactNodeTitle="float"), DisplayName="Get Soft Property (Float)")
	virtual float NativeGetSoftProperty_Float(const FString& Property);
	UFUNCTION(BlueprintCallable, Category="SoftPropertries", meta=(CompactNodeTitle="string"), DisplayName="Get Soft Property (String)")
	virtual FString NativeGetSoftProperty_String(const FString& Property);
	UFUNCTION(BlueprintCallable, Category="SoftPropertries", meta=(CompactNodeTitle="object"), DisplayName="Get Soft Property (Object)")
	virtual UObject* NativeGetSoftProperty_Object(const FString& Property);
	
	virtual FSoftPropertyCollection Native_GetSoftProperties();
	virtual void Native_SetSoftProperties(FSoftPropertyCollection Properties);
};
