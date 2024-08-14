// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_Quest.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/OmegaSubsystem_Save.h"

//##############################################################################################
// Script
//##############################################################################################

UWorld* UOmegaQuestManagerScript::GetWorld() const
{
	if(WorldPrivate) { return  WorldPrivate; }
	if(GetGameInstance()) { return GetGameInstance()->GetWorld(); } return nullptr;
}

UGameInstance* UOmegaQuestManagerScript::GetGameInstance() const
{
	if(WorldPrivate) { return WorldPrivate->GetGameInstance();}
	return Cast<UGameInstance>(GetOuter());
}

UOmegaQuestManagerScript::UOmegaQuestManagerScript(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); }
}



//##############################################################################################
// Component
//##############################################################################################
void UOmegaQuestComponent::BeginPlay()
{
	if(!QuestManagerScript)
	{
		QuestManagerScript=NewObject<UOmegaQuestManagerScript>(this,UOmegaQuestManagerScript::StaticClass());
	}
	QuestManagerScript->WorldPrivate=GetWorld();
	QuestManagerScript->OwnerComp=this;

	SaveSubsystem=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	QuestManagerScript->SaveSubsystem=SaveSubsystem;

	
	Super::BeginPlay();
}

bool UOmegaQuestComponent::StartQuest(UObject* Context)
{
	SetQuestContext(Context);
	if(!IsQuestActive())
	{
		return QuestManagerScript->Try_StartQuest(Context);
	}
	return false;
}

bool UOmegaQuestComponent::EndQuest(bool bComplete)
{
	if(IsQuestActive())
	{
		return QuestManagerScript->Try_EndQuest(bComplete);
	}
	return false;
}

bool UOmegaQuestComponent::IsQuestActive()
{
	return QuestManagerScript->IsQuest_Active();
}

bool UOmegaQuestComponent::IsQuestComplete()
{
	return QuestManagerScript->IsQuest_Finished();
}

UObject* UOmegaQuestComponent::GetState()
{
	return QuestManagerScript->Try_GetStateObject();
}

FString UOmegaQuestComponent::GetState_ID()
{
	return QuestManagerScript->Try_GetStateID();
}

void UOmegaQuestComponent::AttemptLoadState(UObject* NewQuestContext)
{
	if(NewQuestContext)
	{
		SetQuestContext(NewQuestContext);
	}
	//Try Load State
	if(IsQuestActive())
	{
		QuestManagerScript->QuestLoaded(GetState_ID());
	}
}
