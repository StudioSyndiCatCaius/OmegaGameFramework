// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaSettings_Localization.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Localization : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Localization")
	UOAsset_Localization* DefaultLocalization;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Localization")
	TArray<UOAsset_Localization*> LocalizationList;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOAsset_Localization : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Localization",meta=(MultiLine))
	FString VoiceClipsPath;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLocalizationFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Settings", DisplayName="Get OMEGA Settings (Localization)")
	static UOmegaSettings_Localization* GetCurrentSettings_Localization();
};