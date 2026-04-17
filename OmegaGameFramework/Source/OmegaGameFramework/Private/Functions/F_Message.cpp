// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Message.h"

#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/Subsystem_World.h"


UOmegaSubsystem_World* L_GetWorldSub(UObject* WorldContext)
{
	if (WorldContext && WorldContext->GetWorld())
	{
		return WorldContext->GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
	}
	return nullptr;
}


UOmegaGameplayMessage* UOmegaFunctions_Message::Send(UObject* WorldContextObject, UObject* Instigator, FText Text,
	FGameplayTag CategoryTag, FOmegaGameplayMessageMeta meta)
{
	if (UOmegaSubsystem_World* w=L_GetWorldSub(WorldContextObject))
	{
		return w->Message_Send(Instigator, Text, CategoryTag, meta);
	}
	return nullptr;
}

bool UOmegaFunctions_Message::Finish(UObject* WorldContextObject, FGameplayTag CategoryTag)
{
	if (UOmegaSubsystem_World* w=L_GetWorldSub(WorldContextObject))
	{
		if (UOmegaGameplayMessage* ms=w->Message_GetFirstOfCategory(CategoryTag))
		{
			ms->End();
		}
	}
	return false;
}

UOmegaGameplayMessage* UOmegaFunctions_Message::GetCurrent(UObject* WorldContextObject, FGameplayTag CategoryTag)
{
	if (UOmegaSubsystem_World* w=L_GetWorldSub(WorldContextObject))
	{
		return w->Message_GetFirstOfCategory(CategoryTag);
	}
	return nullptr;
}
