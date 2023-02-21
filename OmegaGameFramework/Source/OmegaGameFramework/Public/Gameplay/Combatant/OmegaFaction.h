// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Gameplay/CombatantComponent.h"

#include "OmegaFaction.generated.h"

UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaFaction : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	FText Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	FSlateBrush FactionIcon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	FLinearColor FactionColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tag")
	FGameplayTag FactionTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tag")
	TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> FactionAffinities;
	
	
};
