// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_DynamicCameras.h"

#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerController.h"


ADCam_LookAtPlayer::ADCam_LookAtPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void ADCam_LookAtPlayer::BeginPlay()
{
	Super::BeginPlay();
	initRot=GetActorRotation();
}


void ADCam_LookAtPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADCam_LookAtPlayer::SourceTick_Implementation(float deltaTime, APlayerController* SourcePlayer,
	UOmegaSubsystem_Player* Subsystem)
{
	if(SourcePlayer)
	{
		FRotator _rotTarget = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),SourcePlayer->GetPawn()->GetActorLocation());
		_rotTarget=UKismetMathLibrary::RLerp(initRot,_rotTarget,LookAtPlayerRatio,true);
		SetActorRotation(UKismetMathLibrary::RInterpTo(GetActorRotation(),_rotTarget,deltaTime,LookAtPlayerSpeed));
		SourcePlayer->SetControlRotation(GetActorRotation());
	}
}

