// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JsonObjectWrapper.h"
#include "Dom/JsonObject.h"
#include "OmegaUtils_Structs.generated.h"

USTRUCT()
struct FOmegaGlobalVarsContainer
{
	GENERATED_BODY()
	UPROPERTY() FJsonObjectWrapper main_vars;
	UPROPERTY() TMap<FGuid, FJsonObjectWrapper> vars_guid;
	UPROPERTY() TMap<FGameplayTag, FJsonObjectWrapper> vars_tag;
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
