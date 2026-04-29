// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Quest.h"

#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"


void UOmegaQuestTypeScript::OnQuestStart_Implementation(AOmegaQuestInstance* Instance) const
{
}

void UOmegaQuestTypeScript::OnQuestEnd_Implementation(AOmegaQuestInstance* Instance) const
{
}

UOmegaQuest::UOmegaQuest()
{
}

FOmegaQuestData* UOmegaQuestTypeScript::L_GetQuestData()
{
	if (GetQuestAsset())
	{
		return &GetQuestInstance()->SS_Save->ActiveSaveData->quest_data.FindOrAdd(GetQuestAsset());
	}
	return &local_data;
}

AOmegaQuestInstance* UOmegaQuestTypeScript::GetQuestInstance() const
{
	if (qInst)
	{
		return qInst;
	}
	return nullptr;
}

UOmegaQuest* UOmegaQuestTypeScript::GetQuestAsset() const
{
	if (AOmegaQuestInstance* q=GetQuestInstance())
	{
		return q->QuestAsset;
	}
	return nullptr;
}

void UOmegaQuestTypeScript::OnLoad_Implementation(AOmegaQuestInstance* Instance, FOmegaQuestData data) const
{
}

void UOmegaQuestTypeScript::OnSave_Implementation(AOmegaQuestInstance* Instance) const
{
}

void UOmegaQuestTypeScript::OnEndPlay_Implementation(AOmegaQuestInstance* Instance) const
{
}

bool UOmegaQuestTypeScript::CanQuestStart_Implementation() const
{
	return true;
}

TArray<UObject*> UOmegaQuestTypeScript::GetActiveTasks_Implementation(AOmegaQuestInstance* Instance) const
{
	return TArray<UObject*>();
}

// ------------------------------------------------------------------------------------------------------------------------

AOmegaQuestInstance::AOmegaQuestInstance()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
}

void AOmegaQuestInstance::BeginPlay()
{
	Super::BeginPlay();
}

void AOmegaQuestInstance::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (EndPlayReason==EEndPlayReason::Destroyed)
	{
		if (script_copy)
		{
			script_copy->OnEndPlay(this);
		}
	}
}

void AOmegaQuestInstance::StartQuest(bool bResumeFormSave)
{
	if(QuestAsset)
	{
		if (QuestAsset->QuestScript)
		{
			script_copy=DuplicateObject(QuestAsset->QuestScript,this);
	        script_copy->qInst=this;
	        OGF_Subsystems::oSave(this)->ActiveSaveData->quest_data.FindOrAdd(QuestAsset).Status=QuestStatus_Active;
	        
	        if (bResumeFormSave)
	        {
        		script_copy->OnLoad(this,SS_Save->ActiveSaveData->quest_data.FindOrAdd(QuestAsset));
        		if (SS_World)
        		{
        			SS_World->OnQuest_Updated.Broadcast(this,QuestAsset);
        		}
	        }
	        else
	        {
        		script_copy->OnQuestStart(this);
        		if (SS_World)
        		{
        			SS_World->OnQuest_Start.Broadcast(this,QuestAsset);
        		}
	        }
		}
		else
		{
			OGF_Log::Error("Quest Instance '"+GetName()+" has no valid script.");
		}
	}
	else
	{
		OGF_Log::Error("Quest Instance '"+GetName()+" has no valid asset. Could not set state to ACTIVE");
	}
	
}

void AOmegaQuestInstance::TriggerQuestUpdate()
{
	if (SS_World)
	{
		SS_World->OnQuest_Updated.Broadcast(this,QuestAsset);
	}
}

void AOmegaQuestInstance::StopQuest(bool bFailed)
{
	if (!b_ended)
	{
		b_ended=true;
		if (script_copy)
        {
            script_copy->OnQuestEnd(this);
        }
		if (SS_World)
		{
			SS_World->OnQuest_End.Broadcast(this,QuestAsset);
		}
		WM->Quest_Stop(QuestAsset,bFailed);
	}
}

TArray<UObject*> AOmegaQuestInstance::GetActiveTasks()
{
	if (QuestAsset && QuestAsset->QuestScript)
	{
		return QuestAsset->QuestScript->GetActiveTasks(this);	
	}
	OGF_Log::Error("Quest Instance '"+GetName()+" has not valid asset or questScript");
	return TArray<UObject*>();
}

void AOmegaQuestInstance::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description)
{
	IDataInterface_General::Execute_GetGeneralDataText(QuestAsset,Tag, Name, Description);
}

void AOmegaQuestInstance::GetGeneralAssetLabel_Implementation(FString& Label)
{
	IDataInterface_General::Execute_GetGeneralAssetLabel(QuestAsset,Label);
}

void AOmegaQuestInstance::GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture,
	class UMaterialInterface*& Material, FSlateBrush& Brush)
{
	IDataInterface_General::Execute_GetGeneralDataImages(QuestAsset,Tag, Texture, Material, Brush);
}

FGameplayTag AOmegaQuestInstance::GetObjectGameplayCategory_Implementation()
{
	return IDataInterface_General::Execute_GetObjectGameplayCategory(QuestAsset);
}

FGameplayTagContainer AOmegaQuestInstance::GetObjectGameplayTags_Implementation()
{
	return IDataInterface_General::Execute_GetObjectGameplayTags(QuestAsset);
}
