// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameplayEffect.h"
#include "TimerManager.h"


// Sets default values
AOmegaGameplayEffect::AOmegaGameplayEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOmegaGameplayEffect::BeginPlay()
{
	Super::BeginPlay();

	//Construct DamageFormula Object
	LocalFormula = NewObject<UDamageFormula>(this, DamageFormula, FName("LocalFormula"));

	//Select What Lifetime to use.
	switch (EffectLifetime)
	{
	case EEffectLifetime::EffectLifetime_Instant:
		GetWorldTimerManager().SetTimer(LifetimeTimer, this, &AOmegaGameplayEffect::LifetimeEnd, 0.01f, false);
		break;

	case EEffectLifetime::EffectLifetime_Timer:
		GetWorldTimerManager().SetTimer(LifetimeTimer, this, &AOmegaGameplayEffect::LifetimeEnd, Lifetime, false);
		break;
	case EEffectLifetime::EffectLifetime_OnTrigger:
		//Do code
		break;

	default: break;
	}

	EffectBeginPlay(CombatantInstigator, TargetActor);

}

//Trigger the Effect
void AOmegaGameplayEffect::LifetimeEnd()
{
	
	TriggerEffect();

}

//Run Damage Calculation
void AOmegaGameplayEffect::CalculateDamageValue(float Multiplier, class UObject* DamageInstigator, class UObject* DamageTarget, float& Damage)
{
	float LocalDamage;
	LocalFormula->GetDamageAmount(DamageInstigator, DamageTarget, LocalDamage);
	Damage = LocalDamage;
}

// Called every frame
void AOmegaGameplayEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorldTimerManager().IsTimerActive(LifetimeTimer))
	{
		PastLifetime = GetWorldTimerManager().GetTimerElapsed(LifetimeTimer);
		RemainingLifetime = GetWorldTimerManager().GetTimerRemaining(LifetimeTimer);

		LifetimeUpdated(PastLifetime, RemainingLifetime);
	};
}

//Trigger the effects and destory this Effect Actor.
void AOmegaGameplayEffect::TriggerEffect()
{
	EffectApplied();
	K2_DestroyActor();
}



