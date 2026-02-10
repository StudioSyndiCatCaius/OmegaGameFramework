// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Spawnable.h"

#include "OmegaSettings.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/OmegaUtils_Macros.h"

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
	
	BillboardComponent->SetSprite(nullptr);
	DisplayRoot->ShapeColor=FColor();
	DisplayRoot->SetRelativeLocation(FVector());
	
	if (SpawnableClass && SpawnableClass->ImplementsInterface(UActorInterface_Spawnable::StaticClass()))
	{
		if (AActor* _tempDef=GetMutableDefault<AActor>(SpawnableClass))
		{
			FColor _color;
			FText _disName;
			FVector _rootOffset;
			UTexture2D* _icon=nullptr;
			FVector _boxExt;
			float _iconScale;
			float _boxThick;
			IActorInterface_Spawnable::Execute_GetSpawnablePreviewConfig(_tempDef,_icon,_rootOffset,_disName,_color,_iconScale,_boxExt,_boxThick);
			OGF_CFG()->OverrideActorLabel(this,IActorInterface_Spawnable::Execute_GetSpawnable_ActorLabel(_tempDef));
			if (DisplayRoot)
			{
				if (_icon)
				{
					BillboardComponent->SetSprite(_icon);
				}
				BillboardComponent->SetWorldScale3D(FVector(_iconScale));
				DisplayRoot->ShapeColor=_color;
				DisplayRoot->SetRelativeLocation(_rootOffset);
				DisplayRoot->SetLineThickness(1);
				DisplayRoot->SetBoxExtent(_boxExt);
				DisplayRoot->SetLineThickness(_boxThick);
				TextRenderComponent->SetText(_disName);
				TextRenderComponent->SetHiddenInGame(true);
				TextRenderComponent->SetTextRenderColor(_color);
			}
		}
	}
}

void AOmegaActorSpawnable::BeginPlay()
{
	Super::BeginPlay();
	if (SpawnableClass && SpawnableClass->ImplementsInterface(UActorInterface_Spawnable::StaticClass()))
	{
		if (AActor* _tempDef=GetMutableDefault<AActor>(SpawnableClass))
		{
			bool bAutospawn = false;
			IActorInterface_Spawnable::Execute_GetSpawnableSpawnConfig(_tempDef,bAutospawn);
			if (bAutospawn)
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
	if (SpawnableClass && SpawnableClass->ImplementsInterface(UActorInterface_Spawnable::StaticClass()))
	{
		if (Spawnable_IsAlive())
		{
			if (!bForceRespawn)
			{
				return;
			}
			Spawnable_Destroy();
		}
	
		AActor* _tempActor=GetWorld()->SpawnActorDeferred<AActor>(SpawnableClass,FTransform());
		
		_tempActor->FinishSpawning(GetActorTransform());
		REF_linkedActor=_tempActor;
		IActorInterface_Spawnable::Execute_OnSpawnableSpawn(_tempActor,this,Flag);
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
