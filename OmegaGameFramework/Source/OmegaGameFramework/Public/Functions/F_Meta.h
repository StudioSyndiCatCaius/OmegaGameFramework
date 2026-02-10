// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"
#include "F_Meta.generated.h"

UENUM(BlueprintType)
enum EOmegaCommonMetaParamParseOrder : uint8
{
	LuaFlag		UMETA(DisplayName="LUA then FLAG"),
	FlagLua		UMETA(DisplayName="FLAG then LUA"),
	LuaOnly		UMETA(DisplayName="LUA only"),
	FlagOnly	UMETA(DisplayName="FLAG only"),
};

UCLASS()
class UOmegaFunctions_Meta : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|CommonMeta",DisplayName="Meta - Parse (String)",meta=(AdvancedDisplay="parseOrder"))
	static FString Parse_String(FOmegaCommonMeta source, const FString& param, const FString& Fallback, bool& bValid,TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder);
	
	UFUNCTION(BlueprintPure,Category="Omega|CommonMeta",DisplayName="Meta - Parse (Bool)",meta=(AdvancedDisplay="parseOrder"))
	static bool Parse_Bool(FOmegaCommonMeta source, const FString& param, bool Fallback,bool& bValid, TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder);
	
	UFUNCTION(BlueprintPure,Category="Omega|CommonMeta",DisplayName="Meta - Parse (Int32)",meta=(AdvancedDisplay="parseOrder"))
	static int32 Parse_Int32(FOmegaCommonMeta source, const FString& param, int32 Fallback,bool& bValid, TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder);
	
	UFUNCTION(BlueprintPure,Category="Omega|CommonMeta",DisplayName="Meta - Parse (Float)",meta=(AdvancedDisplay="parseOrder"))
	static float Parse_Float(FOmegaCommonMeta source, const FString& param, float Fallback,bool& bValid, TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder);
};