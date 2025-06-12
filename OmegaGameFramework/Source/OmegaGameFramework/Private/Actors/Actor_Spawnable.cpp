// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Spawnable.h"

#include "Components/BillboardComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UOmegaActorSpawnableModifer::OnActorSetup_Implementation(AActor* Actor, AOmegaActorSpawnable* Spawnable) const
{
}

void UOmegaActorSpawnableModifer::OnActorSpawned_Implementation(AActor* Actor, AOmegaActorSpawnable* Spawnable) const
{
}

AActor* UOmegaActorSpawnableScript::AttemptSpawn_Implementation(AOmegaActorSpawnable* OwningActor) const
{
	return nullptr;
}

AActor* UOmegaActorSpawnableScript_Simple::AttemptSpawn_Implementation(AOmegaActorSpawnable* OwningActor) const
{
	if(Possibles.IsValidIndex(0))
	{
		TSoftClassPtr<AActor> _inClass=Possibles[UKismetMathLibrary::RandomInteger(Possibles.Num()-1)];
		if(_inClass)
		{
			AActor* out = OwningActor->GetWorld()->SpawnActorDeferred<AActor>(_inClass.LoadSynchronous(),FTransform());
			out->FinishSpawning(OwningActor->GetTransform());
			return Super::AttemptSpawn_Implementation(OwningActor);
		}
	}
	return nullptr;
}

AOmegaActorSpawnable::AOmegaActorSpawnable()
{
	RootComponent=CreateDefaultSubobject<UBillboardComponent>("ROOT");
	USphereComponent* _range=CreateOptionalDefaultSubobject<USphereComponent>("Range");
	_range->SetupAttachment(RootComponent);

	//Script=NewObject<UOmegaActorSpawnableScript>(this,UOmegaActorSpawnableScript_Simple::StaticClass());
}

void AOmegaActorSpawnable::BeginPlay()
{
	if(Autospawn)
	{
		AActor* out;
		AttemptSpawn(true,out);
	}
	Super::BeginPlay();
}

bool AOmegaActorSpawnable::AttemptSpawn(bool bForceRespawn,AActor*& Actor)
{
	if(SpawnChance<1.0 && UKismetMathLibrary::RandomFloat()>SpawnChance)
	{
		return false;
	}
	Actor=nullptr;
	if(bForceRespawn && LinkedActor_IsAlive())
	{
		REF_linkedActor->K2_DestroyActor();
	}
	if(!LinkedActor_IsAlive() and Script)
	{
		if(AActor* _newActor = Script->AttemptSpawn(this))
		{
			REF_linkedActor=_newActor;
			Actor=REF_linkedActor;
			for(auto* m : Modifiers)
			{
				if(m) { m->OnActorSetup(Actor,this);}
			}
			REF_linkedActor->FinishSpawning(GetTransform());
			for(auto* m : Modifiers)
			{
				if(m) { m->OnActorSpawned(Actor,this);}
			}
			return true;
		}
	}
	return false;
}

bool AOmegaActorSpawnable::LinkedActor_IsAlive() const
{
	if(REF_linkedActor && !REF_linkedActor->IsActorBeingDestroyed())
	{
		return true;
	}
	return false;
}
