// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/OmegaPickupActor.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
AOmegaPickupActor::AOmegaPickupActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AOmegaPickupActor::pickup_finish()
{
	if(is_picking_up)
	{
		is_picking_up=false;
		OnPickup(pawn_target,controller_target);
		if(PickupCue)
		{
			GetWorld()->GetSubsystem<UOmegaGameplayCueSubsystem>()->PlayGameplayCue(PickupCue,GetActorTransform(),FHitResult());
		}
		K2_DestroyActor();
	}
}

// Called when the game starts or when spawned
void AOmegaPickupActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AOmegaPickupActor::Tick(float DeltaTime)
{
	if(pawn_target && is_picking_up)
	{
		if(MoveToActorOnPickup)
		{
			move_to_actor_time=DeltaTime+move_to_actor_time;
			SetActorLocation(UKismetMathLibrary::VLerp(move_origin,pawn_target->GetActorLocation(),move_to_actor_time/MoveToActorDuration));
			if(move_to_actor_time>=MoveToActorDuration)
			{
				pickup_finish();
			}
		}
		else
		{
			pickup_finish();
		}
	}
	Super::Tick(DeltaTime);
}

void AOmegaPickupActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(APawn* pawn_ref = Cast<APawn>(OtherActor))
	{
		if(APlayerController* controller_ref = Cast<APlayerController>(pawn_ref->GetController()))
		{
			if(CanPickup(pawn_ref,controller_ref))
			{
				pawn_target=pawn_ref;
				controller_target=controller_ref;
				move_origin=GetActorLocation();
				is_picking_up=true;
			}
		}
	}
	Super::NotifyActorBeginOverlap(OtherActor);
}

