// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaEditorSettings.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Global.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"

void UOmegaEditorSettings::GetHiddenVariables(UObject* Object, TArray<FName>& HiddenProperties,
                                              TArray<FName>& HiddenCategories)
{
	OGF_GLOBAL_SETTINGS()->Object_EditorHideVariables(Object,HiddenProperties,HiddenCategories);
}
