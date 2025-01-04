// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Utility.h"
#include "ShaderCompiler.h"
#include "Internationalization/Internationalization.h"
#include "CoreGlobals.h"
#include "GameFramework/GameUserSettings.h"
#include "HAL/IConsoleManager.h"
#include "Sound/SoundClass.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/Class.h"
#include "UObject/UnrealType.h"

bool UOmegaUtilityFunctions::AreShadersCompiling()
{
	// Create an instance of FShaderCompilingManager
	return GShaderCompilingManager->IsCompiling();
}

int32 UOmegaUtilityFunctions::GetShaderCompilationRemaining()
{
	// Get the number of remaining shader jobs
	return GShaderCompilingManager->GetNumRemainingJobs();

}

void UOmegaUtilityFunctions::SetTextLocalized(FText& TextToLocalize)
{

}

bool UOmegaUtilityFunctions::IsBuild_Shipping()
{
	/*
#if UE_BUILD_SHIPPING
	return true;
#else
	return false;
#endif
*/
	return false;
}

void UOmegaUtilityFunctions::GetWindowMode(bool& Success, bool& Fullscreen, bool& IsFullscreenWindowed)
{
	/*
	Success = false;
	Fullscreen = false;
	IsFullscreenWindowed = false;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	EWindowMode::Type Mode = Window->GetWindowMode();

	if (Mode == EWindowMode::Type::Fullscreen)
	{
		Success = true;
		Fullscreen = true;
	}
	else if (Mode == EWindowMode::Type::WindowedFullscreen)
	{
		Success = true;
		Fullscreen = true;
		IsFullscreenWindowed = true;
	}
	else if (Mode == EWindowMode::Type::Windowed)
	{
		Success = true;
	}
	*/
}

void UOmegaUtilityFunctions::SetWindowMode(const bool Fullscreen, const bool IsFullscreenWindowed)
{
	/*
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	if (Fullscreen)
	{
		if (IsFullscreenWindowed)
		{
			Window->SetWindowMode(EWindowMode::Type::WindowedFullscreen);
		}
		else
		{
			Window->SetWindowMode(EWindowMode::Type::Fullscreen);
		}
	}
	else
	{
		Window->SetWindowMode(EWindowMode::Type::Windowed);
	}
	*/
}

/*
bool UOmegaUtilityFunctions::CompareFloatValues(float Value1, float Value2, EComparisonMethod ComparisonMethod)
{
	{
		switch (ComparisonMethod)
		{
		case EComparisonMethod::Equal_To:
			return FMath::IsNearlyEqual(Value1, Value2);
		case EComparisonMethod::Not_Equal_To:
			return !FMath::IsNearlyEqual(Value1, Value2);
		case EComparisonMethod::Less_Than:
			return Value1 < Value2;
		case EComparisonMethod::Less_Than_Or_Equal_To:
			return Value1 <= Value2;
		case EComparisonMethod::Greater_Than:
			return Value1 > Value2;
		case EComparisonMethod::Greater_Than_Or_Equal_To:
			return Value1 >= Value2;
		default:
			// Invalid comparison method
			return false;
		}
	}
}
*/
UClass* UOmegaAssetFunctions::GetBlueprintClassFromPath(const FString Path)
{
	FSoftClassPath LocalPath;
	LocalPath.SetSubPathString(Path);
	return LocalPath.ResolveClass();
}

// ================================================================================
// ================================================================================
// MATH
// ================================================================================
// ================================================================================


FWidgetTransform UOmegaMathFunctions::LerpWidgetTransform(FWidgetTransform a, FWidgetTransform b, float alpha)
{
	FWidgetTransform out;
	out.Angle=UKismetMathLibrary::Lerp(a.Angle,b.Angle,alpha);
	
	out.Scale=LerpVector2D(a.Scale,b.Scale,alpha);
	out.Shear=LerpVector2D(a.Shear,b.Shear,alpha);
	out.Translation=LerpVector2D(a.Translation,b.Translation,alpha);

	return out;
}

FVector2D UOmegaMathFunctions::LerpVector2D(FVector2D a, FVector2D b, float alpha)
{
	FVector2D out;
	out.X=UKismetMathLibrary::Lerp(a.X,b.X,alpha);
	out.Y=UKismetMathLibrary::Lerp(a.Y,b.Y,alpha);
	return out;
}

float UOmegaMathFunctions::GetAngle_FromVectors(FVector A, FVector B)
{
	return UKismetMathLibrary::DegAcos(UKismetMathLibrary::Dot_VectorVector(UKismetMathLibrary::Normal(A),UKismetMathLibrary::Normal(B)));
}

float UOmegaMathFunctions::GetAngle_FromRotators(FRotator A, FRotator B)
{
	return GetAngle_FromVectors(UKismetMathLibrary::Conv_RotatorToVector(A),UKismetMathLibrary::Conv_RotatorToVector(B));
}

float UOmegaMathFunctions::NormalizeToRange_int32(int32 value, int32 min, int32 max)
{
	return UKismetMathLibrary::NormalizeToRange(value,min,max);
}


TArray<FString> UOmegaUtilityFunctions::GetBlueprintCallableAndPureFunctions(UObject* Object)
{
	TArray<FString> FunctionNames;

	if (!Object)
	{
		UE_LOG(LogTemp, Warning, TEXT("Object is null"));
		return FunctionNames;
	}

	UClass* Class = Object->GetClass();

	// Iterate through all the functions of the class
	for (TFieldIterator<UFunction> FunctionIt(Class); FunctionIt; ++FunctionIt)
	{
		UFunction* Function = *FunctionIt;

		// Check if the function is BlueprintCallable or BlueprintPure
		if (Function->HasAnyFunctionFlags(FUNC_BlueprintCallable) || Function->HasAnyFunctionFlags(FUNC_BlueprintPure))
		{
			// Add the function's name to the array
			FunctionNames.Add(Function->GetName());
		}
	}

	return FunctionNames;
}

// ================================================================================
// ================================================================================
// CONSOLE VAR
// ================================================================================
// ================================================================================

void UOmegaUtilityFunctions::ApplyGraphicsSettingsFromUserSettings()
{
	
    // Get the current game user settings object
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (!UserSettings)
    {
        UE_LOG(LogTemp, Warning, TEXT("UserSettings is null!"));
        return;
    }

    // Get each graphics setting value from GameUserSettings
    int32 ResolutionQuality = UserSettings->GetResolutionScaleNormalized() * 100; // Convert from 0-1 to 0-100
    int32 ViewDistanceQuality = UserSettings->GetViewDistanceQuality();
    int32 AntiAliasingQuality = UserSettings->GetAntiAliasingQuality();
    int32 ShadowQuality = UserSettings->GetShadowQuality();
    int32 PostProcessQuality = UserSettings->GetPostProcessingQuality();
    int32 TextureQuality = UserSettings->GetTextureQuality();
    int32 EffectsQuality = UserSettings->GetVisualEffectQuality();
    int32 FoliageQuality = UserSettings->GetFoliageQuality();

	// Apply these settings using SetConsoleVariableInt
	SetConsoleVariableInt(TEXT("sg.ResolutionQuality"), ResolutionQuality);
	SetConsoleVariableInt(TEXT("sg.ViewDistanceQuality"), ViewDistanceQuality);
	SetConsoleVariableInt(TEXT("sg.AntiAliasingQuality"), AntiAliasingQuality);
	SetConsoleVariableInt(TEXT("sg.ShadowQuality"), ShadowQuality);
	SetConsoleVariableInt(TEXT("sg.PostProcessQuality"), PostProcessQuality);
	SetConsoleVariableInt(TEXT("sg.TextureQuality"), TextureQuality);
	SetConsoleVariableInt(TEXT("sg.EffectsQuality"), EffectsQuality);
	SetConsoleVariableInt(TEXT("sg.FoliageQuality"), FoliageQuality);

    // Log the settings for debugging purposes
    UE_LOG(LogTemp, Log, TEXT("Graphics settings applied from GameUserSettings: Res:%d ViewDist:%d AA:%d Shadow:%d PostProcess:%d Texture:%d Effects:%d Foliage:%d"),
           ResolutionQuality, ViewDistanceQuality, AntiAliasingQuality, ShadowQuality, PostProcessQuality, TextureQuality, EffectsQuality, FoliageQuality);

}

void UOmegaUtilityFunctions::SetConsoleVariableBool(FString VariableName, bool bValue)
{
	IConsoleVariable* ConsoleVariable = IConsoleManager::Get().FindConsoleVariable(*VariableName);
	if (ConsoleVariable)
	{
		ConsoleVariable->Set(bValue);
		UE_LOG(LogTemp, Log, TEXT("Set %s to %s"), *VariableName, bValue ? TEXT("true") : TEXT("false"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Console variable %s not found!"), *VariableName);
	}
}

void UOmegaUtilityFunctions::SetConsoleVariableFloat(FString VariableName, float Value)
{
	IConsoleVariable* ConsoleVariable = IConsoleManager::Get().FindConsoleVariable(*VariableName);
	if (ConsoleVariable)
	{
		ConsoleVariable->Set(Value);
		UE_LOG(LogTemp, Log, TEXT("Set %s to %f"), *VariableName, Value);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Console variable %s not found!"), *VariableName);
	}
}

void UOmegaUtilityFunctions::SetConsoleVariableInt(FString VariableName, int32 Value)
{
	IConsoleVariable* ConsoleVariable = IConsoleManager::Get().FindConsoleVariable(*VariableName);
	if (ConsoleVariable)
	{
		ConsoleVariable->Set(Value);
		UE_LOG(LogTemp, Log, TEXT("Set %s to %d"), *VariableName, Value);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Console variable %s not found!"), *VariableName);
	}
}

// ================================================================================
// ================================================================================
// AUDIO
// ================================================================================
// ================================================================================

void UOmegaAudioFunctions::SoundClass_SetVolume(USoundClass* SoundClass, const double Volume)
{
	if (SoundClass == nullptr)
	{
		return;
	}
	SoundClass->Properties.Volume = Volume;
}

double UOmegaAudioFunctions::SoundClass_GetVolume(USoundClass* SoundClass)
{
	if (SoundClass == nullptr)
	{
		return 0;
	}
	return SoundClass->Properties.Volume;
}

void UOmegaAudioFunctions::SoundClass_SetPitch(USoundClass* SoundClass, const double Pitch)
{
	if (SoundClass == nullptr)
	{
		return;
	}
	SoundClass->Properties.Pitch = Pitch;
}

double UOmegaAudioFunctions::SoundClass_GetPitch(USoundClass* SoundClass)
{
	if (SoundClass == nullptr)
	{
		return 0;
	}
	return SoundClass->Properties.Pitch;
}