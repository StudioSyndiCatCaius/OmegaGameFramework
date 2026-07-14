// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Actor_PlayerState.generated.h"

class UCombatantComponent;

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	
	AOmegaPlayerState();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components") UCombatantComponent* Combatant;
};
