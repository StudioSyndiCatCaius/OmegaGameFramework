// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "FlowSettings.h"

#include "FlowAsset.h"
#include "FlowAssetTrait.h"

UFlowSettings::UFlowSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bCreateFlowSubsystemOnClients(true)
	, bWarnAboutMissingIdentityTags(true)
{
}

TArray<UFlowAsset*> UFlowFunctions::FilterFlowAssetsWithTrait(TArray<UFlowAsset*> in,
	TSubclassOf<UFlowAssetTrait> Trait)
{
	TArray<UFlowAsset*> out;
	for(auto* f : in)
	{
		if(f)
		{
			for(auto* trait : f->Traits)
			{
				if(trait && trait->GetClass()->IsChildOf(Trait))
				{
					out.Add(f);
				}
			}
		}
	}
	return out;
}

UFlowAssetTrait* UFlowFunctions::GetFirstAssetTrait(UFlowAsset* FlowAsset, TSubclassOf<UFlowAssetTrait> Class,
	bool& Result)
{
	if(FlowAsset)
	{
		for(auto* trait : FlowAsset->Traits)
		{
			if(trait && trait->GetClass()->IsChildOf(Class))
			{
				Result=true;
				return trait;
			}
		}
	}
	Result=false;
	return nullptr;
}
