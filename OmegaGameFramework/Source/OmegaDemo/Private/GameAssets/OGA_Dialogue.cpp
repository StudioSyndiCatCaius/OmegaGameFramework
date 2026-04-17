// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAssets/OGA_Dialogue.h"

#include "Functions/F_Common.h"

TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> UOmegaGA_Dialogue::FlowGraph_GetAvailableNodes_Implementation() const
{
	TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> out = Super::FlowGraph_GetAvailableNodes_Implementation();
	out.Add(UOGA_Node_DLG_Message::StaticClass());
	out.Add(UOGA_Node_DLG_Choice::StaticClass());
	out.Add(UOGA_Node_DLG_ChoiceHUB::StaticClass());
	return out;
}

void UOmegaGA_Dialogue::GetEnabledEditors_Implementation(bool& Enable3DEditor, bool& FlowGraphEditor) const
{
	FlowGraphEditor=true;
}


FSlateBrush UOGA_Node_DLG_Message::FlowNode_GetPortrait_Implementation() const
{
	if (Speaker)
	{
		FSlateBrush Brush=UOmegaGameFrameworkBPLibrary::GetObjectIcon(Speaker,FGameplayTag());
		Brush.ImageSize.X=50;
		Brush.ImageSize.Y=50;
		return Brush;
	}
	return FSlateBrush();
}

FString UOGA_Node_DLG_Message::FlowNode_GetDescription_Implementation() const
{
	return Text.ToString();
}

FLinearColor UOGA_Node_DLG_Message::FlowNode_GetColor_Implementation() const
{
	if (Text.IsEmpty())
	{
		return FLinearColor(0.5,0.4,0.4,0.5);
	}
	return FLinearColor(0.2,0.5,1,0.5);
}

void UOGA_Node_DLG_Message::GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed,
	FOmegaClassNamedLists& named_lists)
{
	IDataInterface_General::GetMetaConfig_Implementation(bitflags, guid, seed, named_lists);
	bitflags=Flags;
	named_lists=Lists;
}

