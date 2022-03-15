// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameplayEffect.h"
#include "TimerManager.h"
#include "Kismet/KismetSystemLibrary.h"



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
	case EEffectLifetime::EffectLifetime_OnDestroy:
		//Do code
		break;
	default: break;
	}

	//CorrectContext
	if(!EffectContext)
	{
		EffectContext = GetOwner();
	}

	
	EffectBeginPlay(EffectContext);

}

//Trigger the Effect
void AOmegaGameplayEffect::LifetimeEnd()
{
	
	TriggerEffect();
	K2_DestroyActor();
}


//Run Damage Calculation
float AOmegaGameplayEffect::CalculateDamageValue()
{
	float LocalDamage;
	LocalFormula->GetDamageAmount(CombatantInstigator, TargetedCombatant, LocalDamage);
	LocalDamage = LocalDamage * Power;
	return LocalDamage;
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
	EffectApplied(CalculateDamageValue());
	OnEffectTriggered.Broadcast(this, CalculateDamageValue());
	UE_LOG(LogTemp, Display, TEXT("Applied Effect"));
	
	if(EffectLifetime == EEffectLifetime::EffectLifetime_OnTrigger)
	{
		K2_DestroyActor();
	}
	
}


//Tags
FGameplayTag AOmegaGameplayEffect::GetObjectGameplayCategory_Implementation()
{
	return EffectCategory;
}

FGameplayTagContainer AOmegaGameplayEffect::GetObjectGameplayTags_Implementation()
{
	return EffectTags;
}
