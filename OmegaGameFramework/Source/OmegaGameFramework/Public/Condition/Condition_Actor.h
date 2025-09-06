// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Condition_Actor.generated.h"


UCLASS(Blueprintable,BlueprintType,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaCondition_Actor : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Actor Condition")
	bool CheckActorCondition(AActor* Actor) const;
	
};

USTRUCT(BlueprintType)
struct FOmegaConditions_Actor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Conditions")
	TArray<UOmegaCondition_Actor*> Conditions;

	bool CheckConditions(AActor* actor)
	{
		if(actor)
		{
			for(auto* a : Conditions)
			{
				if(a && !a->CheckActorCondition(actor)) { return false;  }
			}
		}
		return true;
	}
};
