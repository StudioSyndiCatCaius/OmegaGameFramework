// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAssets/OGA_Quest.h"

TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> UOmegaGA_Quest::FlowGraph_GetAvailableNodes_Implementation() const
{

	TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> out = Super::FlowGraph_GetAvailableNodes_Implementation();
	out.Add(UOGA_Node_Quest_AwaitGEvent::StaticClass());
	out.Add(UOGA_Node_Quest_Dialogue::StaticClass());
	out.Add(UOGA_Node_Quest_Battle::StaticClass());
	return out;
}

void UOmegaGA_Quest::GetEnabledEditors_Implementation(bool& Enable3DEditor, bool& FlowGraphEditor) const
{
	FlowGraphEditor=true;
}

UOGA_Node_QuestTask::UOGA_Node_QuestTask()
{
}
