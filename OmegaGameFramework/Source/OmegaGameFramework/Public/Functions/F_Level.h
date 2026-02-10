// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"


#include "F_Level.generated.h"



class ALevelInstance;

UCLASS()
class UOmegaLevelFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Level")
	static bool IsLevelInstance_ReferenceValid(const ALevelInstance* LevelInstance);
	
	
};
