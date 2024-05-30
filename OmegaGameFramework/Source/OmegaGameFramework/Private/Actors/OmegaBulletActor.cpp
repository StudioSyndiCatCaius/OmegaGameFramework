// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/OmegaBulletActor.h"
#include "Components/SphereComponent.h"
#include "Components/BillboardComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/CombatantComponent.h"
#include "Kismet/GameplayStatics.h"

AOmegaBulletActor::AOmegaBulletActor()
{
	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;

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
}

void AOmegaBulletActor::BeginPlay()
{
	local_spawnCue(CueOnSpawn);
	Super::BeginPlay();
}


void AOmegaBulletActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	TriggerImpact(OtherActor);
}

void AOmegaBulletActor::TriggerImpact(AActor* ImpactedActor)
{
	if(ImpactedActor)
	{
		//try get combatant
		UCombatantComponent* comb_target = local_getCombatant(ImpactedActor);
		
		OnImpact(ImpactedActor,comb_target);
		local_spawnCue(CueOnImpact);
		UOmegaScriptedEffectFunctions::ApplyCustomScriptedEffectToCombatant(ImpactEffects,comb_target,InstigatorCombatant);
		
		Destroy();
	}
}

void AOmegaBulletActor::local_spawnCue(TSubclassOf<AOmegaGameplayCue> cue)
{
	if(cue)
	{
		UOmegaGameplayCueFunctions::PlayGameplayCue(this,cue,GetActorTransform(),FHitResult(),nullptr);
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
