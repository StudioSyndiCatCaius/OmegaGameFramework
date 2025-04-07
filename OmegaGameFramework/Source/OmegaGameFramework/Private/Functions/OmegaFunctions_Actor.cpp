// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Actor.h"

#include "Kismet/KismetMathLibrary.h"

// =====================================================================================================================
// ACTOR
// =====================================================================================================================

void UOmegaActorFunctions::ApplyActorConfigAsset(AActor* Actor, UOmegaActorConfig* Config)
{
	if(Actor && Config)
	{
		for(auto* i : Config->Scripts)
		{
			i->OnActorConfigured(Actor);
		}
	}
}

// =====================================================================================================================
// PAWN
// =====================================================================================================================


void UOmegaPawnFunctions::MovePawn2D_Grounded(APawn* Pawn, FVector2D Axis, bool bForce, FVector Forward, FVector Right)
{
	if(Pawn)
	{
		Pawn->AddMovementInput(Forward,Axis.X,bForce);
		Pawn->AddMovementInput(Right,Axis.Y,bForce);
	}
}

void UOmegaPawnFunctions::RotateControl2D(APawn* Pawn, FVector2D Axis, float Scale, bool bInvertX, bool bInvertY)
{
	if(Pawn)
	{
		Pawn->AddControllerPitchInput(Axis.X*Scale*UKismetMathLibrary::SelectFloat(-1,1,bInvertX));
		Pawn->AddControllerYawInput(Axis.Y*Scale*UKismetMathLibrary::SelectFloat(-1,1,bInvertY));
	}
}

void UOmegaPawnFunctions::GetPawnControlVectors(APawn* Pawn, bool X, bool Y, bool Z, FVector& Forward, FVector& Right,
                                                FVector& Up)
{
	if(Pawn)
	{
		FRotator control_rot=Pawn->GetControlRotation();
		FRotator base_rot=UKismetMathLibrary::MakeRotator(
			UKismetMathLibrary::SelectFloat(control_rot.Roll,0,X),
			UKismetMathLibrary::SelectFloat(control_rot.Pitch,0,Y),
			UKismetMathLibrary::SelectFloat(control_rot.Yaw,0,Z)
			);
		Forward=UKismetMathLibrary::GetForwardVector(base_rot);
		Right=UKismetMathLibrary::GetRightVector(base_rot);
		Up=UKismetMathLibrary::GetUpVector(base_rot);
	}
}
