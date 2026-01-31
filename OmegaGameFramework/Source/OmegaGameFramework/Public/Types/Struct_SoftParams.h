
#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameplayTagContainer.h"
#include "Struct_SoftParams.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaSoftParams
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, bool> params_bool;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, int32> params_int;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, float> params_float;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, FString> params_string;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FName, UPrimaryDataAsset*> params_DataAsset;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Params") TMap<FGameplayTag,int32> bitflags;
};
