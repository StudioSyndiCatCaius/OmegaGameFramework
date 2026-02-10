// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Misc/OmegaUtils_Structs.h"
#include "OmegaSettings_Preferences.generated.h"


class UGamePreference;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Preferences : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Camera")
	UGamePreference* Pref_Camera_InvertX;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Camera")
	UGamePreference* Pref_Camera_InvertY;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Camera")
	UGamePreference* Pref_Camera_Sensitivity;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaPreferenceSettingsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Settings|Preferences")
	static UOmegaSettings_Preferences* GetSettings_Preferences();

	UFUNCTION(BlueprintCallable,Category="Omega|Settings|",meta=(WorldContext="WorldContextObject"))
	static FOmega_CameraConfig GetCameraConfig_FromPreferences(UObject* WorldContextObject);

};

