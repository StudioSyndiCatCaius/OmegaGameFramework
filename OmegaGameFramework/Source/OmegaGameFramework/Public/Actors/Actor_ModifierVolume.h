// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Actor_ModifierVolume.generated.h"

class UActorModifierScript;
class UOmegaCondition_Actor;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AActor_ModifierVolume : public AActor
{
	GENERATED_BODY()

	FTimerHandle timer_toMod;

	TArray<AActor*> L_GetActorsToMod() const;
public:
	UFUNCTION() void L_RunModifier();
	AActor_ModifierVolume();
	
	virtual void BeginPlay() override;
	
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* Range;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifier") float Modify_Delay;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifier") bool Modify_Overlaps;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Modifier") TArray<UOmegaCondition_Actor*> Modify_OverlapFilter;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifier") TArray<TSoftObjectPtr<AActor>> Modify_Direct;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Modifier") TArray<UActorModifierScript*> Modifiers;
};
