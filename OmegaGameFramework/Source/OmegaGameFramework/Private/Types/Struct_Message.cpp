// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Types/Struct_Message.h"

#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Subsystems/Subsystem_World.h"


FSlateBrush UOmegaGameplayMessage::GetMessagePortrait(UObject* WorldContext) const
{
	return OGF_GAME_CORE()->Message_GetPortrait(WorldContext,this);
}

bool UOmegaGameplayMessage::End()
{
	if (subsytem_ref)
	{
		return subsytem_ref->Message_End(this);
	}
	return false;
}
