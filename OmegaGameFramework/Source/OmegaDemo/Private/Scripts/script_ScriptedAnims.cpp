// Fill out your copyright notice in the Description page of Project Settings.

#include "Scripts/script_ScriptedAnims.h"

#include "DefaultLevelSequenceInstanceData.h"
#include "DataAssets/DA_Appearance.h"
#include "DataAssets/DA_AssetLib.h"
#include "Functions/F_Math.h"
#include "Actors/Actor_Spline.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneObjectBindingID.h"
#include "MovieSceneSequenceID.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


// -----------------------------------------------------------------------
// UScriptedAnim_PlayPresets
// -----------------------------------------------------------------------

void UScriptedAnim_PlayPresets::OnBegin_Implementation()
{
	FOmegaScriptedAnimationData AnimData;
	AnimData.anim_preset = Presets;

	UOmegaFunctions_ScriptedAnimation::PlayScriptedAnimationWithCallbacks(
		this,
		GetAnimationInstigator(),
		AnimData,
		[this](const FString&) { FinishAnimation(); }
	);
}


// -----------------------------------------------------------------------
// UScriptedAnim_InterpTransform
// -----------------------------------------------------------------------

void UScriptedAnim_InterpTransform::OnBegin_Implementation()
{
	AActor* Instigator = GetAnimationInstigator();
	if (!IsValid(Instigator) || !IsValid(TransformTarget))
	{
		FinishAnimation();
		return;
	}

	REF_StartTransform = Instigator->GetActorTransform();
	REF_StartTime = Instigator->GetWorld()->GetTimeSeconds();

	Instigator->GetWorld()->GetTimerManager().SetTimer(
		REF_TimerHandle,
		this, &UScriptedAnim_InterpTransform::TickInterp,
		0.016f, true
	);
}

void UScriptedAnim_InterpTransform::TickInterp()
{
	AActor* Instigator = GetAnimationInstigator();
	UWorld* World = Instigator ? Instigator->GetWorld() : nullptr;

	if (!IsValid(Instigator) || !IsValid(TransformTarget) || !World)
	{
		if (World) World->GetTimerManager().ClearTimer(REF_TimerHandle);
		FinishAnimation();
		return;
	}

	const float Alpha = FMath::Clamp(
		(World->GetTimeSeconds() - REF_StartTime) / FMath::Max(OverTime, KINDA_SMALL_NUMBER),
		0.f, 1.f
	);

	const FTransform& Target = TransformTarget->GetActorTransform();
	const FVector NewLoc   = bLocation ? FMath::Lerp(REF_StartTransform.GetLocation(), Target.GetLocation(), Alpha) : Instigator->GetActorLocation();
	const FQuat   NewRot   = bRotation ? FQuat::Slerp(REF_StartTransform.GetRotation(), Target.GetRotation(), Alpha) : Instigator->GetActorQuat();
	const FVector NewScale = bScale    ? FMath::Lerp(REF_StartTransform.GetScale3D(),   Target.GetScale3D(),  Alpha) : Instigator->GetActorScale3D();

	Instigator->SetActorTransform(FTransform(NewRot, NewLoc, NewScale));

	if (Alpha >= 1.f)
	{
		World->GetTimerManager().ClearTimer(REF_TimerHandle);
		FinishAnimation();
	}
}


// -----------------------------------------------------------------------
// UScriptedAnim_LevelSequence
// -----------------------------------------------------------------------

void UScriptedAnim_LevelSequence::OnBegin_Implementation()
{
	AActor* Instigator = GetAnimationInstigator();

	ULevelSequence* SequenceToPlay = Fallback;

	if (IsValid(Instigator) && !AssetLibraryName.IsNone())
	{
		UOmegaAssetLibrary_Animation* AnimLib = nullptr;
		UOmegaAssetLibrary_Sound* SoundLib = nullptr;
		UOmegaAssetLibrary_SlateBrush* SlateLib = nullptr;
		UOmegaAppearanceFunctions::GetAppearanceLibraries(Instigator, AnimLib, SoundLib, SlateLib);

		if (IsValid(AnimLib))
		{
			bool bResult = false;
			if (ULevelSequence* Found = AnimLib->GetLevelSequence_Named(AssetLibraryName, false, bResult, Fallback))
			{
				SequenceToPlay = Found;
			}
		}
	}

	if (!IsValid(SequenceToPlay) || !IsValid(Instigator))
	{
		FinishAnimation();
		return;
	}

	FMovieSceneSequencePlaybackSettings Settings;
	ULevelSequencePlayer* Player = ULevelSequencePlayer::CreateLevelSequencePlayer(
		Instigator, SequenceToPlay, Settings, REF_SequenceActor
	);

	if (!IsValid(Player))
	{
		FinishAnimation();
		return;
	}
	REF_SequenceActor->bOverrideInstanceData = true;
	if (UDefaultLevelSequenceInstanceData* instDat=Cast<UDefaultLevelSequenceInstanceData>(REF_SequenceActor->DefaultInstanceData))
	{
		instDat->TransformOrigin=GetAnimationInstigator()->GetActorTransform();
	}

	// Bind instigator to the named possessable slot
	if (IsValid(REF_SequenceActor) && !InstigatorSequenceBinding.IsNone())
	{
		if (UMovieScene* MovieScene = SequenceToPlay->GetMovieScene())
		{
			for (int32 i = 0; i < MovieScene->GetPossessableCount(); ++i)
			{
				const FMovieScenePossessable& Possessable = MovieScene->GetPossessable(i);
				if (FName(*Possessable.GetName()) == InstigatorSequenceBinding)
				{
					REF_SequenceActor->SetBinding(
						UE::MovieScene::FRelativeObjectBindingID(Possessable.GetGuid(), MovieSceneSequenceID::Root),
						TArray<AActor*>{Instigator}
					);
					break;
				}
			}
		}
	}

	Player->OnFinished.AddDynamic(this, &UScriptedAnim_LevelSequence::OnSequenceFinished);
	Player->Play();
}

void UScriptedAnim_LevelSequence::OnSequenceFinished()
{
	if (IsValid(REF_SequenceActor))
	{
		REF_SequenceActor->Destroy();
		REF_SequenceActor = nullptr;
	}
	FinishAnimation();
}


// -----------------------------------------------------------------------
// UScriptedAnim_Montage
// -----------------------------------------------------------------------

void UScriptedAnim_Montage::OnBegin_Implementation()
{
	ACharacter* Char = Cast<ACharacter>(GetAnimationInstigator());
	if (!IsValid(Char))
	{
		FinishAnimation();
		return;
	}

	REF_Montage = Fallback;

	if (!AssetLibraryName.IsNone())
	{
		UOmegaAssetLibrary_Animation* AnimLib = nullptr;
		UOmegaAssetLibrary_Sound* SoundLib = nullptr;
		UOmegaAssetLibrary_SlateBrush* SlateLib = nullptr;
		UOmegaAppearanceFunctions::GetAppearanceLibraries(Char, AnimLib, SoundLib, SlateLib);

		if (IsValid(AnimLib))
		{
			bool bResult = false;
			REF_Montage = AnimLib->GetMontage_Named(AssetLibraryName, false, bResult, Fallback);
		}
	}

	if (!IsValid(REF_Montage))
	{
		FinishAnimation();
		return;
	}

	UAnimInstance* AnimInstance = Char->GetMesh() ? Char->GetMesh()->GetAnimInstance() : nullptr;
	if (!IsValid(AnimInstance))
	{
		FinishAnimation();
		return;
	}

	const float PlayLength = AnimInstance->Montage_Play(REF_Montage);
	if (PlayLength <= 0.f)
	{
		FinishAnimation();
		return;
	}

	REF_AnimInstance = AnimInstance;
	REF_AnimInstance->OnMontageEnded.AddDynamic(this, &UScriptedAnim_Montage::OnMontageEnded);
}

void UScriptedAnim_Montage::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage != REF_Montage) return;

	if (IsValid(REF_AnimInstance))
	{
		REF_AnimInstance->OnMontageEnded.RemoveDynamic(this, &UScriptedAnim_Montage::OnMontageEnded);
		REF_AnimInstance = nullptr;
	}
	REF_Montage = nullptr;
	FinishAnimation();
}


// -----------------------------------------------------------------------
// UScriptedAnim_PawnMoveBASE helpers
// -----------------------------------------------------------------------

void UScriptedAnim_PawnMoveBASE::SetPawnSpeed(APawn* Pawn, float Speed)
{
	if (ACharacter* Char = Cast<ACharacter>(Pawn))
	{
		if (UCharacterMovementComponent* CMC = Char->GetCharacterMovement())
		{
			REF_OriginalSpeed = CMC->MaxWalkSpeed;
			CMC->MaxWalkSpeed = Speed;
		}
	}
}

void UScriptedAnim_PawnMoveBASE::RestorePawnSpeed(APawn* Pawn)
{
	if (!bRestoreSpeedOnFinish) return;
	if (ACharacter* Char = Cast<ACharacter>(Pawn))
	{
		if (UCharacterMovementComponent* CMC = Char->GetCharacterMovement())
		{
			CMC->MaxWalkSpeed = REF_OriginalSpeed;
		}
	}
}

void UScriptedAnim_PawnMoveBASE::FinishMove(APawn* Pawn)
{
	if (IsValid(Pawn))
	{
		Pawn->GetWorld()->GetTimerManager().ClearTimer(REF_TimerHandle);
		RestorePawnSpeed(Pawn);
	}
	FinishAnimation();
}


// -----------------------------------------------------------------------
// UScriptedAnim_PawnMoveAlongSpline
// -----------------------------------------------------------------------

void UScriptedAnim_PawnMoveAlongSpline::OnBegin_Implementation()
{
	APawn* Pawn = Cast<APawn>(GetAnimationInstigator());
	AOmegaSplineActor* SplineActor = Spline.Get();

	if (!IsValid(Pawn) || !IsValid(SplineActor) || !IsValid(SplineActor->Spline) || SplineActor->Spline->GetNumberOfSplinePoints() == 0)
	{
		FinishAnimation();
		return;
	}

	SetPawnSpeed(Pawn, MoveSpeed);
	REF_SplineIndex = 0;

	const FVector FirstPoint = SplineActor->Spline->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World);
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Pawn->GetController(), FirstPoint);

	Pawn->GetWorld()->GetTimerManager().SetTimer(
		REF_TimerHandle,
		this, &UScriptedAnim_PawnMoveAlongSpline::TickSplineMove,
		0.1f, true
	);
}

void UScriptedAnim_PawnMoveAlongSpline::TickSplineMove()
{
	APawn* Pawn = Cast<APawn>(GetAnimationInstigator());
	AOmegaSplineActor* SplineActor = Spline.Get();

	if (!IsValid(Pawn) || !IsValid(SplineActor))
	{
		FinishMove(Pawn);
		return;
	}

	const int32 NumPoints = SplineActor->Spline->GetNumberOfSplinePoints();
	const FVector CurrentTarget = SplineActor->Spline->GetLocationAtSplinePoint(REF_SplineIndex, ESplineCoordinateSpace::World);

	if (FVector::Dist(Pawn->GetActorLocation(), CurrentTarget) < 100.f)
	{
		REF_SplineIndex++;
		if (REF_SplineIndex >= NumPoints)
		{
			FinishMove(Pawn);
		}
		else
		{
			const FVector NextPoint = SplineActor->Spline->GetLocationAtSplinePoint(REF_SplineIndex, ESplineCoordinateSpace::World);
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(Pawn->GetController(), NextPoint);
		}
	}
}


// -----------------------------------------------------------------------
// UScriptedAnim_MoveToPoint
// -----------------------------------------------------------------------

void UScriptedAnim_MoveToPoint::OnBegin_Implementation()
{
	APawn* Pawn = Cast<APawn>(GetAnimationInstigator());
	AActor* PointActor = Point.Get();

	if (!IsValid(Pawn) || !IsValid(PointActor))
	{
		FinishAnimation();
		return;
	}

	SetPawnSpeed(Pawn, MoveSpeed);
	REF_TargetLocation = PointActor->GetActorLocation();

	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Pawn->GetController(), REF_TargetLocation);

	Pawn->GetWorld()->GetTimerManager().SetTimer(
		REF_TimerHandle,
		this, &UScriptedAnim_MoveToPoint::TickPointMove,
		0.1f, true
	);
}

void UScriptedAnim_MoveToPoint::TickPointMove()
{
	APawn* Pawn = Cast<APawn>(GetAnimationInstigator());
	if (!IsValid(Pawn)) { FinishMove(Pawn); return; }

	if (FVector::Dist(Pawn->GetActorLocation(), REF_TargetLocation) < 50.f)
	{
		FinishMove(Pawn);
	}
}


// -----------------------------------------------------------------------
// UScriptedAnim_MoveOffset
// -----------------------------------------------------------------------

void UScriptedAnim_MoveOffset::OnBegin_Implementation()
{
	APawn* Pawn = Cast<APawn>(GetAnimationInstigator());
	if (!IsValid(Pawn)) { FinishAnimation(); return; }

	if (OffsetIsStart)
	{
		// Teleport pawn to (current - Offset), then move back to current
		const FVector OriginalLocation = Pawn->GetActorLocation();
		const FVector StartLocation = UOmegaMathFunctions::Offset_ActorLocation(Pawn, Offset * -1.f);
		Pawn->TeleportTo(StartLocation, Pawn->GetActorRotation());
		REF_TargetLocation = OriginalLocation;
	}
	else
	{
		REF_TargetLocation = UOmegaMathFunctions::Offset_ActorLocation(Pawn, Offset);
	}

	SetPawnSpeed(Pawn, MoveSpeed);
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Pawn->GetController(), REF_TargetLocation);

	Pawn->GetWorld()->GetTimerManager().SetTimer(
		REF_TimerHandle,
		this, &UScriptedAnim_MoveOffset::TickOffsetMove,
		0.1f, true
	);
}

void UScriptedAnim_MoveOffset::TickOffsetMove()
{
	APawn* Pawn = Cast<APawn>(GetAnimationInstigator());
	if (!IsValid(Pawn)) { FinishMove(Pawn); return; }

	if (FVector::Dist(Pawn->GetActorLocation(), REF_TargetLocation) < 50.f)
	{
		FinishMove(Pawn);
	}
}
