// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Prop.h"

#include "Components/AudioComponent.h"
#include "NiagaraComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/SkeletalMesh.h"
#include "Components/BoxComponent.h"
#include "Components/Component_Saveable.h"
#include "Components/StateTreeComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"

void UOmegaProp_Preset::L_setBoundsFromComp(UBoxComponent* bounds, USceneComponent* comp,FBoxSphereBounds BoxBounds)
{
	if(bounds && comp && SetRangeToMeshBounds)
	{
		bounds->SetBoxExtent(BoxBounds.BoxExtent);
		bounds->SetRelativeLocation(comp->Bounds.Origin-comp->GetComponentLocation());
	}
}



void UOmegaProp_Preset::L_InitToSocket(USceneComponent* target, USceneComponent* socket_source,FName socket)
{
	if(target && socket_source)
	{
		if(socket_source->DoesSocketExist(socket))
		{
			FVector _loc=socket_source->GetSocketLocation(socket)-socket_source->GetComponentLocation();
			target->SetRelativeLocation(_loc);
		}
	}
}

UOAsset_Appearance* UOmegaProp_Preset::GetAppearanceAsset_Implementation()
{
	if(Appearance_Preset)
	{
		return Appearance_Preset;
	}
	if(Appearance_Custom)
	{
		return Appearance_Custom;
	}
	return nullptr;
}

void UOmegaProp_Preset::Apply(AOmegaProp* prop)
{
	if(prop && prop->RangeBox)
	{
		USceneComponent* socket_target=nullptr;
		prop->RangeBox->SetCollisionEnabled(CollisionType);
		if(StaticMesh)
		{
			StaticMesh->OnAppliedToComponent(prop->MeshStatic);
			socket_target=prop->MeshStatic;
			if(UStaticMesh* mesh=prop->MeshStatic->GetStaticMesh())
			{
				L_setBoundsFromComp(prop->RangeBox,prop->MeshStatic,mesh->GetBounds());
			}
			
			//L_SetCompToHalfHeight(prop->RangeBox,prop->MeshStatic);
		}
		if(SkeletalMesh)
		{
			SkeletalMesh->OnAppliedToComponent(prop->MeshSkeletal);
			socket_target=prop->MeshSkeletal;
			if(USkeletalMesh* mesh=prop->MeshSkeletal->GetSkeletalMeshAsset())
			{
				L_setBoundsFromComp(prop->RangeBox,prop->MeshSkeletal,mesh->GetBounds());
			}
			//L_SetCompToHalfHeight(prop->RangeBox,prop->MeshSkeletal);
		}
		if(Audio)
		{
			prop->Audio->SetSound(Audio);
			L_InitToSocket(prop->Audio,socket_target,Audio_AttachSocket);
			//L_SetCompToHalfHeight(prop->RangeBox,prop->Audio);
		}
		if(Niagara)
		{
			prop->Niagara->SetAsset(Niagara);
			L_InitToSocket(prop->Niagara,socket_target,Niagara_AttachSocket);
			//L_SetCompToHalfHeight(prop->RangeBox,prop->Niagara);
		}

		prop->GetRootComponent()->SetMobility(Mobility);
		TArray<USceneComponent*> childComps;
		prop->GetRootComponent()->GetChildrenComponents(true,childComps);
		for(auto* s : childComps)
		{
			if(s)
			{
				s->SetMobility(Mobility);
			}
		}
	}
}

void UOmegaProp_Preset::aConstruct(AOmegaProp* a)
{
	if(a)
	{
		FActorModifiers mods;
		mods.Script=Mods_Construct;
		mods.ApplyMods(a);
	}
}

void UOmegaProp_Preset::aBeginPlay(AOmegaProp* a)
{
	if(a)
	{
		FActorModifiers mods;
		mods.Script=Mods_BeginPlay;
		mods.ApplyMods(a);
	}
}

UOAsset_Appearance* AOmegaProp::GetAppearanceAsset_Implementation()
{
	if(Preset)
	{
		
	}
	return nullptr;
}

void AOmegaProp::OnConstruction(const FTransform& Transform)
{
	
	Super::OnConstruction(Transform);
}

void AOmegaProp::BeginPlay()
{

	Super::BeginPlay();
}



AOmegaProp::AOmegaProp()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	RangeBox=CreateOptionalDefaultSubobject<UBoxComponent>("Range");
	MeshStatic=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh - Static");
	MeshStatic->SetupAttachment(RootComponent);
	MeshStatic->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	MeshSkeletal=CreateOptionalDefaultSubobject<USkeletalMeshComponent>("Mesh - Skeletal");
	MeshSkeletal->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	MeshSkeletal->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
//	MeshSkeletal->AnimationData.bSavedLooping=false;
	//MeshSkeletal->AnimationData.bSavedPlaying=false;
	MeshSkeletal->SetupAttachment(RootComponent);
	Audio=CreateOptionalDefaultSubobject<UAudioComponent>("Audio");
	Audio->SetupAttachment(RootComponent);
	Niagara=CreateOptionalDefaultSubobject<UNiagaraComponent>("Niagara");
	Niagara->SetupAttachment(RootComponent);
	
	//Saveable=CreateOptionalDefaultSubobject<UOmegaSaveableComponent>("Savable");
	//StateTree=CreateOptionalDefaultSubobject<UStateTreeComponent>("StateTree");

	RootComponent->SetMobility(EComponentMobility::Type::Static);
	TArray<USceneComponent*> childComps;
	RootComponent->GetChildrenComponents(true,childComps);
	for(auto* s : childComps)
	{
		if(s)
		{
			s->SetMobility(EComponentMobility::Type::Static);
		}
	}

	
}

