// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Slate/WidgetTransform.h"
#include "Math/Vector2D.h"
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
};

UCLASS()
class UOmegaAssetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure,Category="Omega|Asset")
	UClass* GetBlueprintClassFromPath(const FString Path);
	
};


UCLASS()
class UOmegaAudioFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable,Category="Omega|Audio")
	static void SetSoundWaveVolume(USoundWave* SoundWave, float NewVolume) { if(SoundWave) { SoundWave->Volume=NewVolume;  }}
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
	
};

