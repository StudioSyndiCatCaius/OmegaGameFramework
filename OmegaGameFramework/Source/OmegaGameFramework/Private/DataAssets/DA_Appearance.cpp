// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_Appearance.h"

UOAsset_Appearance* UOmegaAppearanceFunctions::GetAppearanceAsset(UObject* Source)
{
	if(Source && Source->GetClass()->ImplementsInterface(UDataInterface_AppearanceSource::StaticClass()))
	{
		if(UOAsset_Appearance* apr= IDataInterface_AppearanceSource::Execute_GetAppearanceAsset(Source))
		{
			return apr;
		}
	}
	return nullptr;
}

void UOmegaAppearanceFunctions::GetAppearanceLibraries(UObject* Source,
	UOmegaAssetLibrary_Animation*& Anim, UOmegaAssetLibrary_Sound*& Sound, UOmegaAssetLibrary_SlateBrush*& Slate)
{
	if(Source && Source->GetClass()->ImplementsInterface(UDataInterface_AssetLibraries::StaticClass()))
	{
		IDataInterface_AssetLibraries::Execute_GetAppearanceLibraries(Source,Anim,Sound,Slate);
	}
	if(UOAsset_Appearance* apr=GetAppearanceAsset(Source))
	{
		if(!Anim)
		{
			Anim=apr->Library_Anim;
		}
		if(!Sound)
		{
			Sound=apr->Library_Voice;
		}
		if(!Slate)
		{
			Slate=apr->Library_Slate;
		}
	}
	
}
