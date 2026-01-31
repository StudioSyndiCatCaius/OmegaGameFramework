// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"


#include "F_Localization.generated.h"




UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLocalizationFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static TArray<FString> GetVoiceLineDirectories(FString subpath, FString file);
	
	static USoundBase* GetVoiceSoundByPath(FString subpath, FString file);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Localization",DisplayName="Localization - Play Voice Clip")
	static void PlayVoiceClip(AActor* Instigator, FString VoiceClip);

	UFUNCTION(BlueprintCallable,Category="Omega|Localization",DisplayName="Localization - Get Voice Line")
	static USoundBase* VoiceLine_Get(FName Line);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Localization",DisplayName="Localization - Get Voice Clip")
	static USoundBase* GetVoiceClip_ByID(FName ID, FString VoiceClip);

};
