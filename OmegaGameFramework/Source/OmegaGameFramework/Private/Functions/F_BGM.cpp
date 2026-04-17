// Copyright Studio Syndicat 2021. All Rights Reserved.



#include "Functions/F_BGM.h"

#include "Functions/F_Common.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_World.h"


void UOmegaFunctions_BGM::Play(UObject* WorldContextObject, UOmegaBGM* BGM, FGameplayTag Slot, bool bFadePrevious)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		m->BGM_Play(BGM,Slot,bFadePrevious);
	}
}

void UOmegaFunctions_BGM::Pause(UObject* WorldContextObject, bool bPaused)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		m->BGM_Pause(bPaused);
	}
}

void UOmegaFunctions_BGM::Lock(UObject* WorldContextObject, bool bLocked)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		m->BGM_Lock(bLocked);
	}
}

void UOmegaFunctions_BGM::Stop(UObject* WorldContextObject, bool bFade, float FadeTime)
{
	if (UOmegaSubsystem_GameInstance* m=OGF_Subsystems::oGameInstance(WorldContextObject))
	{
		m->BGM_Stop(bFade,FadeTime);
	}
}
