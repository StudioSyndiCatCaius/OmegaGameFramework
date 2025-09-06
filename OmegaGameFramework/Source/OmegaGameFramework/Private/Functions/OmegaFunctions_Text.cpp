// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Text.h"

#include "OmegaSettings_Gameplay.h"
#include "OmegaSettings_Slate.h"

FText UOmegaTextFormater_Collection::ApplyTextFormat(FText in,UObject* WorldContext, FGameplayTag Tag, FOmegaCommonMeta meta)
{
	FText out=in;
	if((Tags_Accepted.IsEmpty() || Tags_Accepted.HasTagExact(Tag))
		&& (Tags_Rejected.IsEmpty() || !Tags_Rejected.HasTagExact(Tag)))
	{
		for(auto* a : Collections)
		{
			if(a)
			{
				out=a->ApplyTextFormat(out,WorldContext,Tag,meta);
			}
		}
		for(auto* a : Scripts)
		{
			if(a)
			{
				out=a->FormatText(out,WorldContext,Tag,meta);
			}
		}
	}
	return out;
}

FText UOmegaTextFunctions::ApplyGameplayTextFormating(UObject* WorldContextObject,FText In, FGameplayTag Tag, FOmegaCommonMeta meta)
{
	if(UOmegaSettings_Slate* set=UOmegaSlateFunctions::GetCurrentSlateStyle())
	{
		if(set->TextFormater)
		{
			return set->TextFormater->ApplyTextFormat(In, WorldContextObject, Tag,meta);
		}
	}
	return In;
}
