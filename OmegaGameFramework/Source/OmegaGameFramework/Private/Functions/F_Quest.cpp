// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Functions/F_Quest.h"

bool UOmegaFunctions_Quest::Start(UObject* WorldContext, UOmegaQuest* quest)
{
	if (quest && WorldContext && WorldContext->GetWorld()->GetGameInstance())
	{
		if (UOmegaQuestSubsystem* _subsys=WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>())
		{
			if (UOmegaQuestComponent* comp=_subsys->GetQuest_FirstWithAsset(quest))
			{
				return comp->StartQuest(quest);
			}
		}
	}
	return false;
}


bool UOmegaFunctions_Quest::End(UObject* WorldContext, UOmegaQuest* quest, bool bComplete)
{
	if (quest && WorldContext && WorldContext->GetWorld()->GetGameInstance())
	{
		if (UOmegaQuestSubsystem* _subsys=WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>())
		{
			if (UOmegaQuestComponent* comp=_subsys->GetQuest_FirstWithAsset(quest))
			{
				return comp->EndQuest(bComplete);
			}
		}
	}
	return false;
}

bool UOmegaFunctions_Quest::CheckCondition(UObject* WorldContext, UOmegaQuest* in, EOmegaQuestConditionType Condition)
{
	if (in && WorldContext && WorldContext->GetWorld()->GetGameInstance())
	{
		if (UOmegaQuestSubsystem* _subsys=WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaQuestSubsystem>())
		{
			if (UOmegaQuestComponent* comp=_subsys->GetQuest_FirstWithAsset(in))
			{
				switch (Condition) {
				case QuestFilter_Startable:
					return comp->CanQuestStart();
				case QuestFilter_Active:
					return comp->IsQuestActive();
				case QuestFilter_Complete:
					return comp->IsQuestComplete();
				}	
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
