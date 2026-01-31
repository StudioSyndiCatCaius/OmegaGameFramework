// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaEditorSettings.h"

#include "OmegaSettings.h"
#include "OmegaGameCore.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"

void UOmegaEditorSettings::GetHiddenVariables(UObject* Object, TArray<FName>& HiddenProperties,
                                              TArray<FName>& HiddenCategories)
{
	OGF_GAME_CORE()->Object_EditorHideVariables(Object,HiddenProperties,HiddenCategories);
}
