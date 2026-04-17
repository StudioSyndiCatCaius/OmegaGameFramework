// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAssets/OGA_Menu.h"

TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> UOmegaGA_Menu::FlowGraph_GetAvailableNodes_Implementation() const
{

	TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> out = Super::FlowGraph_GetAvailableNodes_Implementation();
	out.Add(UOGA_Node_Menu_Option::StaticClass());
	return out;
}

void UOmegaGA_Menu::GetEnabledEditors_Implementation(bool& Enable3DEditor, bool& FlowGraphEditor) const
{
	FlowGraphEditor=true;
}

FSlateBrush UOGA_Node_Menu_Option::FlowNode_GetPortrait_Implementation() const
{
	FSlateBrush b= State_Background;
	float _f=3;
	b.ImageSize.X=16*_f;
	b.ImageSize.Y=9*_f;
	return b;
}

