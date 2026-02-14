// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Structs.h"

#include "F_Save.generated.h"


class UOmegaSaveGlobal;
class UOmegaSaveGame;
class USaveGame;


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Save", meta = (WorldContext = "WorldContextObject",DeterminesOutputType="Class"))
	static UOmegaSaveGame* GetSave_Game(const UObject* WorldContextObject, TSubclassOf<UOmegaSaveGame> Class=nullptr);

	UFUNCTION(BlueprintPure,Category="Omega|Save", meta = (WorldContext = "WorldContextObject",DeterminesOutputType="Class"))
	static UOmegaSaveGlobal* GetSave_Global(const UObject* WorldContextObject, TSubclassOf<UOmegaSaveGlobal> Class=nullptr);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Set TagParam <Int>")
	static void SetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 Value, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Set TagParam <Bool>")
	static void SetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool Value, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Get TagParam <Int>")
	static int32 GetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Set TagParam <Bool>")
	static bool GetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandBoolAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Check TagParam <Bool>")
	static bool CheckSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal, bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandEnumAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Check TagParam <Int>")
	static int32 CheckSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 CheckValue, bool bGlobal, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome);

	//Asset
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Data Asset - Get JSON")
	static FJsonObjectWrapper DataAsset_GetJson(const UObject* WorldContextObject, UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Data Asset - Set JSON")
	static void DataAsset_SetJson(const UObject* WorldContextObject, UPrimaryDataAsset* Asset, FJsonObjectWrapper Json, bool bGlobal);
	
	//GUID
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) GUID - Get JSON")
	static FJsonObjectWrapper GUID_GetJson(const UObject* WorldContextObject, FGuid Guid, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) GUID - Set JSON")
	static void GUID_SetJson(const UObject* WorldContextObject, FGuid Guid, FJsonObjectWrapper Json, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",DisplayName="Save Game (Custom)")
	static bool Custom_SaveGame(USaveGame* SaveGameObject, const FString& path, const FString& file);

	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",DisplayName="Load Game (Custom)")
	static USaveGame* Custom_LoadGame(const FString& path, const FString& file);

	// Param Set
	UFUNCTION(BlueprintPure,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Get Param (Bool)")
	static bool GetSaveParam_Bool(const UObject* WorldContextObject, FName Param, bool bGlobal,bool Fallback=false);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Get Param (Int)")
	static int32 GetSaveParam_Int(const UObject* WorldContextObject, FName Param, bool bGlobal,int32 Fallback=0);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Get Param (Float)")
	static float GetSaveParam_Float(const UObject* WorldContextObject, FName Param, bool bGlobal,float Fallback=0.0);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Get Param (String)")
	static FString GetSaveParam_String(const UObject* WorldContextObject, FName Param, bool bGlobal,const FString& Fallback="");
	UFUNCTION(BlueprintPure,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Get Param (Vector)")
	static FVector GetSaveParam_Vector(const UObject* WorldContextObject, FName Param, bool bGlobal,FVector Fallback);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Get Param (DataAsset)")
	static UPrimaryDataAsset* GetSaveParam_DataAsset(const UObject* WorldContextObject, FName Param, bool bGlobal,UPrimaryDataAsset* Fallback=nullptr);

	UFUNCTION(BlueprintCallable,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set Save Param (Bool)")
	static void SetSaveParam_Bool(const UObject* WorldContextObject, bool Value, FName Param, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set Save Param (Int)")
	static void SetSaveParam_Int(const UObject* WorldContextObject, int32 Value, FName Param, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set Save Param (Float)")
	static void SetSaveParam_Float(const UObject* WorldContextObject, float Value, FName Param, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set Save Param (String)")
	static void SetSaveParam_String(const UObject* WorldContextObject, const FString& Value, FName Param, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set Save Param (Vector)")
	static void SetSaveParam_Vector(const UObject* WorldContextObject, FVector Value, FName Param, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Param", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="💾Save - Set Save Param (DataAsset)")
	static void SetSaveParam_DataAsset(const UObject* WorldContextObject, UPrimaryDataAsset* Value, FName Param, bool bGlobal);
	
	// ===============================================================
	// ENTITY
	// ===============================================================
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static void SetEntity_ByAsset(const UObject* WorldContextObject, UPrimaryDataAsset* Key, FOmegaEntity Entity, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static FOmegaEntity GetEntity_ByAsset(const UObject* WorldContextObject, UPrimaryDataAsset* Key, bool bGlobal);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static void SetEntity_ByGuid(const UObject* WorldContextObject, FGuid Key, FOmegaEntity Entity, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static FOmegaEntity GetEntity_ByGuid(const UObject* WorldContextObject, FGuid Key, bool bGlobal);
	


};

