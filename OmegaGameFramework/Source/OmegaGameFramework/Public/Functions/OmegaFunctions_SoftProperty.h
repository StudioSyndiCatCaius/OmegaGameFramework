// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_SoftProperty.generated.h"

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
	FString GetSoftProperty(FName Property);

	UFUNCTION(BlueprintNativeEvent, Category="SoftPropertries")
	TMap<FName, FString> GetSoftPropertyMap();
};

//#####################################################################################################
// PROPERTY FUNCTIONS
//#####################################################################################################
UCLASS()
class UOmegaSoftPropertyFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Soft Properties", meta=(CompactNodeTitle="Soft String"))
	static FString GetSoftProperty_String(UObject* Object, FName PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Soft Properties", meta=(CompactNodeTitle="Soft Bool"))
	static bool GetSoftProperty_bool(UObject* Object, FName PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Soft Properties", meta=(CompactNodeTitle="Soft Float"))
	static float GetSoftProperty_float(UObject* Object, FName PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Soft Properties", meta=(CompactNodeTitle="Soft Int32"))
	static int32 GetSoftProperty_int32(UObject* Object, FName PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Soft Properties", meta=(CompactNodeTitle="Soft Vector"))
	static FVector GetSoftProperty_Vector(UObject* Object, FName PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Soft Properties", meta=(CompactNodeTitle="Soft Rotator"))
	static FRotator GetSoftProperty_Rotator(UObject* Object, FName PropertyName);
};
//#################################################################################################################################################
// +++++++++++++++++++++++++++++++ TAG PROPERTIES ++++++++++++++++++++++++++++++++++++++++++++++
//#################################################################################################################################################

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UOmegaTagPropertyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IOmegaTagPropertyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, Category="SoftPropertries")
	FString GetTagProperty(const FGameplayTag& Property);

	UFUNCTION(BlueprintNativeEvent, Category="SoftPropertries")
	TMap<FGameplayTag, FString> GetTagPropertyMap();
};

//#####################################################################################################
// PROPERTY FUNCTIONS
//#####################################################################################################
UCLASS()
class UOmegaTagPropertyFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Tag Properties", meta=(CompactNodeTitle="Tag String"))
	static FString GetTagProperty_String(UObject* Object, FGameplayTag PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Tag Properties", meta=(CompactNodeTitle="Tag Bool"))
	static bool GetTagProperty_bool(UObject* Object, FGameplayTag PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Tag Properties", meta=(CompactNodeTitle="Tag Float"))
	static float GetTagProperty_float(UObject* Object,FGameplayTag PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Tag Properties", meta=(CompactNodeTitle="Tag Int32"))
	static int32 GetTagProperty_int32(UObject* Object,FGameplayTag PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Tag Properties", meta=(CompactNodeTitle="Tag Vector"))
	static FVector GetTagProperty_Vector(UObject* Object,FGameplayTag PropertyName);
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Tag Properties", meta=(CompactNodeTitle="Tag Rotator"))
	static FRotator GetTagProperty_Rotator(UObject* Object,FGameplayTag PropertyName);
};