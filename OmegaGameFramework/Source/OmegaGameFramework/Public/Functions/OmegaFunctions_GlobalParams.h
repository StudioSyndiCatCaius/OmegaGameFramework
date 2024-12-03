// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaFunctions_GlobalParams.generated.h"


UCLASS()
class UOmegaGlobalVariables_Guid : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Guid",meta=(WorldContext="WorldContextObject"),DisplayName="Set GUID Global Variable (Bool)")
	static void SetGlobalGuidVariable_Bool(UObject* WorldContextObject, FGuid GUID, EOmegaGlobalParamTarget Target, FString Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Guid",meta=(WorldContext="WorldContextObject"),DisplayName="Get GUID Global Variable (Bool)")
	static bool GetGlobalGuidVariable_Bool(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Guid",meta=(WorldContext="WorldContextObject"),DisplayName="Set GUID Global Variable (Int32)")
	static void SetGlobalGuidVariable_Int32(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Guid",meta=(WorldContext="WorldContextObject"),DisplayName="Set GUID Global Variable (Int32)")
	static int32 GetGlobalGuidVariable_Int32(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Guid",meta=(WorldContext="WorldContextObject"),DisplayName="Set GUID Global Variable (Float)")
	static void SetGlobalGuidVariable_Float(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Guid",meta=(WorldContext="WorldContextObject"),DisplayName="Set GUID Global Variable (Float)")
	static float GetGlobalGuidVariable_Float(UObject* WorldContextObject, FGuid GUID,  EOmegaGlobalParamTarget Target, FString Variable);
};


UCLASS()
class UOmegaGlobalVariables_Named : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Named",meta=(WorldContext="WorldContextObject"),DisplayName="Set Global Variable (Bool)")
	static void SetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Named",meta=(WorldContext="WorldContextObject"),DisplayName="Get Global Variable (Bool)")
	static bool GetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Named",meta=(WorldContext="WorldContextObject"),DisplayName="Set Global Variable (Int32)")
	static void SetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Named",meta=(WorldContext="WorldContextObject"),DisplayName="Get Global Variable (Int32)")
	static int32 GetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Named",meta=(WorldContext="WorldContextObject"),DisplayName="Set Global Variable (Float)")
	static void SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Named",meta=(WorldContext="WorldContextObject"),DisplayName="Get Global Variable (Float)")
	static float GetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FString Variable);
};

