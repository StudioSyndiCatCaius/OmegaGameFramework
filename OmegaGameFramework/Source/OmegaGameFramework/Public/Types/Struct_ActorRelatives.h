// Struct_ActorRelatives.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Struct_ActorRelatives.generated.h"

USTRUCT(BlueprintType)
struct FOmegaActorRelatives
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorRelatives")
	TMap<FName, TSoftObjectPtr<AActor>> RelativeActors;
	
};

UINTERFACE(MinimalAPI) class UActorInterface_Relatives : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_Relatives
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ActorRelatives") FOmegaActorRelatives ActorRelatives_Get();
};