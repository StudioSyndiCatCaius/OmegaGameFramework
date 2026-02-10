// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/Obj_Lua.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "Functions/F_Common.h"

TArray<FOmegaAttributeModifier> UOmegaLuaBaseObject::GetModifierValues_Implementation(UCombatantComponent* CombatantComponent)
{
	TArray<FOmegaAttributeModifier> out;
	FLuaValue mod_list = ILuaInterface::Execute_GetValue(this,"").GetField(Param_AttributeMods);
	for(FLuaValue att_name : ULuaBlueprintFunctionLibrary::LuaTableGetKeys(mod_list))
	{
		bool result;
		UObject* output = UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(att_name.String,UOmegaAttribute::StaticClass(),result);
		if(output && result)
		{
			FOmegaAttributeModifier new_mod;
			new_mod.Attribute=Cast<UOmegaAttribute>(output);
			new_mod.Incrementer=mod_list.GetField(att_name.String).ToFloat();
			out.Add(new_mod);
		}
	}
	return out;
}
