// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Slate/WidgetTransform.h"
#include "Math/Vector2D.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaFunctions_Utility.generated.h"

UCLASS()
class UOmegaUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
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

	
};

UCLASS()
class UOmegaAssetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure,Category="Omega|Asset")
	UClass* GetBlueprintClassFromPath(const FString Path);
	
};

class USoundClass;

UCLASS()
class UOmegaAudioFunctions : public UBlueprintFunctionLibrary
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

UCLASS()
class UOmegaMathFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Widget")
	static FWidgetTransform LerpWidgetTransform(FWidgetTransform a, FWidgetTransform b, float alpha);

	UFUNCTION(BlueprintPure,Category="Omega|Widget")
	static FVector2D LerpVector2D(FVector2D a, FVector2D b, float alpha);

	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static float GetAngle_FromVectors(FVector A, FVector B);

	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static float GetAngle_FromRotators(FRotator A, FRotator B);

	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static FRotator Conv_VectorToRot_Flat(FVector Vector);

	UFUNCTION(BlueprintPure,Category="Omega|Math", DisplayName="Normalize to Range (Int32)")
	static float NormalizeToRange_int32(int32 value, int32 min, int32 max);

	// Seed Randomization
	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static int32 GetSeedFromGuid(FGuid Guid);

	UFUNCTION(BlueprintPure,Category="Omega|Math|Curve")
	static float GetCurve_Value(FFloatCurve Curve, float time)
	{
		return  Curve.Evaluate(time);
	}

	UFUNCTION(BlueprintCallable,Category="Omega|Math",meta=(ExpandEnumAsExecs="Outcome"))
	static bool RNG_RollFromFloat(float chance, TEnumAsByte<EOmegaFunctionResult>& Outcome);


	UFUNCTION(BlueprintPure,Category="Omega|Math")
	static float Variate_Float(float in, float amount, bool bAmountIsScale);
};