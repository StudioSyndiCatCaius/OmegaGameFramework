// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "DataAssets/DA_AssetLib.h"

UAnimSequence* UOmegaAssetLibrary_Animation::GetAnimation_Named(FName Name,bool& Result,UAnimSequence* fall_back)
{
	Result=false;
	if(Anims_Named.Contains(Name))
	{
		Result=true;
		return Anims_Named[Name];
	}
	if(Fallback)
	{
		return Fallback->GetAnimation_Named(Name,Result);
	}
	return fall_back;
}

UAnimMontage* UOmegaAssetLibrary_Animation::GetMontage_Named(FName Name,bool& Result,UAnimMontage* fall_back)
{
	Result=false;
	if(Montages_Named.Contains(Name))
	{
		Result=true;
		return Montages_Named[Name];
	}
	if(Fallback)
	{
		return Fallback->GetMontage_Named(Name,Result);
	}
	return fall_back;
}
ULevelSequence* UOmegaAssetLibrary_Animation::GetLevelSequence_Named(FName Name,bool& Result,ULevelSequence* fall_back)
{
	Result=false;
	if(LevelSequences_Named.Contains(Name))
	{
		Result=true;
		return LevelSequences_Named[Name];
	}
	if(Fallback)
	{
		return Fallback->GetLevelSequence_Named(Name,Result);
	}
	return fall_back;
}

UBlendSpace* UOmegaAssetLibrary_Animation::GetBlendSpace_Named(FName Name,bool& Result,UBlendSpace* fall_back)
{
	Result=false;
	if(BlendSpace_Named.Contains(Name))
	{
		Result=true;
		return BlendSpace_Named[Name];
	}
	if(Fallback)
	{
		return Fallback->GetBlendSpace_Named(Name,Result);
	}
	return fall_back;
}
UAimOffsetBlendSpace* UOmegaAssetLibrary_Animation::GetAimOffset_Named(FName Name,bool& Result,UAimOffsetBlendSpace* fall_back)
{
	Result=false;
	if(AimBlendSpace_Named.Contains(Name))
	{
		Result=true;
		return AimBlendSpace_Named[Name];
	}
	if(Fallback)
	{
		return Fallback->GetAimOffset_Named(Name,Result);
	}
	return fall_back;
}

TArray<UAnimSequence*> UOmegaAssetLibrary_Animation::GetAnimation_NamedList(FName Name) const
{
	TArray<UAnimSequence*> out;
	if(Anims_Named.Contains(Name))
	{
		return Anims_NamedLists[Name].List;
	}
	if(Fallback)
	{
		return Fallback->GetAnimation_NamedList(Name);
	}
	return out;
}

TArray<UAnimMontage*> UOmegaAssetLibrary_Animation::GetMontage_NamedList(FName Name) const
{
	TArray<UAnimMontage*> out;
	if(Montages_NamedList.Contains(Name))
	{
		return Montages_NamedList[Name].List;
	}
	if(Fallback)
	{
		return Fallback->GetMontage_NamedList(Name);
	}
	return out;
}

TArray<ULevelSequence*> UOmegaAssetLibrary_Animation::GetLevelSequence_NamedList(FName Name) const
{
	TArray<ULevelSequence*> out;
	if(LevelSequences_NamedList.Contains(Name))
	{
		return LevelSequences_NamedList[Name].List;
	}
	if(Fallback)
	{
		return Fallback->GetLevelSequence_NamedList(Name);
	}
	return out;
}

USoundBase* UOmegaAssetLibrary_Sound::GetSound_Named(FName Name, bool& Result,USoundBase* fall_back)
{
	Result=false;
	if(Sounds_Named.Contains(Name))
	{
		Result=true;
		return Sounds_Named[Name];
	}
	if(Fallback)
	{
		return Fallback->GetSound_Named(Name,Result);
	}
	return fall_back;
}

FSlateBrush UOmegaAssetLibrary_SlateBrush::GetBrush_Named(FName Name, bool& Result,FSlateBrush fall_back)
{
	Result=false;
	if(Brushes_Named.Contains(Name))
	{
		Result=true;
		return Brushes_Named[Name];
	}
	if(Fallback)
	{
		return Fallback->GetBrush_Named(Name,Result);
	}
	return fall_back;
}
