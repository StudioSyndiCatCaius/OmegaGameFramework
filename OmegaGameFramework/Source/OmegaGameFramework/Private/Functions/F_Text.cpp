// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Text.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Gameplay.h"
#include "OmegaSettings_Global.h"
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
	FText out=In;
	UOmegaGlobalSettings* _set=GetMutableDefault<UOmegaSettings>()->GetGlobalSettings();
	out=_set->Text_PreGameplayFormat(out,Tag,meta);
	if(UOmegaTextFormater_Collection* set=GetMutableDefault<UOmegaSettings>()->DefaultSettings_Text.LoadSynchronous())
	{
		out=set->ApplyTextFormat(In, WorldContextObject, Tag,meta);
	}
	out=_set->Text_PostGameplayFormat(out,Tag,meta);
	return out;
}

