// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Types/Struct_SpawnableTypeConfig.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "Functions/F_Common.h"
#include "Kismet/KismetMathLibrary.h"

void FOmegaSpawnableTypeConfig::SetFromLua(FLuaValue lua)
{

	TArray<FLuaValue> keys_bitflags=ULuaBlueprintFunctionLibrary::LuaTableGetValues(lua.GetField("bitflags"));
	for (FLuaValue key : keys_bitflags)
	{
		FOmegaBitmaskEditorEntry entry;
		entry.Title=FText::FromString(key.ToString());
		Bitmask_Config.Bitflags.Add(entry);
	}
	TArray<FLuaValue> keys_bitenums=ULuaBlueprintFunctionLibrary::LuaTableGetValues(lua.GetField("bitenums"));
	for (FLuaValue key : keys_bitenums)
	{
		FOmegaBitmaskEditorEnumData entry;
		entry.Title=FText::FromString(key.GetField("name").ToString());
		TArray<FLuaValue> opts=ULuaBlueprintFunctionLibrary::LuaTableGetValues(key.GetField("options"));
		for (FLuaValue opt : opts)
		{
			FOmegaBitmaskEditorEntry optData;
			optData.Title=FText::FromString(key.ToString());
			entry.Options.Add(optData);
		}
		Bitmask_Config.BitEnums.Add(entry);
	}
	
	TArray<FLuaValue> keys_lists=ULuaBlueprintFunctionLibrary::LuaTableGetValues(lua.GetField("lists"));
	for (FLuaValue key : keys_lists)
	{
		NamedLists.Add(key.ToName());
	}
	
	TArray<FLuaValue> keys_relatives=ULuaBlueprintFunctionLibrary::LuaTableGetValues(lua.GetField("relatives"));
	for (FLuaValue key : keys_relatives)
	{
		ActorRelatives.Add(key.ToName());
	}
	
	FVector _ColorVec=ULuaBlueprintFunctionLibrary::Conv_LuaValueToFVector(lua.GetField("Color"),FVector());
	Color=UKismetMathLibrary::Conv_VectorToLinearColor(_ColorVec).ToFColor(true);
	Color.A=255;
	RangeOffset=ULuaBlueprintFunctionLibrary::Conv_LuaValueToFVector(lua.GetField("BoundsOffset"),FVector());
	RangeSize=ULuaBlueprintFunctionLibrary::Conv_LuaValueToFVector(lua.GetField("BoundsSize"),FVector());
	LineThickness=lua.GetField("BoundsThickness").ToFloat();
	bool iconFound;
	if (UTexture2D* _foundTxt=Cast<UTexture2D>(UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(lua.GetField("Icon").ToString(),UTexture2D::StaticClass(),iconFound)))
	{
		Icon=_foundTxt;
	}
	IconSize=lua.GetField("IconSize").ToFloat();
}
