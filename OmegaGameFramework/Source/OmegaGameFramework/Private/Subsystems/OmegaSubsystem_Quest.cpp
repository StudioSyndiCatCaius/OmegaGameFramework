// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_Quest.h"
#include "Engine/World.h"
#include "Functions/OmegaFunctions_Common.h"
#include "Functions/OmegaFunctions_Save.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/OmegaSubsystem_AssetHandler.h"
#include "Subsystems/OmegaSubsystem_Save.h"

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
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>()->local_RegisterQuestComponent(this,true);
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
	if(CanQuestStart())
	{
		if(Quest || !QuestAsset)
		{
			SetQuestAsset(Quest);
		}
		if(QuestAsset)
		{
			QuestData.Status=Active;
			QuestAsset->QuestScript->OnQuestStart(this);
			GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>()->OnQuestStart.Broadcast(this,Quest);
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
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>()->OnQuestEnd.Broadcast(this,QuestAsset);
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

