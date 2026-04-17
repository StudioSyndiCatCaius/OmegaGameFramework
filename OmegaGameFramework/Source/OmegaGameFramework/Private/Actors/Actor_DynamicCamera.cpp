// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/Actor_DynamicCamera.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_World.h"


AOmegaDynamicCamera::AOmegaDynamicCamera()
{
	//Setup Root Billboard
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CameraRoot"));
	comp_spring = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	comp_spring->TargetArmLength=0.0;
	comp_spring->SetupAttachment(RootComponent);
	comp_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	comp_camera->SetupAttachment(comp_spring);
	comp_camera->PostProcessSettings.MotionBlurAmount=0.05f;
}

FVector AOmegaDynamicCamera::L_Average_Vector(TArray<FVector> inputs, FVector CurrentValue, float DeltaTime) const
{
	FVector sum = FVector::ZeroVector;
	if (inputs.Num() == 0)
		return CurrentValue;

	for (const FVector& vec : inputs)
	{
		sum += vec;
	}
	FVector average = sum / inputs.Num();
	return FMath::VInterpTo(CurrentValue, average, DeltaTime, InterpSpeed); // Using 1.0f as interp speed, adjust as necessary
}


float AOmegaDynamicCamera::L_Average_Float(TArray<float> inputs, float CurrentValue, float DeltaTime)
{
	float sum = 0.0f;
	if (inputs.Num() == 0)
		return CurrentValue;

	for (float val : inputs)
	{
		sum += val;
	}
	float average = sum / inputs.Num();
	return FMath::FInterpTo(CurrentValue, average, DeltaTime, InterpSpeed); // Using 1.0f as interp speed, adjust as necessary
}

FTransform AOmegaDynamicCamera::L_Average_Transform(TArray<FTransform> inputs, FTransform CurrentValue, float DeltaTime)
{
	if (inputs.Num() == 0)
		return CurrentValue;

	FVector averageLocation = FVector::ZeroVector;
	FQuat averageRotation = FQuat::Identity;
	FVector averageScale = FVector::ZeroVector;

	for (const FTransform& xform : inputs)
	{
		averageLocation += xform.GetLocation();
		averageRotation += xform.GetRotation();
		averageScale += xform.GetScale3D();
	}

	float numInputs = static_cast<float>(inputs.Num());
	averageLocation /= numInputs;
	averageRotation /= numInputs;
	averageScale /= numInputs;

	averageRotation.Normalize(); // Normalize the quaternion

	FVector interpolatedLocation = FMath::VInterpTo(CurrentValue.GetLocation(), averageLocation, DeltaTime, InterpSpeed);
	FQuat interpolatedRotation = FQuat::Slerp(CurrentValue.GetRotation(), averageRotation, DeltaTime);
	FVector interpolatedScale = FMath::VInterpTo(CurrentValue.GetScale3D(), averageScale, DeltaTime, InterpSpeed);

	return FTransform(interpolatedRotation, interpolatedLocation, interpolatedScale);
}

void AOmegaDynamicCamera::DynaCam_GetComponents_Implementation(USpringArmComponent*& spring_arm, UCameraComponent*& camera)
{
	spring_arm=comp_spring; camera=comp_camera;
}


void AOmegaDynamicCamera::Tick(float DeltaSeconds)
{
	if(DeltaSeconds<=0.0) { return; } //Failsafe because BeginPlay keeps causing problems.
	
	if(CameraActive)
	{
		if(!REF_SourcePlayer)
		{
			REF_SourcePlayer=UGameplayStatics::GetPlayerController(this,0);
		}
		/*
		if(!REF_Subsystem && REF_SourcePlayer)
		{
			REF_Subsystem=REF_SourcePlayer->GetLocalPlayer()->GetSubsystem<UOmegaDynamicCameraSubsystem>();
		}
		if(REF_Subsystem && REF_SourcePlayer)
		{
			//ActiveTick(DeltaSeconds,REF_Subsystem->GetSourceCamera()!=this,REF_SourcePlayer);
		}
		*/
	}
	if(SetRotationToPlayerControl)
	{
		UGameplayStatics::GetPlayerController(this,0)->SetControlRotation(GetActorRotation());
	}
	Super::Tick(DeltaSeconds);
}

bool AOmegaDynamicCamera::L_CanPlayerUse(APlayerController* Player) const
{
	if (Player)
	{
		if (restricted_players.IsEmpty()) { return true;}
		if (restricted_players.Contains(Player)) { return true; }
	}
	return false;
}

void AOmegaDynamicCamera::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetPlayerController(this,0)->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->DynaCam_Register(this,true);
	if(GlobalBinding.IsValid())
	{
		GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->SetGlobalActorBinding(GlobalBinding,this);
	}
	
	SS_World->OnGameplayMessage_Begin.AddDynamic(this, &AOmegaDynamicCamera::K2_OnGameMessageBegin);
	SS_World->OnGameplayMessage_End.AddDynamic(this, &AOmegaDynamicCamera::K2_OnGameMessageEnd);
}


