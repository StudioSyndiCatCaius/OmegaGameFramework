// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Log.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Misc/OmegaUtils_Methods.h"

void UOmegaFunctions_Log::Warning(FText Text, float Duration)
{
	OGF_Log::PrintToScreen("Ω WARNING: "+Text.ToString(),FColor::Yellow,Duration);
}

void UOmegaFunctions_Log::Error(FText Text, float Duration)
{
	OGF_Log::PrintToScreen("Ω ERROR: "+Text.ToString(),FColor::Red,Duration);
}
