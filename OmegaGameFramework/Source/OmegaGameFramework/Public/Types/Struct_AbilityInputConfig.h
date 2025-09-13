
#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Struct_AbilityInputConfig.generated.h"


class AOmegaAbility;

USTRUCT(BlueprintType)
struct FOmegaAbilityInputConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Ability") TSubclassOf<AOmegaAbility> Ability;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Ability") bool CancelOnRelease;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Ability") TArray<FKey> TriggerKeys;
};