// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Constants.h"
#include "Widget/HUDLayer.h"
#include "Widget/Menu.h"
#include "Actors/OmegaGameplaySystem.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"

#define LOCAL_GETKEYS(v) \
TArray<FName> out; \
GetMutableDefault<UOmegaSettings>()->v.GetKeys(out); \
return out; \

#define LOCAL_GETCLASS(v) \
if (UClass* c = OGF_CFG()->v.FindOrAdd(Name).LoadSynchronous()) \
{ \
return c; \
} \
OGF_Log::Error(FString::Printf(TEXT("No valid constant class : " #v " of ID '%s'"), *Name.ToString())); \
return nullptr;

TArray<FName> UOmegaFunctions_Constants::opts_dataasset()
{
	
	LOCAL_GETKEYS(Constant_DataAssetsClass)
}

TArray<FName> UOmegaFunctions_Constants::opts_system()
{
	LOCAL_GETKEYS(Constant_Systems)
}

TArray<FName> UOmegaFunctions_Constants::opts_menu()
{
	LOCAL_GETKEYS(Constant_Menus)
}

TArray<FName> UOmegaFunctions_Constants::opts_hud()
{
	LOCAL_GETKEYS(Constant_Huds)
}

TArray<FName> UOmegaFunctions_Constants::opts_int()
{
	LOCAL_GETKEYS(Constant_int)
}

TArray<FName> UOmegaFunctions_Constants::opts_float()
{
	LOCAL_GETKEYS(Constant_float)
}

TArray<FName> UOmegaFunctions_Constants::opts_string()
{
	LOCAL_GETKEYS(Constant_string)
}

TArray<FName> UOmegaFunctions_Constants::opts_da()
{
	LOCAL_GETKEYS(Constant_DataAsset)
}

TArray<FName> UOmegaFunctions_Constants::opts_daList()
{
	LOCAL_GETKEYS(Constant_DataAssetList)
}

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

int32 UOmegaFunctions_Constants::Int(FName Name)
{
	return OGF_CFG()->Constant_int.FindOrAdd(Name);
}

float UOmegaFunctions_Constants::Float(FName Name)
{
	return OGF_CFG()->Constant_float.FindOrAdd(Name);
}

FString UOmegaFunctions_Constants::String(FName Name)
{
	return OGF_CFG()->Constant_string.FindOrAdd(Name);
}

UPrimaryDataAsset* UOmegaFunctions_Constants::DataAsset(FName Name)
{
	if (UPrimaryDataAsset* da=OGF_CFG()->Constant_DataAsset.FindOrAdd(Name).LoadSynchronous())
	{
		return da;
	}
	return nullptr;
}

TArray<UPrimaryDataAsset*> UOmegaFunctions_Constants::DataAssetList(FName Name)
{
	return OGF_CFG()->Constant_DataAssetList.FindOrAdd(Name).GetAssets();
}
