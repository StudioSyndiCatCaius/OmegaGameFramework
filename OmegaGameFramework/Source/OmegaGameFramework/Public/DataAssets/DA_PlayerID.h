// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Misc/GeneralDataObject.h"
#include "DA_PlayerID.generated.h"

UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_PlayerID : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Player") int32 DefaultIndex=-1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Player") FLinearColor PlayerColor;
	virtual void GetGeneralAssetColor_Implementation(FGameplayTag Tag,FLinearColor& Color) override { Color = PlayerColor; };
};
