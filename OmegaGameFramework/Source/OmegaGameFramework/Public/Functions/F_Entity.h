// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"
#include "F_Entity.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Entity : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static FOmegaEntity* getEntityRefById(const UObject* WorldContextObject, FOmegaEntityID ID, EOmegaGlobalParamTarget Target = SAVE_GAME);

	static FOmegaEntitySet* _getEntitySaveObj(const UObject* context, EOmegaGlobalParamTarget Target = SAVE_GAME);

	UFUNCTION() static TArray<FName> opts_entity_int32();
	UFUNCTION() static TArray<FName> opts_entity_string();
	
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static void SetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, FOmegaEntity Entity, EOmegaGlobalParamTarget Target = SAVE_GAME);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static FOmegaEntity GetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, EOmegaGlobalParamTarget Target = SAVE_GAME);
	
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Data Asset > Entity ID")
	static FOmegaEntityID Conv_DataAsset_2_EntityID(UPrimaryDataAsset* Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Name > Entity ID")
	static FOmegaEntityID Conv_Name_2_EntityID(FName Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="GUID > Entity ID")
	static FOmegaEntityID Conv_GUID_2_EntityID(FGuid Key);
	
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="GUID > Entity ID")
	static TArray<FOmegaEntityID> GetAllEntityIDs_FromDataAssetClass(TSubclassOf<UPrimaryDataAsset> Class);
	
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Entity ID > Data Asset")
	static UPrimaryDataAsset* Conv_EntityID_2_DataAsset(FOmegaEntityID Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Entity ID >  Name")
	static FName Conv_EntityID_2_Name(FOmegaEntityID Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Entity ID >  GUID")
	static FGuid Conv_EntityID_2_GUID(FOmegaEntityID Key);
	
	UFUNCTION(BlueprintPure,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Get Transform")
	static FTransform GetTransform(UObject* WorldContextObject, FOmegaEntityID ID, EOmegaGlobalParamTarget Target = SAVE_GAME);
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Set Transform")
	static void SetTransform(UObject* WorldContextObject, FOmegaEntityID ID, FTransform Value, EOmegaGlobalParamTarget Target = SAVE_GAME);
	
	UFUNCTION(BlueprintPure,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Get Param (Int)")
	static int32 GetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, UPARAM(meta=(GetOptions="opts_entity_int32")) FName param, EOmegaGlobalParamTarget Target = SAVE_GAME);
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Set Param (Int)")
	static void SetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, UPARAM(meta=(GetOptions="opts_entity_int32")) FName param, int32 Value, bool bAdded, EOmegaGlobalParamTarget Target = SAVE_GAME);
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Add Param (Int)")
	static void AddSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, UPARAM(meta=(GetOptions="opts_entity_int32")) FName param, int32 Value, EOmegaGlobalParamTarget Target = SAVE_GAME);

	UFUNCTION(BlueprintPure,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Get Param (String)")
	static FString GetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, UPARAM(meta=(GetOptions="opts_entity_string")) FName param, EOmegaGlobalParamTarget Target = SAVE_GAME);
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Set Param (String)")
	static void SetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, UPARAM(meta=(GetOptions="opts_entity_string")) FName param, FString Value, EOmegaGlobalParamTarget Target = SAVE_GAME);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Set Tags")
	static void SetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID, FGameplayTagContainer tags, bool bActive, EOmegaGlobalParamTarget Target = SAVE_GAME);
	UFUNCTION(BlueprintPure,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Get Tags")
	static FGameplayTagContainer GetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID, EOmegaGlobalParamTarget Target = SAVE_GAME);
	UFUNCTION(BlueprintPure,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target"),DisplayName="👤Entity - Has Tag?")
	static bool SaveEntity_HasTags(UObject* WorldContextObject, FOmegaEntityID ID, FGameplayTagContainer tag, EOmegaGlobalParamTarget Target = SAVE_GAME);

	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="Target",ExpandBoolAsExecs="Result"),DisplayName="👤Entity - Check Tag")
	static bool SaveEntity_CheckTag(UObject* WorldContextObject, FOmegaEntityID ID, FGameplayTagContainer tag, EOmegaGlobalParamTarget Target, bool& Result, bool AddIfFalse=false);
};
