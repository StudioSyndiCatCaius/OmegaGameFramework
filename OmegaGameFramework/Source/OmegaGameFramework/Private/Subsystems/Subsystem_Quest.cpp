// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/Subsystem_Quest.h"

#include "OmegaGameCore.h"
#include "OmegaSettings.h"
#include "Engine/World.h"
#include "Functions/F_Common.h"
#include "Functions/F_Save.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_AssetHandler.h"
#include "Subsystems/Subsystem_Save.h"

//##############################################################################################
// Script
//##############################################################################################


UOmegaQuest* UOmegaQuestTypeScript::GetQuestAsset() const
{
	if(UOmegaQuest* OuterQuest =Cast<UOmegaQuest>(GetOuter()))
	{
		return OuterQuest;
	}
	return nullptr;
}

UOmegaQuest::UOmegaQuest()
{
	if(!Guid.IsValid()) { Guid= FGuid::NewGuid();}
}



bool UOmegaQuestTypeScript::CanQuestStart_Implementation() const
{
	return true;
}



void UOmegaQuestSubsystem::local_RegisterQuestComponent(UOmegaQuestComponent* comp, bool comp_registered)
{
	if(comp)
	{
		if(comp_registered && !REF_QuestComps.Contains(comp))
		{
			REF_QuestComps.Add(comp);
		}
		if(!comp_registered && REF_QuestComps.Contains(comp))
		{
			REF_QuestComps.Remove(comp);
		}
	}
}

UOmegaQuestComponent* UOmegaQuestSubsystem::GetQuest_FirstWithAsset(UOmegaQuest* Quest)
{
	for(auto* i : REF_QuestComps)
	{
		if(i && i->IsValidLowLevel() && i->GetQuestAsset()==Quest)
		{
			return i;
		}
	}
	return nullptr;
}

bool UOmegaQuestSubsystem::StartQuest_FirstWithAsst(UOmegaQuest* Quest)
{
	if(UOmegaQuestComponent* i = GetQuest_FirstWithAsset(Quest))
	{
		return i->StartQuest(Quest);
	}
	return false;
}

TArray<UOmegaQuestComponent*> UOmegaQuestSubsystem::GetQuests_Active()
{
	TArray<UOmegaQuestComponent*> out;
	for(auto* i : REF_QuestComps)
	{
		if(i && i->IsQuestActive())
		{
			out.Add(i);
		}
	}
	return out;
}

TArray<UOmegaQuestComponent*> UOmegaQuestSubsystem::GetQuests_Complete()
{
	TArray<UOmegaQuestComponent*> out;
	for(auto* i : REF_QuestComps)
	{
		if(i && i->IsQuestComplete())
		{
			out.Add(i);
		}
	}
	return out;
}

TArray<UObject*> UOmegaQuestSubsystem::GetActiveQuestTasks(TSubclassOf<UObject> Class)
{
	TArray<UObject*> out;
	for (auto* a :GetQuests_Active())
	{
		if (a)
		{
			for (auto* t : a->GetActiveQuestTasks())
			{
				if (!Class || t->GetClass()->IsChildOf(Class))
				{
					out.Add(t);
				}
			}
		}
	}
	return out;
}

void UOmegaQuestComponent::LoadQuestData(FOmegaQuestData Data)
{
	QuestData=Data;
	if(QuestAsset->QuestScript)
	{
		QuestAsset->QuestScript->OnLoad(this);
	}
}

void UOmegaQuestComponent::TryLoad_Auto()
{
	if(QuestAsset)
	{
		if(UOmegaSaveGame* _save=UOmegaSaveFunctions::GetSave_Game(this))
		{
			LoadQuestData(_save->quest_data.FindOrAdd(QuestAsset));
		}
	}
}

void UOmegaQuestComponent::TrySave_Auto()
{
	if(QuestAsset)
	{
		if(UOmegaSaveGame* _save=UOmegaSaveFunctions::GetSave_Game(this))
		{
			_save->quest_data.Add(QuestAsset,QuestData);
			if(QuestAsset->QuestScript)
			{
				QuestAsset->QuestScript->OnSave(this);
			}
		}
	}
}

//##############################################################################################
// Component
//##############################################################################################
void UOmegaQuestComponent::BeginPlay()
{
	if(QuestAsset)
	{
		SetQuestAsset(QuestAsset);
	}
	if(bAutoLoadFromSaveJson)
	{
		TryLoad_Auto();
	}
	subsystem_quest=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>();
	subsystem_quest->local_RegisterQuestComponent(this,true);
	Super::BeginPlay();
}

void UOmegaQuestComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::Destroyed || EndPlayReason==EEndPlayReason::LevelTransition)
	{
		if(GetWorld()->GetGameInstance())
		{
			GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>()->local_RegisterQuestComponent(this,false);
		}
		if(QuestAsset && QuestAsset->QuestScript)
		{
			QuestAsset->QuestScript->OnComponentEndPlay(this);
		}
	}
	Super::EndPlay(EndPlayReason);
}


void UOmegaQuestComponent::SetQuestAsset(UOmegaQuest* Quest)
{
	if(Quest && Quest->QuestScript && Quest->QuestScript->CanQuestStart())
	{
		
		Quest->QuestScript->REF_Comp=this;
		QuestAsset=Quest;
	}
}

bool UOmegaQuestComponent::StartQuest(UOmegaQuest* Quest)
 {
	if(CanQuestStart() && subsystem_quest)
	{
		if(Quest || !QuestAsset)
		{
			SetQuestAsset(Quest);
		}
		if(QuestAsset)
		{
			QuestData.Status=Active;
			QuestAsset->QuestScript->OnQuestStart(this);
			OGF_GAME_CORE()->Quest_OnStart(QuestAsset,subsystem_quest);
			subsystem_quest->OnQuestStart.Broadcast(this,Quest);
			OnQuestStart.Broadcast(this,Quest);
			return  true;
		}
	}
	return false;
}

bool UOmegaQuestComponent::EndQuest(bool bComplete)
{
	if(IsQuestActive())
	{
		subsystem_quest->OnQuestEnd.Broadcast(this,QuestAsset);
		OGF_GAME_CORE()->Quest_OnEnd(QuestAsset,subsystem_quest);
		OnQuestEnd.Broadcast(this,QuestAsset);
		if (bComplete)
		{
			SetQuestStatus(Complete);
		}
		else
		{
			SetQuestStatus(Failed);
		}
	}
	return false;
}

void UOmegaQuestComponent::SetQuestStatus(EOmegaQuestStatus NewStatus)
{
	if(QuestData.Status!=NewStatus)
	{
		QuestData.Status=NewStatus;
		OnQuestStatusChanged.Broadcast(this,NewStatus);
	}
}

bool UOmegaQuestComponent::IsQuestActive() const
{
	if(QuestAsset)
	{
		return QuestData.Status==Active;
	}
	return false;
}

bool UOmegaQuestComponent::IsQuestComplete() const
{
	
	if(QuestAsset)
	{
		return QuestData.Status==Complete;
	}
	return false;
}

bool UOmegaQuestComponent::CanQuestStart() const
{
	if(QuestAsset)
	{
		return !IsQuestActive() &&
			!IsQuestComplete() &&
				OGF_GAME_CORE()->Quest_CanStart(QuestAsset,subsystem_quest) &&
			GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->CustomSaveConditionsMet(QuestAsset->Condition_ToStart);
	}
	return false;
}

TArray<UObject*> UOmegaQuestComponent::GetActiveQuestTasks()
{
	TArray<UObject*> out;
	if(QuestAsset && QuestAsset->QuestScript)
	{
		return QuestAsset->QuestScript->GetActiveTasks(this);
	}
	return out;
}

