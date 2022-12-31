// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_EditSaveTags.h"

#include "Save/OmegaSaveSubsystem.h"

void ULinearEvent_EditSaveTags::Native_Begin()
{
	
	

	switch (Action)
	{
		case EAddRemove::Add:
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->AddStoryTags(Tags, GlobalSave);
		break;
		case EAddRemove::Remove:
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->RemoveStoryTags(Tags, GlobalSave);
		break;
	}
	Super::Native_Begin();
	Finish("");
}
