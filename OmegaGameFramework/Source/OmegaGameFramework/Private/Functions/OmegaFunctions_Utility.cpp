// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Utility.h"
#include "ShaderCompiler.h"
#include "Internationalization/Internationalization.h"
#include "CoreGlobals.h"

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
