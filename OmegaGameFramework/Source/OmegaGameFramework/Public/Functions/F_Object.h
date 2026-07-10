// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Condition/Condition_DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Selectors/Selector_DataAsset.h"
#include "Selectors/Selector_Object.h"

#include "F_Object.generated.h"

/** A per-object metadata store backed by Lua values.
 *  Keyed by UObject pointer; each entry holds a Lua table of named parameters. */
USTRUCT(BlueprintType)
struct FOmegaObjectMeta
{
	GENERATED_BODY()

	/** Internal map from object to its associated Lua metadata table. */
	UPROPERTY() TMap<UObject*, FLuaValue> ObjectMap;

	/** Ensures a Lua metadata entry exists for TargetObject and returns a pointer to it. */
	FLuaValue* ValidateMeta(UObject* WorldContext, UObject* TargetObject);
	/** Retrieves a named parameter from the Lua table associated with obj. */
	FLuaValue GetParam(UObject* WC, UObject* obj, FName param);
};

UCLASS(Blueprintable,BlueprintType,Abstract,CollapseCategories,EditInlineNew,DefaultToInstanced,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaObjectUtilityScript : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere,Category="Utility")
	bool bInvert;
	UPROPERTY(EditAnywhere,Category="Utility")
	float ScaleWeight=1.0;
	
	
	UFUNCTION(BlueprintNativeEvent, Category="CombatantFilter")
	const float CheckUtility(UObject* Object, FGameplayTag UtilityTag, FOmegaCommonMeta meta);

	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaObjectUtilityAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Utility")
	bool bReverse;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Utility")
	float RandomOffsetRange=0.0;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Utility")
	TArray<UOmegaObjectUtilityScript*> Scripts;

};


// Filter delegate — return true to KEEP the object
DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FObjectFilterDelegate, UObject*, Object);

// Sort delegate — return true if A should come BEFORE B
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FObjectSortDelegate, UObject*, A, UObject*, B);

DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(float, FObjectFloatCompareDelegate, UObject*, A, UObject*, B);

UCLASS()
class UOmegaObjectFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Omega|Object",DisplayName="Object - Filter Array")
	static TArray<UObject*> FilterObjectArray(
		const TArray<UObject*>& Objects,
		FObjectFilterDelegate FilterDelegate);

	UFUNCTION(BlueprintCallable, Category = "Omega|Object",DisplayName="Object - Sort Array")
	static TArray<UObject*> SortObjectArray(
		const TArray<UObject*>& Objects,
		FObjectSortDelegate SortDelegate);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Object",DisplayName="Object - Select By Utility Weight",
		meta=(AdvancedDisplay="bReverse,RandomOffsetRange"))
	static UObject* SelectObjectByWeight(
		const TArray<UObject*>& Objects,
		FObjectFloatCompareDelegate CheckDelegate, bool bReverse=false, float RandomOffsetRange=0.0);


	UFUNCTION(BlueprintCallable, Category = "Omega|Object",DisplayName="Object - Select By Utility Asset",
		meta=(AdvancedDisplay="Utility,meta"))
	static UObject* SelectObjectByUtilityAsset(
		const TArray<UObject*>& Objects,
		UOmegaObjectUtilityAsset* ScriptAsset, UPARAM(meta=(Categories="EVENT")) FGameplayTag UtilityTag, FOmegaCommonMeta meta,
		float& SelectedUtility,float& AverageUtility);
	
	
	/** Renames a UObject to NewName at runtime. Use with caution — mainly useful for debugging or procedural content. */
	UFUNCTION(BlueprintCallable,Category="Omega|Selector")
	static void Rename_Object(UObject* object, FString NewName);

	/** Duplicates a UObject into NewOuter, casting the result to Class. Returns the new copy. */
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(DeterminesOutputType="Class"))
	static UObject* Duplicate_Object(UObject* object,UObject* NewOuter, UClass* Class);

	/** Evaluates an FOmegaSelect_Object selector and returns the resulting UObject. */
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(WorldContext="WorldContextObject"))
	static UObject* RunSelector_Object(UObject* WorldContextObject, FOmegaSelect_Object Selector);

	/** Evaluates an FOmegaSelect_DataAsset selector and returns the resulting PrimaryDataAsset. */
	UFUNCTION(BlueprintCallable,Category="Omega|Selector",meta=(WorldContext="WorldContextObject"))
	static UPrimaryDataAsset* RunSelector_DataAsset(UObject* WorldContextObject, FOmegaSelect_DataAsset Selector);

	/** Checks an Asset against a set of data asset conditions. Reasons is populated with failure messages for any unmet conditions. */
	UFUNCTION(BlueprintCallable,Category="Omega|Selector")
	static bool CheckCondition_DataAsset(UPrimaryDataAsset* Asset, FOmegaConditions_DataAsset Selector,TArray<FText>& Reasons);

	UFUNCTION(BlueprintCallable, Category="Omega|Interface",DisplayName="Interface Array to Objects",meta=(DeterminesOutputType="FilterClass"))
	static TArray<UObject*> Conv_InterfaceArrayToObjects(
		TArray<TScriptInterface<IInterface>> Interfaces,
		TSubclassOf<UObject> FilterClass);
	
	// -----------------------------------------------------------------------------------------------------------------
	// Tag Event/Query
	// -----------------------------------------------------------------------------------------------------------------
	
	/** Fires a gameplay tag event on Object, passing optional metadata. */
	UFUNCTION(BlueprintCallable, Category="Omega|GameplayTags",DisplayName="Object - Fire Tag Event")
	static void Object_TagEvent(UObject* Object, UPARAM(meta=(Categories="EVENT")) FGameplayTag Event, FOmegaCommonMeta meta);

	/** Queries Object with a tag-based query, returning true if the object satisfies the query. */
	UFUNCTION(BlueprintPure, Category="Omega|GameplayTags",DisplayName="Object - Check Tag Query")
	static bool Object_TagQuery(UObject* Object, UPARAM(meta=(Categories="QUERY")) FGameplayTag Event, FOmegaCommonMeta meta);

	UFUNCTION(BlueprintCallable, Category="Omega|GameplayTags",DisplayName="Object - Check Tag Utility")
	static float Object_TagUtility(UObject* Object, UPARAM(meta=(Categories="UTILITY")) FGameplayTag Event, FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintCallable, Category="Omega|GameplayTags",DisplayName="Object - Evaluate Utility List")
	static UObject* Object_SelectByTagUtility(TArray<UObject*> Objects, UPARAM(meta=(Categories="UTILITY")) FGameplayTag Event,
		FOmegaCommonMeta meta, bool bReverse=false, float RandomOffsetRange=0.0);
	
	
	// -----------------------------------------------------------------------------------------------------------------
	// Meta
	// -----------------------------------------------------------------------------------------------------------------
private:
	/** Returns the raw Lua table stored for Object inside the given Meta container. */
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta -Get Table")
	static FLuaValue Meta_GetTable(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object);

	/** Sets a named bool parameter in the Lua metadata table for Object. */
	UFUNCTION(BlueprintCallable,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Set (Bool)")
	static void Meta_SetBool(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, bool NewValue);
	/** Sets a named int32 parameter in the Lua metadata table for Object. */
	UFUNCTION(BlueprintCallable,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Set (Int)")
	static void Meta_SetInt(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, int32 NewValue);
	/** Sets a named float parameter in the Lua metadata table for Object. */
	UFUNCTION(BlueprintCallable,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Set (Float)")
	static void Meta_SetFloat(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, float NewValue);

	/** Gets a named bool parameter from the Lua metadata table for Object. Returns Fallback if the key is absent. */
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Get (Bool)")
	static bool Meta_GetBool(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, bool Fallback=false);
	/** Gets a named int32 parameter from the Lua metadata table for Object. Returns Fallback if the key is absent. */
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Get (Int)")
	static int32 Meta_GetInt(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, int32 Fallback=0);
	/** Gets a named float parameter from the Lua metadata table for Object. Returns Fallback if the key is absent. */
	UFUNCTION(BlueprintPure,Category="Omega|Meta",meta=(WorldContext="WorldContextObject"),DisplayName="Object Meta - Get (Float)")
	static float Meta_GetFloat(UObject* WorldContextObject, UPARAM(ref) FOmegaObjectMeta& Meta,UObject* Object, FName param, float Fallback=0);

public:
	
	// ----------------------------------------------------------------------------------------------
	// ParamFromName
	// ---------------------------------------------------------------------------------------------
	
	// Gets a string value from the _ parsed name of the object. (E.G. - 'skill_fire_3' with param 1 returns 'fire')
	UFUNCTION(BlueprintPure, Category = "Omega|NameParam",DisplayName="Name Param - Get (String)")
	static FString GetNameParam_String(UObject* Object, uint8 param);
	
	// Gets an int value from the _ parsed name of the object. (E.G. - 'skill_fire_3' with param 2 returns '3')
	UFUNCTION(BlueprintPure, Category = "Omega|NameParam",DisplayName="Name Param - Get (Int)")
	static int32 GetNameParam_Int(UObject* Object, uint8 param);
	
};
