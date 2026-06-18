// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearChoice_SimpleChoice.h"

#include "Misc/OmegaUtils_Methods.h"

bool ULinearChoice_SimpleChoice::IsChoiceAvailable_Implementation() const
{
	if (UOmegaSaveSubsystem* sub=OGF_Subsystems::oSave(this))
	{
		if(!SaveTagsQuery.IsEmpty() && !SaveTagsQuery.Matches(sub->GetStoryTags(false)))
		{
			return false;
		}
		return UOmegaFunctions_GlobalScripting::RunGlobalConditions(this,Conditions);	
	}
	return true;
}
