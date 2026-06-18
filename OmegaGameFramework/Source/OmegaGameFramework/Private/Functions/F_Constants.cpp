// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Constants.h"
#include "Widget/HUDLayer.h"
#include "Widget/Menu.h"
#include "DataAssets/DA_EquipSlot.h"
#include "DataAssets/DA_Attribute.h"
#include "Actors/OmegaGameplaySystem.h"
#include "OmegaSettings_Constants.h"
#include "Components/Component_Leveling.h"
#include "DataAssets/DA_DamageType.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"

#define LOCAL_GETKEYS(v) \
TArray<FName> out; \
GetMutableDefault<UOmegaSettings_Constants>()->v.GetKeys(out); \
return out; \

#define LOCAL_GETCLASS(v) \
if (UClass* c = GetMutableDefault<UOmegaSettings_Constants>()->v.FindOrAdd(Name).LoadSynchronous()) \
{ \
return c; \
} \
OGF_Log::Error(FString::Printf(TEXT("No valid constant class : " #v " of ID '%s'"), *Name.ToString())); \
return nullptr;

TArray<FName> UOmegaFunctions_Constants::opts_dataasset(){ LOCAL_GETKEYS(Constant_DataAssetsClass) }
TArray<FName> UOmegaFunctions_Constants::opts_system(){ LOCAL_GETKEYS(Constant_Systems)}
TArray<FName> UOmegaFunctions_Constants::opts_menu(){ LOCAL_GETKEYS(Constant_Menus)}
TArray<FName> UOmegaFunctions_Constants::opts_hud(){ LOCAL_GETKEYS(Constant_Huds)}
TArray<FName> UOmegaFunctions_Constants::opts_int(){ LOCAL_GETKEYS(Constant_int)}
TArray<FName> UOmegaFunctions_Constants::opts_byte(){ LOCAL_GETKEYS(Constant_byte)}
TArray<FName> UOmegaFunctions_Constants::opts_float(){ LOCAL_GETKEYS(Constant_float)}
TArray<FName> UOmegaFunctions_Constants::opts_string(){ LOCAL_GETKEYS(Constant_string)}
TArray<FName> UOmegaFunctions_Constants::opts_da(){ LOCAL_GETKEYS(Constant_DataAsset)}
TArray<FName> UOmegaFunctions_Constants::opts_daList(){ LOCAL_GETKEYS(Constant_DataAssetList)}
TArray<FName> UOmegaFunctions_Constants::opts_att(){ LOCAL_GETKEYS(Constant_Attributes)}
TArray<FName> UOmegaFunctions_Constants::opts_equipSlot(){ LOCAL_GETKEYS(Constant_EquipSlots)}
TArray<FName> UOmegaFunctions_Constants::opts_leveling(){ LOCAL_GETKEYS(Constant_Leveling)}
TArray<FName> UOmegaFunctions_Constants::opts_text(){ LOCAL_GETKEYS(Constant_Text)}
TArray<FName> UOmegaFunctions_Constants::opts_textList(){ LOCAL_GETKEYS(Constant_TextList)}
TArray<FName> UOmegaFunctions_Constants::opts_level(){ LOCAL_GETKEYS(Constant_Level) }
TArray<FName> UOmegaFunctions_Constants::opts_levelList(){LOCAL_GETKEYS(Constant_LevelList)}
TArray<FName> UOmegaFunctions_Constants::opts_damageType(){LOCAL_GETKEYS(Constant_DamageTypes)}


TSubclassOf<UPrimaryDataAsset> UOmegaFunctions_Constants::Class_DataAsset(FName Name)
{
	LOCAL_GETCLASS(Constant_DataAssetsClass)
}
TSubclassOf<AOmegaGameplaySystem> UOmegaFunctions_Constants::Class_System(FName Name)
{
	LOCAL_GETCLASS(Constant_Systems)
}
TSubclassOf<UMenu> UOmegaFunctions_Constants::Class_Menu(FName Name)
{
	LOCAL_GETCLASS(Constant_Menus)
}
TSubclassOf<UHUDLayer> UOmegaFunctions_Constants::Class_HUD(FName Name)
{
	LOCAL_GETCLASS(Constant_Huds)
}

#define LOCAL_GETKEYVAL(v) \
UOmegaSettings_Constants* cfg=GetMutableDefault<UOmegaSettings_Constants>(); \
if (!cfg->v.Contains(Name)) \
{ \
	cfg->v.Add(Name, Fallback); \
} \
return cfg->v.FindOrAdd(Name); \


uint8 UOmegaFunctions_Constants::Byte(FName Name, uint8 Fallback)
{
	LOCAL_GETKEYVAL(Constant_byte)
}

int32 UOmegaFunctions_Constants::Int(FName Name, int32 Fallback)
{
	LOCAL_GETKEYVAL(Constant_int)
}

float UOmegaFunctions_Constants::Float(FName Name, float Fallback)
{
	LOCAL_GETKEYVAL(Constant_float)
}

FString UOmegaFunctions_Constants::String(FName Name, FString Fallback)
{
	LOCAL_GETKEYVAL(Constant_string)
}

UPrimaryDataAsset* UOmegaFunctions_Constants::DataAsset(FName Name, TSubclassOf<UPrimaryDataAsset> Class)
{
	if (UPrimaryDataAsset* da=GetMutableDefault<UOmegaSettings_Constants>()->Constant_DataAsset.FindOrAdd(Name).LoadSynchronous())
	{
		if (!Class || da->GetClass()->IsChildOf(Class))
		{
			return da;
		}
	}
	return nullptr;
}

TArray<UPrimaryDataAsset*> UOmegaFunctions_Constants::DataAssetList(FName Name, TSubclassOf<UPrimaryDataAsset> Class)
{
	TArray<UPrimaryDataAsset*> aList=GetMutableDefault<UOmegaSettings_Constants>()->Constant_DataAssetList.FindOrAdd(Name).GetAssets();
	TArray<UPrimaryDataAsset*> out;
	if (Class)
	{
		for (auto* a : aList)
		{
			if (a && a->GetClass()->IsChildOf(Class))
			{
				out.Add(a);
			}
		}
	}
	else
	{
		return aList;
	}
	return out;
}

UOmegaAttribute* UOmegaFunctions_Constants::Attribute(FName Name)
{
	if (UOmegaAttribute* da=GetMutableDefault<UOmegaSettings_Constants>()->Constant_Attributes.FindOrAdd(Name).LoadSynchronous())
	{
		return da;
	}
	return nullptr;
}

UEquipmentSlot* UOmegaFunctions_Constants::EquipSlot(FName Name)
{
	if (UEquipmentSlot* da=GetMutableDefault<UOmegaSettings_Constants>()->Constant_EquipSlots.FindOrAdd(Name).LoadSynchronous())
	{
		return da;
	}
	return nullptr;
}

UOmegaLevelingAsset* UOmegaFunctions_Constants::Leveling(FName Name)
{
	if (UOmegaLevelingAsset* da=GetMutableDefault<UOmegaSettings_Constants>()->Constant_Leveling.FindOrAdd(Name).LoadSynchronous())
	{
		return da;
	}
	return nullptr;
}

UOmegaDamageType* UOmegaFunctions_Constants::DamageType(FName Name)
{
	if (UOmegaDamageType* da=GetMutableDefault<UOmegaSettings_Constants>()->Constant_DamageTypes.FindOrAdd(Name).LoadSynchronous())
	{
		return da;
	}
	return nullptr;
}

FText UOmegaFunctions_Constants::Text(FName Name)
{
	return GetMutableDefault<UOmegaSettings_Constants>()->Constant_Text.FindOrAdd(Name);
}

FText UOmegaFunctions_Constants::ListedText(FName Name, int32 index)
{
	return GetMutableDefault<UOmegaSettings_Constants>()->Constant_TextList.FindOrAdd(Name).GetText(index);
}

TSoftObjectPtr<UWorld> UOmegaFunctions_Constants::Level(FName Name)
{
	return GetMutableDefault<UOmegaSettings_Constants>()->Constant_Level.FindOrAdd(Name);
}

TArray<TSoftObjectPtr<UWorld>> UOmegaFunctions_Constants::LevelList(FName Name)
{
	return GetMutableDefault<UOmegaSettings_Constants>()->Constant_LevelList.FindOrAdd(Name).List;
}
