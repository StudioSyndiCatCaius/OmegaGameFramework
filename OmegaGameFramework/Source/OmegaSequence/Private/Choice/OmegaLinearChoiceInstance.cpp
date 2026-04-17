// Fill out your copyright notice in the Description page of Project Settings.


#include "Choice/OmegaLinearChoiceInstance.h"

bool AOmegaLinearChoiceInstance::SelectChoice(int32 Index)
{
	if(ChoiceData.Choices.IsValidIndex(Index))
	{
		UOmegaLinearChoice* choice_ref=ChoiceData.Choices[Index];
		choice_ref->OnChoiceSelected();
		OnChoiceSelected.Broadcast(choice_ref, Index);
		K2_DestroyActor();
		return true;
	}
	else
	{
		return false;
	}
}

TArray<UOmegaLinearChoice*> AOmegaLinearChoiceInstance::GetChoices()
{
	return ChoiceData.Choices;
}

void AOmegaLinearChoiceInstance::GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed,
	FOmegaClassNamedLists& named_lists)
{
	IDataInterface_General::GetMetaConfig_Implementation(bitflags, guid, seed, named_lists);
	bitflags=ChoiceData.flags;
	named_lists=ChoiceData.NamedLists;
}

