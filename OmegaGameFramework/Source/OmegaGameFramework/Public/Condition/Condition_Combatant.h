// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Condition_Combatant.generated.h"


class UCombatantComponent;

UCLASS(Blueprintable,BlueprintType,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaCondition_Combatant : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Actor Condition")
	bool CheckCombatantCondition(UCombatantComponent* Combatant) const;
	
};

USTRUCT(BlueprintType)
struct FOmegaConditions_Combatant
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Conditions")
	TArray<UOmegaCondition_Combatant*> Conditions;

	bool CheckConditions(UCombatantComponent* c)
	{
		if(c)
		{
			for(auto* a : Conditions)
			{
				if(a && !a->CheckCombatantCondition(c)) { return false;  }
			}
		}
		return true;
	}
};
