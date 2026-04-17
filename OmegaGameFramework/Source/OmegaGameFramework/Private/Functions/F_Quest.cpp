// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Functions/F_Quest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"

TArray<AOmegaQuestInstance*> UOmegaFunctions_Quest::GetAllActiveInstances(UObject* WorldContext)
{
	TArray<AOmegaQuestInstance*> out;
	if (UOmegaSubsystem_World* w=OGF_Subsystems::oWorld(WorldContext))
	{
		return w->WorldManager->quest_instances;
	}
	return out;
}

AOmegaQuestInstance* UOmegaFunctions_Quest::Start(UObject* WorldContext, UOmegaQuest* quest)
{
	if (UOmegaSubsystem_World* w=OGF_Subsystems::oWorld(WorldContext))
	{
		if (AOmegaWorldManager* wm=w->WorldManager.Get())
		{
			return wm->Quest_Start(quest);	
		}
	}
	return nullptr;
}


bool UOmegaFunctions_Quest::End(UObject* WorldContext, UOmegaQuest* quest, bool bComplete)
{
	if (UOmegaSubsystem_World* w=OGF_Subsystems::oWorld(WorldContext))
	{
		if (AOmegaWorldManager* wm=w->WorldManager.Get())
		{
			return wm->Quest_Stop(quest,!bComplete);	
		}
	}
	return false;
}

bool UOmegaFunctions_Quest::CheckCondition(UObject* WorldContext, UOmegaQuest* in, EOmegaQuestConditionType Condition)
{
	if (UOmegaSubsystem_World* w=OGF_Subsystems::oWorld(WorldContext))
	{
		if (AOmegaWorldManager* wm=w->WorldManager.Get())
		{
			switch (Condition) {
			case QuestFilter_Startable:
				return wm->Quest_CanStart(in);
			case QuestFilter_Active:
				return wm->Quest_GetStatus(in)==QuestStatus_Active;
			case QuestFilter_Complete:
				return wm->Quest_GetStatus(in)==QuestStatus_Complete;
			}
		}
	}
	
	return false;
}

TArray<UOmegaQuest*> UOmegaFunctions_Quest::Filter(UObject* WorldContext, TArray<UOmegaQuest*> in, EOmegaQuestConditionType Condition, bool NOT)
{
	TArray<UOmegaQuest*> out;
	for (auto* i : in)
	{
		if (CheckCondition(WorldContext,i,Condition)!=NOT)
		{
			out.Add(i);
		}
	}
	return out;
}
