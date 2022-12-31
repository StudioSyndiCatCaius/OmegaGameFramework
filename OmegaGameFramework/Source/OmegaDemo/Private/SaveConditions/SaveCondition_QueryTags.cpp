// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveConditions/SaveCondition_QueryTags.h"

bool USaveCondition_QueryTags::CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const
{
	return SaveSubsystem->SaveTagsMatchQuery(TagQuery,GlobalSave);
}
