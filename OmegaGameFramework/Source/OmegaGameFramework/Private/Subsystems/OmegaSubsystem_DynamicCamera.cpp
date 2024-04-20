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
	//
}

TSubclassOf<AOmegaDynamicCamera> UOmegaDynamicCameraSubsystem::GetDynamicCameraClass()
{
	const FSoftClassPath LocalCamPath = GetMutableDefault<UOmegaSettings>()->DynamicCameraClass;
	UClass* const LocalRefClass = LocalCamPath.IsValid() ? LoadObject<UClass>(NULL, *LocalCamPath.ToString()) : nullptr;
	return (LocalRefClass != nullptr) ? LocalRefClass : AOmegaDynamicCamera::StaticClass();
}

AOmegaDynamicCamera* UOmegaDynamicCameraSubsystem::GetDynamicCamera()
{
	if(!ref_camera)
	{
		ref_camera = GetWorld()->SpawnActorDeferred<AOmegaDynamicCamera>(GetDynamicCameraClass(),FTransform());
		ref_camera->FinishSpawning(FTransform());
	}
	return ref_camera;
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

void AOmegaDynamicCamera::SetSourceActive(UObject* source, bool bActive)
{
	if(source && source->GetClass()->ImplementsInterface(UOmegaDynamicCameraSource::StaticClass()))
	{
		if(bActive)
		{
			REF_Sources.AddUnique(source);
		}
		else
		{
			REF_Sources.Remove(source);
		}
	}
}

void AOmegaDynamicCamera::SetSourceList(TArray<UObject*> Sources)
{
	ClearSources();
	for (auto* temp_source: Sources)
	{
		SetSourceActive(temp_source,true);
	}
}

void AOmegaDynamicCamera::ClearSources()
{
	REF_Sources.Empty();
}

void UOmegaDynamicCameraFunctions::SetDynamicCamera_Active(UObject* WorldContextObject, APlayerController* player,
	bool bActive)
{
	const APlayerController* ref_player=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if(player)
	{
		ref_player=player;
	}
	ref_player->GetLocalPlayer()->GetSubsystem<UOmegaDynamicCameraSubsystem>()->SetDynamicCameraActive(bActive);
}

void UOmegaDynamicCameraFunctions::SetDynamicCamera_SourceActive(UObject* WorldContextObject, APlayerController* player,
                                                                 UObject* Source, bool bActive)
{
	const APlayerController* ref_player=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if(player)
	{
		ref_player=player;
	}
	ref_player->GetLocalPlayer()->GetSubsystem<UOmegaDynamicCameraSubsystem>()->GetDynamicCamera()->SetSourceActive(Source,bActive);
}

void UOmegaDynamicCameraFunctions::SetDynamicCamera_SourceList(UObject* WorldContextObject, APlayerController* player,
	TArray<UObject*> Sources)
{
	const APlayerController* ref_player=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if(player)
	{
		ref_player=player;
	}
	ref_player->GetLocalPlayer()->GetSubsystem<UOmegaDynamicCameraSubsystem>()->GetDynamicCamera()->SetSourceList(Sources);
	
}

void UOmegaDynamicCameraFunctions::ClearDynamicCameraSources(UObject* WorldContextObject, APlayerController* player)
{
	const APlayerController* ref_player=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if(player)
	{
		ref_player=player;
	}
	ref_player->GetLocalPlayer()->GetSubsystem<UOmegaDynamicCameraSubsystem>()->GetDynamicCamera()->ClearSources();
}

