// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaStoryWorldSubsystem.h"

#include "Speaker/OmegaSpeakerComponent.h"

//////////////////
/// SPEAKERS /////
//////////////////

//REGISTER SPEAKER
void UOmegaStoryWorldSubsystem::RegisterSpeaker(UOmegaSpeakerComponent* Speaker)
{
	if(Speaker)
	{
		RegisteredSpeakers.Add(Speaker);
	}
}

//UNREGISTER SPEAKER
void UOmegaStoryWorldSubsystem::UnregisterSpeaker(UOmegaSpeakerComponent* Speaker)
{
	if(GetAllSpeakers().Contains(Speaker))
	{
		GetAllSpeakers().Remove(Speaker);
	}
}

//GET ALL SPEAKERS
 TArray<UOmegaSpeakerComponent*> UOmegaStoryWorldSubsystem::GetAllSpeakers()
{
	TArray<UOmegaSpeakerComponent*> OutSpeakers;

	for(auto TempSpeaker : RegisteredSpeakers)
	{
		if(TempSpeaker != nullptr)
		{
			OutSpeakers.Add(TempSpeaker);
		}
	}
	return OutSpeakers;
}

UOmegaSpeakerComponent* UOmegaStoryWorldSubsystem::GetSpeakerFromID(FGameplayTag ID)
{
	for(auto* TempSpeaker : GetAllSpeakers())
	{
		if(TempSpeaker->SpeakerID == ID)
		{
			return TempSpeaker;
		}
	}
	return nullptr;
}

