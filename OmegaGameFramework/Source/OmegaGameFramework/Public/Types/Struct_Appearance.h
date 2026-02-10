
#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Struct_Appearance.generated.h"

class UOmegaBodyType;

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaBodyAppearanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaBodyType* BodyType=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	TMap<FName, FName> params_name;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	TMap<FName, float> params_float;
};


USTRUCT(Blueprintable,BlueprintType)
struct FOmegaBodyAppearanceInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	UOmegaBodyType* BodyType=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Body")
	TMap<FName, FVector> Params;
};
