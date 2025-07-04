// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Condition_DataAsset.generated.h"


UCLASS(Blueprintable,BlueprintType,Abstract,Const,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaCondition_DataAsset : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Actor Condition")
	bool CheckAssetCondition(UPrimaryDataAsset* Asset) const;
	
};

USTRUCT(BlueprintType)
struct FOmegaConditions_DataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Conditions")
	TArray<UOmegaCondition_DataAsset*> Conditions;

	bool CheckConditions(UPrimaryDataAsset* asset)
	{
		if(asset)
		{
			for(auto* a : Conditions)
			{
				if(a && !a->CheckAssetCondition(asset)) { return false;  }
			}
		}
		return true;
	}
};
