// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Ability_Dodge.h"

#include "GameFramework/Character.h"
#include "Gameplay/CombatantFunctions.h"


// Sets default values
AAbility_Dodge::AAbility_Dodge()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbility_Dodge::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAbility_Dodge::Native_AbilityActivated(UObject* Context)
{
	if(GetDodgeMontage())
	{
		UAnimInstance* AnimInstRef = GetAbilityOwnerMesh()->GetAnimInstance();
		
	}
	Super::Native_AbilityActivated(Context);
}

// Called every frame
void AAbility_Dodge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbility_Dodge::SetDodgeEffectsActive(bool EffectsActive)
{
	if(EffectsActive==bDodgeEffectsActive)
	{
		return;
	}
	EffectsActive=bDodgeEffectsActive;
	if(bDodgeEffectsActive)
	{
		for(FOmegaEffectContainer TempEffect : DodgeEffects)
		{
			AOmegaGameplayEffect* NewEffect = CombatantOwner->CreateEffect(TempEffect.EffectClass, TempEffect.Power, GetActorTransform(), CombatantOwner, TempEffect.AddedTags, this);
			EffectList.Add(NewEffect);
		}
	}
	else
	{
		for(auto* TempEffect: EffectList)
		{
			if(TempEffect)
			{
				TempEffect->Destroy();
			}
		}
	}
}


