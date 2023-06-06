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