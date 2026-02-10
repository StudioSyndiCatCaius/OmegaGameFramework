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


UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Localization"))
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Localization : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	TArray<UOmegaLocalizedVoice_Preset*> L_GetVoicePresets() const;
	TArray<UOmegaLocalizedVoice_Script*> L_GetVoiceScripts() const;
	
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Localization")
	TSoftObjectPtr<UOAsset_Localization> DefaultLocalization;
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Localization")
	TArray<TSoftObjectPtr<UOAsset_Localization>> LocalizationList;
	
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Voice Clip")
	FString VoiceClip_Prefex="vo_{id}_";

	
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Voice",meta=(MultiLine))
	FString Internal_Voice_Path="/Game/0_Main/Assets/audio/voice/";

	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Voice",meta=(MultiLine))
	FString Subpath_Clip="/voice/{culture}/clip/";
	UPROPERTY(EditAnywhere,Config,BlueprintReadOnly,Category="Voice",meta=(MultiLine))
	FString Subpath_Line="/voice/{culture}/line/";
	

	//sound classes to search for a voice clip or line
	UPROPERTY(EditAnywhere,Config,Category="Voice")
	TArray<TSoftClassPtr<USoundBase>> VoiceSoundClasses;
	
	UPROPERTY(EditAnywhere,Config,Category="Voice")
	TArray<TSoftObjectPtr<UOmegaLocalizedVoice_Preset>> VoiceScript_Preset;

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
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_Localization : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Localization")
	USoundBase* GetVoiceClipByKey(FName key);
};