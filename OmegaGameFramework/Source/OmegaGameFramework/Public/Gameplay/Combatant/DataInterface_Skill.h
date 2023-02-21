// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Interface.h"
#include "DataInterface_Skill.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_Skill : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IDataInterface_Skill
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, Category="Combatant")
	TSubclassOf<UCombatantFilter> GetSkillTargetFilter(); 
};
