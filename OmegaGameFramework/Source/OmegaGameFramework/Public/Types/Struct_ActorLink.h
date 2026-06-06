
#pragma once

#include "CoreMinimal.h"
#include "Struct_ActorLink.generated.h"


USTRUCT(BlueprintType)
struct FOmegaActorLink
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) AActor* A;
	UPROPERTY(BlueprintReadWrite, Category="Message", EditAnywhere) AActor* B;
	
	bool Has(const AActor* actor) const;
};

inline bool FOmegaActorLink::Has(const AActor* actor) const
{
	if (actor && (A==actor || B==actor))
	{
		return true;
	}
	return false;
}


