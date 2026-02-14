// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


#define OGF_GLOBAL_SETTINGS() GetMutableDefault<UOmegaSettings>()->GetGlobalSettings()

#define OGF_CFG() GetMutableDefault<UOmegaSettings>()
#define OGF_CFG_STYLE() GetMutableDefault<UOmegaStyleSettings>()
#define OGF_CFG_NAMEDASSETS() GetMutableDefault<UOmegaAssetSettings>()
#define OGF_CFG_LUA() GetMutableDefault<ULuaSettings>()

#define OGF_NAMED_ASSET_LIST(PropertyName) \
TArray<FName> out; \
GetMutableDefault<UOmegaAssetSettings>()->PropertyName.GetKeys(out); \
return out;


#define OGF_SUB_LUA() GetWorld()->GetGameInstance()->GetSubsystem<ULuaSubsystem>()

#define OGF_LUA_DOCODE(code) 	ULuaBlueprintFunctionLibrary::LuaRunString(this,nullptr,code.LuaCode);


#define OGF_UASSET_SOUND_UI(name) LoadObject<USoundWave>(this, TEXT("/OmegaGameFramework/audio/ui/" #name "." #name))