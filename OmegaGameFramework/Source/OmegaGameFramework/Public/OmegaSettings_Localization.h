// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "OmegaSettings_Localization.generated.h"



UCLASS(Abstract,Const,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaLocalizedVoice_Script : public UOmegaInstancableObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Omega|Localization")
	USoundBase* GetVoiceClipByKey(UOmegaSubsystem_Localization* Subsystem, FName key) const;
};

UCLASS(EditInlineNew,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaLocalizedVoice_Preset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Voice")
	TArray<UOmegaLocalizedVoice_Script*> Scripts;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Localization : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	TArray<UOmegaLocalizedVoice_Preset*> L_GetVoicePresets() const;
	TArray<UOmegaLocalizedVoice_Script*> L_GetVoiceScripts() const;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Localization")
	UOAsset_Localization* DefaultLocalization;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Localization")
	TArray<UOAsset_Localization*> LocalizationList;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Voice",meta=(MultiLine))
	FString Default_VoiceCue_Path="/Game/0_Main/Assets/audio/voice/";
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Voice")
	FString VoiceClip_Prefex="vo_{id}_";

	UPROPERTY(EditAnywhere,Category="Voice")
	TArray<UOmegaLocalizedVoice_Preset*> VoiceScript_Preset;
	UPROPERTY(EditAnywhere,Instanced,Category="Voice")
	UOmegaLocalizedVoice_Preset* VoiceScript_custom;
	
	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Localization",meta=(MultiLine))
	//FString Default_VoiceMessage_Path="/Game/0_Main/Assets/audio/vo_msg/";
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOAsset_Localization : public UOmegaDataAsset
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

	UFUNCTION(BlueprintCallable,Category="Omega|Localization")
	static void PlayVoiceClip(AActor* Instigator, FString VoiceClip);

	UFUNCTION(BlueprintCallable,Category="Omega|Localization")
	static USoundBase* GetVoiceClip_ByID(FName ID, FString VoiceClip);
	
	UFUNCTION(BlueprintPure,Category="Omega|Settings", DisplayName="Get OMEGA Settings (Localization)")
	static UOmegaSettings_Localization* GetCurrentSettings_Localization();
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_Localization : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Localization")
	USoundBase* GetVoiceClipByKey(FName key);
};