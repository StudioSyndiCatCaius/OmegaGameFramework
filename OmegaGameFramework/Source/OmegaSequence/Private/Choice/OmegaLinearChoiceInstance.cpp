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

