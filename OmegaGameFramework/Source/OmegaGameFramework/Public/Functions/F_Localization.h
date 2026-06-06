// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"


#include "F_Localization.generated.h"

UINTERFACE(MinimalAPI)
class UDataInterface_VoiceSource : public UInterface
{
	GENERATED_BODY()
public:
	static bool Uses(UObject* object);
};
class OMEGAGAMEFRAMEWORK_API IDataInterface_VoiceSource
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Localization",DisplayName="Voice - Get ID")
	FString VoiceSource_GetID();
};




UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLocalizationFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static TArray<FString> GetAllVoiceLineDirectories();
	
	UFUNCTION(BlueprintPure,Category="Omega|Localization",DisplayName="友Localization - Get Voice Language")
	static FString GetLang_Voice();
	
	UFUNCTION(BlueprintCallable,Category="Omega|Localization",DisplayName="友Localization - Set Voice Language")
	static void SetLang_Voice(const FString& language);
	
	/**
	 * Will attempt to play a voice cue gotten from " Get Voice Clip (Cue)".
	 * ID check order:
	 *		1. ID from the actors Sound Library asset (if applicable).
	 *		2. If no sound Library Asset, get it from the actor's `Object Label`
	 *	@param bTryUseInstigatorSoundLibrary Will try to get the ID string from the object's SoundLibrary from it's AppearanceAsset or `UDataInterface_AssetLibraries`. Defaults to Label if none 
	 */
	UFUNCTION(BlueprintCallable,Category="Omega|Localization",DisplayName="友Localization - Play Voice Cue",meta=(AdvancedDisplay="RandomRange, bTryUseInstigatorSoundLibrary"))
	static void PlayVoiceClip(AActor* Instigator, FString VoiceClip, int32 RandomRange=5, bool bTryUseInstigatorSoundLibrary=true);

	static USoundBase* GetVoiceSoundByPath(UObject* WorldContext,FString subpath, FString file, bool Internal=true,bool External=true);

	UFUNCTION(BlueprintCallable,Category="Omega|Localization",DisplayName="友Localization - Get Voice Clip (Line)",meta=(WorldContext="WorldContext"))
	static USoundBase* GetVoice_Line(UObject* WorldContext,FName Line);
	
	/**
	 * Will attempt to get a voice cue.
	 * Load order: 
	 *		1. Check if an external path voice file exists, and loads it in.
	 *		2. If no external voice file, tries to load Base Sound from LOCALE and ID path
	 */
	UFUNCTION(BlueprintCallable,Category="Omega|Localization",DisplayName="友Localization - Get Voice Clip (Cue)",meta=(WorldContext="WorldContext",AdvancedDisplay="RandomRange"))
	static USoundBase* GetVoice_Cue(UObject* WorldContext,FName ID, const FString& VoiceClip, int32 RandomRange=5);

};
