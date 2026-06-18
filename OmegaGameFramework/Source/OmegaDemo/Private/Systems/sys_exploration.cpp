// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/sys_exploration.h"

#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "Actors/Actor_DynamicCamera.h"
#include "Functions/F_Actor.h"
#include "Functions/F_Camera.h"
#include "Functions/F_Common.h"
#include "Functions/F_Math.h"
#include "Functions/F_Player.h"


// Sets default values
AOmegaDemoSystem_Exploration::AOmegaDemoSystem_Exploration()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOmegaDemoSystem_Exploration::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOmegaDemoSystem_Exploration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOmegaDemoSystem_Exploration::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	Super::SystemActivated_Implementation(Context, Flag);
}

void AOmegaDemoSystem_Exploration::OnInputAction_Begin_Implementation(APlayerController* Player, FGameplayTag Action,
	FVector axis)
{
	if (Action==Input_Interact)
	{
		if (APawn* Pawn=Player->GetPawn())
		{
			bool bOutcome;
			if (AActor* interactTarget=UOmegaActorFunctions::GetActorTagTarget(Pawn,TagTarget_Interact,bOutcome))
			{
				FOmegaCommonMeta InteracMeta = {};
				if (UOmegaActorFunctions::CheckIsActorInteractable(interactTarget,Pawn,InteractTag,InteracMeta,bOutcome))
				{
					UOmegaActorFunctions::PerformInteraction(interactTarget,Pawn,InteractTag,InteracMeta);
				}
			}
		}
	}
}

void AOmegaDemoSystem_Exploration::OnInputAction_End_Implementation(APlayerController* Player, FGameplayTag Action,
	FVector axis)
{
	
}

void AOmegaDemoSystem_Exploration::OnInputAction_Update_Implementation(APlayerController* Player, FGameplayTag Action,
	float DeltaTime, FVector axis)
{
	bool bOutcome;
	if(AOmegaDynamicCamera* dynaCam=UOmegaCameraFunctions::GetDynamicCamera_Source(this,bOutcome,Player))
	{
		IDataInterface_InputAction::Execute_OnInputAction_Update(dynaCam, Player, Action, DeltaTime, axis);
	}
	else
	{
		APawn* Pawn=Player->GetPawn();
		if (Action == Input_Move && bEnableInput_Move)
		{
			FVector v_forward, v_right, v_up;
			UOmegaPawnFunctions::GetPawnControlVectors(Pawn,false,false,true,v_forward,v_right,v_up);
			UOmegaPawnFunctions::MovePawn2D_Grounded(Pawn, FVector2D(axis.X,axis.Y), false,v_forward,v_right);
		}
		else if (Action == Input_Camera && bEnableInput_CameraControl)
		{
			FOmega_CameraConfig camConfig;
			UOmegaPawnFunctions::RotateControl2D(Pawn, FVector2D(axis.X,axis.Y), camConfig);
		}
	}
}
