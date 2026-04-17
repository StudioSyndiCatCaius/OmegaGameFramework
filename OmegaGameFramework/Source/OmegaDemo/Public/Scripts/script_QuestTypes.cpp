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
			subsys->OnFlowNodeEntered.AddDynamic(script,&UOmegaQuestType_FlowAsset::L_OnFlowNodeEnter);
			subsys->OnFlowEventFinish.AddDynamic(script,&UOmegaQuestType_FlowAsset::L_OnFlowFinish);
			Instance->questContext=subsys->StartRootFlow(Instance,flow,data);
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
	FFlowAssetOverrideData in_dat;
	in_dat.StartingNodes.Append(data.active_guids);
	L_StartQuestFlow(this,Instance,Flow_Asset,in_dat);
}

TArray<UObject*> UOmegaQuestType_FlowAsset::GetActiveTasks_Implementation(AOmegaQuestInstance* Instance) const
{
	TArray<UObject*> out;
	if (UFlowAsset* f=L_GetFlowInstance())
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



bool L_FlowMatched(UOmegaQuestTypeScript* script, UFlowAsset* flow)
{
	if (UFlowAsset* flow_inst=Cast<UFlowAsset>(script->GetQuestInstance()->questContext))
	{
		if (flow->AssetGuid==flow_inst->AssetGuid)
		{
			return true;
		}
	}
	return false;
}

void UOmegaQuestType_FlowAsset::L_OnFlowNodeEnter(UFlowAsset* FlowAsset, UFlowNode* Node, FName Input)
{
	if (L_FlowMatched(this,FlowAsset))
	{
		GetQuestInstance()->WM->Quest_GetData(GetQuestInstance()->QuestAsset)->active_guids=FlowAsset->GetActiveNodeGuids();
	}
}

void UOmegaQuestType_FlowAsset::L_OnFlowFinish(UFlowAsset* FlowAsset, FName Output, const FString& Flag)
{
	if (L_FlowMatched(this,FlowAsset))
	{
		GetQuestInstance()->StopQuest(false);
	}
}
