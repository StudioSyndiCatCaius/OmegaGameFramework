// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "GameFramework/Actor.h"
#include "sys_exploration.generated.h"

class UCombatantComponent;
class UOmegaCombatEncounter_Component;
class UTurnBasedManagerComponent;

UCLASS(Abstract,DisplayName="♎ System - Exploration")
class OMEGADEMO_API AOmegaDemoSystem_Exploration : public AOmegaGameplaySystem
{
	GENERATED_BODY()

public:

	AOmegaDemoSystem_Exploration();

protected:

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SystemActivated_Implementation(UObject* Context, const FString& Flag) override;
	
	virtual void OnInputAction_Begin_Implementation(APlayerController* Player, FGameplayTag Action, FVector axis) override;
	virtual void OnInputAction_End_Implementation(APlayerController* Player, FGameplayTag Action, FVector axis) override;
	virtual void OnInputAction_Update_Implementation(APlayerController* Player, FGameplayTag Action, float DeltaTime, FVector axis) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config") bool bEnableInput_Move=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config") bool bEnableInput_CameraControl=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config|Inputs") FGameplayTag TagTarget_Interact=FGameplayTag::RequestGameplayTag("TARGET.Interactable");
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config|Inputs") FGameplayTag InteractTag=FGameplayTag::RequestGameplayTag("INTERACTION.Default");
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config|Inputs") FGameplayTag Input_Move=FGameplayTag::RequestGameplayTag("INPUT.Game.Move");
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config|Inputs") FGameplayTag Input_Camera=FGameplayTag::RequestGameplayTag("INPUT.Game.Control");
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Config|Inputs") FGameplayTag Input_Interact=FGameplayTag::RequestGameplayTag("INPUT.Game.Interact");
};


