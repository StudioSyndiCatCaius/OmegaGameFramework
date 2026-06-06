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

	UFUNCTION(BlueprintNativeEvent,Category="Actor Condition")
	bool CheckCombatantCondition(UCombatantComponent* Combatant) const;
	
};

inline bool UOmegaCondition_Combatant::CheckCombatantCondition_Implementation(UCombatantComponent* Combatant) const
{
	return true;
}

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCondition_Combatant_Preset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Conditions") TArray<UOmegaCondition_Combatant*> Conditions;
};

USTRUCT(BlueprintType)
struct FOmegaConditions_Combatant
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Conditions",DisplayName="❓ Presets") TArray<UOmegaCondition_Combatant_Preset*> Presets;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Conditions",DisplayName="❓ Inline") TArray<UOmegaCondition_Combatant*> Conditions;

	bool CheckConditions(UCombatantComponent* c)
	{
		if(c)
		{
			TArray<UOmegaCondition_Combatant*> _conList=Conditions;
		
			for (auto* preset :Presets)
			{
				if (preset)
				{
					_conList.Append(preset->Conditions);
				}
			}
			for(auto* a : _conList)
			{
				if(a && !a->CheckCombatantCondition(c)) { return false;  }
			}
		}
		return true;
	}
};
