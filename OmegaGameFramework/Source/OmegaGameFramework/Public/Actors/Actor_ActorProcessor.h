// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Actor_ActorProcessor.generated.h"




UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaActorProcessor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly,Category="ActorProcessor",DisplayName="Registered Actors") TArray<AActor*> REF_TrackedActors;

public:

	UPROPERTY(EditAnywhere,Category="ActorProcessor") bool Register_OverlapEvents;
	UPROPERTY(EditAnywhere,Category="ActorProcessor") bool Register_HitEvents;
	UPROPERTY(EditAnywhere,Category="ActorProcessor") bool Register_CursorEvents;

	UFUNCTION(BlueprintCallable,Category="ActorProcessor")
	TArray<AActor*> GetRegisteredActors();
	
	UFUNCTION(BlueprintCallable,Category="ActorProcessor")
	void SetActorRegisteredToProcessor(AActor* Actor, bool bIsRegistered);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorRegistered(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorUnregistered(AActor* Actor);



	// Overlap events
	UFUNCTION(BlueprintImplementableEvent,Category="ActorProcessor",DisplayName="Registered Actor - Begin Overlap")
	void OnRegistered_ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION(BlueprintImplementableEvent,Category="ActorProcessor")
	void OnRegistered_ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
	// Hit event
	UFUNCTION(BlueprintImplementableEvent,Category="ActorProcessor")
	void OnRegistered_ActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
	// Mouse events
	UFUNCTION(BlueprintImplementableEvent,Category="ActorProcessor")
	void OnRegistered_BeginCursorOver(AActor* TouchedActor);
	UFUNCTION(BlueprintImplementableEvent,Category="ActorProcessor")
	void OnRegistered_EndCursorOver(AActor* TouchedActor);
	UFUNCTION(BlueprintImplementableEvent,Category="ActorProcessor")
	void OnRegistered_Clicked(AActor* TouchedActor, FKey ButtonPressed);
};
