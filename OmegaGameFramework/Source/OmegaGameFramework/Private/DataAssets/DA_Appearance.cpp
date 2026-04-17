// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_Appearance.h"

void UOAsset_Appearance::Apply(ACharacter* c) const
{
	if (c)
	{
		UOmegaComponentModifierFunctions::ApplyModifierTo_SkeletalMesh(Mesh,c->GetMesh());
	}
}

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
	if (!Source) { return; }
	if(Source && Source->GetClass()->ImplementsInterface(UDataInterface_AssetLibraries::StaticClass()))
	{
		UOmegaAssetLibrary_Animation* _anim = nullptr;
		UOmegaAssetLibrary_Sound* _sound = nullptr;
		UOmegaAssetLibrary_SlateBrush* _slate = nullptr;
		IDataInterface_AssetLibraries::Execute_GetAppearanceLibraries(Source,_anim,_sound,_slate);
		if (_anim) { Anim=_anim; }
		if(_sound) { Sound=_sound; }
		if(_slate) { Slate=_slate; }
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
