// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Utility.h"
#include "ShaderCompiler.h"
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

FRotator UOmegaMathFunctions::Conv_VectorToRot_Flat(FVector Vector)
{
	FRotator _out;
	_out.Pitch=Vector.Y;
	_out.Roll=Vector.X;
	_out.Yaw=Vector.Z;
	return _out;
}

FWidgetTransform UOmegaMathFunctions::Conv_Transform3DToTransformWidget(const FTransform Transform)
{
	FWidgetTransform _ts;
	_ts.Translation=UKismetMathLibrary::Conv_VectorToVector2D(Transform.GetLocation());
	_ts.Angle=Transform.GetRotation().Rotator().Roll;
	_ts.Scale=UKismetMathLibrary::Conv_VectorToVector2D(Transform.GetScale3D());
	return _ts;
}

float UOmegaMathFunctions::NormalizeToRange_int32(int32 value, int32 min, int32 max)
{
	return UKismetMathLibrary::NormalizeToRange(value,min,max);
}

int32 UOmegaMathFunctions::GetSeedFromGuid(FGuid Guid)
{
	return Guid.A+Guid.B+Guid.C+Guid.D;
}

bool UOmegaMathFunctions::RNG_RollFromFloat(float chance, bool& Outcome)
{
	float _rand = UKismetMathLibrary::RandomFloat();
	if(_rand==0.0 || _rand>chance)
	{
		Outcome=true;
		return true;
	}
	Outcome=false;
	return false;
}

float UOmegaMathFunctions::Variate_Float(float in, float amount, bool bAmountIsScale)
{
	float _offset = UKismetMathLibrary::RandomFloatInRange(amount*-1,amount);
	if(bAmountIsScale) { return in+(_offset*in);} return in+_offset;
}

FVector UOmegaMathFunctions::Offset_Vector(FVector Vector, const FRotator& Rotation, FVector Offset)
{
	return Vector+
		(UKismetMathLibrary::GetForwardVector(Rotation)*Offset.X)+
		(UKismetMathLibrary::GetRightVector(Rotation)*Offset.Y)+
		(UKismetMathLibrary::GetUpVector(Rotation)*Offset.Z);
}

FVector UOmegaMathFunctions::Offset_ActorLocation(const AActor* Actor, FVector Offset)
{
	if(Actor)
	{
		return Offset_Vector(Actor->GetActorLocation(),Actor->GetActorRotation(),Offset);
	}
	return FVector();
}

FVector UOmegaMathFunctions::Offset_PawnLocationFromControl(const APawn* Pawn, FVector Offset)
{
	if(Pawn)
	{
		return Offset_Vector(Pawn->GetActorLocation(),Pawn->GetControlRotation(),Offset);
	}
	return FVector();
}

FVector UOmegaMathFunctions::Random_VectorInRange(FVector Min, FVector Max)
{
	FVector _out;
	_out.X=UKismetMathLibrary::RandomFloatInRange(Min.X,Max.X);
	_out.Y=UKismetMathLibrary::RandomFloatInRange(Min.Y,Max.Y);
	_out.Z=UKismetMathLibrary::RandomFloatInRange(Min.Z,Max.Z);
	return _out;
}

FRotator UOmegaMathFunctions::Random_RotatorInRange(const FRotator& Min, const FRotator& Max)
{
	FRotator _out;
	_out.Yaw=UKismetMathLibrary::RandomFloatInRange(Min.Yaw,Max.Yaw);
	_out.Pitch=UKismetMathLibrary::RandomFloatInRange(Min.Pitch,Max.Pitch);
	_out.Roll=UKismetMathLibrary::RandomFloatInRange(Min.Roll,Max.Roll);
	return _out;
}

TMap<UPrimaryDataAsset*, int32> UOmegaMathFunctions::InvertMapValues_AssetInt(TMap<UPrimaryDataAsset*, int32> in)
{
	TMap<UPrimaryDataAsset*, int32> out;
	for(const auto& p : in)
	{
		out.Add(p.Key,p.Value*-1);
	}
	return out;
}

TMap<UPrimaryDataAsset*, float> UOmegaMathFunctions::InvertMapValues_Assetfloat(TMap<UPrimaryDataAsset*, float> in)
{
	TMap<UPrimaryDataAsset*, float> out;
	for(const auto& p : in)
	{
		out.Add(p.Key,p.Value*-1);
	}
	return out;
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

FTransform UOmegaMathFunctions::AddTransforms(const FTransform A, const FTransform B)
{
	FTransform out;
	out.SetLocation(A.GetLocation()+B.GetLocation());
	out.SetScale3D(A.GetScale3D()+B.GetScale3D());
	out.SetRotation(UKismetMathLibrary::ComposeRotators(A.GetRotation().Rotator(),B.GetRotation().Rotator()).Quaternion());
	return out;
}
