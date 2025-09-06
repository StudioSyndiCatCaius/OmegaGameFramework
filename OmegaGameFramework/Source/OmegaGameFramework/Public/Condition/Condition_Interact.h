// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Condition_Actor.h"
#include "Condition_Interact.generated.h"


UCLASS(Blueprintable,BlueprintType,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaCondition_Interact : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent,Category="Condition")
	bool CheckCondition(AActor* Instigator,AActor* Target,FGameplayTag InteractTag,FOmegaCommonMeta meta) const;
	
};

inline bool UOmegaCondition_Interact::CheckCondition_Implementation(AActor* Instigator, AActor* Target,
	FGameplayTag InteractTag, FOmegaCommonMeta meta) const
{
	return true;
}

USTRUCT(BlueprintType)
struct FOmegaConditions_Interact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Conditions")
	TArray<UOmegaCondition_Interact*> Conditions;

	bool CheckConditions(AActor* Instigator,AActor* Target,FGameplayTag InteractTag,FOmegaCommonMeta meta)
	{
		if(Instigator && Target)
		{
			for(auto* a : Conditions)
			{
				if(a && !a->CheckCondition(Instigator,Target,InteractTag,meta)) { return false;  }
			}
		}
		return true;
	}
};


/// TYPES
///
///
UCLASS(DisplayName="(Can Interact) Actor Conditions")
class OMEGAGAMEFRAMEWORK_API UOmegaCondition_Interact_ActorCheck : public UOmegaCondition_Interact
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,Instanced,Category="Condition")
	TArray<UOmegaCondition_Actor*> Conditions_Instigator;
	UPROPERTY(EditAnywhere,Instanced,Category="Condition")
	TArray<UOmegaCondition_Actor*> Conditions_Target;
	
	virtual bool CheckCondition_Implementation(AActor* Instigator, AActor* Target, FGameplayTag InteractTag, FOmegaCommonMeta meta) const override;
	
};

inline bool UOmegaCondition_Interact_ActorCheck::CheckCondition_Implementation(AActor* Instigator, AActor* Target,
	FGameplayTag InteractTag, FOmegaCommonMeta meta) const
{
	FOmegaConditions_Actor con_i;
	con_i.Conditions=Conditions_Instigator;
	if(!con_i.CheckConditions(Instigator)) { return false; }
	FOmegaConditions_Actor con_t;
	con_t.Conditions=Conditions_Instigator;
	if(!con_t.CheckConditions(Target)) { return false; }
	return true;
}
