// Fill out your copyright notice in the Description page of Project Settings.

#include "OmegaDebug_Functions.h"

#include "Subsystems/OmegaSubsystem_Quest.h"

UOmegaDebugDevSettings::UOmegaDebugDevSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UOmegaDebugSubsystem::StartDebugProfile(UOmegaDebugProfile* Profile)
{
	if(Profile)
	{
		for(auto* i : Profile->Scripts)
		{
			if(i)
			{
				i->OnProfileBegin(this);
			}
		}
		if(Profile->bAutostartQuests)
		{
			for(TSoftObjectPtr<UOmegaQuest> q : Profile->QuestsToAutostart)
			{
				if(UOmegaQuest* _quest = q.LoadSynchronous())
				{
					GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>()->StartQuest_FirstWithAsst(_quest);
				}
			}
		}
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->AddStoryTags(Profile->AutoSaveTags,true);
	}
}

void UOmegaDebugSubsystem::StartDebugProfile_Default()
{
	if(UOmegaSettings_Debug* set = UOmegaDebugsFunctions::GetOmegaDebugSettings())
	{
		StartDebugProfile(set->DefaultSettingsProfile);
	}
}

UOmegaSettings_Debug* UOmegaDebugsFunctions::GetOmegaDebugSettings()
{
	if(UOmegaSettings_Debug* set = 	GetMutableDefault<UOmegaDebugDevSettings>()->GetDefaultSettings())
	{
		return set;
	}
	return nullptr;
}

