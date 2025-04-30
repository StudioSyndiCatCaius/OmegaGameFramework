// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Misc/GeneralDataObject.h"
#include "DA_TransformPreset.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_TransformPreset : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Transform")
	FTransform Transform;

	UFUNCTION(BlueprintCallable,Category="Omega|TransformPreset")
	void ApplyToWidget(UUserWidget* Widget);

	UFUNCTION(BlueprintCallable,Category="Omega|TransformPreset")
	void ApplyToActor(AActor* Actor);
};
