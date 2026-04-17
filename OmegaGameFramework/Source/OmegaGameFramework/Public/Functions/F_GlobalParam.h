// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/Struct_SoftParams.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_GlobalParam.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_GlobalVars : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static void L_CallParamUpdateDel(UObject* WorldContextObject, FName param, EOmegaGlobalParamTarget target, int32 valueInt,int32 OldValue);

public:
	static FOmegaSoftParams* GetParamStruct(UObject* WorldContextObject, EOmegaGlobalParamTarget Target);
	// ======================================================
	// BITFLAGS
	// ======================================================
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param SET (bool)")
	static void SetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param GET (bool)")
	static bool GetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param SET (Int32)")
	static void SetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param GET (Int32)")
	static int32 GetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Float",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param SET (float)")
	static void SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Float",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param GET (float)")
	static float GetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|String",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param SET (String)")
	static void SetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, FString Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|String",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param GET (String)")
	static FString GetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param SET (Vector)")
	static void SetGlobalVariable_Vector(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, FVector Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param GET (Vector)")
	static FVector GetGlobalVariable_Vector(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param SET (Rotator)")
	static void SetGlobalVariable_Rotator(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, FRotator Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param GET (Rotator)")
	static FRotator GetGlobalVariable_Rotator(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|DataAsset",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param SET (Data Asset)")
	static void SetGlobalVariable_DataAsset(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, UPrimaryDataAsset* Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|DataAsset",meta=(WorldContext="WorldContextObject"),DisplayName="🌎Globals - Param GET (Data Asset)")
	static UPrimaryDataAsset* GetGlobalVariable_DataAsset(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	// ======================================================
	// BITFLAGS
	// ======================================================
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="🌎Globals -🚩 Set Bitflag")
	static void Bitflag_Set(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag, uint8 Flag, bool bValue);
	
	UFUNCTION(BlueprintPure,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="🌎Globals -🚩 Get Bitflag")
	static bool Bitflag_Get(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag, uint8 Flag);
	
	// Remove entry entirely
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="🌎Globals -🚩 Clear Bitflag")
	static void Bitflag_Clear(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag);
	// Check if any flags are set
	UFUNCTION(BlueprintPure,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="🌎Globals -🚩 Has Any Bitflag")
	static bool Bitflag_HasAny(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag);
	
};
