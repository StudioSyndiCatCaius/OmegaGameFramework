// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "I_GameplayState.generated.h"

class AActor;

UINTERFACE(DisplayName="♎Actor🔵 - 🎮Gameplay Modifier") class UDataInterface_GameplayModifier : public UInterface
{
	GENERATED_BODY()
public:
};

class OMEGAGAMEFRAMEWORK_API IDataInterface_GameplayModifier
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, Category="♎I|🎮Gameplay Modifier",DisplayName="🎮Gameplay Modifier - Blocked System Tags")
	FGameplayTagContainer GameplayModifier_BlockedSystemTags();

};