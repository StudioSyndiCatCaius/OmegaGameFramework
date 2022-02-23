// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "OmegaAttributeSet.generated.h"


class UOmegaAttribtute;

UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaAttributeSet : public UDataAsset
{
	GENERATED_BODY()

public:
		UPROPERTY(EditDefaultsOnly, Category = "Attributes")
		TArray<class UOmegaAttribute*> Attributes;

		UPROPERTY(EditDefaultsOnly, Category = "Tags")
		FGameplayTag ValueCategory;
	
};
