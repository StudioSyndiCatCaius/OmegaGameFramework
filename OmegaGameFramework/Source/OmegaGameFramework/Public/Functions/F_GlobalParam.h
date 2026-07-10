// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/Struct_SoftParams.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataAsset.h"
#include "F_GlobalParam.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_GlobalVars : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static void L_CallParamUpdateDel(UObject* WorldContextObject, FName param, EOmegaGlobalParamTarget target, int32 valueInt,int32 OldValue);

public:
	static FOmegaSoftParams* GetParamStruct(UObject* WorldContextObject, EOmegaGlobalParamTarget Target);

	UFUNCTION() static TArray<FName> opts_global_bool();
	UFUNCTION() static TArray<FName> opts_global_int32();
	UFUNCTION() static TArray<FName> opts_global_float();
	UFUNCTION() static TArray<FName> opts_global_string();
	UFUNCTION() static TArray<FName> opts_global_vector();
	UFUNCTION() static TArray<FName> opts_global_rotator();
	UFUNCTION() static TArray<FName> opts_global_asset();
	// ======================================================
	// BITFLAGS
	// ======================================================
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Bool",meta=(WorldContext="WorldContextObject",CompactNodeTitle="SET (bool)"),DisplayName="🌎Globals - Param SET (bool)")
	static void SetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_bool")) FName Variable, bool Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Bool",meta=(WorldContext="WorldContextObject",CompactNodeTitle="GET (bool)"),DisplayName="🌎Globals - Param GET (bool)")
	static bool GetGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_bool")) FName Variable);
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Bool",meta=(WorldContext="WorldContextObject",CompactNodeTitle="TOGGLE (bool)"),DisplayName="🌎Globals - Param TOGGLE (bool)")
	static bool ToggleGlobalVariable_Bool(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_bool")) FName Variable);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Int32",meta=(WorldContext="WorldContextObject",CompactNodeTitle="SET (int32)"),DisplayName="🌎Globals - Param SET (Int32)")
	static void SetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_int32")) FName Variable, int32 Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Int32",meta=(WorldContext="WorldContextObject",CompactNodeTitle="ADD (int32)"),DisplayName="🌎Globals - Param ADD (Int32)")
	static void AddGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_int32")) FName Variable, int32 Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Int32",meta=(WorldContext="WorldContextObject",CompactNodeTitle="GET (int32)"),DisplayName="🌎Globals - Param GET (Int32)")
	static int32 GetGlobalVariable_Int32(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_int32")) FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Float",meta=(WorldContext="WorldContextObject",CompactNodeTitle="SET (float)"),DisplayName="🌎Globals - Param SET (float)")
	static void SetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_float")) FName Variable, float Value);
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Float",meta=(WorldContext="WorldContextObject",CompactNodeTitle="ADD (float)"),DisplayName="🌎Globals - Param ADD (float)")
	static void AddGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_float")) FName Variable, float Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Float",meta=(WorldContext="WorldContextObject",CompactNodeTitle="GET (float)"),DisplayName="🌎Globals - Param GET (float)")
	static float GetGlobalVariable_Float(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_float")) FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|String",meta=(WorldContext="WorldContextObject",CompactNodeTitle="SET (string)"),DisplayName="🌎Globals - Param SET (String)")
	static void SetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_string")) FName Variable, FString Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|String",meta=(WorldContext="WorldContextObject",CompactNodeTitle="GET (string)"),DisplayName="🌎Globals - Param GET (String)")
	static FString GetGlobalVariable_String(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_string")) FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject",CompactNodeTitle="SET (vector)"),DisplayName="🌎Globals - Param SET (Vector)")
	static void SetGlobalVariable_Vector(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_vector")) FName Variable, FVector Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject",CompactNodeTitle="GET (vector)"),DisplayName="🌎Globals - Param GET (Vector)")
	static FVector GetGlobalVariable_Vector(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_vector")) FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject",CompactNodeTitle="SET (rotator)"),DisplayName="🌎Globals - Param SET (Rotator)")
	static void SetGlobalVariable_Rotator(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_rotator")) FName Variable, FRotator Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|Vector",meta=(WorldContext="WorldContextObject",CompactNodeTitle="GET (rotator)"),DisplayName="🌎Globals - Param GET (Rotator)")
	static FRotator GetGlobalVariable_Rotator(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_rotator")) FName Variable);

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Variables|DataAsset",meta=(WorldContext="WorldContextObject",CompactNodeTitle="SET (asset)"),DisplayName="🌎Globals - Param SET (Data Asset)")
	static void SetGlobalVariable_DataAsset(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_asset")) FName Variable, UPrimaryDataAsset* Value);
	UFUNCTION(BlueprintPure,Category="Omega|Global|Variables|DataAsset",meta=(WorldContext="WorldContextObject",CompactNodeTitle="GET (asset)",DeterminesOutputType="Class"),DisplayName="🌎Globals - Param GET (Data Asset)")
	static UPrimaryDataAsset* GetGlobalVariable_DataAsset(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, UPARAM(meta=(GetOptions="opts_global_asset")) FName Variable, TSubclassOf<UPrimaryDataAsset> Class=nullptr);

	// ======================================================
	// BITFLAGS
	// ======================================================

	UFUNCTION(BlueprintCallable,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter="BITFLAG",CompactNodeTitle="🚩 SET"),DisplayName="🌎Globals -🚩 Set Bitflag")
	static void Bitflag_Set(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag, uint8 Flag, bool bValue);

	UFUNCTION(BlueprintPure,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter="BITFLAG",CompactNodeTitle="🚩 GET"),DisplayName="🌎Globals -🚩 Get Bitflag")
	static bool Bitflag_Get(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag, uint8 Flag);

	// Remove entry entirely
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter="BITFLAG",CompactNodeTitle="🚩 CLEAR"),DisplayName="🌎Globals -🚩 Clear Bitflag")
	static void Bitflag_Clear(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag);
	// Check if any flags are set
	UFUNCTION(BlueprintPure,Category="Omega|Global|Bitflags",meta=(WorldContext="WorldContextObject",GameplayTagFilter="BITFLAG",CompactNodeTitle="🚩 ANY?"),DisplayName="🌎Globals -🚩 Has Any Bitflag")
	static bool Bitflag_HasAny(UObject* WorldContextObject, EOmegaGlobalParamTarget Target, FGameplayTag Tag);
	
	
	// ======================================================
	// Guid BITFLAGS
	// ======================================================
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Guidflags",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="🌎Guidflag - Set")
	static void Guidflag_Set(UObject* WorldContextObject, FGuid Guid, uint8 Flag, bool bValue, EOmegaGlobalParamTarget Target=EOmegaGlobalParamTarget::SAVE_GAME);

	UFUNCTION(BlueprintPure,Category="Omega|Global|Guidflags",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="🌎Guidflag - Get")
	static bool Guidflag_Get(UObject* WorldContextObject, FGuid Guid, uint8 Flag, EOmegaGlobalParamTarget Target=EOmegaGlobalParamTarget::SAVE_GAME);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Global|Guidflags",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="🌎Guidflag - Clear")
	static void Guidflag_Clear(UObject* WorldContextObject, FGuid Guid, EOmegaGlobalParamTarget Target=EOmegaGlobalParamTarget::SAVE_GAME);
	
	
};
