// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JsonObjectWrapper.h"
#include "Dom/JsonObject.h"
#include "Misc/OmegaUtils_Enums.h"
#include "StructUtils/InstancedStruct.h"
#include "OmegaUtils_Structs.generated.h"

class UOmegaLevelingAsset;
class UActorModifierScript;
class UOmegaCondition_Actor;
class UStateTree;
class AOmegaAbility;
class UEquipmentSlot;
class UOmegaAttribute;
class UAnimMontage;
class UAnimSequence;
class ULevelSequence;

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaSoftParams
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, int32> params_int;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, FVector> params_vectors;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, FVector> params_string;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaParsedParams
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data") TMap<FName, FString> params;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaParsedTable
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Table") TMap<FName,FOmegaParsedParams> params;
};

USTRUCT()
struct FOmegaGlobalVarsContainer
{
	GENERATED_BODY()
	UPROPERTY() FJsonObjectWrapper main_vars;
	UPROPERTY() TMap<FGuid, FJsonObjectWrapper> vars_guid;
	UPROPERTY() TMap<FGameplayTag, FJsonObjectWrapper> vars_tag;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaCommonMeta
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") UObject* Context=nullptr;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") TArray<FName> Flags;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") TMap<FName,FString> soft_params;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") FInstancedStruct InstancedStruct;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") TMap<FName,FInstancedStruct> NamedInstStructs;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaActorMeta
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") TMap<FGameplayTag,AActor*> TaggedTargets;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") FGameplayTagContainer Tags;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Meta") TMap<FName,FString> boundParam;
};




USTRUCT(Blueprintable,BlueprintType)
struct FOmegaCustomObjectData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") FText Name;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") FSlateBrush Icon;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") FText Description;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FName,FVector> Params_num;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FName,FString> Params_string;
};


USTRUCT(Blueprintable,BlueprintType)
struct FOmegaQuestData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Quest") TEnumAsByte<EOmegaQuestStatus> Status=Unstarted;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Quest") int32 state=0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Quest") TMap<FGameplayTag,int32> params_int;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Quest") FGameplayTagContainer Tags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Quest") TArray<FGuid> active_guids;
};
// ==============================================================================================================
// Configs
// ==============================================================================================================

USTRUCT(Blueprintable,BlueprintType)
struct FOmega_CameraConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera") bool invertX=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera") bool invertY=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera") float scale=1.0;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaBoolVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Bool Vector") bool X=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Bool Vector") bool Y=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Bool Vector") bool Z=true;
};


// ==============================================================================================================
// Lists
// ==============================================================================================================

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_Actors
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<AActor*> List;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_DataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<UPrimaryDataAsset*> List;
};


USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_Guids
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<FGuid> List;
};


USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_Int
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<int32> List;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_Names
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<FName> List;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_Montages
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<UAnimMontage*> List;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_AnimSequences
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<UAnimSequence*> List;
	
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaList_LevelSequences
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TArray<ULevelSequence*> List;
	
};


// ==============================================================================================================
// Lists
// ==============================================================================================================

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaMap_AssetInt
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TMap<UPrimaryDataAsset*,int32> map;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaMap_AssetTags
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="List") TMap<UPrimaryDataAsset*,FGameplayTagContainer> map;
};


// ==============================================================================================================
// Entity
// ==============================================================================================================

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaEntityDataset
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data")
	TArray<UPrimaryDataAsset*> AssetList;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data")
	TMap<UPrimaryDataAsset*,UPrimaryDataAsset*> assets_linked;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data")
	TMap<UPrimaryDataAsset*,int32> params_asset;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data")
	TMap<FName,int32> params_named;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaEntityID
{
	GENERATED_BODY()
	/*
	 * 0 = Data Asset
	 * 1 = Name
	 * 3 = GUID
	 **/
    UPROPERTY() uint8 entity_type;
    UPROPERTY() FString entity_string;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaEntity
{
	GENERATED_BODY()
	UPROPERTY() TMap<int8,int8> internal_flags;
	UPROPERTY() FTransform Transform;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars",meta=(Bitmask)) int32 BitFlags;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") FGameplayTagContainer Tags;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TArray<FName> Tags_Named;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") FJsonObjectWrapper JsonData;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data") TMap<UOmegaAttribute*,float> Attributes;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data") TMap<UEquipmentSlot*, UPrimaryDataAsset*> Equipment;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data") TMap<UPrimaryDataAsset*,int32> Inventory;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data") TMap<UOmegaLevelingAsset*,float> xp;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FName,int32> params_int32;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FName,float> params_float;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FName,FString> params_string;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FName,FOmegaList_DataAsset> AssetList_Named;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FName,FOmegaEntityDataset> datasets_named;

	
	int8 Flag_Get(int8 flag) { return internal_flags.FindOrAdd(flag); }
	void Flag_Set(int8 flag,int8 val) { internal_flags.Add(flag,val); }
	
	bool HasTags(FGameplayTagContainer InTags, bool bExact) const
	{
		if(bExact)
		{
			return Tags.HasAllExact(InTags);
		}
		return Tags.HasAnyExact(InTags);
	}

	FOmegaEntityDataset Dataset_Get(FName Set)
	{
		if(Set.IsValid()) { return datasets_named.FindOrAdd(Set);} return  FOmegaEntityDataset();
	}
	void Dataset_Set(FName Set, const FOmegaEntityDataset& dataset)
	{
		if(Set.IsValid()) { datasets_named.Add(Set,dataset);} 
	}
};


USTRUCT(Blueprintable,BlueprintType)
struct FOmegaEntitySet
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data",DisplayName="Entities (DataAsset)")
	TMap<UPrimaryDataAsset*,FOmegaEntity> Entities_Asset;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data",DisplayName="Entities (Guid)")
	TMap<FGuid,FOmegaEntity> Entities_Guid;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data",DisplayName="Entities (Named)")
	TMap<FName,FOmegaEntity> Entities_Named;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Data",DisplayName="Entities (Tagged)")
	TMap<FGameplayTag,FOmegaEntity> Entities_Tagged;

	//Asset
	bool Asset_HasTags(UPrimaryDataAsset* A, FGameplayTagContainer Tags, bool bExact)
	{
		return Entities_Asset.FindOrAdd(A).HasTags(Tags,bExact);
	}
	TArray<UPrimaryDataAsset*> Asset_GetWithTags(const FGameplayTagContainer& Tags, bool bExact)
	{
		TArray<UPrimaryDataAsset*> out;
		TArray<UPrimaryDataAsset*> k;
		Entities_Asset.GetKeys(k);
		for(auto* i : k)
		{
			if(Asset_HasTags(i,Tags,bExact)) { out.Add(i);}
		}
		return out;
	}
	void Asset_SetTags(UPrimaryDataAsset* A, FGameplayTagContainer Tags, bool bActive)
	{
		if(A)
		{
			if(bActive)
			{
				Entities_Asset.FindOrAdd(A).Tags.AppendTags(Tags);
			}
			else
			{
				Entities_Asset.FindOrAdd(A).Tags.RemoveTags(Tags);
			}
		}
	}

	//Guid
	bool Guid_HasTags(FGuid A, const FGameplayTagContainer& Tags, bool bExact)
	{
		return Entities_Guid.FindOrAdd(A).HasTags(Tags,bExact);
	}
	TArray<FGuid> Guid_GetWithTags(const FGameplayTagContainer& Tags, bool bExact)
	{
		TArray<FGuid> out;
		TArray<FGuid> k;
		Entities_Guid.GetKeys(k);
		for(auto i : k)
		{
			if(Guid_HasTags(i,Tags,bExact)) { out.Add(i);}
		}
		return out;
	}
	void Guid_SetTags(FGuid A, FGameplayTagContainer Tags, bool bActive)
	{
		if(bActive)
		{
			Entities_Guid.FindOrAdd(A).Tags.AppendTags(Tags);
		}
		else
		{
			Entities_Guid.FindOrAdd(A).Tags.RemoveTags(Tags);
		}
	}
};


USTRUCT(Blueprintable,BlueprintType)
struct FOmegaCharacterConfigInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character")
	TArray<TSoftClassPtr<AOmegaAbility>> Abilities;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character")
	TSoftObjectPtr<UStateTree> StateTree;
};

