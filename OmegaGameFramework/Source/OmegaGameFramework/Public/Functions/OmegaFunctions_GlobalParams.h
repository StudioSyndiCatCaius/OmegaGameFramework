// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaFunctions_GlobalParams.generated.h"


UCLASS()
class UOmegaGlobalVariables_Guid : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Guid|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable (GUID) <🔴Bool>")
	static void SetGlobalGuidVariable_Bool(UObject* WorldContextObject, FGuid GUID, EOmegaGlobalParamTarget Target, FString Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Guid|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable (GUID) <🔴Bool>")
	static bool GetGlobalGuidVariable_Bool(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Guid|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable (GUID) <🔷Int32>")
	static void SetGlobalGuidVariable_Int32(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Guid|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable (GUID) <🔷Int32>")
	static int32 GetGlobalGuidVariable_Int32(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Guid|Float",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable (GUID) <📗Float>")
	static void SetGlobalGuidVariable_Float(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Guid|Float",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable (GUID) <📗Float>")
	static float GetGlobalGuidVariable_Float(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Guid|String",meta=(WorldContext="WorldContextObject",NodeColor="Red"),DisplayName="Ω Set Global Variable (GUID) <🌸String>")
	static void SetGlobalGuidVariable_String(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable, FString Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Guid|String",meta=(WorldContext="WorldContextObject",NodeColor="Red"),DisplayName="Ω Get Global Variable (GUID) <🌸String>")
	static FString GetGlobalGuidVariable_String(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable);
};


UCLASS()
class UOmegaGlobalVariables_Named : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Named|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable <🔴Bool>")
	static void SetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Named|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable <🔴Bool>")
	static bool GetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Named|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable <🔷Int32>")
	static void SetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Named|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable <🔷Int32>")
	static int32 GetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Named|Float",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable <📗Float>")
	static void SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Named|Float",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable <📗Float>")
	static float GetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Named|String",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable <🌸String>")
	static void SetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable, FString Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Named|String",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable <🌸String>")
	static FString GetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable);
};

UCLASS()
class UOmegaGlobalVariables_Tagged : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Tagged|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable (Tagged) <🔴Bool>")
	static void SetTaggedGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Tagged|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable (Tagged) <🔴Bool>")
	static bool GetTaggedGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Tagged|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable (Tagged) <🔷Int32>")
	static void SetTaggedGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Tagged|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable (Tagged) <🔷Int32>")
	static int32 GetTaggedGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Tagged|Float",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable (Tagged) <📗Float>")
	static void SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Tagged|Float",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable (Tagged) <📗Float>")
	static float GetTaggedGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Tagged|String",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Set Global Variable (Tagged) <🌸String>")
	static void SetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable, FString Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Tagged|String",meta=(WorldContext="WorldContextObject"),DisplayName="Ω Get Global Variable (Tagged) <🌸String>")
	static FString GetTaggedGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Variable);
};

