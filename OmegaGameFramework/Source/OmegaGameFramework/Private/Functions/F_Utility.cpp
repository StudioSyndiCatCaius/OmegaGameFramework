// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Utility.h"
#include "Internationalization/Internationalization.h"
#include "CoreGlobals.h"

#include "GameFramework/GameUserSettings.h"
#include "Engine/AssetManager.h"
#include "HAL/IConsoleManager.h"
#include "Sound/SoundClass.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"

#include "Misc/OmegaUtils_Methods.h"
#include "UObject/Class.h"
#include "UObject/UnrealType.h"

bool UOmegaUtilityFunctions::AreStreamedLevelsLoading(UObject* WorldContextObject)
{
	if(WorldContextObject)
	{
		return OGF_Load::LevelStream_IsLoading(WorldContextObject->GetWorld());
	}
	return true;
}

bool UOmegaUtilityFunctions::IsGameAsyncLoading(int32& PackagesLeft)
{
	PackagesLeft=GetNumAsyncPackages();
	return IsAsyncLoading();
}

bool UOmegaUtilityFunctions::AreShadersCompiling()
{
	return false;
}

int32 UOmegaUtilityFunctions::GetShaderCompilationRemaining()
{
	// Get the number of remaining shader jobs
	return 0;

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

TArray<UObject*> UOmegaUtilityFunctions::SortObjectsByDisplayName(TArray<UObject*> Objects)
{
	Objects.Sort([](const UObject& A, const UObject& B)
	{
		return IsObjectNameFirst(const_cast<UObject*>(&A), const_cast<UObject*>(&B));
	});
    
	return Objects;
}

bool UOmegaStringFunctions::IsStringFirst(const FString& A, const FString& B)
{
	return A.Compare(B, ESearchCase::IgnoreCase) < 0;
}

TMap<FName, FString> UOmegaStringFunctions::ParseStringIntroParams(const FString& string,
	const FString& param_delimiter, const FString& value_delimiter)
{
	TMap<FName, FString> out;
	TArray<FString> string_list=UKismetStringLibrary::ParseIntoArray(string,param_delimiter);
	for(FString s : string_list)
	{
		FString s_param;
		FString s_val;
		UKismetStringLibrary::Split(s,value_delimiter,s_param,s_val);

		out.Add(FName(s_param),s_val);
	}
	return out;
}

bool UOmegaUtilityFunctions::IsObjectNameFirst(UObject* A, UObject* B)
{
	if (!A || !B)
	{
		// Handle null objects - null objects go to the end
		return A && !B;
	}
    
	// Get display names for comparison
	FString NameA = A->GetName();
	FString NameB = B->GetName();
    
	// Compare alphabetically (case-insensitive)
	return NameA.Compare(NameB, ESearchCase::IgnoreCase) < 0;
}

uint8 UOmegaUtilityFunctions::GetBitmaskFlag_FromTag(FGameplayTag Flag)
{
	// Return 0 if the tag is invalid
	if (!Flag.IsValid())
	{
		return 0;
	}
    
	// Get the leaf tag name (the last part after the final dot)
	FString TagString = Flag.ToString();
	FString LeafName;
    
	if (TagString.Split(TEXT("."), nullptr, &LeafName, ESearchCase::IgnoreCase, ESearchDir::FromEnd))
	{
		// LeafName now contains the last part of the tag
	}
	else
	{
		// No dots found, the entire tag is the leaf
		LeafName = TagString;
	}
    
	// Try to parse the leaf name as a number (e.g., "BITFLAG.0", "BITFLAG.1")
	if (LeafName.IsNumeric())
	{
		int32 BitIndex = FCString::Atoi(*LeafName);
		if (BitIndex >= 0 && BitIndex <= 7)
		{
			return 1 << BitIndex;
		}
	}
    
	// Alternative: Use a hash or mapping system
	// Calculate a consistent bit position from the tag
	uint32 Hash = GetTypeHash(Flag);
	uint8 BitIndex = Hash % 8;  // Limit to 0-7 for uint8
    
	return 1 << BitIndex;
}

TArray<FString> UOmegaUtilityFunctions::GetCommandLineArgs()
{
	TArray<FString> Args;
	TArray<FString> Tokens;
	TArray<FString> Switches;
    
	// This properly handles quoted strings and switches
	FCommandLine::Parse(FCommandLine::Get(), Tokens, Switches);
    
	// Combine tokens and switches
	Args.Append(Tokens);
	Args.Append(Switches);
    
	return Args;
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


// ================================================================================
// ================================================================================
// MATH
// ================================================================================
// ================================================================================


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

