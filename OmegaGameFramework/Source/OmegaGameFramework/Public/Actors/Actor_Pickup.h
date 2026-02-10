// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Pickup.generated.h"

class AOmegaGameplayCue;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaPickupActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaPickupActor();

	UPROPERTY() FVector move_origin;
	UPROPERTY() APawn* pawn_target;
	UPROPERTY() APlayerController* controller_target;
	UPROPERTY() float move_to_actor_time;
	UPROPERTY() bool is_picking_up;
	void pickup_finish();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintImplementableEvent,Category="Pickup")
	bool CanPickup(APawn* Pawn, APlayerController* Controller);

	UFUNCTION(BlueprintImplementableEvent,Category="Pickup")
	void OnPickup(APawn* Pawn, APlayerController* Controller);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Pickup")
	TSubclassOf<AOmegaGameplayCue> PickupCue;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Pickup")
	bool MoveToActorOnPickup;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Pickup")
	float MoveToActorDuration=0.2;
};
