// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "OmegaAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	UPROPERTY(EditAnywhere, Category="Notify")
	FName CombatantNotify;
	UPROPERTY(EditAnywhere, Category="Notify")
	FString Flag;
};


//Rotation Tracks the Active Target
UCLASS()
class OMEGAGAMEFRAMEWORK_API UAnimNotifyState_CombatantTrackTarget : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Combatant") float RotateSpeed=5;
	UPROPERTY(EditAnywhere, Category="Combatant") bool Rotate_X=false;
	UPROPERTY(EditAnywhere, Category="Combatant") bool Rotate_Y=false;
	UPROPERTY(EditAnywhere, Category="Combatant") bool Rotate_Z=true;
};
