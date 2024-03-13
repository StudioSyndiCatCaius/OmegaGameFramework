// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Utility.h"
#include "ShaderCompiler.h"
#include "Internationalization/Internationalization.h"
#include "CoreGlobals.h"
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