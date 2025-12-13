// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Interactable.h"

#include "OmegaSettings_Gameplay.h"
#include "Components/Component_ActorConfig.h"
#include "Components/Component_Saveable.h"
#include "Components/Component_UtilMesh.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"
#include "Components/TextRenderComponent.h"
#include "Condition/Condition_Interact.h"
#include "DataAssets/DA_ActorModifierCollection.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"



void AOmegaInteractable::OnConstruction(const FTransform& Transform)
{
	Update();
	Super::OnConstruction(Transform);
}

UOmegaProp_Preset* AOmegaInteractable::L_GetPreset()
{
	if(Interactable_Preset)
	{
		return Interactable_Preset;
	}
	return nullptr;
}

AOmegaInteractable::AOmegaInteractable()
{
	if(RangeBox)
	{
		RangeBox->SetBoxExtent(FVector(50,50,50));
		RangeBox->SetLineThickness(1.5);
		RangeBox->ShapeColor=FColor(0,100,255);
		ActorID=CreateOptionalDefaultSubobject<UActorIdentityComponent>("ActorID");
		ActorConfig=CreateOptionalDefaultSubobject<UActorConfigComponent>("Config");
		NameText=CreateOptionalDefaultSubobject<UTextRenderComponent>("Text");
		NameText->SetMaterial(0,LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/m_UTIL_TextOutline.m_UTIL_TextOutline")));
		NameText->SetTextRenderColor(FColor::Blue);
		NameText->bHiddenInGame=true;
		NameText->HorizontalAlignment=EHTA_Center;
		NameText->SetupAttachment(RootComponent);
		SpringArm=CreateOptionalDefaultSubobject<USpringArmComponent>("SpringArm");
		if(SpringArm)
		{
			SpringArm->SetupAttachment(RangeBox);
			SpringArm->bDoCollisionTest=false;
			Camera=CreateOptionalDefaultSubobject<UCameraComponent>("Camera");
			Camera->FieldOfView=50;
			static ConstructorHelpers::FObjectFinder<UStaticMesh> SOFT_CamMesh(TEXT("/OmegaGameFramework/Meshes/util/sm_UTIL_CameraMini.sm_UTIL_CameraMini"));
#if WITH_EDITOR
			Camera->SetCameraMesh(SOFT_CamMesh.Object);
#endif
			Camera->SetupAttachment(SpringArm);
			SpringArm->TargetArmLength=300;
		}

		UtilMesh=CreateOptionalDefaultSubobject<UUtilMeshComponent>("UtilMesh");
		UtilMesh->SetupAttachment(RootComponent);
#if WITH_EDITOR
		UtilMesh->SetStaticMesh(LoadObject<UStaticMesh>(this,TEXT("/OmegaGameFramework/Meshes/util/SM_UTIL_Pointer.SM_UTIL_Pointer")));
		UtilMesh->SetMaterial(0,LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/instances/MI_UTIL_Rotator_B.MI_UTIL_Rotator_B")));
#endif
		UtilMesh->SetRelativeScale3D(FVector(0.6,0.6,0.6));
	}
}

bool AOmegaInteractable::IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if(Interactable_Preset)
	{
		FOmegaConditions_Interact con;
		con.Conditions=Interactable_Preset->InteractConditions;
		return !con.CheckConditions(InteractInstigator,this,Tag,Context);
	}
	return false;
}

TArray<UOmegaObjectTrait*> AOmegaInteractable::GetTraits_Implementation()
{
	TArray<UOmegaObjectTrait*> out;
	if(UPrimaryDataAsset* _asset = ActorID->GetIdentitySourceAsset())
    {
		TArray<UOmegaObjectTrait*> _in = UDataInterface_Traits::GetObjectTraits(_asset);
		out.Append(_in);
    }
	return out;
}

UFlowAsset* AOmegaInteractable::GetFlowAsset_Implementation(FGameplayTag Tag)
{
	if(DialogueFlow)
	{
		return DialogueFlow;
	}
	if(Interactable_Preset && Interactable_Preset->FlowAsset)
	{
		return Interactable_Preset->FlowAsset;
	}
	return nullptr;
}

void AOmegaInteractable::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                           FText& Description)
{
	if(Interactable_Preset)
	{
		Name=UDataInterface_General::GetObjectName(Interactable_Preset);
		Description=UDataInterface_General::GetObjectDesc(Interactable_Preset);
	}
	else
	{
		Name=DisplayName;
	}
	IDataInterface_General::GetGeneralDataText_Implementation(Label, Context, Name, Description);
}

void AOmegaInteractable::OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if(APawn* pawn=Cast<APawn>(InteractInstigator))
	{
		if(pawn->IsPlayerControlled())
		{
			if(UOmegaSettings_Gameplay* set=UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle())
			{
				
			}
		}
	}
}

void AOmegaInteractable::Update()
{
	if(NameText)
	{
		NameText->SetText(UDataInterface_General::GetObjectName(this));
	}
	if(SpringArm)
	{
		FRotator _rot =UKismetMathLibrary::FindLookAtRotation(CameraDirection,SpringArm->GetRelativeLocation());
		SpringArm->SetRelativeRotation(_rot);
		float _dis=UKismetMathLibrary::Vector_Distance(SpringArm->GetRelativeLocation(),CameraDirection);
		SpringArm->TargetArmLength=_dis;
	}


	
#if WITH_EDITOR
	if(Interactable_Preset && GetActorLabel()=="OmegaInteractable")
	{
		AutosetName();
	}
	if(RangeBox && NameText && UtilMesh)
    {
    	float zb=RangeBox->Bounds.BoxExtent.Z;
    	NameText->SetRelativeLocation(FVector(0,0,zb+150));
    	UtilMesh->SetRelativeLocation(FVector(0,0,zb+100));
    }
#endif
	
}

void AOmegaInteractable::AutosetName()
{
#if WITH_EDITOR
	if(Interactable_Preset)
	{
		SetActorLabel(Interactable_Preset->GetName());
	}
#endif
	
}

UOmegaInteractable_Preset::UOmegaInteractable_Preset()
{
	CollisionType=ECollisionEnabled::QueryAndPhysics;
}

void AOmegaInteractable::L_InteractionSystemEnd(UObject* Context, FString Flag)
{
	
}

void AOmegaInteractable::BeginPlay()
{
	Super::BeginPlay();
	if(Saveable->GetSaveParam_Bool("dead"))
	{
		K2_DestroyActor();
	}
}


