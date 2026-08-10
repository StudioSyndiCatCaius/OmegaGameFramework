
#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"

#include "Struct_DamageMeta.generated.h"


USTRUCT(BlueprintType)
struct FOmegaAttributeDamageMeta
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage") UObject* Context=nullptr;
	//Skips over all damage modification, just applying direct damage. Faster than normal damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage") bool ForceNoMod;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage") FHitResult Hit;
};

