// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Meta.h"

#include "Functions/F_CommandLine.h"

FString UOmegaFunctions_Meta::Parse_String(FOmegaCommonMeta source, const FString& param, const FString& Fallback,bool& bValid,
                                           TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder)
{
	bValid=true;
	
	bool bFlagValid=false;
	FString FlagResult=UOmegaFunctions_Command::Parse_String(source.Flag,param,Fallback,bFlagValid);
	FLuaValue luaResult=source.LuaValue.GetField(param);
	
	switch (parseOrder)
	{
	case LuaFlag:
		
		if (!luaResult.IsNil())
		{
			return luaResult.ToString();
		}
		if (bFlagValid)
		{
			return FlagResult;
		}
		
		break;
	case FlagLua:
		
		if (bFlagValid)
		{
			return FlagResult;
		}
		if (!luaResult.IsNil())
		{
			return luaResult.ToString();
		}
		
		break;
	case LuaOnly:
		if (!luaResult.IsNil())
		{
			return luaResult.ToString();
		}
		break;
	case FlagOnly:
		if (bFlagValid)
		{
			return FlagResult;
		}
		break;
	default: ;
	}
	
	bValid=false;
	return Fallback;
}

bool UOmegaFunctions_Meta::Parse_Bool(FOmegaCommonMeta source, const FString& param, bool Fallback, bool& bValid,
	TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder)
{
	FString result=Parse_String(source,param,"",bValid,parseOrder);
	if (bValid)
	{
		return result=="true";
	}
	return Fallback;
}

int32 UOmegaFunctions_Meta::Parse_Int32(FOmegaCommonMeta source, const FString& param, int32 Fallback, bool& bValid,
	TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder)
{
	FString result=Parse_String(source,param,"",bValid,parseOrder);
	if (bValid)
	{
		return FCString::Atoi(*result);
	}
	return Fallback;
}

float UOmegaFunctions_Meta::Parse_Float(FOmegaCommonMeta source, const FString& param, float Fallback, bool& bValid,
	TEnumAsByte<EOmegaCommonMetaParamParseOrder> parseOrder)
{
	FString result=Parse_String(source,param,"",bValid,parseOrder);
	if (bValid)
	{
		return FCString::Atof(*result);
	}
	return Fallback;
}
