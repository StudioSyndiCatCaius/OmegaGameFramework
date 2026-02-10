// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Level.h"

#include "LevelInstance/LevelInstanceActor.h"

bool UOmegaLevelFunctions::IsLevelInstance_ReferenceValid(const ALevelInstance* LevelInstance)
{
	if(LevelInstance)
	{
		return LevelInstance->GetWorldAsset().IsValid();
	}
	return false;
}



