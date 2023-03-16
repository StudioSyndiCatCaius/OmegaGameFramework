// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/DynamicCamera.h"

#include "OmegaSettings.h"
#include "Kismet/KismetMathLibrary.h"

void UOmegaDynamicCameraSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UOmegaDynamicCameraSubsystem::Tick(float DeltaTime)
{
	if(CameraState && GetDynamicCamera())
	{
		Local_SetCamData(false);
	}
}

TSubclassOf<ACameraActor> UOmegaDynamicCameraSubsystem::GetDynamicCameraClass()
{
	const FSoftClassPath LocalCamPath = GetMutableDefault<UOmegaSettings>()->DynamicCameraClass;
	UClass* const LocalRefClass = LocalCamPath.IsValid() ? LoadObject<UClass>(NULL, *LocalCamPath.ToString()) : nullptr;
	return (LocalRefClass != nullptr) ? LocalRefClass : ACameraActor::StaticClass();
}

ACameraActor* UOmegaDynamicCameraSubsystem::GetDynamicCamera()
{
	if(CamCompRef)
	{
		return CamCompRef;
	}
	FTransform TempTrans;
	CamCompRef = Cast<ACameraActor>(GetWorld()->SpawnActor(GetDynamicCameraClass()));
	return CamCompRef;
}

void UOmegaDynamicCameraSubsystem::SetCameraState(UDynamicCameraState* NewState, bool SnapToView)
{
	if(NewState)
	{
		CameraState = NewState;
		if(SnapToView)
		{
			Local_SetCamData(true);
		}
	}
}

void UOmegaDynamicCameraSubsystem::Local_SetCamData(bool Snap)
{
	FVector TargetLoc;
	FRotator TargetRot;
	float TargetFOV=0;
	float TargetInterpSpeed=0;
	float TrackingLerp=1;
	
	CameraState->Type->GetTargetData(this,TargetLoc, TargetRot, TargetFOV, TargetInterpSpeed, TrackingLerp);
	
	if(Snap)
	{
		TargetInterpSpeed=0;
	}

	const float LocalDeltaTime = GetWorld()->GetDeltaSeconds();

	if(RootTarget)
	{
		TargetLoc = TargetLoc+RootTarget->GetActorLocation();
		TargetRot = UKismetMathLibrary::ComposeRotators(TargetRot, RootTarget->GetActorRotation());
	}

	if(TrackingTargets.IsValidIndex(0))
	{
		const FVector AvgTargetLoc = UGameplayStatics::GetActorArrayAverageLocation(TrackingTargets);
		TargetRot = UKismetMathLibrary::RLerp(TargetRot, UKismetMathLibrary::FindLookAtRotation(GetDynamicCamera()->GetActorLocation(), AvgTargetLoc), TrackingLerp, true);
	}
	
	CamCompRef->SetActorLocation(UKismetMathLibrary::VInterpTo(CamCompRef->GetActorLocation(), TargetLoc, LocalDeltaTime, TargetInterpSpeed));
	CamCompRef->SetActorRotation(UKismetMathLibrary::RInterpTo(CamCompRef->GetActorRotation(), TargetRot, LocalDeltaTime, TargetInterpSpeed));
	CamCompRef->GetCameraComponent()->SetFieldOfView(UKismetMathLibrary::FInterpTo(CamCompRef->GetCameraComponent()->FieldOfView, TargetFOV, LocalDeltaTime, TargetInterpSpeed));
}

void UOmegaDynamicCameraSubsystem::SetDynamicCameraActive(bool IsActive)
{
	APlayerController* LocalController = GetLocalPlayer()->GetPlayerController(GetWorld());
	if(IsActive)
	{
		LocalController->SetViewTarget(GetDynamicCamera());
	}
	else
	{
		LocalController->SetViewTarget(LocalController->K2_GetPawn());
	}
}

