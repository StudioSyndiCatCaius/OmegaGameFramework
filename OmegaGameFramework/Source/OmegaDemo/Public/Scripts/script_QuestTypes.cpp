#include "script_QuestTypes.h"

#include "FlowAsset.h"
#include "FlowSubsystem.h"
#include "Functions/F_Common.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"


void L_StartQuestFlow(const UOmegaQuestType_FlowAsset* script, AOmegaQuestInstance* Instance, UFlowAsset* flow, FFlowAssetOverrideData data)
{
	if (flow)
	{
		if (UFlowSubsystem* subsys=Instance->GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>())
		{
			OGF_Log::LogInfo(FString::Printf(TEXT("QUEST_FLOW_START: '%s' | bOverrideStartingNodes=%s | StartingNodes=%d"),
				*Instance->GetName(),
				data.bOverrideStartingNodes ? TEXT("true") : TEXT("false"),
				data.StartingNodes.Num()));
			subsys->OnFlowNodeEntered.AddDynamic(script,&UOmegaQuestType_FlowAsset::L_OnFlowNodeEnter);
			subsys->OnFlowEventFinish.AddDynamic(script,&UOmegaQuestType_FlowAsset::L_OnFlowFinish);
			Instance->questContext=subsys->StartRootFlow(Instance,flow,data);
			OGF_Log::LogInfo(FString::Printf(TEXT("QUEST_FLOW_START: StartRootFlow result = %s"),
				Instance->questContext ? TEXT("SUCCESS") : TEXT("NULL (owner already in RootInstances?)")));
		}
	}
	else
	{
		OGF_Log::Error("Could not start quest instance: "+Instance->GetName()+" -- Quest asset was invalid.");
	}
}

UFlowAsset* UOmegaQuestType_FlowAsset::L_GetFlowInstance() const
{
	if (!GetQuestInstance()) { return nullptr; }
	if (UFlowAsset* flow_inst=Cast<UFlowAsset>(GetQuestInstance()->questContext))
	{
		return flow_inst;
	}
	return nullptr;
}

void UOmegaQuestType_FlowAsset::OnQuestStart_Implementation(AOmegaQuestInstance* Instance) const
{
	L_StartQuestFlow(this,Instance,Flow_Asset,FFlowAssetOverrideData());
}

void UOmegaQuestType_FlowAsset::OnLoad_Implementation(AOmegaQuestInstance* Instance, FOmegaQuestData data) const
{
	OGF_Log::LogInfo(FString::Printf(TEXT("QUEST_LOAD: '%s' - saved active_guids count: %d | bOverride will be: %s"),
		*Instance->GetName(), data.active_guids.Num(), data.active_guids.IsEmpty() ? TEXT("false (start from Start)") : TEXT("true (resume from saved nodes)")));
	for (const FGuid& g : data.active_guids)
	{
		OGF_Log::LogInfo(FString::Printf(TEXT("QUEST_LOAD:   GUID -> %s"), *g.ToString()));
	}

	FFlowAssetOverrideData in_dat;
	if (!data.active_guids.IsEmpty())
	{
		in_dat.bOverrideStartingNodes = true;
		in_dat.StartingNodes.Append(data.active_guids);
	}
	L_StartQuestFlow(this,Instance,Flow_Asset,in_dat);
}

TArray<UObject*> UOmegaQuestType_FlowAsset::GetActiveTasks_Implementation(AOmegaQuestInstance* Instance) const
{
	TArray<UObject*> out;
	if (UFlowAsset* f=Cast<UFlowAsset>(Instance->questContext))
	{
		for (auto* node : f->GetActiveNodes())
		{
			if (node)
			{
				FText _desc=UOmegaGameFrameworkBPLibrary::GetObjectDisplayDescription(node,FGameplayTag());
			
				if (!_desc.IsEmpty())
				{
					out.Add(node);
				}
			}
		}
	}
	
	return out;
}

bool L_FlowMatched(UOmegaQuestType_FlowAsset* script, UFlowAsset* flow)
{
	if (!script || !script->Flow_Asset) { return false; }
	if (flow->AssetGuid==script->Flow_Asset->AssetGuid)
	{
		return true;
	}
	return false;
}

void UOmegaQuestType_FlowAsset::OnEndPlay_Implementation(AOmegaQuestInstance* Instance) const
{
	if (UFlowSubsystem* subsys = Instance->GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>())
	{
		subsys->OnFlowNodeEntered.RemoveDynamic(this, &UOmegaQuestType_FlowAsset::L_OnFlowNodeEnter);
		subsys->OnFlowEventFinish.RemoveDynamic(this, &UOmegaQuestType_FlowAsset::L_OnFlowFinish);
		subsys->FinishRootFlow(Instance, EFlowFinishPolicy::Abort);
	}
}

void UOmegaQuestType_FlowAsset::L_OnFlowNodeEnter(UFlowAsset* FlowAsset, UFlowNode* Node, FName Input)
{
	if (L_FlowMatched(this,FlowAsset))
	{
		TArray<FGuid> guids = FlowAsset->GetActiveNodeGuids();
		OGF_Log::LogInfo(FString::Printf(TEXT("QUEST_GUID_SAVE: Node entered '%s' | Saving %d active GUID(s)"),
			Node ? *Node->GetClass()->GetName() : TEXT("NULL"), guids.Num()));
		for (const FGuid& g : guids)
		{
			OGF_Log::LogInfo(FString::Printf(TEXT("QUEST_GUID_SAVE:   GUID -> %s"), *g.ToString()));
		}
		L_GetQuestData()->active_guids = guids;
	}
}

void UOmegaQuestType_FlowAsset::L_OnFlowFinish(UFlowAsset* FlowAsset, FName Output, const FString& Flag)
{
	if (L_FlowMatched(this,FlowAsset))
	{
		GetQuestInstance()->StopQuest(false);
	}
}
