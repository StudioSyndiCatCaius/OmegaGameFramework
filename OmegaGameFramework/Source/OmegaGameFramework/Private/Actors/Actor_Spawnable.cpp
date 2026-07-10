// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Spawnable.h"

#include "Misc/OmegaFlowAssetBase.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "OmegaSettings.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/Component_GameplayActor.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Functions/F_Common.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Engine.h"
#include "Materials/Material.h"


bool AOmegaActorSpawnable::L_ClassUsesInterface() const
{
	if (Config.Class && Config.Class->ImplementsInterface(UActorInterface_Spawnable::StaticClass()))
	{
		return true;
	}
	return false;
}



AOmegaActorSpawnable::AOmegaActorSpawnable()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComp=RootComponent;
	
	DisplayRoot=CreateOptionalDefaultSubobject<UBoxComponent>("DisplayRoot");
	DisplayRoot->SetupAttachment(RootComponent);
	
	ArrowComponent=CreateOptionalDefaultSubobject<UArrowComponent>("Arrow");
	ArrowComponent->SetupAttachment(DisplayRoot);
	BillboardComponent=CreateOptionalDefaultSubobject<UBillboardComponent>("Billboard");
	BillboardComponent->SetupAttachment(DisplayRoot);
	TextRenderComponent=CreateOptionalDefaultSubobject<UTextRenderComponent>("Text");
	TextRenderComponent->SetupAttachment(DisplayRoot);
	TextRenderComponent->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	TextRenderComponent->SetMaterial(0,OGF_UASSET_MAT_TEXT_CAMFACE());
}

void AOmegaActorSpawnable::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (id<=0)
	{
		id=FMath::RandRange(1,9999999);
	}
	BillboardComponent->SetSprite(nullptr);
	TextRenderComponent->SetText(FText::FromString("-"));
	TextRenderComponent->SetWorldRotation(FRotator(0,0,0));
	DisplayRoot->ShapeColor=FColor(100,100,100);
	DisplayRoot->SetLineThickness(2);
	DisplayRoot->SetRelativeLocation(FVector());
	DisplayRoot->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DisplayRoot->SetCollisionResponseToAllChannels(ECR_Ignore);
	
	FOmegaSpawnablePreviewConfig PreviewConfig;
	
	UPrimaryDataAsset* _effectiveIdentity = Config.Identity;

	bool b_validSpawnable=false;
	if (L_ClassUsesInterface())
	{
		if (AActor* _tempDef=GetMutableDefault<AActor>(Config.Class))
		{
			b_validSpawnable=true;
			PreviewConfig=IActorInterface_Spawnable::Execute_GetSpawnablePreviewConfig(_tempDef);
			OGF_CFG()->OverrideActorLabel(this,IActorInterface_Spawnable::Execute_GetSpawnable_ActorLabel(_tempDef));
		}
	}

#if WITH_EDITOR
	if (GetActorLabel().Contains("OmegaActorSpawnable"))
	{
		if (Config.Identity)
		{
			SetActorLabel(PreviewConfig.Label+"_"+Config.Identity.GetName());
		}
		else
		{
			SetActorLabel(PreviewConfig.Label+"_"+FString::FromInt(UKismetMathLibrary::RandomIntegerInRange(0,99999)));
		}
	}
#endif
	
	if (b_validSpawnable)
	{
		if (DisplayRoot)
		{
			if (PreviewConfig.Icon)
			{
				BillboardComponent->SetSprite(PreviewConfig.Icon);
			}
			BillboardComponent->SetWorldScale3D(FVector(PreviewConfig.IconSize));
			DisplayRoot->ShapeColor=PreviewConfig.Color.ToFColor(true);
			ArrowComponent->SetArrowColor(PreviewConfig.Color);
			DisplayRoot->SetRelativeLocation(PreviewConfig.RangeOffset);
			DisplayRoot->SetLineThickness(1);
			DisplayRoot->SetBoxExtent(PreviewConfig.RangeSize);
			DisplayRoot->SetLineThickness(PreviewConfig.LineThickness);
			if (_effectiveIdentity)
			{
				FString _st=PreviewConfig.Label+": \n"+_effectiveIdentity->GetName();
				TextRenderComponent->SetText(FText::FromString(_st));
			}
			else
			{
				TextRenderComponent->SetText(FText::FromString(PreviewConfig.Label));
			}
			TextRenderComponent->SetHiddenInGame(true);
			TextRenderComponent->SetTextRenderColor(PreviewConfig.Color.ToFColor(true));
			TextRenderComponent->SetWorldLocation(GetActorLocation()+FVector(0,0,PreviewConfig.RangeSize.Z+PreviewConfig.RangeOffset.Z+10));
		}
	}
	
}

void AOmegaActorSpawnable::BeginPlay()
{
	Super::BeginPlay();
	if (L_ClassUsesInterface())
	{
		if (AActor* _tempDef=GetMutableDefault<AActor>(Config.Class))
		{
			bool bAutospawn = false;
			if (L_ClassUsesInterface())
			{
				IActorInterface_Spawnable::Execute_GetSpawnableSpawnConfig(_tempDef,bAutospawn);	
				if (bAutospawn)
				{
					Spawnable_Spawn(true);
				}
			}
			else
			{
				Spawnable_Spawn(true);
			}
			
		}
	}
}



bool AOmegaActorSpawnable::Spawnable_IsAlive() const
{
	if (REF_linkedActor && !REF_linkedActor->IsActorBeingDestroyed())
	{
		return true;
	}
	return false;
}

void AOmegaActorSpawnable::Spawnable_Spawn(bool bForceRespawn)
{
	if (L_ClassUsesInterface())
	{
		if (Spawnable_IsAlive())
		{
			if (!bForceRespawn)
			{
				return;
			}
			Spawnable_Destroy();
		}
	
		AActor* _tempActor=GetWorld()->SpawnActorDeferred<AActor>(Config.Class,FTransform(),this,nullptr,ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
		_tempActor->Tags.Append(Config.Tags);
		if (UActorComponent* com=_tempActor->GetComponentByClass(UGameplayActorComponent::StaticClass()))
		{
			UGameplayActorComponent* c=Cast<UGameplayActorComponent>(com);
			if (Config.Identity)
			{
				c->SetIdentitySourceAsset(Config.Identity);
			}
			if (Config.Flow.IsValid())
			{
				c->DefaultFlow=Config.Flow;	
			}
			if (Config.Zone)
			{
				c->Zone=Config.Zone;	
			}
		}
		
		_tempActor->FinishSpawning(GetActorTransform());
		REF_linkedActor=_tempActor;
		
#if WITH_EDITOR
		REF_linkedActor->SetActorLabel(GetActorLabel()+"_SPAWNED");
#endif
		
		if (L_ClassUsesInterface())
		{
			IActorInterface_Spawnable::Execute_OnSpawnableSpawn(_tempActor,this);
		}
	}
}

void AOmegaActorSpawnable::Spawnable_Destroy()
{
	if (Spawnable_IsAlive())
	{
		REF_linkedActor->K2_DestroyActor();
		REF_linkedActor=nullptr;
	}
}
