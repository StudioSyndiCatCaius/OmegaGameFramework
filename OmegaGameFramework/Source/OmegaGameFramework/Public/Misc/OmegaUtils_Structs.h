// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JsonObjectWrapper.h"
#include "Dom/JsonObject.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaUtils_Structs.generated.h"

USTRUCT()
struct FOmegaGlobalVarsContainer
{
	GENERATED_BODY()
	UPROPERTY() FJsonObjectWrapper main_vars;
	UPROPERTY() TMap<FGuid, FJsonObjectWrapper> vars_guid;
	UPROPERTY() TMap<FGameplayTag, FJsonObjectWrapper> vars_tag;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaSaveVars
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") TMap<FGameplayTag,int32> params_int32;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") FGameplayTagContainer Tags;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Vars") FJsonObjectWrapper JsonData;
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

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Quest") TEnumAsByte<EOmegaQuestStatus> Status;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Quest") int32 state;
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

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	bool invertX;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	bool invertY;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	float scale=1.0;
};

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaBoolVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Bool Vector")
	bool X=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Bool Vector")
	bool Y=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Bool Vector")
	bool Z=true;
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