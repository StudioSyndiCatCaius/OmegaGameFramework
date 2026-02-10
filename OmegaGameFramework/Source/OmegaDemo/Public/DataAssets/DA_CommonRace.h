// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/DA_Appearance.h"
#include "DataAssets/DA_CombatSource.h"

#include "DA_CommonRace.generated.h"



UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonRace : public UOAsset_CombatSource
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Race", meta=(ExposeOnSpawn),DisplayName="Appearance (Default)")
	UOAsset_Appearance* Appearance_Default;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Race", meta=(ExposeOnSpawn),DisplayName="Appearance (Gender)")
	TMap<EOmegaGender,UOAsset_Appearance*> Appearance_Gender;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Race", meta=(ExposeOnSpawn),DisplayName="Appearance (Tagged)")
	TMap<FGameplayTag,UOAsset_Appearance*> Appearance_Tagged;
};
