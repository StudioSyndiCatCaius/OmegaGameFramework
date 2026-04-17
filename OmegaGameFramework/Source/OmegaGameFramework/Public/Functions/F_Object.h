// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Condition/Condition_DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Selectors/Selector_DataAsset.h"
#include "Selectors/Selector_Object.h"

#include "F_Object.generated.h"

USTRUCT(BlueprintType)
struct FOmegaObjectMeta
{
	GENERATED_BODY()
	
	UPROPERTY() TMap<UObject*, FLuaValue> ObjectMap;
	
	FLuaValue* ValidateMeta(UObject* WorldContext, UObject* TargetObject);
	FLuaValue GetParam(UObject* WC, UObject* obj, FName param);
};


UCLASS()
class UOmegaObjectFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|Selector")
	static void Rename_Object(UObject* object, FString NewName);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(DeterminesOutputType="Class"))
	static UObject* Duplicate_Object(UObject* object,UObject* NewOuter, UClass* Class);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(WorldContext="WorldContextObject"))
	static UObject* RunSelector_Object(UObject* WorldContextObject, FOmegaSelect_Object Selector);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(WorldContext="WorldContextObject"))
	static UPrimaryDataAsset* RunSelector_DataAsset(UObject* WorldContextObject, FOmegaSelect_DataAsset Selector);

	UFUNCTION(BlueprintCallable,Category="Omega|Selector")
	static bool CheckCondition_DataAsset(UPrimaryDataAsset* Asset, FOmegaConditions_DataAsset Selector,TArray<FText>& Reasons);
	
	// -----------------------------------------------------------------------------------------------------------------
	// mETA
	// -----------------------------------------------------------------------------------------------------------------
private:
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta -Get Table")
	static FLuaValue Meta_GetTable(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Set (Bool)")
	static void Meta_SetBool(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, bool NewValue);
	UFUNCTION(BlueprintCallable,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Set (Int)")
	static void Meta_SetInt(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, int32 NewValue);
	UFUNCTION(BlueprintCallable,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Set (Float)")
	static void Meta_SetFloat(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, float NewValue);
	
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Get (Bool)")
	static bool Meta_GetBool(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, bool Fallback=false);
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Get (Int)")
	static int32 Meta_GetInt(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, int32 Fallback=0);
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Get (Float)")
	static float Meta_GetFloat(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, float Fallback=0);
		
};
