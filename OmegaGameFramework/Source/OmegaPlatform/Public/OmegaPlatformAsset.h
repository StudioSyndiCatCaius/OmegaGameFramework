// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "OmegaPlatformAsset.generated.h"

USTRUCT(BlueprintType)
struct FPlatformKeyInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slate Brush")
	FSlateBrush KeyIcon;
};

UCLASS(BlueprintType, Blueprintable)
class OMEGAPLATFORM_API UOmegaPlatformAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Key")
	TMap<FKey,FPlatformKeyInfo> KeyInfo;
};
