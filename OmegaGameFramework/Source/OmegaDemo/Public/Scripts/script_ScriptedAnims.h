// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "Functions/F_ScriptedAnim.h"
#include "script_ScriptedAnims.generated.h"


class AOmegaSplineActor;
class ALevelSequenceActor;
class UAnimInstance;

UCLASS(DisplayName="🏃S Anim - Interp Transform")
class OMEGADEMO_API UScriptedAnim_InterpTransform : public UOmegaScriptedAnimation
{
	GENERATED_BODY()

public:

	virtual void OnBegin_Implementation() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") AActor* TransformTarget;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") bool bLocation=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") bool bRotation=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") bool bScale=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") float OverTime=1;

private:
	FTransform REF_StartTransform;
	float REF_StartTime = 0.f;
	FTimerHandle REF_TimerHandle;
	void TickInterp();
};

UCLASS(DisplayName="🏃S Anim - PRESETS")
class OMEGADEMO_API UScriptedAnim_PlayPresets : public UOmegaScriptedAnimation
{
	GENERATED_BODY()

public:

	virtual void OnBegin_Implementation() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") 
	TArray<UOmegaScriptedAnimation_Preset*> Presets;

};



UCLASS(DisplayName="🏃S Anim - Level Sequence")
class OMEGADEMO_API UScriptedAnim_LevelSequence : public UOmegaScriptedAnimation
{
	GENERATED_BODY()

public:

	virtual void OnBegin_Implementation() override;

	//name of animation to first try getting from the actor's anim asset library
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") FName AssetLibraryName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") ULevelSequence* Fallback;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") FName InstigatorSequenceBinding="Instigator";

private:
	UPROPERTY() ALevelSequenceActor* REF_SequenceActor = nullptr;
	UFUNCTION() void OnSequenceFinished();
};



UCLASS(DisplayName="🏃S Anim - (Character) Montage")
class OMEGADEMO_API UScriptedAnim_Montage : public UOmegaScriptedAnimation
{
	GENERATED_BODY()
	virtual void OnBegin_Implementation() override;

public:
	//name of animation to first try getting from the actor's anim asset library
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") FName AssetLibraryName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim") UAnimMontage* Fallback;

private:
	UPROPERTY() UAnimInstance* REF_AnimInstance = nullptr;
	UPROPERTY() UAnimMontage* REF_Montage = nullptr;
	UFUNCTION() void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
};

// -- T

UCLASS(Abstract)
class OMEGADEMO_API UScriptedAnim_PawnMoveBASE : public UOmegaScriptedAnimation
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim")
	float MoveSpeed=300;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim")
	bool bRestoreSpeedOnFinish=true;

protected:
	float REF_OriginalSpeed = 0.f;
	FTimerHandle REF_TimerHandle;
	void SetPawnSpeed(APawn* Pawn, float Speed);
	void RestorePawnSpeed(APawn* Pawn);
	void FinishMove(APawn* Pawn);
};


UCLASS(DisplayName="🏃S Anim - (Pawn) Move Along Spline")
class OMEGADEMO_API UScriptedAnim_PawnMoveAlongSpline : public UScriptedAnim_PawnMoveBASE
{
	GENERATED_BODY()

public:
	virtual void OnBegin_Implementation() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim")
	TSoftObjectPtr<AOmegaSplineActor> Spline;

private:
	int32 REF_SplineIndex = 0;
	void TickSplineMove();
};

UCLASS(DisplayName="🏃S Anim - (Pawn) Move To Point")
class OMEGADEMO_API UScriptedAnim_MoveToPoint : public UScriptedAnim_PawnMoveBASE
{
	GENERATED_BODY()

public:
	virtual void OnBegin_Implementation() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim")
	TSoftObjectPtr<AActor> Point;

private:
	FVector REF_TargetLocation = FVector::ZeroVector;
	void TickPointMove();
};


UCLASS(DisplayName="🏃S Anim - (Pawn) Move Offset Position")
class OMEGADEMO_API UScriptedAnim_MoveOffset : public UScriptedAnim_PawnMoveBASE
{
	GENERATED_BODY()

	virtual void OnBegin_Implementation() override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim")
	FVector Offset;

	//If true, will invert the offset and set the pawn there at the START of the animation, the move to the transform the started at
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim")
	bool OffsetIsStart;

private:
	FVector REF_TargetLocation = FVector::ZeroVector;
	void TickOffsetMove();
};
