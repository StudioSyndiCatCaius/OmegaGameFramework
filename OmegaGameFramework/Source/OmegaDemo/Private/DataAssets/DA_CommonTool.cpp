// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_CommonTool.h"

#include "OmegaSettings_Demo.h"

UOAsset_CommonTool::UOAsset_CommonTool()
{
	for (uint8 i = (uint8)EOmegaToolEvents::ToolEvent_Equip; i <= (uint8)EOmegaToolEvents::ToolEvent_Trigger; i++)
	{
		EOmegaToolEvents Event = (EOmegaToolEvents)i;
		if (!EventAssets.Contains(Event))
		{
			EventAssets.Add(Event,FOmegaTool_EventAssets());
		}
	}
}

bool UOAsset_CommonTool::Tool_CanTrigger_Implementation(AOmegaToolActor* Tool)
{
	return IDataInterface_Tool::Tool_CanTrigger_Implementation(Tool);
}

int32 UOAsset_CommonTool::Tool_OnActivate_Implementation(AOmegaToolActor* Tool, bool bActivated)
{
	return IDataInterface_Tool::Tool_OnActivate_Implementation(Tool, bActivated);
}

int32 UOAsset_CommonTool::Tool_OnTrigger_Implementation(AOmegaToolActor* Tool)
{
	return IDataInterface_Tool::Tool_OnTrigger_Implementation(Tool);
}

int32 UOAsset_CommonTool::ToolActor_BeginPlay_Implementation(AOmegaToolActor* Tool)
{
	return IDataInterface_Tool::ToolActor_BeginPlay_Implementation(Tool);
}

void UOAsset_CommonTool::GetTool_EventAssets_Implementation(EOmegaToolEvents Animation, FOmegaTool_EventAssets& Assets)
{
	if (EventAssets.Contains(Animation))
	{
		Assets=EventAssets[Animation];
	}
}

TSubclassOf<AOmegaToolActor> UOAsset_CommonTool::GetToolActorClass_Implementation()
{
	if (ToolActorClass)
	{
		return ToolActorClass;
	}
	if (TSubclassOf<AOmegaToolActor> tcls=GetMutableDefault<UOmegaSettings_Demo>()->Default_ToolActor.LoadSynchronous())
	{
		return tcls;
	}
	return nullptr;
}
