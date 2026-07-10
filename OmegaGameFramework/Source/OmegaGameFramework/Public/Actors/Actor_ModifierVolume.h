// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_Component.h"
#include "Functions/F_TagEvent.h"
#include "GameFramework/Actor.h"
#include "Actor_ModifierVolume.generated.h"

class UActorModifierScript;
class UOmegaCondition_Actor;
class UBoxComponent;

// A box volume that applies actor modifier scripts to overlapping or directly-listed actors, optionally on a timer or in response to tag events.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AActor_ModifierVolume : public AActor, public IActorTagEventInterface
{
	GENERATED_BODY()

	FTimerHandle timer_toMod;

	TArray<AActor*> L_GetActorsToMod() const;
public:
	UFUNCTION() void L_RunModifier();
	AActor_ModifierVolume();

	virtual void BeginPlay() override;
	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;


	// Box collision component defining the volume's area of effect.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* Range;

	// Seconds between each modifier application pass. Set to 0 to apply only once at BeginPlay.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifier") float Modify_Delay;
	// When true, modifier scripts are applied to actors currently overlapping the volume.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifier") bool Modify_Overlaps;
	// Conditions an overlapping actor must pass to receive the modifier. Leave empty to accept all actors.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Modifier") TArray<UOmegaCondition_Actor*> Modify_OverlapFilter;
	// A fixed list of actors that always receive the modifier regardless of overlap.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifier") TArray<TSoftObjectPtr<AActor>> Modify_Direct;

	// Modifier scripts applied to each qualifying actor on each pass.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Modifier") TArray<UActorModifierScript*> Modifiers;
	// Additional modifier scripts triggered when specific gameplay tag events fire on this actor.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifier") TMap<FGameplayTag,FActorModifiers> Modifiers_OnTagEvent;
};
