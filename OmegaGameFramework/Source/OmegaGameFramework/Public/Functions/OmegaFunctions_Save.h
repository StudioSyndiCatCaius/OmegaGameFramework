// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"

#include "OmegaFunctions_Save.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static void SetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 Value, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static void SetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool Value, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static int32 GetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static bool GetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandEnumAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="Check Save Param (Bool)")
	static bool CheckSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal, TEnumAsByte<EOmegaBranch>& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandEnumAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="Check Save Param (Int)")
	static int32 CheckSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 CheckValue, bool bGlobal, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome);
	
};
