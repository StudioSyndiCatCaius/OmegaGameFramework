// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "Components/ActorComponent.h"
#include "Component_Squad.generated.h"

class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSquadMembersChanged, UCombatantSquadComponent*, Component, UCombatantComponent*, Member, bool, bInSquad);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UCombatantSquadComponent : public UActorComponent
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FOnSquadMembersChanged OnSquadMembersChanged;

	UPROPERTY(VisibleInstanceOnly,Category="Squad")
	TArray<UCombatantComponent*> SquadMembers;
	
	UFUNCTION(BlueprintCallable,Category="Squad")
	TArray<UCombatantComponent*> GetSquadMembers();

	UFUNCTION(BlueprintCallable,Category="Squad")
	void SetCombatantInSquad(UCombatantComponent* Combatant, bool bInSquad);

	UFUNCTION(BlueprintCallable,Category="Squad")
	void SwapSquadMembers_ByIndex(int32 A, int32 B);
	
	UFUNCTION(BlueprintCallable,Category="Squad")
	void SwapSquadMembers_ByAsset(UPrimaryDataAsset* A, UPrimaryDataAsset* B);
	
	UFUNCTION(BlueprintCallable,Category="Squad")
	int32 GetMemberIndex_ByAsset(UPrimaryDataAsset* Asset);
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API USquadSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()


public:


	
};
