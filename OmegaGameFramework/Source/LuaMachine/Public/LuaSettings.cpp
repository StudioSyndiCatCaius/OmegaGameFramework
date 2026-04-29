#include "LuaSettings.h"


ULuaSettings::ULuaSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GlobalScriptBindPaths.Add("/Game/0_Main/Blueprints/GlobalScripts/");
}