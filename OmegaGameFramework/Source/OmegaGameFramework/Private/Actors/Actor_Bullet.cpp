// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Bullet.h"

#include "Actors/Actor_GameplayCue.h"
#include "Components/SphereComponent.h"
#include "Components/BillboardComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/Component_Combatant.h"
#include "Kismet/GameplayStatics.h"

AOmegaBulletActor::AOmegaBulletActor()
{
	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize components
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;

	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComponent"));
	BillboardComponent->SetupAttachment(RootComponent);

	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	ProjectileComponent->UpdatedComponent = RootComponent;
	ProjectileComponent->InitialSpeed=1000;
	ProjectileComponent->MaxSpeed=1000;
	ProjectileComponent->ProjectileGravityScale=0;

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AOmegaBulletActor::OnSphereOverlap);
	SphereComponent->OnComponentHit.AddDynamic(this,&AOmegaBulletActor::OnSphereHit);	
}

void AOmegaBulletActor::BeginPlay()
{
	local_spawnCue(CueOnSpawn,FHitResult());
	if (InstigatorCombatant)
	{
		SphereComponent->IgnoreActorWhenMoving(InstigatorCombatant->GetOwner(),true);
	}
	if (GetInstigator()) { SphereComponent->IgnoreActorWhenMoving(GetInstigator(),true); }
	Super::BeginPlay();
}


void AOmegaBulletActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	FHitResult _hit;
	if (bImpactOnOverlap) { Native_Impact(OtherActor,_hit);}
}

void AOmegaBulletActor::OnSphereHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (bImpactOnHit) { Native_Impact(OtherActor,Hit);}
}

void AOmegaBulletActor::Native_Impact(AActor* ImpactedActor, FHitResult HitResult)
{
	if (bHandlingImpact) { return; }
	if (ImpactedActor && (!InstigatorCombatant || ImpactedActor!=InstigatorCombatant->GetOwner()))
	{
		bHandlingImpact = true;
		TriggerImpact(ImpactedActor,HitResult);
		bHandlingImpact = false;
	}
}

void AOmegaBulletActor::TriggerImpact(AActor* ImpactedActor, FHitResult HitResult)
{
	if(ImpactedActor)
	{
		//try get combatant
		UCombatantComponent* comb_target = local_getCombatant(ImpactedActor);
		
		impactCount+=1;
		OnImpact(ImpactedActor,comb_target);
		local_spawnCue(CueOnImpact,HitResult);
		UOmegaScriptedEffectFunctions::ApplyCustomScriptedEffectToCombatant(ImpactEffects,comb_target,InstigatorCombatant);
		
		if (ImpactDestroy!=0 && impactCount>=ImpactDestroy)
		{
			Destroy();
		}
	}
}

void AOmegaBulletActor::local_spawnCue(FOmegaGameplayCueConfig cue, FHitResult HitResult)
{
	if(cue.CueClass)
	{
		UOmegaGameplayCueFunctions::PlayGameplayCue_FromConfig(this,cue,GetActorTransform(),HitResult,nullptr);
	}
}

UCombatantComponent* AOmegaBulletActor::local_getCombatant(AActor* actor)
{
	if(UCombatantComponent* temp_comb = Cast<UCombatantComponent>(actor->GetComponentByClass(UCombatantComponent::StaticClass())))
	{
		return temp_comb;
	}
	return nullptr;
}

void UOmegaBulletFunctions::SpawnBullet(UObject* WorldContextObject, TSubclassOf<AOmegaBulletActor> Bullet,
	FTransform Origin, FOmegaCustomScriptedEffects Effects, UCombatantComponent* Instigator)
{
	if(Bullet)
	{
		AOmegaBulletActor* CueRef = WorldContextObject->GetWorld()->SpawnActorDeferred<AOmegaBulletActor>(Bullet, Origin, nullptr);
		CueRef->InstigatorCombatant=Instigator;
		CueRef->ImpactEffects=Effects;
		UGameplayStatics::FinishSpawningActor(CueRef, Origin);
		
	}
}
