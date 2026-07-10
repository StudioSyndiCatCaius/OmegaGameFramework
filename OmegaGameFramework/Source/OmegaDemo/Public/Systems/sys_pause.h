// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "GameFramework/Actor.h"
#include "sys_pause.generated.h"

class UCombatantComponent;
class UOmegaCombatEncounter_Component;
class UTurnBasedManagerComponent;

//Stops the Exploration Mode
UCLASS(Abstract,DisplayName="♎ System - Pause")
class OMEGADEMO_API AOmegaDemoSystem_Pause : public AOmegaGameplaySystem
{
	GENERATED_BODY()
public:
	AOmegaDemoSystem_Pause();

};


//Stops the Exploration Mode AND pauses game time
UCLASS(Abstract,DisplayName="♎ System - Menu")
class OMEGADEMO_API AOmegaDemoSystem_Menu : public AOmegaGameplaySystem
{
	GENERATED_BODY()

public:

	AOmegaDemoSystem_Menu();

protected:

	virtual void BeginPlay() override;

public:
	virtual void SystemActivated_Implementation(UObject* Context, const FString& Flag) override;
	virtual void SystemShutdown_Implementation(UObject* Context, const FString& Flag) override;
	
	void L_SetState(bool bPause);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config") bool bFullGamePause;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config") FGameplayTagContainer PauseActorTags;
};

