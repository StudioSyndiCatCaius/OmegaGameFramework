// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems//OmegaSubsystem_DynamicCamera.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "OmegaSettings.h"
#include "GameFramework/Pawn.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/KismetMathLibrary.h"

void UOmegaDynamicCameraSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UOmegaDynamicCameraSubsystem::Tick(float DeltaTime)
{
	last_delta=DeltaTime;
	if(AOmegaDynamicCamera* cam_source = GetSourceCamera())
	{
		if(AOmegaDynamicCamera* cam_master = GetDynamicCamera())
		{
			InterpToTarget(cam_source,cam_master,cam_source->InterpSpeed);
		}
	}
	if(is_DynamicCamerActive)
	{
		if(time_SinceLastCheck>0.0)
		{
			time_SinceLastCheck=time_SinceLastCheck-DeltaTime;
		}
		else
		{
			/*
			APlayerController* local_playerController = GetLocalPlayer()->GetPlayerController(GetLocalPlayer()->GetWorld());
			if(local_playerController->GetViewTarget() != GetDynamicCamera())
			{
				local_playerController->SetViewTarget(GetDynamicCamera());
			}
			time_SinceLastCheck=0.5;
			*/
		}
			 
	}
}

void UOmegaDynamicCameraSubsystem::SnapToCurrentSource()
{
	if(AOmegaDynamicCamera* cam_source = GetSourceCamera())
	{
		if(AOmegaDynamicCamera* cam_master = GetDynamicCamera())
		{
			InterpToTarget(cam_source,cam_master,0.0);
		}
	}
}

TSubclassOf<AOmegaDynamicCamera> UOmegaDynamicCameraSubsystem::GetDynamicCameraClass()
{
	const FSoftClassPath LocalCamPath = GetMutableDefault<UOmegaSettings>()->DynamicCameraClass;
	UClass* const LocalRefClass = LocalCamPath.IsValid() ? LoadObject<UClass>(NULL, *LocalCamPath.ToString()) : nullptr;
	return (LocalRefClass != nullptr) ? LocalRefClass : AOmegaDynamicCamera::StaticClass();
}

AOmegaDynamicCamera* UOmegaDynamicCameraSubsystem::GetDynamicCamera()
{
	if(!master_camera)
	{
		master_camera = GetWorld()->SpawnActorDeferred<AOmegaDynamicCamera>(GetDynamicCameraClass(),FTransform());
		master_camera->FinishSpawning(FTransform());
	}
	return master_camera;
}

AOmegaDynamicCamera* UOmegaDynamicCameraSubsystem::GetSourceCamera()
{
	if(override_camera)
	{
		return override_camera;
	}
	AOmegaDynamicCamera* out=nullptr;
	for(auto* temp_cam : source_cameras)
	{
		if(temp_cam)
		{
			if(out)
			{
				if(temp_cam->CameraActive && temp_cam->Priority>=out->Priority)
				{
					out=temp_cam;
				}
			}
			else
			{
				out=temp_cam;
			}
		}
	}
	return out;
}

void UOmegaDynamicCameraSubsystem::SetCameraSourceRegistered(AOmegaDynamicCamera* Camera, bool IsActive)
{
	if(Camera)
	{
		if(IsActive)
		{
			source_cameras.AddUnique(Camera);
		}
		else
		{
			source_cameras.Remove(Camera);
		}
	}
}

void UOmegaDynamicCameraSubsystem::SetDynamicCameraActive(bool IsActive)
{
	is_DynamicCamerActive = IsActive;
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

void UOmegaDynamicCameraSubsystem::InterpToTarget(AOmegaDynamicCamera* cam_source, AOmegaDynamicCamera* cam_master,
	float speed)
{
	if(cam_source && cam_master)
	{
		const FVector loc_master = GetDynamicCamera()->GetActorLocation();
		cam_master->SetActorLocation(UKismetMathLibrary::VInterpTo(loc_master,cam_source->GetActorLocation(),last_delta,speed));
		cam_master->SetActorRotation(UKismetMathLibrary::RInterpTo(cam_master->GetActorRotation(),cam_source->GetActorRotation(),last_delta,speed));
		cam_master->comp_camera->SetFieldOfView(UKismetMathLibrary::FInterpTo(cam_master->comp_camera->FieldOfView,cam_source->comp_camera->FieldOfView,last_delta,speed));

		cam_master->comp_spring->TargetArmLength=UKismetMathLibrary::FInterpTo(cam_master->comp_spring->TargetArmLength,cam_source->comp_spring->TargetArmLength,last_delta,speed);
		cam_master->comp_spring->SetRelativeLocation(UKismetMathLibrary::VInterpTo(cam_master->comp_spring->GetRelativeLocation(),cam_source->comp_spring->GetRelativeLocation(),last_delta,speed));
		cam_master->comp_spring->SetRelativeRotation(UKismetMathLibrary::RInterpTo(cam_master->comp_spring->GetRelativeRotation(),cam_source->comp_spring->GetRelativeRotation(),last_delta,speed));
	}
}

void UOmegaDynamicCameraSubsystem::SetOverrideCamera(AOmegaDynamicCamera* Camera)
{
	if(Camera)
	{
		override_camera=Camera;
	}
	else
	{
		override_camera=nullptr;
	}
}

void UOmegaDynamicCameraSubsystem::ClearOverrideCamera()
{
	override_camera=nullptr;
}

AOmegaDynamicCamera::AOmegaDynamicCamera()
{
	//Setup Root Billboard
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CameraRoot"));
	comp_spring = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	comp_spring->SetupAttachment(RootComponent);
	comp_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	comp_camera->SetupAttachment(comp_spring);
}

FVector AOmegaDynamicCamera::LOCAL_Average_Vector(TArray<FVector> inputs, FVector CurrentValue, float DeltaTime)
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


float AOmegaDynamicCamera::LOCAL_Average_Float(TArray<float> inputs, float CurrentValue, float DeltaTime)
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

FTransform AOmegaDynamicCamera::LOCAL_Average_Transform(TArray<FTransform> inputs, FTransform CurrentValue, float DeltaTime)
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

void AOmegaDynamicCamera::Tick(float DeltaSeconds)
{
	if(CameraActive)
	{
		ActiveTick(DeltaSeconds);
	}
	if(SetRotationToPlayerControl)
	{
		UGameplayStatics::GetPlayerController(this,0)->SetControlRotation(GetActorRotation());
	}
	/*
	TArray<FTransform> loc_roots;
	TArray<FVector> loc_targets;
	TArray<FVector> loc_offsets;
	TArray<float> loc_fov;
	TArray<float> loc_length;
	
	for (auto* Element : GetValidSources())
	{
		FTransform temp_trans;
		float temp_float;
		FVector temp_vec;
		if(IOmegaDynamicCameraSource::Execute_GetRootTransform(Element,temp_trans))
		{
			loc_roots.Add(temp_trans);	
		}
		if(IOmegaDynamicCameraSource::Execute_GetTargetLocation(Element,temp_vec))
		{
			loc_targets.Add(temp_vec);	
		}
		if(IOmegaDynamicCameraSource::Execute_GetFieldOfView(Element,temp_float))
		{
			loc_fov.Add(temp_float);	
		}
		if(IOmegaDynamicCameraSource::Execute_GetCameraBoomLength(Element,temp_float))
		{
			loc_length.Add(temp_float);	
		}
		if(IOmegaDynamicCameraSource::Execute_GetCameraBoomOffset(Element,temp_vec))
		{
			loc_offsets.Add(temp_vec);	
		}
	}

	if(loc_length.Num()>0)
	{
		comp_spring->TargetArmLength=LOCAL_Average_Float(loc_length,comp_spring->TargetArmLength,DeltaSeconds);
	}
	if(loc_offsets.Num()>0)
	{
		comp_spring->TargetOffset=LOCAL_Average_Vector(loc_offsets,comp_spring->TargetOffset,DeltaSeconds);
	}
	if(loc_fov.Num()>0)
	{
		comp_camera->SetFieldOfView(LOCAL_Average_Float(loc_fov,comp_camera->FieldOfView,DeltaSeconds));
	
	}
	if(loc_targets.Num()>0)
	{
		comp_camera->SetWorldRotation(UKismetMathLibrary::RInterpTo(
				comp_camera->K2_GetComponentRotation(),
				UKismetMathLibrary::FindLookAtRotation(
					comp_camera->K2_GetComponentLocation(),
					UKismetMathLibrary::GetVectorArrayAverage(loc_targets)),
				DeltaSeconds,InterpSpeed
				));
	}
	if(loc_roots.Num()>0)
	{
		SetActorTransform(LOCAL_Average_Transform(loc_roots,GetActorTransform(),DeltaSeconds));
	}

	if(APlayerController* temp_player = Cast<APlayerController>(GetOwner()))
	{
		if(temp_player->GetViewTarget()==this)
		{
			temp_player->SetControlRotation(comp_camera->K2_GetComponentRotation());
		}
	}
	*/
	
	Super::Tick(DeltaSeconds);
}

TArray<UObject*> AOmegaDynamicCamera::GetValidSources()
{
	TArray<UObject*> out;
	for (auto temp_ref : REF_Sources)
	{
		if(temp_ref && temp_ref->GetClass()->ImplementsInterface(UOmegaDynamicCameraSource::StaticClass()))
		{
			out.AddUnique(temp_ref);
		}
	}
	return out;
}

void AOmegaDynamicCamera::BeginPlay()
{
	UGameplayStatics::GetPlayerController(this,0)->GetLocalPlayer()->GetSubsystem<UOmegaDynamicCameraSubsystem>()->SetCameraSourceRegistered(this,true);
	Super::BeginPlay();
}


