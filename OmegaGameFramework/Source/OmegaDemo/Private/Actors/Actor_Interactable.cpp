// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Interactable.h"

#include "LuaConst.h"
#include "LuaSubsystem.h"
#include "NiagaraComponent.h"
#include "OmegaSettings.h"
#include "OmegaGameplayConfig.h"
#include "OmegaGameManager.h"
#include "Subsystems/Subsystem_World.h"
#include "Components/BillboardComponent.h"
#include "Components/Component_Saveable.h"
#include "Components/Component_UtilMesh.h"
#include "Interfaces/I_ObjectTraits.h"
#include "Components/TextRenderComponent.h"
#include "Condition/Condition_Interact.h"
#include "DataAssets/DA_ActorModifierCollection.h"
#include "Functions/F_Actor.h"
#include "Functions/F_Common.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"



void AOmegaInteractable::OnConstruction(const FTransform& Transform)
{
	Update();
#if WITH_EDITOR
	if(!GetActorLabel().Contains("OmegaInteractable") && Lists.CustomNamedList.FindOrAdd("dialog").Option.IsNone())
	{
		Lists.CustomNamedList.FindOrAdd("dialog").ListID="dialog";
		Lists.CustomNamedList.FindOrAdd("dialog").Option=*GetActorLabel();
	}
#endif
	SetPreviewColor(PreviewColor);
	Super::OnConstruction(Transform);
	
	//corrective flow set. remove long term
	if (DialogueFlow && !GameplayComponent->DefaultFlow)
	{
		GameplayComponent->DefaultFlow=DialogueFlow;
		DialogueFlow=nullptr;
	}
	if (!DisplayName.IsEmpty())
	{
		GameplayComponent->OverrideName=DisplayName;
		DisplayName=FText();
	}
}

AOmegaInteractable::AOmegaInteractable()
{
	RangeBox=CreateOptionalDefaultSubobject<UBoxComponent>("Range");
	RangeBox->SetupAttachment(RootComponent);
	if(RangeBox)
	{
		RangeBox->SetBoxExtent(FVector(50,50,50));
		RangeBox->SetLineThickness(1.0);
		RangeBox->ShapeColor=FColor(0,100,255);
		MeshComponent=CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
		MeshComponent->SetupAttachment(RootComponent);
		NiagaraComponent=CreateOptionalDefaultSubobject<UNiagaraComponent>("Niagara");
		NiagaraComponent->SetupAttachment(RootComponent);
		
		NameText=CreateOptionalDefaultSubobject<UTextRenderComponent>("Text");
		if (UMaterialInterface* _mat=LoadObject<UMaterialInterface>(this,TEXT("/OmegaGameFramework/Materials/Shaders/Util/m_UTIL_TextOutline.m_UTIL_TextOutline")))
		{
			NameText->SetMaterial(0,_mat);	
		}
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
	if (L_IdentityUsesInteractInterface())
	{
		return IActorInterface_Interactable::Execute_IsInteractionBlocked(L_GetIdentity(),InteractInstigator,Tag,Context);
	}
	return false;
}

void AOmegaInteractable::OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
													  FOmegaCommonMeta Context)
{
	if(APawn* pawn=Cast<APawn>(InteractInstigator))
	{
		if(pawn->IsPlayerControlled())
		{
			FGameplayTag _targetType=OGF_CFG()->Default_InteractTag;
			if (RequiredInteractType.IsValid())
			{
				_targetType=RequiredInteractType;
			}
			if (Tag==_targetType)
			{
				if (L_IdentityUsesInteractInterface())
				{
					IActorInterface_Interactable::Execute_OnInteraction(L_GetIdentity(),InteractInstigator,Tag,Context);
				}
			}
		}
	}
}


void AOmegaInteractable::GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed,
	FOmegaClassNamedLists& named_lists)
{
	Super::GetMetaConfig_Implementation(bitflags, guid, seed, named_lists);
	bitflags=Flags;
	named_lists=Lists;
}

TArray<UOmegaObjectTrait*> AOmegaInteractable::GetTraits_Implementation()
{
	TArray<UOmegaObjectTrait*> out;
	if(UPrimaryDataAsset* _asset = GameplayComponent->GetIdentitySourceAsset())
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
	return nullptr;
}

void AOmegaInteractable::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description)
{
	if(GameplayComponent)
	{
		IDataInterface_General::Execute_GetGeneralDataText(GameplayComponent,Tag,Name,Description);
	}
	else
	{
		Name=DisplayName;
	}
}



void AOmegaInteractable::Update()
{
	if(NameText)
	{
		NameText->SetText(UOmegaGameFrameworkBPLibrary::GetObjectDisplayName(this,FGameplayTag()));
	}
	if(SpringArm)
	{
		FRotator _rot =UKismetMathLibrary::FindLookAtRotation(CameraDirection,SpringArm->GetRelativeLocation());
		SpringArm->SetRelativeRotation(_rot);
		float _dis=UKismetMathLibrary::Vector_Distance(SpringArm->GetRelativeLocation(),CameraDirection);
		SpringArm->TargetArmLength=_dis;
	}

#if WITH_EDITOR
	if(GameplayComponent && GameplayComponent->GetIdentitySourceAsset() && GetActorLabel()=="OmegaInteractable")
	{
		UPrimaryDataAsset* _id=GameplayComponent->GetIdentitySourceAsset();
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
	if(GameplayComponent && GameplayComponent->GetIdentitySourceAsset())
	{
		UPrimaryDataAsset* _id=GameplayComponent->GetIdentitySourceAsset();
		SetActorLabel(_id->GetName());
	}
#endif
	
}

void AOmegaInteractable::SetPreviewColor(FColor Color)
{
	PreviewColor=Color;
	if (NameText)
	{
		NameText->SetTextRenderColor(Color);
	}
	if(RangeBox)
	{
		RangeBox->ShapeColor=Color;
	}
	if (UtilMesh)
	{
		if (!dynaMat_PointerMesh)
		{
			dynaMat_PointerMesh=UtilMesh->CreateAndSetMaterialInstanceDynamic(0);
		}
		if(dynaMat_PointerMesh)
		{
			dynaMat_PointerMesh->SetVectorParameterValue("Tint",Color);
		}
	}
}

UOmegaInteractable_Preset::UOmegaInteractable_Preset()
{
	CollisionType=ECollisionEnabled::QueryAndPhysics;
}


UPrimaryDataAsset* AOmegaInteractable::L_GetIdentity() const
{
	if (GameplayComponent)
	{
		if (UPrimaryDataAsset* _id=GameplayComponent->GetIdentitySourceAsset())
		{
			return _id;
		}
	}
	return nullptr;
}

bool AOmegaInteractable::L_IdentityUsesInteractInterface() const
{
	if (GameplayComponent && GameplayComponent->GetIdentitySourceAsset())
	{
		if (UPrimaryDataAsset* _id=GameplayComponent->GetIdentitySourceAsset())
		{
			if (UOmegaActorFunctions::UsesInterface(_id))
			{
				return true;
			}
		}
	}
	return false;
}

void AOmegaInteractable::L_InteractionSystemEnd(UObject* Context, FString Flag)
{
	
}

void AOmegaInteractable::BeginPlay()
{
	Super::BeginPlay();

}


