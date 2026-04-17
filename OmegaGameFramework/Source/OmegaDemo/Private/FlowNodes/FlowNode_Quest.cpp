// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Quest.h"

#include "Actors/Actor_Quest.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"

void UFlowNode_QuestStart::L_QuestEnd(AOmegaQuestInstance* comp, UOmegaQuest* q)
{
	if(q==Quest.LoadSynchronous())
	{
		TriggerOutput(TEXT("Finish"),true);
	}
}

UFlowNode_QuestStart::UFlowNode_QuestStart()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Start")));
	OutputPins.Add(FFlowPin(TEXT("Finish")));
	OutputPins.Add(FFlowPin(TEXT("FailedStart")));
}

void UFlowNode_QuestStart::ExecuteInput(const FName& PinName)
{
	if(UOmegaQuest* q=Quest.LoadSynchronous())
	{
		if (UOmegaSubsystem_World* ss_world=OGF_Subsystems::oWorld(this))
		{
			if (AOmegaQuestInstance* inst=ss_world->WorldManager->Quest_Start(q))
			{
				QuestInstance=inst;
				TriggerOutput(TEXT("Start"),true);
				ss_world->OnQuest_End.AddDynamic(this,&UFlowNode_QuestStart::L_QuestEnd);
					
				Super::ExecuteInput(PinName);
				return;
			}
			OGF_Log::Error("Failed to Start quest FlowNode: could not start quest");
		}
		else
		{
			OGF_Log::Error("Failed to Start quest FlowNode: World subsystem is invalid");
		}
	}
	else
	{
		OGF_Log::Error("Failed to Start quest FlowNode: no valid quest asset");
		Finish();
	}
	TriggerOutput(TEXT("FailedStart"),true);
	Super::ExecuteInput(PinName);
}

#if WITH_EDITOR
FString UFlowNode_QuestStart::GetNodeDescription() const
{
	return Super::GetNodeDescription();
}
#endif


UFlowNode_QuestState::UFlowNode_QuestState()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Unstarted")));
	OutputPins.Add(FFlowPin(TEXT("Active")));
	OutputPins.Add(FFlowPin(TEXT("Complete")));
	OutputPins.Add(FFlowPin(TEXT("Failed")));
}

void UFlowNode_QuestState::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	
	EOmegaQuestStatus QuestStatus=OGF_Subsystems::oWorld(this)->WorldManager->Quest_GetStatus(Quest.LoadSynchronous());
	
	switch(QuestStatus)
	{
	case QuestStatus_Unstarted:
		TriggerOutput(TEXT("Unstarted"),true);
		break;
	case QuestStatus_Active:
		TriggerOutput(TEXT("Active"),true);
		break;
	case QuestStatus_Complete:
		TriggerOutput(TEXT("Complete"),true);
		break;
	case QuestStatus_Failed:
		TriggerOutput(TEXT("Failed"),true);
		break;
	}
}
#if WITH_EDITOR
FString UFlowNode_QuestState::GetNodeDescription() const
{
	if (UOmegaQuest* q=Quest.LoadSynchronous())
	{
		return "Quest State: "+q->GetName()+" Is.. ";
	}
	return Super::GetNodeDescription();
}
#endif
