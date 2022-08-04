// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/GameSystem_TurnBasedCombat.h"




// Sets default values
AGameSystem_TurnBasedCombat::AGameSystem_TurnBasedCombat()
{
	//COMPONENTS
	CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	TurnManager = CreateDefaultSubobject<UTurnBasedManagerComponent>(TEXT("Turn Manager"));
	
	
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameSystem_TurnBasedCombat::BeginPlay()
{
	Super::BeginPlay();
	//TURN SETUP
	TurnManager->OnTurnStart.AddDynamic(this, &AGameSystem_TurnBasedCombat::OnTurnBegin);
	
}

// Called every frame
void AGameSystem_TurnBasedCombat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameSystem_TurnBasedCombat::OnTurnBegin(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer GameplayTags)
{
	Combatant->GrantAbility(TurnAbility);
	bool LocalSuccess;
	AOmegaAbility* TempAbility = Combatant->ExecuteAbility(TurnAbility, this, LocalSuccess);
	if(!LocalSuccess)
	{
		return;
	}
	TempAbility->OnAbilityFinished.AddDynamic(this, &AGameSystem_TurnBasedCombat::AGameSystem_TurnBasedCombat::TurnAbilityFinish);
}

void AGameSystem_TurnBasedCombat::TurnAbilityFinish(bool Cancelled)
{
	
}

void AGameSystem_TurnBasedCombat::TryAdvanceTurn()
{
}

