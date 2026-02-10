// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Condition_DataAsset.generated.h"


UCLASS(Blueprintable,BlueprintType,Abstract,Const,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaCondition_DataAsset : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Actor Condition")
	bool CheckAssetCondition(UPrimaryDataAsset* Asset, FText& Reason) const;
	
};

USTRUCT(BlueprintType)
struct FOmegaConditions_DataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Conditions")
	TArray<UOmegaCondition_DataAsset*> Conditions;

	bool CheckConditions(UPrimaryDataAsset* asset,TArray<FText>& Reasons)
	{
		bool out=true;
		if(asset)
		{
			for(auto* a : Conditions)
			{
				FText r;
				if(a && !a->CheckAssetCondition(asset,r))
				{
					out=false;
					Reasons.Add(r);
				}
			}
		}
		return out;
	}
};
