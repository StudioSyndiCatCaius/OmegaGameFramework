// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/Struct_SoftParams.h"
#include "F_GlobalParam.generated.h"

UENUM(Blueprintable,BlueprintType)
enum EOmegaGlobalParamTarget
{
	WORLD			UMETA(DisplayName = "🌎 World"),
	GAME_INSTANCE	UMETA(DisplayName = "🎮 Game Instance"),
	SAVE_GAME		UMETA(DisplayName = "💾 Save (Game)"),
	SAVE_GLOBAL		UMETA(DisplayName = "💾 Save (Global)"),
};


UCLASS()
class UOmegaFunctions_GlobalVars : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static FOmegaSoftParams* GetParamStruct(UObject* WorldContextObject, EOmegaGlobalParamTarget Target);
public:
	
	// ======================================================
	// BITFLAGS
	// ======================================================
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param SET (bool)")
	static void SetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Bool",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param GET (bool)")
	static bool GetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param SET (Int32)")
	static void SetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Int32",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param GET (Int32)")
	static int32 GetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|Float",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param SET (float)")
	static void SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|Float",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param GET (float)")
	static float GetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param SET (String)")
	static void SetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, FString Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param GET (String)")
	static FString GetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param SET (Vector)")
	static void SetGlobalVariable_Vector(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, FVector Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param GET (Vector)")
	static FVector GetGlobalVariable_Vector(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param SET (Rotator)")
	static void SetGlobalVariable_Rotator(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, FRotator Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param GET (Rotator)")
	static FRotator GetGlobalVariable_Rotator(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param SET (Data Asset)")
	static void SetGlobalVariable_DataAsset(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable, UPrimaryDataAsset* Value);
	UFUNCTION(BlueprintPure,Category="Omega|GlobalVariables|String",meta=(WorldContext="WorldContextObject"),DisplayName="GLOBALS - Param GET (Data Asset)")
	static UPrimaryDataAsset* GetGlobalVariable_DataAsset(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FName Variable);
	
	// ======================================================
	// BITFLAGS
	// ======================================================
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="GLOBALS -🚩 Set Bitflag")
	static void Bitflag_Set(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag, uint8 Flag, bool bValue);
	
	UFUNCTION(BlueprintPure,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="GLOBALS -🚩 Get Bitflag")
	static bool Bitflag_Get(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag, uint8 Flag);
	
	// Remove entry entirely
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="GLOBALS -🚩 Clear Bitflag")
	static void Bitflag_Clear(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag);
	// Check if any flags are set
	UFUNCTION(BlueprintPure,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter = "BITFLAG"),DisplayName="GLOBALS -🚩 Has Any Bitflag")
	static bool Bitflag_HasAny(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag);
	
};
