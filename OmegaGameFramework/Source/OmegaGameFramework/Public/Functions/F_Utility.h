// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Slate/WidgetTransform.h"
#include "Math/Vector2D.h"
#include "Misc/OmegaUtils_Enums.h"
#include "GameplayTagContainer.h"
#include "F_Utility.generated.h"

UCLASS()
class UOmegaUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintPure, Category="Omega|Load", meta=(Keywords="if, is",WorldContext="WorldContextObject"))
	static bool AreStreamedLevelsLoading(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static bool IsGameAsyncLoading(int32& PackagesLeft);
	
	//###############################################################################
	// Shader
	//###############################################################################
	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static bool AreShadersCompiling();

	UFUNCTION(BlueprintPure, Category="Omega|Utilities|Shader", meta=(Keywords="if, is"))
	static int32 GetShaderCompilationRemaining();

	//###############################################################################
	// Text
	//###############################################################################
	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Text")
	static void SetTextLocalized(FText& TextToLocalize);

	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Text")
	static TArray<FString> GetBlueprintCallableAndPureFunctions(UObject* Object);

	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Graphics")
	static void ApplyGraphicsSettingsFromUserSettings();

	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Console")
	static void SetConsoleVariableBool(FString VariableName, bool bValue);
	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Console")
	static void SetConsoleVariableFloat(FString VariableName, float Value);
	UFUNCTION(BlueprintCallable, Category="Omega|Utilities|Console")
	static void SetConsoleVariableInt(FString VariableName, int32 Value);

	// INCOMPLETE: these functions still need to be made
	UFUNCTION()
	static bool IsLoading_Foliage()
	{
		return false;
	}

	UFUNCTION()
	static bool IsLoading_Textures()
	{
		return false;
	}

	UFUNCTION(BlueprintPure, Category = "Omega|Utilities|Build", Meta = (DisplayName = "Is Shipping Build", Keywords = "compile export mode version type build platform"))
	static bool IsBuild_Shipping();
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Utilities|Viewport", Meta = (DisplayName = "Get Window Mode", Keywords = "screen fullscreen windowed"))
	static void GetWindowMode(bool& Success, bool& Fullscreen, bool& IsFullscreenWindowed);

	UFUNCTION(BlueprintCallable, Category = "LOmega|Utilities|Viewport", Meta = (DisplayName = "Set Window Mode", Keywords = "screen fullscreen windowed"))
	static void SetWindowMode(const bool Fullscreen, const bool IsFullscreenWindowed);

	UFUNCTION(BlueprintCallable,Category="Omega|Utilities")
	static TArray<UObject*> SortObjectsByDisplayName(TArray<UObject*> Objects);

	UFUNCTION(BlueprintPure,Category="Omega|Utilities")
	static bool IsObjectNameFirst(UObject* A, UObject* B);

	UFUNCTION(BlueprintPure, Category = "Bitmask", meta = (GameplayTagFilter = "BITFLAG"))
	static uint8 GetBitmaskFlag_FromTag(FGameplayTag Flag);

	UFUNCTION(BlueprintPure,Category="Omega|Utilities")
	static TArray<FString> GetCommandLineArgs();
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaStringFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//Check if StringA comes before StringB alphabetically
	UFUNCTION(BlueprintPure,Category="Omega|String")
	static bool IsStringFirst(const FString& A, const FString& B);
	

	UFUNCTION(BlueprintPure,Category="Omega|String")
	static TMap<FName,FString> ParseStringIntroParams(const FString& string, const FString& param_delimiter=" ",const FString& value_delimiter="=");
};



class USoundClass;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAudioFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable,Category="Omega|Audio")
	static void SetSoundWaveVolume(USoundWave* SoundWave, float NewVolume) { if(SoundWave) { SoundWave->Volume=NewVolume;  }}

	/**
	* Sets the volume of a Sound Class.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Set Volume"))
	static void SoundClass_SetVolume(USoundClass* SoundClass, const double Volume);

	/**
	* Returns the volume of a Sound Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Get Volume"))
	static double SoundClass_GetVolume(USoundClass* SoundClass);

	/**
	* Sets the pitch of a Sound Class.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Set Pitch"))
	static void SoundClass_SetPitch(USoundClass* SoundClass, const double Pitch);

	/**
	* Returns the pitch of a Sound Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Get Pitch"))
	static double SoundClass_GetPitch(USoundClass* SoundClass);
};
