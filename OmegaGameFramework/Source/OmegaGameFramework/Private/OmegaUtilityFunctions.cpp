// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaUtilityFunctions.h"
#include "ShaderCompiler.h"

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
