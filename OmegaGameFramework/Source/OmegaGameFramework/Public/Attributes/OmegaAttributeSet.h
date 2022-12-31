// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "OmegaAttributeSet.generated.h"


class UOmegaAttribute;

UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaAttributeSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	TArray<class UOmegaAttribute*> Attributes;

	UPROPERTY()
	FGameplayTag ValueCategory;

	UFUNCTION(BlueprintPure, Category="Attributes")
	TArray<UOmegaAttribute*> GetMetricAttributes();
	UFUNCTION(BlueprintPure, Category="Attributes")
	TArray<UOmegaAttribute*> GetStaticAttributes();
	
	UFUNCTION()
	TArray<UOmegaAttribute*> Local_GetAtt(bool bStatic);
};
