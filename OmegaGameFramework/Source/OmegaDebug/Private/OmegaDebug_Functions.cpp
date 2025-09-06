// Fill out your copyright notice in the Description page of Project Settings.

#include "OmegaDebug_Functions.h"

#include "Modifiers/Modifier_Save.h"
#include "Subsystems/OmegaSubsystem_Quest.h"

UOmegaDebugDevSettings::UOmegaDebugDevSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


UOmegaSettings_Debug* UOmegaDebugSubsystem::L_GetSettingsAsset() const
{
	if(GetMutableDefault<UOmegaDebugDevSettings>()->GetDefaultSettings())
	{
		return GetMutableDefault<UOmegaDebugDevSettings>()->GetDefaultSettings();
	}
	return GetMutableDefault<UOmegaSettings_Debug>();
}

UOmegaDebugProfile* UOmegaDebugSubsystem::L_GetProfileDefault() const
{
	if(L_GetSettingsAsset()->DefaultSettingsProfile)
	{
		return L_GetSettingsAsset()->DefaultSettingsProfile;
	}
	return GetMutableDefault<UOmegaDebugProfile>();
}

void UOmegaDebugSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	if(L_GetSettingsAsset()->bRunDebugProfile)
	{
		GetWorld()->GetTimerManager().SetTimer(timer_starProf,this,&UOmegaDebugSubsystem::StartDebugProfile_Default,
			GetMutableDefault<UOmegaDebugDevSettings>()->Delay_AutostartProfile);
	}
	
}

void UOmegaDebugSubsystem::StartDebugProfile(UOmegaDebugProfile* Profile)
{
	if(Profile)
	{
		if(Profile->DebugSave)
		{
			if(TSubclassOf<UOmegaSaveGame> _cl=Profile->DebugSave.LoadSynchronous())
			{
				if(UOmegaSaveGame* sav = NewObject<UOmegaSaveGame>(this,_cl))
				{
					GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->StartGame(sav,Profile->Save_LoadLevel,Profile->Save_Tags);
				}
			}
		}
		UOmegaSaveGame* _sav=GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->ActiveSaveData;
		
		FOmegaModifiers_Save smods;
		smods.Modifiers=Profile->SaveMods;
		smods.Modify(_sav,GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>(),false);
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

