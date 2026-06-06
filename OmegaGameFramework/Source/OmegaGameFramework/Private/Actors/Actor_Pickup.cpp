// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Pickup.h"

#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "Engine/HitResult.h"
#include "Actors/Actor_GameplayCue.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SplineComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


AOmegaPickupActor::AOmegaPickupActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Range=CreateDefaultSubobject<USphereComponent>("Sphere");
	Range->SetSphereRadius(50);
	RootComponent=Range;
	NiagaraComponent=CreateOptionalDefaultSubobject<UNiagaraComponent>("Niagara");
	AudioComponent=CreateOptionalDefaultSubobject<UAudioComponent>("Audio");
	if (NiagaraComponent) { NiagaraComponent->SetupAttachment(Range); }
	if (AudioComponent) { AudioComponent->SetupAttachment(Range); }
}

void AOmegaPickupActor::pickup_finish()
{
	if(is_picking_up)
	{
		is_picking_up=false;
		if (L_ValidPreset())
		{
			IDataInterface_Pickup::Execute_OnPickup(Preset.GetObject(),pawn_target,controller_target);
		}
		OnPickup(pawn_target,controller_target);
		if(GetConfig().PickupCue.CueClass)
		{
			UOmegaGameplayCueFunctions::PlayGameplayCue_FromConfig(this,GetConfig().PickupCue,GetActorTransform(),FHitResult());
		}
		K2_DestroyActor();
		if (GetConfig().PickupSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this,GetConfig().PickupSound,GetActorLocation());
		}
		if (GetConfig().bFlashScreen)
		{
			controller_target->PlayerCameraManager->StartCameraFade(GetConfig().FlashStartOpacity,0.0,GetConfig().FlashDuration,GetConfig().Color);
		}
	}
}

bool AOmegaPickupActor::L_ValidPreset() const
{
	if (!Preset.GetObject()) { return false;}
	return true;
}

// Called when the game starts or when spawned
void AOmegaPickupActor::BeginPlay()
{
	Super::BeginPlay();
	if (L_ValidPreset())
	{
		IDataInterface_Pickup::Execute_PickupActor_BeginPlay(Preset.GetObject(),this);
	}
}

void AOmegaPickupActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetPreset(Preset);
	if (ID<=0)
	{
		ID=UKismetMathLibrary::RandomIntegerInRange(0,999999);
	}
	if (L_ValidPreset())
	{
		IDataInterface_Pickup::Execute_PickupActor_Construct(Preset.GetObject(),this);
	}
}

// Called every frame
void AOmegaPickupActor::Tick(float DeltaTime)
{
	if(pawn_target && is_picking_up)
	{
		if(GetConfig().MoveToActorOnPickup)
		{
			move_to_actor_time=DeltaTime+move_to_actor_time;
			SetActorLocation(UKismetMathLibrary::VLerp(move_origin,pawn_target->GetActorLocation(),move_to_actor_time/GetConfig().MoveToActorDuration));
			if(move_to_actor_time>=GetConfig().MoveToActorDuration)
			{
				pickup_finish();
			}
		}
		else
		{
			pickup_finish();
		}
	}
	Super::Tick(DeltaTime);
}

void AOmegaPickupActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(APawn* pawn_ref = Cast<APawn>(OtherActor))
	{
		if(APlayerController* controller_ref = Cast<APlayerController>(pawn_ref->GetController()))
		{
			if (L_ValidPreset())
			{
				if (!IDataInterface_Pickup::Execute_CanPickup(Preset.GetObject(),pawn_ref,controller_ref))
				{
					return;
				}
			}
			if(CanPickup(pawn_ref,controller_ref))
			{
				pawn_target=pawn_ref;
				controller_target=controller_ref;
				move_origin=GetActorLocation();
				is_picking_up=true;
			}
		}
	}
	Super::NotifyActorBeginOverlap(OtherActor);
}

FOmegaPickupConfig AOmegaPickupActor::GetConfig() const
{
	if (L_ValidPreset())
	{
		return IDataInterface_Pickup::Execute_GetPickupConfig(Preset.GetObject());
	}
	return Config;
}

void AOmegaPickupActor::SetPreset(TScriptInterface<IDataInterface_Pickup> preset)
{
	if (bIsSettingPreset) { return; }
	FOmegaPickupConfig cfg=GetConfig();
	TGuardValue<bool> ReentrancyGuard(bIsSettingPreset, true);
	if (preset.GetObject())
	{
		Preset=preset;
		if (NiagaraComponent)
		{
			if (UNiagaraSystem* TargetSystem = cfg.NiagaraSystem)
			{
				if (NiagaraComponent->GetAsset() != TargetSystem)
				{
					NiagaraComponent->SetAsset(TargetSystem);
					//NiagaraComponent->ResetSystem();
					NiagaraComponent->SetVariableLinearColor("Color",cfg.Color);
					if (cfg.NiagaraMesh)
					{
						NiagaraComponent->SetVariableStaticMesh("Mesh",cfg.NiagaraMesh);
					}
					//NiagaraComponent->SetColorParameter("Color", GetConfig().Color);
				}
			}
		}
		if (Range)
		{
			Range->ShapeColor=cfg.Color.ToFColor(true);
		}
		
		if (L_ValidPreset())
		{
			IDataInterface_Pickup::Execute_PickupActor_OnInit(Preset.GetObject(),this);
			if (HasActorBegunPlay())
			{
				IDataInterface_Pickup::Execute_PickupActor_BeginPlay(Preset.GetObject(),this);
			}
		}
	}
}

AOmegaPickupTrail::AOmegaPickupTrail()
{
	SplineComponent = CreateDefaultSubobject<USplineComponent>("Spline");
	SplineComponent->SetUnselectedSplineSegmentColor(FColor::Blue);
	if (SplineComponent)
	{
		SplineComponent->SetLocationAtSplinePoint(1,FVector(500,0,0),ESplineCoordinateSpace::World);
	}
	RootComponent = SplineComponent;
	ReferenceMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>("ReferenceMesh");
	ReferenceMesh->SetupAttachment(SplineComponent);
	ReferenceMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ReferenceMesh->SetHiddenInGame(true);
	if (UStaticMesh* msh=LoadObject<UStaticMesh>(nullptr,TEXT("/OmegaGameFramework/Meshes/util/sm_UTIL_DriverReference.sm_UTIL_DriverReference")))
	{
		ReferenceMesh->SetStaticMesh(msh);
	}
}

void AOmegaPickupTrail::SetPreset(TScriptInterface<IDataInterface_Pickup> preset)
{
	if (preset.GetObject())
	{
		Preset = preset;
	}
	if (!ReferenceMesh || !SplineComponent || Count <= 0) { return; }
	ReferenceMesh->ClearInstances();
	const float SplineLength = SplineComponent->GetSplineLength();
	for (int32 i = 0; i < Count; i++)
	{
		const float Distance = Count > 1 ? SplineLength * i / (Count - 0) : 0.f;
		ReferenceMesh->AddInstance(SplineComponent->GetTransformAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::Local));
	}
}

void AOmegaPickupTrail::BeginPlay()
{
	Super::BeginPlay();
	if (ReferenceMesh)
	{
		ReferenceMesh->ClearInstances();
	}
	if (!Preset.GetObject() || Count <= 0 || !SplineComponent) { return; }
	const float SplineLength = SplineComponent->GetSplineLength();
	for (int32 i = 0; i <= Count; i++)
	{
		const float Distance = Count > 1 ? SplineLength * i / (Count - 0) : 0.f;
		const FTransform SpawnTransform = SplineComponent->GetTransformAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		if (AOmegaPickupActor* Pickup = GetWorld()->SpawnActorDeferred<AOmegaPickupActor>(AOmegaPickupActor::StaticClass(),SpawnTransform))
		{
			Pickup->SetPreset(Preset);
			Pickup->ID = ID + i;
			Pickup->FinishSpawning(SpawnTransform);
		}
	}
}

void AOmegaPickupTrail::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (ID <= 0)
	{
		ID = UKismetMathLibrary::RandomIntegerInRange(0, 999999);
	}
	SetPreset(Preset);
}

bool AOmegaPickupActor::CanPickup_Implementation(APawn* Pawn, APlayerController* Controller)
{
	return true;
}

