#include "script_StoryStates.h"

#include "Functions/F_Level.h"

void UStoryState_Sublevel::L_SetActive(UOmegaSaveSubsystem* ss, bool bActive)
{
	if (ss)
	{
		if (!bActive || ValidMainlevels.Contains(UOmegaLevelFunctions::GetPersistentWorldAssetSoft(ss)))
		{
			TArray<FName> lvlList=UOmegaLevelFunctions::Conv_WorldToNames(Sublevels);
			for (FName lvlName : lvlList)
			{
				UOmegaLevelFunctions::Sublevel_SetLoaded(ss,lvlName,bActive);
			}
		}
	}
}

void UStoryState_Sublevel::OnLevelChange_Implementation(UOmegaSaveSubsystem* SaveSubsystem,
	UOmegaStoryStateAsset* State, const FString& LevelName)
{
	if (SaveSubsystem->IsStoryStateActive(State))
	{
		L_SetActive(SaveSubsystem, true);
	}
}

void UStoryState_Sublevel::OnStateBegin_Implementation(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State)
{
	L_SetActive(SaveSubsystem, true);
}

void UStoryState_Sublevel::OnStateEnd_Implementation(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State)
{
	L_SetActive(SaveSubsystem, false);
}
