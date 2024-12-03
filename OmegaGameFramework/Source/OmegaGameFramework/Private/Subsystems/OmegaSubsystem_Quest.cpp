// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_Quest.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
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

void UOmegaQuestTypeScript::OnLoad_Implementation(UOmegaQuestComponent* Component, FJsonObjectWrapper Data) const
{
	
}

FJsonObjectWrapper UOmegaQuestTypeScript::OnSave_Implementation(UOmegaQuestComponent* Component, FJsonObjectWrapper Data) const
{
	return Data;
}

bool UOmegaQuestTypeScript::CanQuestStart_Implementation() const
{
	return true;
}

void UOmegaQuestTypeScript::SetComplete_Implementation(bool bComplete) const
{
	if(GetQuestComponent())
	{
		GetQuestComponent()->JsonSaveData.JsonObject->SetBoolField("complete",bComplete);
	}
}

void UOmegaQuestTypeScript::SetActive_Implementation(bool bActive) const
{
	if(GetQuestComponent())
	{
		GetQuestComponent()->JsonSaveData.JsonObject->SetBoolField("active",bActive);
	}
}

bool UOmegaQuestTypeScript::IsComplete_Implementation() const
{
	if(GetQuestComponent())
	{
		return GetQuestComponent()->JsonSaveData.JsonObject->GetBoolField("complete");
	}
	return false;
}

bool UOmegaQuestTypeScript::IsActive_Implementation() const
{
	if(GetQuestComponent())
	{
		return GetQuestComponent()->JsonSaveData.JsonObject->GetBoolField("active");
	}
	return false;
}

void UOmegaQuestComponent::TryLoadFromJsonSave()
{
	if(QuestAsset && QuestAsset->QuestScript)
	{
		JsonSaveData=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->ActiveSaveData->DataAsset_Json.FindOrAdd(QuestAsset);
		QuestAsset->QuestScript->OnLoad(this, JsonSaveData);
	}
}

void UOmegaQuestComponent::TrySaveToJsonSave()
{
	if(QuestAsset && QuestAsset->QuestScript)
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()
			->ActiveSaveData->DataAsset_Json.Add(QuestAsset,QuestAsset->QuestScript->OnSave(this, JsonSaveData));
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
		TryLoadFromJsonSave();
	}
	
	Super::BeginPlay();
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
	if(!IsQuestActive() && !IsQuestComplete())
	{
		if(Quest || !QuestAsset)
		{
			SetQuestAsset(Quest);
		}
		if(QuestAsset)
		{
			QuestAsset->QuestScript->OnQuestStart(this);
			return  true;
		}
	}
	return false;
}

bool UOmegaQuestComponent::EndQuest(bool bComplete)
{
	return false;
}

bool UOmegaQuestComponent::IsQuestActive()
{
	if(QuestAsset && QuestAsset->QuestScript)
	{
		return QuestAsset->QuestScript->IsActive();
	}
	return false;
}

bool UOmegaQuestComponent::IsQuestComplete()
{
	if(QuestAsset && QuestAsset->QuestScript)
	{
		return QuestAsset->QuestScript->IsComplete();
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


