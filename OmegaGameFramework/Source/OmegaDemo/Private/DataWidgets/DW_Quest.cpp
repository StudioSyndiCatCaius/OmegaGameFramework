// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_Quest.h"
#include "Functions/F_Common.h"
#include "Widget/DataList.h"


void UDataWidgetBase_Quest::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(UActorComponent* temp_comp = local_GetComponentFromObject(Asset,AOmegaQuestInstance::StaticClass()))
	{
		QuestInstance=Cast<AOmegaQuestInstance>(temp_comp);
		if(GetDataList_ActiveTasks())
		{
			GetDataList_ActiveTasks()->SetListOwner(QuestInstance);
		}
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_Quest::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(QuestInstance)
	{
		if(GetDataList_ActiveTasks())
		{
			GetDataList_ActiveTasks()->ClearList();
			for(auto* temp_object : QuestInstance->GetActiveTasks())
			{
				if(temp_object)
				{
					GetDataList_ActiveTasks()->AddAssetToList(temp_object,"");
				}
			}
		}
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}
