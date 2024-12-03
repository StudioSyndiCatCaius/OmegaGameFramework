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

