// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Openable.h"

#include "Components/BoxComponent.h"
#include "Components/Component_ActorState.h"
#include "Components/Component_Inventory.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/Subsystem_Save.h"

void UOmegaOpenableStyle::Apply(AOmegaOpenableActor* Actor)
{
	if(Actor)
	{
		Actor->Range->SetRelativeTransform(RangeTransform);
		if(Mesh)
		{
			Mesh->OnAppliedToComponent(Actor->Mesh);
		}
		if(Anim_Open)
		{
			Actor->Mesh->SetAnimation(Anim_Open);
		}
	}
}

void UOmegaOpenable_Config::Apply(AOmegaOpenableActor* Actor)
{
}

bool UOmegaOpenable_Config::CanOpen(AOmegaOpenableActor* Openable, AActor* TargetActor)
{
	return true;
}

bool UOmegaOpenable_Config::CanAutoOpen(AOmegaOpenableActor* Openable, AActor* TargetActor)
{
	if(Openable && TargetActor)
	{
		for(auto c : AutoOpenFor_Actors)
		{
			if(c && TargetActor->GetClass()->IsChildOf(c)) { return true;}
		}
		if(APawn* p=Cast<APawn>(TargetActor))
		{
			if(!AutoOpenFor_Controllers.IsEmpty())
			{
				for(auto c : AutoOpenFor_Controllers)
				{
					if(c && p->GetController()->GetClass()->IsChildOf(c)) { return true;}
				}
			}
		}
	}
	return false;
}

void AOmegaOpenableActor::N_ActorOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(APawn* p=Cast<APawn>(OtherActor))
	{
		if(GetConfig() && GetConfig()->CanAutoOpen(this,p))
		{
			StartOpening(true);
		}
	}
}

void AOmegaOpenableActor::N_ActorOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(APawn* p=Cast<APawn>(OtherActor))
	{
		if(p->IsPlayerControlled())
		{
			if(GetConfig() && GetConfig()->CanAutoOpen(this,p))
			{
				StartOpening(false);
			}
		}
	}
}

void AOmegaOpenableActor::L_Init()
{
	if(bStartOpen) { SetAnimPosition(1.0);} else { SetAnimPosition(0.0);}
}

UOmegaOpenable_Config* AOmegaOpenableActor::GetConfig() const
{
	if(Config) { return Config; } return GetMutableDefault<UOmegaOpenable_Config>();
}

AOmegaOpenableActor::AOmegaOpenableActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Openable");
	Mesh=CreateOptionalDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionObjectType(ECC_WorldDynamic);
	Mesh->SetupAttachment(RootComponent);
	Range=CreateOptionalDefaultSubobject<UBoxComponent>("Range");
	Range->SetupAttachment(RootComponent);
	Range->SetBoxExtent(FVector(100,100,100));
	PrimaryActorTick.bCanEverTick=true;

	Range->OnComponentBeginOverlap.AddDynamic(this,&AOmegaOpenableActor::N_ActorOverlapBegin);
	Range->OnComponentEndOverlap.AddDynamic(this,&AOmegaOpenableActor::N_ActorOverlapEnd);
}

void AOmegaOpenableActor::Tick(float DeltaSeconds)
{
	bool _IsEnding=false;
	if(L_IsOpening)
	{
		if(l_openForward)
		{
			l_blendVal+=DeltaSeconds;
			if(l_blendVal>=F_GetMaxOpenTime())
			{
				_IsEnding=true;
			}
		}
		else
		{
			l_blendVal+=(DeltaSeconds*-1);
			if(l_blendVal<=0.0)
			{
				_IsEnding=true;
			}
		}
		SetAnimPosition(l_blendVal);
		OnOpenUpdate(l_blendVal,l_openForward);
	}
	if(_IsEnding)
	{
		L_IsOpening=false;
		OnOpenEnd(l_openForward);
	}
	Super::Tick(DeltaSeconds);
}

void AOmegaOpenableActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if(GetOpenableStyle())
	{
		Mesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
		Mesh->AnimationData.bSavedLooping=false;
		Mesh->AnimationData.bSavedPlaying=false;

		GetOpenableStyle()->Apply(this);
	}
	L_Init();
}

void AOmegaOpenableActor::BeginPlay()
{
	L_Init();
	Super::BeginPlay();
}

UOmegaOpenableStyle* AOmegaOpenableActor::GetOpenableStyle_Implementation()
{
	return nullptr;
}

void AOmegaOpenableActor::OnOpenUpdate_Implementation(float time, bool bForward)
{
}

bool AOmegaOpenableActor::CanOpen() const
{
	if(bLocked){ return false;}
	return true;
}

void AOmegaOpenableActor::SetLocked(bool Locked)
{
	bLocked=Locked;
}

void AOmegaOpenableActor::StartOpening(bool bForward,bool bSnap)
{
	if(Mesh && GetOpenableStyle() && CanOpen())
	{
		if(bSnap)
		{
			OnOpenBegin(bForward);
			if(bForward) { SetAnimPosition(1.0);} else { SetAnimPosition(0.0);}
			OnOpenEnd(bForward);
		}
		else
		{
			l_openForward=bForward;
			OnOpenBegin(bForward);
			L_IsOpening=true;
		}
	}
}

void AOmegaOpenableActor::SetAnimPosition(float position)
{
	if(Mesh && Mesh->GetSkeletalMeshAsset())
	{
		Mesh->AnimationData.SavedPosition=position;
		Mesh->AnimationData.ValidatePosition();
		Mesh->SetPosition(position);
	}
}

AOActor_Chest::AOActor_Chest()
{
	Inventory=CreateOptionalDefaultSubobject<UDataAssetCollectionComponent>("Inventory");
}

void AOmegaOpenableActor::OnOpenEnd_Implementation(bool bForward)
{
}

void AOmegaOpenableActor::OnOpenBegin_Implementation(bool bForward)
{
}


// ====================================================================================================================
// DOOR
// ====================================================================================================================