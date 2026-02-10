// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveConditions/SaveCondition_QueryTags.h"

bool USaveCondition_QueryTags::CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const
{
	return SaveSubsystem->SaveTagsMatchQuery(TagQuery,GlobalSave);
}

bool USaveCondition_StoryState::CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const
{
	if(bExact)
	{
		return SaveSubsystem->GetSaveState(GlobalSave).MatchesTagExact(StateTag);
	}
	return SaveSubsystem->GetSaveState(GlobalSave).MatchesTag(StateTag);
}
